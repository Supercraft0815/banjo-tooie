// LLVM pass plugin: makes direct calls match the callee's real signature.
//
// The decomp code declares callees locally and K&R style, so across files a call often
// disagrees with the definition (s32 vs u8 parameters, int vs pointer, too few or too
// many arguments, a value expected from a void function). IDO passed everything in
// registers, so this worked on the N64. WebAssembly needs exact signatures, and its
// backend turns calls it cannot adapt into traps. This pass converts each argument to
// the callee's parameter type the way MIPS registers would (truncate, sign-extend,
// reinterpret), passes the caller's own parameters for missing arguments (register
// pass-through), drops extra ones, and converts the return value. It runs on the linked
// module before and after optimization (inlining makes new direct calls through pointers).
//
//   opt --load-pass-plugin=FixCalls.dylib -passes=bt-fixcalls in.bc -o out.bc
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Plugins/PassPlugin.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <map>
#include <set>

using namespace llvm;

// Symbols the N64 linker places at fixed addresses (undefined_syms.us.txt). Each line is
// "NAME BASE OFFSET" (inside the object BASE, which lives elsewhere natively) or
// "NAME = VALUE" (a ROM offset or other plain number).
static cl::opt<std::string> AbsSyms("bt-abs-syms", cl::desc("file of fixed-address symbols"));
// Where to list the functions that got pass-through parameters ("NAME OLD NEW" per line).
static cl::opt<std::string> Widened("bt-widened", cl::desc("output list of widened functions"));
// bt-xsym: where to list the checked access sites ("ID FUNCTION SYMBOL WIDTH load|store" per line).
static cl::opt<std::string> XsymSites("bt-xsym-sites", cl::desc("output list of checked access sites"));

namespace {

// data.py bridges a gap between two asm data files that holds variables defined in C and marks
// each one's N64 place with an alias "__bt_place_<name>". A zero-initialized variable moves there,
// so code that reaches it from a neighbouring label (`&D_80127040 + 0x10` is D_80127050) hits it
// as on the N64. Variables with an initializer stay where clang put them.
void placeCData(Module &M) {
    const DataLayout &DL = M.getDataLayout();
    SmallVector<GlobalAlias *, 32> Places;
    for (GlobalAlias &GA : M.aliases())
        if (GA.getName().starts_with("__bt_place_"))
            Places.push_back(&GA);
    for (GlobalAlias *GA : Places) {
        StringRef Name = GA->getName().substr(strlen("__bt_place_"));
        auto *GV = M.getGlobalVariable(Name, true);
        APInt Off(32, 0);
        auto *Block = dyn_cast<GlobalVariable>(GA->getAliasee()->stripAndAccumulateConstantOffsets(DL, Off, true));
        if (!GV || GV->isDeclaration() || !GV->getInitializer()->isNullValue() || !Block ||
            Off.getZExtValue() + DL.getTypeAllocSize(GV->getValueType()) > DL.getTypeAllocSize(Block->getValueType())) {
            if (GV && !GV->isDeclaration())
                errs() << "bt-fixcalls: " << Name << " stays outside its asm block (initializer or size)\n";
            GA->eraseFromParent();
            continue;
        }
        GV->replaceAllUsesWith(GA);
        GV->eraseFromParent();
        GA->setName(Name);
    }
}

void resolveAbsSyms(Module &M) {
    auto Buf = MemoryBuffer::getFile(AbsSyms);
    if (!Buf) {
        errs() << "bt-fixcalls: cannot read " << AbsSyms << "\n";
        return;
    }
    LLVMContext &Ctx = M.getContext();
    Type *I8 = Type::getInt8Ty(Ctx), *I32 = Type::getInt32Ty(Ctx);
    SmallVector<StringRef, 0> Lines;
    (*Buf)->getBuffer().split(Lines, '\n', -1, false);
    for (StringRef Line : Lines) {
        SmallVector<StringRef, 3> F;
        Line.split(F, ' ', -1, false);
        if (F.size() != 3)
            continue;
        GlobalValue *GV = M.getNamedValue(F[0]);
        if (!GV || !GV->isDeclaration())
            continue;
        int64_t N;
        if (F[2].getAsInteger(0, N))
            continue;
        Constant *C;
        if (F[1] == "=") {
            C = ConstantExpr::getIntToPtr(ConstantInt::get(I32, N), GV->getType());
        } else {
            GlobalValue *Base = M.getNamedValue(F[1]);
            if (!Base || Base->isDeclaration()) {
                errs() << "bt-fixcalls: " << F[0] << ": base " << F[1] << " not defined\n";
                continue;
            }
            C = ConstantExpr::getGetElementPtr(I8, Base, ConstantInt::get(I32, N));
        }
        GV->replaceAllUsesWith(C);
        GV->eraseFromParent();
    }
}

Value *convert(IRBuilder<> &B, Value *V, Type *To) {
    Type *From = V->getType();
    if (From == To)
        return V;
    const DataLayout &DL = B.GetInsertBlock()->getModule()->getDataLayout();
    if (From->isFloatingPointTy() && To->isFloatingPointTy()) // K&R promotion: same value
        return B.CreateFPCast(V, To);
    // Everything goes through an integer of the source's width, like a register would.
    if (From->isPointerTy())
        V = B.CreatePtrToInt(V, DL.getIntPtrType(From));
    else if (From->isFloatingPointTy())
        V = B.CreateBitCast(V, B.getIntNTy(From->getPrimitiveSizeInBits()));
    else if (!From->isIntegerTy())
        return Constant::getNullValue(To);
    if (To->isPointerTy())
        return B.CreateIntToPtr(B.CreateSExtOrTrunc(V, DL.getIntPtrType(To)), To);
    if (To->isFloatingPointTy())
        return B.CreateBitCast(B.CreateSExtOrTrunc(V, B.getIntNTy(To->getPrimitiveSizeInBits())), To);
    if (To->isIntegerTy())
        return B.CreateSExtOrTrunc(V, To);
    return Constant::getNullValue(To);
}

// IDO passes a struct by value as its words, in a0..a3 and then on the stack, and the game relies on
// that: callers hand over the words one by one, through a queue of raw words (chbaddiesetup), or pass
// a single value for a one-word struct. clang's wasm ABI passes a pointer to a copy (byval), so the
// callee read the first word as an address. Each byval parameter becomes one i32 per word, stored
// into a local copy; each byval argument becomes its words. Runs before bt-bigendian, which swaps
// these loads and stores like any other.
void flattenByVal(Module &M) {
    LLVMContext &Ctx = M.getContext();
    const DataLayout &DL = M.getDataLayout();
    Type *I8 = Type::getInt8Ty(Ctx), *I32 = Type::getInt32Ty(Ctx);
    auto Words = [&](Type *T) { return (unsigned)((DL.getTypeAllocSize(T) + 3) / 4); };
    SmallVector<CallInst *, 16> Calls;
    SmallVector<Function *, 8> Defs;
    for (Function &F : M) {
        if (!F.isDeclaration() && F.getAttributes().hasAttrSomewhere(Attribute::ByVal))
            Defs.push_back(&F);
        for (BasicBlock &BB : F)
            for (Instruction &I : BB)
                if (auto *CI = dyn_cast<CallInst>(&I))
                    if (CI->getAttributes().hasAttrSomewhere(Attribute::ByVal))
                        Calls.push_back(CI);
    }
    for (CallInst *CI : Calls) {
        IRBuilder<> B(CI);
        SmallVector<Value *, 8> Args;
        SmallVector<Type *, 8> Types;
        for (unsigned i = 0; i < CI->arg_size(); i++) {
            Value *A = CI->getArgOperand(i);
            if (Type *T = CI->getParamByValType(i)) {
                for (unsigned w = 0; w < Words(T); w++)
                    Args.push_back(B.CreateAlignedLoad(I32, B.CreateConstGEP1_32(I8, A, w * 4), Align(1)));
            } else {
                Args.push_back(A);
            }
        }
        for (Value *A : Args)
            Types.push_back(A->getType());
        CallInst *New = B.CreateCall(FunctionType::get(CI->getType(), Types, false), CI->getCalledOperand(), Args);
        New->setCallingConv(CI->getCallingConv());
        CI->replaceAllUsesWith(New);
        CI->eraseFromParent();
    }
    for (Function *F : Defs) {
        SmallVector<Type *, 8> Params;
        for (Argument &A : F->args())
            if (Type *T = A.getParamByValType())
                Params.append(Words(T), I32);
            else
                Params.push_back(A.getType());
        Function *NF = Function::Create(FunctionType::get(F->getReturnType(), Params, false), F->getLinkage(),
                                        F->getAddressSpace(), "", &M);
        NF->copyAttributesFrom(F);
        NF->setAttributes(AttributeList().addFnAttributes(Ctx, AttrBuilder(Ctx, F->getAttributes().getFnAttrs())));
        NF->splice(NF->begin(), F);
        IRBuilder<> B(&*NF->getEntryBlock().getFirstInsertionPt());
        unsigned n = 0;
        for (Argument &A : F->args()) {
            if (Type *T = A.getParamByValType()) {
                AllocaInst *Copy = B.CreateAlloca(ArrayType::get(I32, Words(T)));
                for (unsigned w = 0; w < Words(T); w++)
                    B.CreateAlignedStore(NF->getArg(n++), B.CreateConstGEP1_32(I8, Copy, w * 4), Align(4));
                A.replaceAllUsesWith(Copy);
            } else {
                A.replaceAllUsesWith(NF->getArg(n));
                NF->getArg(n++)->takeName(&A);
            }
        }
        F->replaceAllUsesWith(NF); // calls that disagree with NF's type are adapted by the main loop
        NF->takeName(F);
        F->eraseFromParent();
    }
}

// IDO code defines `void f() { g(); }` and relies on f's a0..a3 reaching g. In IR such an f has
// no parameters, so there is nothing to pass through. This gives each function as many leading
// parameters (new ones i32) as its short calls hand on, at most four, until nothing changes.
void addPassThroughParams(Module &M) {
    std::string Report;
    for (bool Changed = true; Changed;) {
        Changed = false;
        SmallVector<std::pair<Function *, unsigned>, 16> Grow;
        for (Function &F : M) {
            if (F.isDeclaration() || F.isVarArg() || F.getName().starts_with("bt_guest_"))
                continue;
            unsigned Want = F.arg_size();
            for (BasicBlock &BB : F)
                for (Instruction &I : BB)
                    if (auto *CI = dyn_cast<CallInst>(&I))
                        if (auto *Callee = dyn_cast<Function>(CI->getCalledOperand()->stripPointerCasts()))
                            if (!Callee->isIntrinsic() && CI->arg_size() < Callee->arg_size())
                                Want = std::max(Want, std::min(4u, (unsigned)Callee->arg_size()));
            if (Want > F.arg_size())
                Grow.push_back({&F, Want});
        }
        for (auto [F, Want] : Grow) {
            SmallVector<Type *, 4> Params(F->getFunctionType()->params());
            while (Params.size() < Want)
                Params.push_back(Type::getInt32Ty(M.getContext()));
            Function *NF = Function::Create(FunctionType::get(F->getReturnType(), Params, false), F->getLinkage(),
                                            F->getAddressSpace(), "", &M);
            NF->copyAttributesFrom(F);
            NF->splice(NF->begin(), F);
            for (unsigned i = 0; i < F->arg_size(); i++) {
                F->getArg(i)->replaceAllUsesWith(NF->getArg(i));
                NF->getArg(i)->takeName(F->getArg(i));
            }
            Report += (F->getName() + " " + Twine(F->arg_size()) + " " + Twine(Want) + "\n").str();
            F->replaceAllUsesWith(NF); // calls now disagree with NF's type; the main loop adapts them
            NF->takeName(F);
            F->eraseFromParent();
            Changed = true;
        }
    }
    if (!Widened.empty()) {
        std::error_code EC;
        raw_fd_ostream(Widened, EC, sys::fs::OF_Append) << Report; // both runs add to it
    }
}

// IDO code also defines `void f(x) { return_g(x); }` and its callers use f's result: v0 still holds
// g's. A void function whose result some call uses, and whose returns follow a call that yields a
// value, returns that value instead (other returns give 0).
void addPassThroughReturns(Module &M) {
    std::string Report;
    SmallPtrSet<Function *, 16> Wanted;
    std::vector<std::string> Stored;
    for (Function &F : M)
        for (BasicBlock &BB : F)
            for (Instruction &I : BB)
                if (auto *CI = dyn_cast<CallInst>(&I))
                    if (auto *Callee = dyn_cast<Function>(CI->getCalledOperand()->stripPointerCasts()))
                        if (!Callee->isDeclaration() && Callee->getReturnType()->isVoidTy() && !CI->getType()->isVoidTy()) {
                            Wanted.insert(Callee);
                            for (User *U : CI->users()) { // a stored result is a moved pointer or a handle: 0 breaks it
                                Value *V = CI;
                                if (auto *C = dyn_cast<CastInst>(U); C && C->hasOneUse())
                                    V = C, U = *C->user_begin();
                                if (auto *S = dyn_cast<StoreInst>(U); S && S->getValueOperand() == V)
                                    Stored.push_back(Callee->getName().str() + " in " + F.getName().str());
                            }
                        }
    auto lastCall = [](ReturnInst *R) -> CallInst * {
        for (Instruction *I = R->getPrevNode(); I; I = I->getPrevNode()) {
            if (isa<DbgInfoIntrinsic>(I) || isa<LifetimeIntrinsic>(I))
                continue;
            auto *CI = dyn_cast<CallInst>(I);
            return CI && !CI->getType()->isVoidTy() && !CI->getType()->isStructTy() ? CI : nullptr;
        }
        return nullptr;
    };
    for (Function *F : Wanted) {
        SmallVector<ReturnInst *, 4> Rets;
        Type *RT = nullptr;
        for (BasicBlock &BB : *F)
            if (auto *R = dyn_cast<ReturnInst>(BB.getTerminator())) {
                Rets.push_back(R);
                if (CallInst *CI = lastCall(R))
                    RT = RT ? RT : CI->getType();
            }
        if (!RT) { // a caller reads a result this function never produces: needs a source fix
            for (const std::string &S : Stored)
                if (S.compare(0, F->getName().size() + 1, (F->getName() + " ").str()) == 0)
                    Report += "VOIDSTORE " + S + "\n";
            continue;
        }
        Function *NF = Function::Create(FunctionType::get(RT, F->getFunctionType()->params(), F->isVarArg()),
                                        F->getLinkage(), F->getAddressSpace(), "", &M);
        NF->copyAttributesFrom(F);
        NF->splice(NF->begin(), F);
        for (unsigned i = 0; i < F->arg_size(); i++) {
            F->getArg(i)->replaceAllUsesWith(NF->getArg(i));
            NF->getArg(i)->takeName(F->getArg(i));
        }
        for (ReturnInst *R : Rets) {
            IRBuilder<> B(R);
            CallInst *CI = lastCall(R);
            B.CreateRet(CI ? convert(B, CI, RT) : Constant::getNullValue(RT));
            R->eraseFromParent();
        }
        Report += ("RET " + F->getName() + "\n").str();
        F->replaceAllUsesWith(NF); // the main loop adapts the calls
        NF->takeName(F);
        F->eraseFromParent();
    }
    if (!Widened.empty()) {
        std::error_code EC;
        raw_fd_ostream(Widened, EC, sys::fs::OF_Append) << Report;
    }
}

// IDO code also has `T f() { g(); }` (no return statement): v0, or f0 for a float, still holds g's
// result and callers use it; clang returns undef there. After mem2reg such a return is undef or a phi
// with undef inputs. Each gets the result of the last call before it with a value of the same register
// class, looking back through single predecessors (0 when there is none).
static Value *lastResult(BasicBlock *BB, Instruction *From, Type *RT) {
    SmallPtrSet<BasicBlock *, 8> Seen;
    for (Instruction *I = From; BB && Seen.insert(BB).second;) {
        for (; I; I = I->getPrevNode())
            if (auto *CI = dyn_cast<CallInst>(I); CI && !isa<IntrinsicInst>(CI)) {
                Type *T = CI->getType();
                if (!T->isVoidTy() && !T->isStructTy() && T->isFloatingPointTy() == RT->isFloatingPointTy())
                    return CI;
            }
        BB = BB->getSinglePredecessor();
        I = BB ? BB->getTerminator() : nullptr;
    }
    return nullptr;
}

void fixUndefReturns(Module &M) {
    std::string Report;
    for (Function &F : M) {
        Type *RT = F.getReturnType();
        if (F.isDeclaration() || RT->isVoidTy() || RT->isStructTy() || RT->isVectorTy())
            continue;
        bool Fixed = false;
        auto replacement = [&](BasicBlock *BB) {
            IRBuilder<> B(BB->getTerminator());
            Value *L = lastResult(BB, BB->getTerminator(), RT);
            Fixed = true;
            return L ? convert(B, L, RT) : Constant::getNullValue(RT);
        };
        for (BasicBlock &BB : F) {
            auto *R = dyn_cast<ReturnInst>(BB.getTerminator());
            Value *V = R ? R->getReturnValue() : nullptr;
            if (!V)
                continue;
            if (isa<UndefValue>(V))
                R->setOperand(0, replacement(&BB));
            else if (auto *P = dyn_cast<PHINode>(V))
                for (unsigned i = 0; i < P->getNumIncomingValues(); i++)
                    if (isa<UndefValue>(P->getIncomingValue(i)))
                        P->setIncomingValue(i, replacement(P->getIncomingBlock(i)));
        }
        if (Fixed) {
            F.removeRetAttr(Attribute::NoUndef);
            Report += ("UNDEFRET " + F.getName() + "\n").str();
        }
    }
    if (!Widened.empty()) {
        std::error_code EC;
        raw_fd_ostream(Widened, EC, sys::fs::OF_Append) << Report;
    }
}

// MIPS O32: the register (or stack slot) each argument of a prototype travels in. A float or double
// is in f12/f14 when it is the first argument, or the second after a first float; everything else
// takes 4-byte slots, a0..a3 then the stack (64-bit values start at an even slot).
static SmallVector<int, 8> o32Registers(ArrayRef<Type *> Params) {
    SmallVector<int, 8> R; // 0..3 a0..a3, 12/14 f12/f14, 100+n stack slot n
    unsigned Slot = 0;
    bool AllFloat = true;
    for (unsigned i = 0; i < Params.size(); i++) {
        Type *T = Params[i];
        bool F = T->isFloatingPointTy();
        unsigned Words = T->getPrimitiveSizeInBits() > 32 ? 2 : 1;
        if (Words == 2)
            Slot = (Slot + 1) & ~1u;
        if (F && i < 2 && AllFloat)
            R.push_back(i ? 14 : 12);
        else
            R.push_back(Slot < 4 ? (int)Slot : 100 + (int)Slot);
        AllFloat &= F;
        Slot += Words;
    }
    return R;
}

// IDO code also calls through a pointer with fewer arguments than the target takes
// (`(*(s32 (**)())(arg0 + 0x24))()` in chbanjoctrl): the caller's own a0..a3 are still in the
// registers. The target is unknown here, so every indirect call with fewer than four integer
// arguments also passes the caller's parameters of the missing slots. A target that takes fewer
// ignores them, natively (the build casts the pointer to the call's type) as on the N64. Only in
// the first run: after inlining the enclosing function is no longer the N64 caller.
static void passThroughIndirect(Module &M) {
    if (M.getNamedMetadata("bt.indirect.passthrough"))
        return;
    M.getOrInsertNamedMetadata("bt.indirect.passthrough");
    Type *I32 = Type::getInt32Ty(M.getContext());
    auto Word = [](Type *T) { return T->isPointerTy() || (T->isIntegerTy() && T->getIntegerBitWidth() <= 32); };
    SmallVector<CallInst *, 64> Work;
    for (Function &F : M)
        for (BasicBlock &BB : F)
            for (Instruction &I : BB)
                if (auto *CI = dyn_cast<CallInst>(&I))
                    if (!isa<Function>(CI->getCalledOperand()->stripPointerCasts()) && !CI->isInlineAsm() &&
                        !CI->getFunctionType()->isVarArg() && CI->arg_size() < 4 &&
                        all_of(CI->args(), [&](Value *A) { return Word(A->getType()); }))
                        Work.push_back(CI);
    for (CallInst *CI : Work) {
        Function *Caller = CI->getFunction();
        SmallVector<Type *, 4> OwnTypes;
        for (Argument &A : Caller->args())
            OwnTypes.push_back(A.getType());
        auto Own = o32Registers(OwnTypes);
        SmallVector<Value *, 4> Args(CI->args());
        for (unsigned Slot = CI->arg_size(); Slot < 4; Slot++) {
            Value *V = nullptr;
            for (unsigned k = 0; k < Own.size(); k++)
                if (Own[k] == (int)Slot && Word(OwnTypes[k]))
                    V = Caller->getArg(k);
            Args.push_back(V ? V : ConstantInt::get(I32, 0));
        }
        while (Args.size() > CI->arg_size() && isa<ConstantInt>(Args.back()))
            Args.pop_back(); // nothing of the caller's to hand on in the last slots
        if (Args.size() == CI->arg_size())
            continue;
        SmallVector<Type *, 4> Types;
        for (Value *A : Args)
            Types.push_back(A->getType());
        IRBuilder<> B(CI);
        CallInst *New = B.CreateCall(FunctionType::get(CI->getType(), Types, false), CI->getCalledOperand(), Args);
        New->setCallingConv(CI->getCallingConv());
        CI->replaceAllUsesWith(New);
        CI->eraseFromParent();
    }
}

struct FixCalls : PassInfoMixin<FixCalls> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        placeCData(M);
        if (!AbsSyms.empty())
            resolveAbsSyms(M);
        flattenByVal(M);
        fixUndefReturns(M);
        addPassThroughParams(M);
        passThroughIndirect(M);
        addPassThroughReturns(M);
        SmallVector<CallInst *, 64> Work;
        for (Function &F : M)
            for (BasicBlock &BB : F)
                for (Instruction &I : BB)
                    if (auto *CI = dyn_cast<CallInst>(&I))
                        if (auto *Callee = dyn_cast<Function>(CI->getCalledOperand()->stripPointerCasts()))
                            if (CI->getFunctionType() != Callee->getFunctionType() && !Callee->isIntrinsic())
                                Work.push_back(CI);
        std::string RegReport;
        for (CallInst *CI : Work) {
            auto *Callee = cast<Function>(CI->getCalledOperand()->stripPointerCasts());
            FunctionType *FT = Callee->getFunctionType();
            IRBuilder<> B(CI);
            SmallVector<Value *, 8> Args;
            unsigned N = FT->getNumParams();
            // A missing argument is what the caller still had in that register on the N64: IDO code
            // often calls f() and lets its own a0..a3 pass through.
            // Prototypes that put a value in another register class (a float where the callee has
            // an int, f12 against a0) are matched by register: the callee reads what the caller left
            // in that register, which may be the caller's own incoming argument.
            Function *Caller = CI->getFunction();
            SmallVector<Type *, 8> CallTypes, OwnTypes;
            for (Value *A : CI->args())
                CallTypes.push_back(A->getType());
            for (Argument &A : Caller->args())
                OwnTypes.push_back(A.getType());
            auto Regs = o32Registers(FT->params()), Have = o32Registers(CallTypes),
                 Own = o32Registers(OwnTypes);
            // Only an argument that one side passes in f12/f14 and the other in a0/a1 moves; other
            // differences (a double for a float shifting the slots) are K&R promotions of the same value.
            bool ByRegister = false;
            for (unsigned i = 0; i < 2 && i < N && i < Have.size(); i++)
                ByRegister |= (Regs[i] >= 12 && Regs[i] < 100) != (Have[i] >= 12 && Have[i] < 100);
            for (unsigned i = 0; i < N; i++) {
                Type *T = FT->getParamType(i);
                Value *V = nullptr;
                if (!ByRegister) {
                    V = i < CI->arg_size()      ? CI->getArgOperand(i)
                        : i < Caller->arg_size() ? (Value *)Caller->getArg(i)
                                                 : nullptr;
                } else {
                    for (unsigned k = 0; k < Have.size() && !V; k++)
                        if (Have[k] == Regs[i])
                            V = CI->getArgOperand(k);
                    for (unsigned k = 0; k < Own.size() && !V; k++)
                        if (Own[k] == Regs[i] && Regs[i] < 100)
                            V = Caller->getArg(k);
                }
                Args.push_back(V ? convert(B, V, T) : Constant::getNullValue(T));
            }
            if (ByRegister)
                RegReport += ("REGMAP " + Callee->getName() + " in " + Caller->getName() + "\n").str();
            if (FT->isVarArg())
                for (unsigned i = N; i < CI->arg_size(); i++)
                    Args.push_back(CI->getArgOperand(i));
            CallInst *New = B.CreateCall(FT, Callee, Args);
            New->setCallingConv(Callee->getCallingConv());
            New->setAttributes(Callee->getAttributes());
            New->setTailCallKind(CI->getTailCallKind() == CallInst::TCK_MustTail ? CallInst::TCK_None
                                                                                  : CI->getTailCallKind());
            Type *Want = CI->getType();
            // A used result that changes register class (f0 against v0) is a wrong declaration, not an
            // IDO idiom: on the N64 the caller would read a stale register. Reported, e.g. an
            // undeclared nearbyintf() gave the float's bits as an int (stretched HUD icon bone).
            if (!Want->isVoidTy() && !FT->getReturnType()->isVoidTy() && !CI->use_empty() &&
                Want->isFloatingPointTy() != FT->getReturnType()->isFloatingPointTy())
                RegReport += ("RETCLASS " + Callee->getName() + " in " + Caller->getName() + "\n").str();
            if (!Want->isVoidTy()) {
                Value *R = FT->getReturnType()->isVoidTy() ? Constant::getNullValue(Want) : convert(B, New, Want);
                CI->replaceAllUsesWith(R);
            }
            CI->eraseFromParent();
        }
        if (!Widened.empty() && !RegReport.empty()) {
            std::error_code EC;
            raw_fd_ostream(Widened, EC, sys::fs::OF_Append) << RegReport;
        }
        return PreservedAnalyses::none();
    }
};

// bt-bigendian: guest memory holds the N64's byte order. The decomp code reads the same bytes
// with different widths (a flag byte inside a word, a word through a byte pointer, bitfields
// in u8 and u32 units); only big-endian memory gives every such pair the N64 result. Each
// load and store wider than a byte swaps its value, initializers are stored swapped, and
// relocated words in initializers (pointers) are swapped at startup by bt_be_fixup(), which
// the host calls before any guest code. ROM data, RDP data and the framebuffer are then
// byte-for-byte N64 RDRAM. Runs on the linked module before optimization, so that no pass
// has combined or split accesses yet. Byte reversal of an N-bit value (N = 8k):
Value *swapValue(IRBuilder<> &B, Value *V) {
    unsigned N = V->getType()->getIntegerBitWidth();
    if (N <= 8)
        return V;
    unsigned P = PowerOf2Ceil(N);
    if (P == N)
        return B.CreateUnaryIntrinsic(Intrinsic::bswap, V);
    Value *W = B.CreateUnaryIntrinsic(Intrinsic::bswap, B.CreateZExt(V, B.getIntNTy(P)));
    return B.CreateTrunc(B.CreateLShr(W, P - N), V->getType());
}

APInt swapBits(const APInt &A) {
    unsigned N = A.getBitWidth();
    if (N <= 8)
        return A;
    unsigned P = PowerOf2Ceil(N);
    return A.zext(P).byteSwap().lshr(P - N).trunc(N);
}

// Integer type of a memory value's bytes; null for a byte (nothing to swap).
IntegerType *memIntType(Type *T, const DataLayout &DL) {
    unsigned Bits = T->isPointerTy() ? DL.getPointerSizeInBits(T->getPointerAddressSpace())
                    : T->isIntegerTy() || T->isFloatingPointTy() ? T->getPrimitiveSizeInBits().getFixedValue()
                                                                 : 0;
    if (!Bits) {
        errs() << "bt-bigendian: unsupported memory type " << *T << "\n";
        report_fatal_error("bt-bigendian");
    }
    if (Bits <= 8)
        return nullptr;
    if (Bits % 8) {
        errs() << "bt-bigendian: memory type " << *T << " is not whole bytes\n";
        report_fatal_error("bt-bigendian");
    }
    return IntegerType::get(T->getContext(), Bits);
}

Value *toInt(IRBuilder<> &B, Value *V, IntegerType *IT) {
    Type *T = V->getType();
    return T->isPointerTy() ? B.CreatePtrToInt(V, IT) : T->isIntegerTy() ? V : B.CreateBitCast(V, IT);
}

Value *fromInt(IRBuilder<> &B, Value *V, Type *T) {
    return T->isPointerTy() ? B.CreateIntToPtr(V, T) : T->isIntegerTy() ? V : B.CreateBitCast(V, T);
}

struct Fixup {
    GlobalVariable *GV;
    uint64_t Offset;
    unsigned Bytes;
};

// The initializer with every number byte-swapped; relocated leaves stay and become fixups.
Constant *swapInit(Constant *C, GlobalVariable *GV, uint64_t Off, const DataLayout &DL, std::vector<Fixup> &Fix) {
    Type *T = C->getType();
    if (isa<ConstantAggregateZero>(C) || isa<UndefValue>(C) || isa<ConstantPointerNull>(C))
        return C;
    if (auto *CI = dyn_cast<ConstantInt>(C))
        return ConstantInt::get(C->getContext(), swapBits(CI->getValue()));
    if (auto *CF = dyn_cast<ConstantFP>(C))
        return ConstantFP::get(C->getContext(), APFloat(CF->getValueAPF().getSemantics(),
                                                        swapBits(CF->getValueAPF().bitcastToAPInt())));
    if (auto *CDS = dyn_cast<ConstantDataSequential>(C)) {
        if (CDS->getElementByteSize() == 1)
            return C;
        SmallVector<Constant *, 64> E;
        for (unsigned i = 0; i < CDS->getNumElements(); i++)
            E.push_back(swapInit(CDS->getElementAsConstant(i), GV, Off + i * CDS->getElementByteSize(), DL, Fix));
        return isa<ConstantDataArray>(C) ? ConstantArray::get(cast<ArrayType>(T), E) : ConstantVector::get(E);
    }
    if (auto *CS = dyn_cast<ConstantStruct>(C)) {
        const StructLayout *SL = DL.getStructLayout(CS->getType());
        SmallVector<Constant *, 16> E;
        for (unsigned i = 0; i < CS->getNumOperands(); i++)
            E.push_back(swapInit(CS->getOperand(i), GV, Off + SL->getElementOffset(i), DL, Fix));
        return ConstantStruct::get(CS->getType(), E);
    }
    if (auto *CA = dyn_cast<ConstantArray>(C)) {
        uint64_t Size = DL.getTypeAllocSize(CA->getType()->getElementType());
        SmallVector<Constant *, 64> E;
        for (unsigned i = 0; i < CA->getNumOperands(); i++)
            E.push_back(swapInit(CA->getOperand(i), GV, Off + i * Size, DL, Fix));
        return ConstantArray::get(CA->getType(), E);
    }
    // A symbol's address (or arithmetic on one): known only after linking.
    if (IntegerType *IT = memIntType(T, DL))
        Fix.push_back({GV, Off, IT->getBitWidth() / 8});
    return C;
}

struct BigEndian : PassInfoMixin<BigEndian> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        const DataLayout &DL = M.getDataLayout();
        SmallVector<Instruction *, 0> Work;
        SmallVector<CallBase *, 0> VarCalls, VaStarts;
        for (Function &F : M)
            for (BasicBlock &BB : F)
                for (Instruction &I : BB)
                    if (isa<LoadInst>(I) || isa<StoreInst>(I))
                        Work.push_back(&I);
                    else if (auto *CB = dyn_cast<CallBase>(&I)) {
                        if (CB->getIntrinsicID() == Intrinsic::vastart)
                            VaStarts.push_back(CB);
                        else if (CB->getFunctionType()->isVarArg() && !CB->getIntrinsicID())
                            VarCalls.push_back(CB);
                    }
                    else if (isa<AtomicRMWInst>(I) || isa<AtomicCmpXchgInst>(I) || isa<VAArgInst>(I)) {
                        errs() << "bt-bigendian: unsupported " << I << " in " << F.getName() << "\n";
                        report_fatal_error("bt-bigendian");
                    }
        for (Instruction *I : Work) {
            IRBuilder<> B(I);
            if (auto *L = dyn_cast<LoadInst>(I)) {
                IntegerType *IT = memIntType(L->getType(), DL);
                if (!IT)
                    continue;
                LoadInst *Raw = B.CreateAlignedLoad(IT, L->getPointerOperand(), L->getAlign(), L->isVolatile());
                Raw->copyMetadata(*L);
                Value *V = fromInt(B, swapValue(B, Raw), L->getType());
                L->replaceAllUsesWith(V);
                V->takeName(L);
                L->eraseFromParent();
            } else {
                auto *S = cast<StoreInst>(I);
                Value *V = S->getValueOperand();
                IntegerType *IT = memIntType(V->getType(), DL);
                if (!IT)
                    continue;
                StoreInst *Raw = B.CreateAlignedStore(swapValue(B, toInt(B, V, IT)), S->getPointerOperand(),
                                                      S->getAlign(), S->isVolatile());
                Raw->copyMetadata(*S);
                S->eraseFromParent();
            }
        }
        // The backend writes a call's variadic arguments and va_start's pointer with its own
        // (little-endian) stores, while va_arg reads through swapped loads: pass the arguments
        // pre-swapped and swap the va_list after va_start.
        for (CallBase *CB : VarCalls) {
            IRBuilder<> B(CB);
            for (unsigned i = CB->getFunctionType()->getNumParams(); i < CB->arg_size(); i++) {
                Value *V = CB->getArgOperand(i);
                Type *T = V->getType();
                if (!T->isIntegerTy() && !T->isFloatingPointTy() && !T->isPointerTy()) {
                    errs() << "bt-bigendian: variadic argument " << *V << " in " << CB->getFunction()->getName() << "\n";
                    report_fatal_error("bt-bigendian");
                }
                if (IntegerType *IT = memIntType(T, DL))
                    CB->setArgOperand(i, fromInt(B, swapValue(B, toInt(B, V, IT)), T));
            }
        }
        for (CallBase *CB : VaStarts) {
            IRBuilder<> B(CB->getNextNode());
            Value *P = CB->getArgOperand(0);
            IntegerType *IT = B.getIntNTy(DL.getPointerSizeInBits());
            B.CreateAlignedStore(swapValue(B, B.CreateAlignedLoad(IT, P, Align(4))), P, Align(4));
        }
        std::vector<Fixup> Fix;
        for (GlobalVariable &GV : M.globals())
            if (GV.hasInitializer() && !GV.getName().starts_with("llvm.")) {
                size_t Before = Fix.size();
                GV.setInitializer(swapInit(GV.getInitializer(), &GV, 0, DL, Fix));
                if (Fix.size() != Before)
                    GV.setConstant(false); // swapped at startup, so loads must not fold the initializer
            }
        // bt_be_fixup(): byte-swaps the relocated words once their values exist.
        LLVMContext &Ctx = M.getContext();
        Function *FF = Function::Create(FunctionType::get(Type::getVoidTy(Ctx), false), GlobalValue::ExternalLinkage,
                                        "bt_be_fixup", &M);
        IRBuilder<> B(BasicBlock::Create(Ctx, "", FF));
        for (const Fixup &X : Fix) {
            Value *P = B.CreateConstInBoundsGEP1_64(B.getInt8Ty(), X.GV, X.Offset);
            IntegerType *IT = B.getIntNTy(X.Bytes * 8);
            B.CreateAlignedStore(swapValue(B, B.CreateAlignedLoad(IT, P, Align(1), true)), P, Align(1), true);
        }
        B.CreateRetVoid();
        return PreservedAnalyses::none();
    }
};

// bt-safepoints: the N64 preempts a game thread anywhere (timer and VI interrupts), and some
// loops wait for a higher-priority thread (func_800C2AB8 waits for the audio thread to stop
// sounds). Host threads only switch at OS calls, so every loop latch calls env.safepoint; the
// build turns that call into a check of the host's preemption flag. The pass runs before the
// optimizer, so the opaque call also keeps loads of shared data inside wait loops after inlining.
struct Safepoints : PassInfoMixin<Safepoints> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        LLVMContext &Ctx = M.getContext();
        Function *SP = Function::Create(FunctionType::get(Type::getVoidTy(Ctx), false),
                                        GlobalValue::ExternalLinkage, "host_safepoint", &M);
        SP->addFnAttr("wasm-import-module", "env");
        SP->addFnAttr("wasm-import-name", "safepoint");
        unsigned N = 0;
        for (Function &F : M) {
            if (F.isDeclaration())
                continue;
            DominatorTree DT(F);
            LoopInfo LI(DT);
            SmallVector<BasicBlock *, 16> Latches;
            for (Loop *L : LI.getLoopsInPreorder())
                L->getLoopLatches(Latches);
            for (BasicBlock *BB : Latches) {
                IRBuilder<>(BB->getTerminator()).CreateCall(SP);
                ++N;
            }
        }
        errs() << "bt-safepoints: " << N << " loop latches\n";
        return PreservedAnalyses::none();
    }
};

// bt-stackslots: IDO matches sometimes reach a neighbouring stack slot through a local's
// address (`func_801067C4((&sp28) - 1)` in suautobaddies_entrypoint_1). On the N64 that is
// another word of the frame; in LLVM it lies outside the object, and once inlining exposes the
// accesses SROA drops them (the actor loop then never advanced). Allocas reached at constant
// offsets outside their size grow to cover them, with room for the access at the far end.
struct StackSlots : PassInfoMixin<StackSlots> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        const DataLayout &DL = M.getDataLayout();
        Type *I8 = Type::getInt8Ty(M.getContext());
        const int64_t Slack = 16;  // bytes an access at the outermost offset may span
        unsigned N = 0;
        for (Function &F : M) {
            SmallVector<AllocaInst *, 16> Allocas;
            for (BasicBlock &BB : F)
                for (Instruction &I : BB)
                    if (auto *A = dyn_cast<AllocaInst>(&I); A && A->isStaticAlloca())
                        Allocas.push_back(A);
            for (AllocaInst *A : Allocas) {
                std::optional<TypeSize> Sz = A->getAllocationSize(DL);
                if (!Sz || Sz->isScalable())
                    continue;
                int64_t Size = (int64_t)Sz->getFixedValue(), Lo = 0, Hi = Size;
                SmallVector<std::pair<Value *, int64_t>, 16> Work{{A, 0}};
                while (!Work.empty()) {
                    auto [V, Off] = Work.pop_back_val();
                    for (User *U : V->users()) {
                        auto *G = dyn_cast<GEPOperator>(U);
                        APInt O(DL.getIndexTypeSizeInBits(A->getType()), 0);
                        if (!G || !G->accumulateConstantOffset(DL, O))
                            continue;
                        int64_t At = Off + O.getSExtValue();
                        if (At < 0 || At >= Size) {
                            Lo = std::min(Lo, At);
                            Hi = std::max(Hi, At + Slack);
                        }
                        Work.push_back({G, At});
                    }
                }
                if (Lo == 0 && Hi == Size)
                    continue;
                auto *NA = new AllocaInst(ArrayType::get(I8, (uint64_t)(Hi - Lo)), A->getAddressSpace(), nullptr,
                                          std::max(A->getAlign(), Align(8)), A->getName() + ".frame", A->getIterator());
                Value *P = IRBuilder<>(A).CreateConstGEP1_64(I8, NA, -Lo, A->getName());
                for (Use &U : make_early_inc_range(A->uses()))
                    if (auto *II = dyn_cast<IntrinsicInst>(U.getUser()); II && II->isLifetimeStartOrEnd())
                        U.set(NA);  // lifetime markers must name an alloca
                    else
                        U.set(P);
                A->eraseFromParent();
                errs() << "bt-stackslots: " << F.getName() << ": slot reached at " << Lo << ".." << Hi - Slack << "\n";
                ++N;
            }
        }
        errs() << "bt-stackslots: " << N << " stack slots widened\n";
        return N ? PreservedAnalyses::none() : PreservedAnalyses::all();
    }
};

// bt-xsym (diagnostic builds, BT_XSYM=1): finds code that reaches one data symbol through the
// address of another (IDO matches do this; data.py keeps neighbours together so it works, but
// typed C data and 64-bit layouts break it). Each load and store whose address is a data label
// plus arithmetic gets a range check against that label's extent (up to the next label of its
// asm block, or the C variable's size); a miss calls env.xsym(site, address). Runs before
// inlining, so the label is still visible in the function that computes the address.
struct Xsym : PassInfoMixin<Xsym> {
    static GlobalValue *label(Value *V, unsigned Depth = 0) {
        while (Depth++ < 32) {
            if (isa<GlobalAlias>(V) || isa<GlobalVariable>(V))
                return cast<GlobalValue>(V);
            auto *O = dyn_cast<Operator>(V);
            if (!O)
                return nullptr;
            switch (O->getOpcode()) {
            case Instruction::GetElementPtr:
            case Instruction::BitCast:
            case Instruction::IntToPtr:
            case Instruction::PtrToInt:
            case Instruction::Sub:  // label - x: only the first operand is the address
                V = O->getOperand(0);
                break;
            case Instruction::Add:
                if (GlobalValue *G = label(O->getOperand(0), Depth))
                    return G;
                V = O->getOperand(1);
                break;
            default:
                return nullptr;
            }
        }
        return nullptr;
    }

    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        const DataLayout &DL = M.getDataLayout();
        LLVMContext &Ctx = M.getContext();
        Type *IP = DL.getIntPtrType(Ctx), *I64 = Type::getInt64Ty(Ctx);
        // Extent of each label: up to the next label of the same block, else the object's end.
        std::map<const GlobalObject *, std::set<uint64_t>> Starts;
        std::map<const GlobalValue *, std::pair<uint64_t, const GlobalObject *>> At;
        for (GlobalAlias &GA : M.aliases()) {
            APInt Off(DL.getIndexTypeSizeInBits(GA.getType()), 0);
            const Value *Base = GA.getAliasee()->stripAndAccumulateConstantOffsets(DL, Off, true);
            auto *Obj = dyn_cast<GlobalVariable>(Base);
            if (!Obj || Off.isNegative())
                continue;
            At[&GA] = {Off.getZExtValue(), Obj};
            Starts[Obj].insert(Off.getZExtValue());
        }
        auto extent = [&](GlobalValue *G) -> uint64_t {
            if (auto *GV = dyn_cast<GlobalVariable>(G)) {
                if (GV->isDeclaration() || Starts.count(GV))  // whole asm blocks are not labels
                    return 0;
                return DL.getTypeAllocSize(GV->getValueType());
            }
            auto It = At.find(G);
            if (It == At.end())
                return 0;
            auto [Off, Obj] = It->second;
            uint64_t End = DL.getTypeAllocSize(Obj->getValueType());
            auto Next = Starts[Obj].upper_bound(Off);
            return (Next == Starts[Obj].end() ? End : *Next) - Off;
        };
        Function *Hit = Function::Create(FunctionType::get(Type::getVoidTy(Ctx), {IP, IP}, false),
                                         GlobalValue::ExternalLinkage, "host_xsym", &M);
        Hit->addFnAttr("wasm-import-module", "env");
        Hit->addFnAttr("wasm-import-name", "xsym");
        std::error_code EC;
        raw_fd_ostream Out(XsymSites.empty() ? std::string("xsym_sites.txt") : std::string(XsymSites), EC);
        unsigned N = 0;
        for (Function &F : M) {
            if (F.isDeclaration() || &F == Hit)
                continue;
            SmallVector<std::tuple<Instruction *, Value *, GlobalValue *, uint64_t, uint64_t>, 32> Work;
            for (BasicBlock &BB : F)
                for (Instruction &I : BB) {
                    Value *Ptr;
                    Type *Ty;
                    if (auto *L = dyn_cast<LoadInst>(&I))
                        Ptr = L->getPointerOperand(), Ty = L->getType();
                    else if (auto *S = dyn_cast<StoreInst>(&I))
                        Ptr = S->getPointerOperand(), Ty = S->getValueOperand()->getType();
                    else
                        continue;
                    GlobalValue *G = label(Ptr);
                    uint64_t Size = G ? extent(G) : 0, Width = DL.getTypeStoreSize(Ty);
                    if (Size && (Ptr != G || Width > Size))
                        Work.push_back({&I, Ptr, G, Size, Width});
                }
            for (auto [I, Ptr, G, Size, Width] : Work) {
                IRBuilder<> B(I);
                Value *Addr = B.CreatePtrToInt(Ptr, IP);
                Value *Off = B.CreateZExt(B.CreateSub(Addr, B.CreatePtrToInt(G, IP)), I64);
                Value *Bad = B.CreateICmpUGT(B.CreateAdd(Off, ConstantInt::get(I64, Width)), ConstantInt::get(I64, Size));
                IRBuilder<> T(SplitBlockAndInsertIfThen(Bad, I->getIterator(), false));
                T.CreateCall(Hit, {ConstantInt::get(IP, N), Addr});
                Out << N++ << ' ' << F.getName() << ' ' << G->getName() << ' ' << Width << ' '
                    << (isa<LoadInst>(I) ? "load" : "store") << '\n';
            }
        }
        errs() << "bt-xsym: " << N << " checked accesses\n";
        return PreservedAnalyses::none();
    }
};

// bt-datagroup: data_to_c.py definitions carry section ".btgroup.<module>.<N64 offset>". clang emits
// globals in order of first mention and the linker places each one apart, so code that reaches a
// table through its neighbour's label (IDO matched C does) would read other data. Each module's
// definitions become one packed block at their N64 offsets, the labels aliases into it, as data.py
// builds the asm modules. Runs after bt-bigendian (its fixups follow the aliases).
struct DataGroup : PassInfoMixin<DataGroup> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        const DataLayout &DL = M.getDataLayout();
        std::map<std::string, std::map<uint64_t, GlobalVariable *>> Groups;
        for (GlobalVariable &GV : M.globals()) {
            StringRef S = GV.getSection();
            if (!GV.hasInitializer() || !S.consume_front(".btgroup."))
                continue;
            auto [Mod, Off] = S.rsplit('.');
            uint64_t O;
            if (Off.getAsInteger(0, O) || !Groups[Mod.str()].emplace(O, &GV).second)
                report_fatal_error(Twine("bt-datagroup: bad section ") + GV.getSection());
        }
        LLVMContext &Ctx = M.getContext();
        Type *I8 = Type::getInt8Ty(Ctx);
        for (auto &[Mod, Members] : Groups) {
            SmallVector<Type *, 0> Types;
            SmallVector<Constant *, 0> Inits;
            std::vector<std::pair<GlobalVariable *, unsigned>> Fields;
            std::vector<std::pair<GlobalVariable *, uint64_t>> Inner;
            uint64_t Cur = 0;
            Align A(4);
            for (auto &[O, GV] : Members) {
                if (O < Cur) {
                    // bss_to_c.py: the previous label's declared type runs over this label, which
                    // then names bytes inside it. Only zero data can share storage.
                    if (!GV->getInitializer()->isNullValue())
                        report_fatal_error(Twine("bt-datagroup: overlap in ") + Mod);
                    uint64_t End = O + DL.getTypeAllocSize(GV->getValueType());
                    if (End > Cur) {
                        ArrayType *Pad = ArrayType::get(I8, End - Cur);
                        Types.push_back(Pad);
                        Inits.push_back(ConstantAggregateZero::get(Pad));
                        Cur = End;
                    }
                    Inner.push_back({GV, O});
                    continue;
                }
                if (O > Cur) {
                    ArrayType *Pad = ArrayType::get(I8, O - Cur);
                    Types.push_back(Pad);
                    Inits.push_back(ConstantAggregateZero::get(Pad));
                }
                Fields.push_back({GV, (unsigned)Types.size()});
                Types.push_back(GV->getValueType());
                Inits.push_back(GV->getInitializer());
                Cur = O + DL.getTypeAllocSize(GV->getValueType());
                A = std::max(A, GV->getAlign().valueOrOne());
            }
            StructType *ST = StructType::get(Ctx, Types, /*isPacked=*/true);
            auto *Block = new GlobalVariable(M, ST, false, GlobalValue::InternalLinkage,
                                             ConstantStruct::get(ST, Inits), "bt_group." + Mod);
            Block->setAlignment(A);
            auto Rename = [&](GlobalVariable *GV, Constant *At) {
                std::string Name = GV->getName().str();
                GV->setName("");
                auto *GA = GlobalAlias::create(GV->getValueType(), 0, GV->getLinkage(), Name, At, &M);
                GA->setVisibility(GV->getVisibility());
                GV->replaceAllUsesWith(GA);
                GV->eraseFromParent();
            };
            for (auto &[GV, Idx] : Fields) {
                Constant *Idxs[] = {ConstantInt::get(Type::getInt32Ty(Ctx), 0),
                                    ConstantInt::get(Type::getInt32Ty(Ctx), Idx)};
                Rename(GV, ConstantExpr::getInBoundsGetElementPtr(ST, Block, Idxs));
            }
            for (auto &[GV, O] : Inner)
                Rename(GV, ConstantExpr::getInBoundsGetElementPtr(
                               I8, Block, ConstantInt::get(Type::getInt32Ty(Ctx), O)));
        }
        return PreservedAnalyses::none();
    }
};

} // namespace

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "bt-fixcalls", "1", [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](StringRef Name, ModulePassManager &MPM, ArrayRef<PassBuilder::PipelineElement>) {
                        if (Name == "bt-fixcalls")
                            MPM.addPass(FixCalls());
                        else if (Name == "bt-bigendian")
                            MPM.addPass(BigEndian());
                        else if (Name == "bt-safepoints")
                            MPM.addPass(Safepoints());
                        else if (Name == "bt-stackslots")
                            MPM.addPass(StackSlots());
                        else if (Name == "bt-datagroup")
                            MPM.addPass(DataGroup());
                        else if (Name == "bt-xsym")
                            MPM.addPass(Xsym());
                        else
                            return false;
                        return true;
                    });
            }};
}

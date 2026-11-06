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
// module before and after LTO optimization (inlining makes new direct calls).
//
//   opt --load-pass-plugin=FixCalls.dylib -passes=bt-fixcalls in.bc -o out.bc
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Plugins/PassPlugin.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"

using namespace llvm;

// Symbols the N64 linker places at fixed addresses (undefined_syms.us.txt). Each line is
// "NAME BASE OFFSET" (inside the object BASE, which lives elsewhere natively) or
// "NAME = VALUE" (a ROM offset or other plain number).
static cl::opt<std::string> AbsSyms("bt-abs-syms", cl::desc("file of fixed-address symbols"));

namespace {

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
        uint64_t N;
        F[2].getAsInteger(0, N);
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

struct FixCalls : PassInfoMixin<FixCalls> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        if (!AbsSyms.empty())
            resolveAbsSyms(M);
        SmallVector<CallInst *, 64> Work;
        for (Function &F : M)
            for (BasicBlock &BB : F)
                for (Instruction &I : BB)
                    if (auto *CI = dyn_cast<CallInst>(&I))
                        if (auto *Callee = dyn_cast<Function>(CI->getCalledOperand()->stripPointerCasts()))
                            if (CI->getFunctionType() != Callee->getFunctionType() && !Callee->isIntrinsic())
                                Work.push_back(CI);
        for (CallInst *CI : Work) {
            auto *Callee = cast<Function>(CI->getCalledOperand()->stripPointerCasts());
            FunctionType *FT = Callee->getFunctionType();
            IRBuilder<> B(CI);
            SmallVector<Value *, 8> Args;
            unsigned N = FT->getNumParams();
            // A missing argument is what the caller still had in that register on the N64: IDO code
            // often calls f() and lets its own a0..a3 pass through.
            Function *Caller = CI->getFunction();
            for (unsigned i = 0; i < N; i++) {
                Type *T = FT->getParamType(i);
                Args.push_back(i < CI->arg_size()      ? convert(B, CI->getArgOperand(i), T)
                               : i < Caller->arg_size() ? convert(B, Caller->getArg(i), T)
                                                        : Constant::getNullValue(T));
            }
            if (FT->isVarArg())
                for (unsigned i = N; i < CI->arg_size(); i++)
                    Args.push_back(CI->getArgOperand(i));
            CallInst *New = B.CreateCall(FT, Callee, Args);
            New->setCallingConv(Callee->getCallingConv());
            New->setAttributes(Callee->getAttributes());
            New->setTailCallKind(CI->getTailCallKind() == CallInst::TCK_MustTail ? CallInst::TCK_None
                                                                                  : CI->getTailCallKind());
            Type *Want = CI->getType();
            if (!Want->isVoidTy()) {
                Value *R = FT->getReturnType()->isVoidTy() ? Constant::getNullValue(Want) : convert(B, New, Want);
                CI->replaceAllUsesWith(R);
            }
            CI->eraseFromParent();
        }
        return PreservedAnalyses::none();
    }
};

} // namespace

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "bt-fixcalls", "1", [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](StringRef Name, ModulePassManager &MPM, ArrayRef<PassBuilder::PipelineElement>) {
                        if (Name != "bt-fixcalls")
                            return false;
                        MPM.addPass(FixCalls());
                        return true;
                    });
            }};
}

#include "common.h"

const char R_808005A0_gzreg[] = "DPC_STATUS_XBUS_DMEM_DMA";
const char R_808005BC_gzreg[] = "DPC_STATUS_FREEZE";
const char R_808005D0_gzreg[] = "DPC_STATUS_FLUSH";
const char R_808005E4_gzreg[] = "DPC_STATUS_START_GCLK";
const char R_808005FC_gzreg[] = "DPC_STATUS_TMEM_BUSY";
const char R_80800614_gzreg[] = "DPC_STATUS_PIPE_BUSY";
const char R_8080062C_gzreg[] = "DPC_STATUS_CMD_BUSY";
const char R_80800640_gzreg[] = "DPC_STATUS_CBUF_READY";
const char R_80800658_gzreg[] = "DPC_STATUS_DMA_BUSY";
const char R_8080066C_gzreg[] = "DPC_STATUS_END_VALID";
const char R_80800684_gzreg[] = "DPC_STATUS_START_VALID";
const char R_8080069C_gzreg[] = "";
const char R_808006A0_gzreg[] = "SP_STATUS_HALT";
const char R_808006B0_gzreg[] = "SP_STATUS_BROKE";
const char R_808006C0_gzreg[] = "SP_STATUS_DMA_BUSY";
const char R_808006D4_gzreg[] = "SP_STATUS_DMA_FULL";
const char R_808006E8_gzreg[] = "SP_STATUS_IO_FULL";
const char R_808006FC_gzreg[] = "SP_STATUS_SSTEP";
const char R_8080070C_gzreg[] = "SP_STATUS_INTR_BREAK";
const char R_80800724_gzreg[] = "SP_STATUS_YIELD";
const char R_80800734_gzreg[] = "SP_STATUS_YIELDED";
const char R_80800748_gzreg[] = "SP_STATUS_TASKDONE";
const char R_8080075C_gzreg[] = "SP_STATUS_SIG3";
const char R_8080076C_gzreg[] = "SP_STATUS_SIG4";
const char R_8080077C_gzreg[] = "SP_STATUS_SIG5";
const char R_8080078C_gzreg[] = "SP_STATUS_SIG6";
const char R_8080079C_gzreg[] = "SP_STATUS_SIG7";
const char R_808007AC_gzreg[] = "";
const char R_808007B0_gzreg[] = "BD";
const char R_808007B4_gzreg[] = "IP8";
const char R_808007B8_gzreg[] = "IP7";
const char R_808007BC_gzreg[] = "IP6";
const char R_808007C0_gzreg[] = "IP5";
const char R_808007C4_gzreg[] = "IP4";
const char R_808007C8_gzreg[] = "IP3";
const char R_808007CC_gzreg[] = "IP2";
const char R_808007D0_gzreg[] = "IP1";
const char R_808007D4_gzreg[] = "Interrupt";
const char R_808007E0_gzreg[] = "TLB modification exception";
const char R_808007FC_gzreg[] = "TLB exception on load or instruction fetch";
const char R_80800828_gzreg[] = "TLB exception on store";
const char R_80800840_gzreg[] = "Address error on load or instruction fetch";
const char R_8080086C_gzreg[] = "Address error on store";
const char R_80800884_gzreg[] = "Bus error exception on instruction fetch";
const char R_808008B0_gzreg[] = "Bus error exception on data reference";
const char R_808008D8_gzreg[] = "System call exception";
const char R_808008F0_gzreg[] = "Breakpoint exception";
const char R_80800908_gzreg[] = "Reserved instruction exception";
const char R_80800928_gzreg[] = "Coprocessor unusable exception";
const char R_80800948_gzreg[] = "Arithmetic overflow exception";
const char R_80800968_gzreg[] = "Trap exception";
const char R_80800978_gzreg[] = "Virtual coherency exception on intruction fetch";
const char R_808009A8_gzreg[] = "Floating point exception (see fpcsr)";
const char R_808009D0_gzreg[] = "Watchpoint exception";
const char R_808009E8_gzreg[] = "Virtual coherency exception on data reference";
const char R_80800A18_gzreg[] = "";
const char R_80800A1C_gzreg[] = "CU3";
const char R_80800A20_gzreg[] = "CU2";
const char R_80800A24_gzreg[] = "CU1";
const char R_80800A28_gzreg[] = "CU0";
const char R_80800A2C_gzreg[] = "RP";
const char R_80800A30_gzreg[] = "FR";
const char R_80800A34_gzreg[] = "RE";
const char R_80800A38_gzreg[] = "BEV";
const char R_80800A3C_gzreg[] = "TS";
const char R_80800A40_gzreg[] = "SR";
const char R_80800A44_gzreg[] = "CH";
const char R_80800A48_gzreg[] = "CE";
const char R_80800A4C_gzreg[] = "DE";
const char R_80800A50_gzreg[] = "IM8";
const char R_80800A54_gzreg[] = "IM7";
const char R_80800A58_gzreg[] = "IM6";
const char R_80800A5C_gzreg[] = "IM5";
const char R_80800A60_gzreg[] = "IM4";
const char R_80800A64_gzreg[] = "IM3";
const char R_80800A68_gzreg[] = "IM2";
const char R_80800A6C_gzreg[] = "IM1";
const char R_80800A70_gzreg[] = "KX";
const char R_80800A74_gzreg[] = "SX";
const char R_80800A78_gzreg[] = "UX";
const char R_80800A7C_gzreg[] = "USR";
const char R_80800A80_gzreg[] = "SUP";
const char R_80800A84_gzreg[] = "KER";
const char R_80800A88_gzreg[] = "ERL";
const char R_80800A8C_gzreg[] = "EXL";
const char R_80800A90_gzreg[] = "IE";
const char R_80800A94_gzreg[] = "";
const char R_80800A98_gzreg[] = "FS";
const char R_80800A9C_gzreg[] = "C";
const char R_80800AA0_gzreg[] = "Unimplemented operation";
const char R_80800AB8_gzreg[] = "Invalid operation";
const char R_80800ACC_gzreg[] = "Division by zero";
const char R_80800AE0_gzreg[] = "Overflow";
const char R_80800AEC_gzreg[] = "Underflow";
const char R_80800AF8_gzreg[] = "Inexact operation";
const char R_80800B0C_gzreg[] = "EV";
const char R_80800B10_gzreg[] = "EZ";
const char R_80800B14_gzreg[] = "EO";
const char R_80800B18_gzreg[] = "EU";
const char R_80800B1C_gzreg[] = "EI";
const char R_80800B20_gzreg[] = "FV";
const char R_80800B24_gzreg[] = "FZ";
const char R_80800B28_gzreg[] = "FO";
const char R_80800B2C_gzreg[] = "FU";
const char R_80800B30_gzreg[] = "FI";
const char R_80800B34_gzreg[] = "RN";
const char R_80800B38_gzreg[] = "RZ";
const char R_80800B3C_gzreg[] = "RP";
const char R_80800B40_gzreg[] = "RM";
const char R_80800B44_gzreg[] = "";

struct GzRegEntry {
    s32 mask;
    s32 value : 32;
    s8 *name;
};

void func_80800000_gzreg(s32 arg0, s8 *arg1, struct GzRegEntry *arg2) {
    void func_8001D37C(BtIntPtr arg0, ...);
    s32 first;
    s32 mask;
    s8 *separator;
    s8 *format;

    first = 1;
    func_8001D37C("%s: x%08X ", arg1, arg0);
    func_8001D37C("<");
    separator = ",";
    format = "%s";
    mask = arg2->mask;
    if (mask != 0) {
        do {
            if ((mask & arg0) == arg2->value) {
                if (first != 0) {
                    first = 0;
                } else {
                    func_8001D37C(separator);
                }
                func_8001D37C(format, arg2->name);
            }
            arg2++;
            mask = arg2->mask;
        } while (mask != 0);
    }
    func_8001D37C(">\n");
}

void func_808000CC_gzreg(s8 *arg0, f32 arg1) {
    u32 func_800F21C4(f32);
    u32 temp_v0;

    temp_v0 = func_800F21C4(arg1);
    switch (temp_v0) {
    case 0:
        sprintf(arg0, "S.NaN");
        return;
    case 1:
        sprintf(arg0, "Q.NaN");
        return;
    case 2:
        sprintf(arg0, "+ve INF");
        return;
    case 3:
        sprintf(arg0, "-ve INF");
        return;
    case 4:
    case 5:
    case 8:
    case 9:
        sprintf(arg0, "%.6e", (f64)arg1);
        return;
    case 6:
    case 7:
        sprintf(arg0, "%d", *(s32 *)&arg1);
        break;
    }
}    typedef struct { u8 pad0[0x11C]; u32 unk11C; } Objreg_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void gzreg_entrypoint_0(void *arg0) {
    void func_8001D37C(BtIntPtr arg0, ...);
    extern struct GzRegEntry D_80800FF0_gzreg;
    extern struct GzRegEntry D_80801140_gzreg;
    extern struct GzRegEntry D_808012B4_gzreg;
    s8 sp50[24];
    s8 sp40[16];
    s8 sp30[16];
    __OSThreadContext *context;

    context = (__OSThreadContext *)((BtIntPtr)arg0 + 0x20);
    func_8001D37C("pc:x%08X\n", ((Objreg_arg0 *)arg0)->unk11C);
    func_80800000_gzreg(context->cause,
        "cause",
        &D_80800FF0_gzreg);
    func_8001D37C("\n");
    func_8001D37C("at:x%08X v0:x%08X v1:x%08X a0:x%08X\n",
        (u32)context->at,
        (u32)context->v0,
        (u32)context->v1,
        (u32)context->a0);
    func_8001D37C("a1:x%08X a2:x%08X a3:x%08X t0:x%08X\n",
        (u32)context->a1,
        (u32)context->a2,
        (u32)context->a3,
        (u32)context->t0);
    func_8001D37C("t1:x%08X t2:x%08X t3:x%08X t4:x%08X\n",
        (u32)context->t1,
        (u32)context->t2,
        (u32)context->t3,
        (u32)context->t4);
    func_8001D37C("t5:x%08X t6:x%08X t7:x%08X s0:x%08X\n",
        (u32)context->t5,
        (u32)context->t6,
        (u32)context->t7,
        (u32)context->s0);
    func_8001D37C("s1:x%08X s2:x%08X s3:x%08X s4:x%08X\n",
        (u32)context->s1,
        (u32)context->s2,
        (u32)context->s3,
        (u32)context->s4);
    func_8001D37C("s5:x%08X s6:x%08X s7:x%08X t8:x%08X\n",
        (u32)context->s5,
        (u32)context->s6,
        (u32)context->s7,
        (u32)context->t8);
    func_8001D37C("t9:x%08X gp:x%08X sp:x%08X s8:x%08X\n",
        (u32)context->t9,
        (u32)context->gp,
        (u32)context->sp,
        (u32)context->s8);
    func_8001D37C("ra:x%08X %s          badvaddr:x%08X\n",
        (u32)context->ra, "          ", context->badvaddr);
    func_8001D37C("\n");
    func_80800000_gzreg(context->fpcsr, "fpcsr", &D_808012B4_gzreg);
    func_8001D37C("\n");
    func_808000CC_gzreg(sp50, context->fp0.f.f_even);
    func_808000CC_gzreg(sp40, context->fp2.f.f_even);
    func_808000CC_gzreg(sp30, context->fp4.f.f_even);
    func_8001D37C("f0  %-13s f2  %-13s f4  %-13s\n", sp50, sp40, sp30);
    func_808000CC_gzreg(sp50, context->fp6.f.f_even);
    func_808000CC_gzreg(sp40, context->fp8.f.f_even);
    func_808000CC_gzreg(sp30, context->fp10.f.f_even);
    func_8001D37C("f6  %-13s f8  %-13s f10 %-13s\n", sp50, sp40, sp30);
    func_808000CC_gzreg(sp50, context->fp12.f.f_even);
    func_808000CC_gzreg(sp40, context->fp14.f.f_even);
    func_808000CC_gzreg(sp30, context->fp16.f.f_even);
    func_8001D37C("f12 %-13s f14 %-13s f16 %-13s\n", sp50, sp40, sp30);
    func_808000CC_gzreg(sp50, context->fp18.f.f_even);
    func_808000CC_gzreg(sp40, context->fp20.f.f_even);
    func_808000CC_gzreg(sp30, context->fp22.f.f_even);
    func_8001D37C("f18 %-13s f20 %-13s f22 %-13s\n", sp50, sp40, sp30);
    func_808000CC_gzreg(sp50, context->fp24.f.f_even);
    func_808000CC_gzreg(sp40, context->fp26.f.f_even);
    func_808000CC_gzreg(sp30, context->fp28.f.f_even);
    func_8001D37C("f24 %-13s f26 %-13s f28 %-13s\n", sp50, sp40, sp30);
    func_808000CC_gzreg(sp50, context->fp30.f.f_even);
    func_8001D37C("f30 %-13s\n", sp50);
    func_8001D37C("\n");
    func_80800000_gzreg(context->sr, "sr", &D_80801140_gzreg);
}

void gzreg_entrypoint_1(void)
{
    void func_8001D37C(BtIntPtr arg0, ...);
    s32 heap_bytes_free(void);
    extern struct GzRegEntry D_80800EA0_gzreg;
    extern struct GzRegEntry D_80800F30_gzreg;
    func_8001D37C("RDP current = 0x%08X   (0x%016llx) \n",
        IO_READ(DPC_CURRENT_REG) + K0BASE,
        *(u64 *)(IO_READ(DPC_CURRENT_REG) + K0BASE));
    func_8001D37C("RDP start   = 0x%08X   (0x%016llx) \n",
        IO_READ(DPC_START_REG) + K0BASE,
        *(u64 *)(IO_READ(DPC_START_REG) + K0BASE));
    func_8001D37C("RDP end     = 0x%08X   (0x%016llx) \n",
        IO_READ(DPC_END_REG) + K0BASE,
        *(u64 *)(IO_READ(DPC_END_REG) + K0BASE));
    func_80800000_gzreg(IO_READ(DPC_STATUS_REG), "\nRDP status:", &D_80800EA0_gzreg);
    func_80800000_gzreg(IO_READ(SP_STATUS_REG), "\nRSP status:", &D_80800F30_gzreg);
    func_8001D37C("\nFree memory was %d bytes.\n", heap_bytes_free());
}

s32 gzreg_entrypoint_2(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x11C);
}

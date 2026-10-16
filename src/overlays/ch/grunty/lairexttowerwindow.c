#include "common.h"

void func_80800000_chgruntylairexttowerwindow(s32 arg0) 
{
}
s32 func_80800008_chgruntylairexttowerwindow(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_80800070_chgruntylairexttowerwindow(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            _chexploder_entrypoint_3(arg0, arg0->position, 0xC);
            break;
        case 0x90:
            func_80800070_chgruntylairexttowerwindow(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800070_chgruntylairexttowerwindow(Actor *arg0) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    extern s32 D_808000D0_chgruntylairexttowerwindow;
    extern s32 D_8080013C_chgruntylairexttowerwindow;
    (void)&arg0;
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_808000D0_chgruntylairexttowerwindow);
    func_800C4AF0(arg0->position, &D_8080013C_chgruntylairexttowerwindow);
}

OSThread *chgruntylairexttowerwindow_entrypoint_0(void)
{
    extern u8 D_80800150_chgruntylairexttowerwindow[];

    return (OSThread *) D_80800150_chgruntylairexttowerwindow;
}

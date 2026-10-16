#include "core2/1EDD9C0.h"

s32 func_801040D0(void) {
    s32 func_800DFAD0(s32 *);
    extern s32 D_80135AB0;
    extern s32 D_80135AB8;
    (*(s32 **)((s8 *)(&D_80135AB0) + (0))) = &D_80135AB8;
    (*(s32 *)((s8 *)(&D_80135AB0) + (4))) = 0x6D;
    func_800DFAD0(&D_80135AB0);
    return (s32) &D_80135AB0;
}

void *func_8010410C(void)
{
    extern u8 D_80136BC0[];

    return D_80136BC0;
}

OSThread *func_80104118(void)
{
    extern u8 D_80136BE8[];

    return (OSThread *) D_80136BE8;
}

OSThread *func_80104124(void)
{
    extern u8 D_80124400[];

    return (OSThread *) D_80124400;
}

OSThread *func_80104130(void)
{
    extern u8 D_80136BF8[];

    return (OSThread *) D_80136BF8;
}

OSThread *func_8010413C(void)
{
    extern u8 D_80136D10[];

    return (OSThread *) D_80136D10;
}

void *func_80104148(s32 arg0) {
    extern u8 D_80136D88[];
    return D_80136D88 + arg0 * 20;
}

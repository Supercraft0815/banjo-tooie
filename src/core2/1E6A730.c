#include "core2/1E6A730.h"

s32 func_80090E40(void)
{
	return 0x18;
}    typedef struct { f32 unk0; u8 pad4[0xB]; u8 unkF; } Obj1E6A730_func_80090E48_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */ typedef struct { u8 pad0[0x30]; void * unk30; } Obj1E6A730_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80090E48(void *arg0) {
    s32 func_8008FD48();
    void func_80092DE4(PlayerState *, f32 *);
    void func_80092E5C(PlayerState *, f32 *);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    BtIntPtr func_8009FBB0(PlayerState *, f32[3], f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    extern s32 D_80117DB0;


    f32 sp34[3];
    void *temp_v1;

    if (((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xD))) == 0) || (func_8008FD48() != 1)) {
        func_80092E5C(arg0, sp34);
    } else {
        func_80092DE4(arg0, sp34);
    }
    func_800BABB8(func_8009FBB0(arg0, sp34, 0.0f), 0, 0, 1.0f, &D_80117DB0);
    temp_v1 = (((Obj1E6A730_arg0 *)arg0)->unk30);
    if (((((Obj1E6A730_func_80090E48_temp_v1 *)temp_v1)->unkF) != 0) && ((((Obj1E6A730_func_80090E48_temp_v1 *)temp_v1)->unk0) == 0.0f)) {
        (((Obj1E6A730_func_80090E48_temp_v1 *)temp_v1)->unk0) = (f32) 0.12f;
        func_8009DF94(arg0, 0x3ED, func_800DC178(0.5f, 0.7f), 0x1770);
    }
}

void func_80090F38(void *arg0) {
    f32 func_800DC0C0();
    s32 func_800DC128(s32 arg0, s32 arg1);
    f32 func_800DC178(f32, f32);






    f32 temp_f0;

    (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) = 0.0f;
    temp_f0 = func_800DC0C0();
    if (temp_f0 < 0.5f) {
        (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) = func_800DC178(0.6f, 0.7f);
        (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) = 1;
        return;
    }
    if (temp_f0 < 0.7f) {
        (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) = func_800DC178(0.7, 1.0f);
        (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) = func_800DC128(1, 4);
        return;
    }
    (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) = func_800DC178(2.3f, 2.6f);
    (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) = func_800DC128(6, 0xF);
}

void func_80091030(void *arg0) {
    (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) = 0.0f;
    (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) = 1;
}

void func_80091054(BtIntPtr arg0) 
{

}

void func_8009105C(PlayerState *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xC))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (4))) = 2.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xE))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x14))) = 0.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xF))) = 1;
    func_800910BC(arg0, 1);
}    typedef struct { u8 pad0[0x4]; f32 unk4; u8 pad8[0x6]; u8 unkE; u8 padF[0x1]; f32 unk10; f32 unk14; } Obj1E6A730_func_800910BC_p; /* offsets.py genstruct: fields from raw offsets on p; rename once understood */

void func_800910BC(PlayerState *arg0, s32 arg1) {
    void *p;

    p = *(void **)((s8 *)arg0 + 0x30);
    if (((Obj1E6A730_func_800910BC_p *)p)->unkE == 4) {
        ((Obj1E6A730_func_800910BC_p *)p)->unk4 = 0.0f;
        *(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x30) + 0xC) = 0;
        *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x30) + 0x14) = 0.0f;
        p = *(void **)((s8 *)arg0 + 0x30);
        ((Obj1E6A730_func_800910BC_p *)p)->unk10 = ((Obj1E6A730_func_800910BC_p *)p)->unk14;
    }
    p = *(void **)((s8 *)arg0 + 0x30);
    *(s8 *)((s8 *)p + 0xE) = arg1;
}

void func_80091104(s32 *arg0, s32 arg1)
{
    *(u8 *) (arg0[12] + 0xF) = arg1;
}

void func_80091110(void *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    s32 func_800F40EC(PlayerState *);


    f32 sp24;
    f32 temp_f0;

    func_800D9078((((Obj1E6A730_arg0 *)arg0)->unk30));
    if ((func_800F40EC(arg0) == 2) && ((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xE))) != 4)) {
        temp_f0 = func_800D8FF8();
        sp24 = temp_f0;
        if ((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) != 0) {
            (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) = (f32) ((*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) - temp_f0);
            if ((*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) < 0.0f) {
                (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (8))) = func_800DC178(0.066f, 0.1f);
                (*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) = (u8) ((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xC))) - 1);
                func_80090E48(arg0);
            }
        }
        (*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) = (f32) ((*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) - sp24);
        if (!((*(f32 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (4))) > 0.0f)) {
            if ((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xE))) == 3) {
                func_80091030(arg0);
            } else {
                func_80090F38(arg0);
            }
            if ((*(u8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xE))) == 2) {
                (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xD))) = 1;
                return;
            }
            if (func_800DC0C0() >= 0.5f) {
                (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xD))) = 0;
                return;
            }
            (*(s8 *)((s8 *)((((Obj1E6A730_arg0 *)arg0)->unk30)) + (0xD))) = 1;
        }
    }
}

void func_80091290(PlayerState *arg0, f32 arg1, s32 arg2, s32 arg3) {




    void func_80092C90(void *, f32[3], s32);
    BtIntPtr func_8009FBB0(PlayerState *, f32 *, f32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 scale;
    f32 position[3];
    s32 count;
    BtIntPtr emitter;
    f32 lifetime;

    scale = func_800F10B4(arg1, 5.0f, 20.0f, 4.0f, 0.7f);
    func_80092C90(arg0, position, arg3);
    (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x10)) += arg1 * func_800D8FF8();
    count = (s32)(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x10));
    (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x10)) -= count;
    emitter = func_8009FBB0(arg0, position, 40.0f);
    func_800BA930(emitter, -60, -50, -60, 60, 100, 60);
    if (arg2) {
        func_800BA6B0((u8 *)emitter, -50, -70, -50, 50, 70, 50);
        lifetime = 0.09f;
        func_800BA7C4((void *)emitter, lifetime, 0.1f);
        func_800BA7FC((void *)emitter, 0.2f, 0.22f);
    } else {
        func_800BA7C4((void *)emitter, 0.09f, 0.09f);
        func_800BA7FC((void *)emitter, 0.12f, 0.12f);
    }
    func_800BA8F8((void *)emitter, scale, scale);
    arg3 = 0;
    if (count > 0) {
        do {
            func_800BA22C(emitter, 1);
            arg3++;
        } while (arg3 != count);
    }
    if (arg1 > 3.0f) {
        arg1 = func_800F10B4(arg1, 3.0f, 60.0f, 3.0f, 8.0f);
    }
    (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x14)) += arg1 * func_800D8FF8();
    count = (s32)(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x14));
    (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x14)) -= count;
}

void func_800914FC(PlayerState *arg0, f32 arg1, s32 arg2) {
    func_80091290(arg0, arg1, arg2, 4);
}

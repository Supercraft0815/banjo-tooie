#include "core2/1E831D0.h"
#include "attract_inventory.inc"
void func_800A98E0(void) {
    void _gsattract_entrypoint_3(void);
    extern u8 D_80127760;
    extern s8 D_80127763;
    if ((D_80127760 != 1) && (D_80127760 == 2)) {
        _gsattract_entrypoint_3();
    }
    D_80127763 = 1;
}

void func_800A9924(s16 arg0, u8 arg1) {
    extern u8 D_80127760;
    void _glrecord_entrypoint_3(s32 arg0, s32 arg1);
    s32 func_800D3D28(void);
    void func_800A9D08(void);
    void func_8001608C(void);
    D_80127760 = *(&D_80127760 + 1);
    *(&D_80127760 + 1) = 0;
    func_800D3D28();
    if (D_80127760 == 1 || D_80127760 == 2) {
        _glrecord_entrypoint_3(*(s16 *)(&D_80127760 + 6), *(s16 *)(&D_80127760 + 8));
    }
    func_800A9D08();
    func_8001608C();
}

void func_800A9998(void) {
    extern u8 D_80127760;
    void func_800E80A0(void);
    void _gsattract_entrypoint_0(void);
    void func_800A1618(s32 arg0);
    switch (D_80127760) {
        case 1: func_800E80A0(); break;
        case 2: _gsattract_entrypoint_0(); break;
    }
    if (*(&D_80127760 + 4) != 0) {
        *(&D_80127760 + 4) = 0;
    }
    func_800A1618(1);
}

void func_800A9A14(void) {
    extern u8 D_80127760;
    s32 func_8001211C(void);
    void _gcgoto_entrypoint_14(s32 arg0);
    void func_800E8144(void);
    void _gsattract_entrypoint_1(void);
    func_8001211C();
    _gcgoto_entrypoint_14(1);
    if (*(&D_80127760 + 2) != 0 && *(&D_80127760 + 3) == 0) {
        func_800A98E0();
    }
    switch (D_80127760) {
        case 1: func_800E8144(); break;
        case 2: _gsattract_entrypoint_1(); break;
    }
}

void func_800A9AA4(BT_PARAM_OR_VOID(s32 bt_a0)) {
    extern u8 D_80127760;
    void func_800E817C(void);
    void _gsattract_entrypoint_2(void);
    switch (D_80127760) {
        case 1: func_800E817C(); break;
        case 2: _gsattract_entrypoint_2(); break;
    }
}

void func_800A9AF8(void) {
    extern u8 D_80127760;
    void func_800E8104(void);
    int func_800D3D58(void);
    void _glrecord_entrypoint_4(void);
    void func_800A1618(s32 arg0);
    switch (D_80127760) {
        case 1: func_800E8104(); break;
        case 2: break;
    }
    if (*(&D_80127760 + 4) == 0) {
            func_800D3D58();
        *(u8 *)(BtUIntPtr)&D_80127760 = 0;
        _glrecord_entrypoint_4();
    }
    *(&D_80127760 + 2) = *(&D_80127760 + 3) = 0;
    func_800A1618(0);
}

void func_800A9B84(void) {
}    typedef struct { u8 unk0; s8 unk1; u8 unk2; u8 pad3[0x1]; s8 unk4; u8 pad5[0x1]; s16 unk6; s16 unk8; s16 unkA; s16 unkC; } Obj1E831D0_D_80127760; /* offsets.py genstruct: fields from raw offsets on &D_80127760; rename once understood */

void func_800A9B8C(s32 arg0, s32 arg1) {
    extern u8 D_80127760;
    (((Obj1E831D0_D_80127760 *)&D_80127760)->unkA) = (s16) arg0;
    (((Obj1E831D0_D_80127760 *)&D_80127760)->unkC) = (s16) arg1;
}

void func_800A9BA0(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_80127760;
    void func_800A79D4(s32, s32);
    void func_800A7A90(s32);
    void func_800A7B18(u32);
    (((Obj1E831D0_D_80127760 *)&D_80127760)->unk1) = (s8) arg0;
    if ((((Obj1E831D0_D_80127760 *)&D_80127760)->unk0) != 0) {
        (((Obj1E831D0_D_80127760 *)&D_80127760)->unk4) = 1;
    }
    (((Obj1E831D0_D_80127760 *)&D_80127760)->unk6) = (s16) arg1;
    (((Obj1E831D0_D_80127760 *)&D_80127760)->unk8) = (s16) arg2;
    func_800A79D4(arg1, arg2);
    func_800A7A90(1);
    func_800A7B18(3U);
}

/* extern */

void func_800A9BFC(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800EA090(void);
    s32 func_800EA05C();
    struct { s32 map; s32 entrance; } saved;
    s32 entrance;

    func_800A9B84();
    saved.map = func_800EA05C();
    entrance = func_800EA090();
    func_800A9B8C(saved.map, entrance);
    func_800A9BA0(arg0, arg1, arg2);
}

/* extern */

void func_800A9C50(void) {
    extern u8 D_80127760;
    void func_800A79D4(s32, s32);
    void func_800A7A90(s32);
    void func_800A7B18(u32);
    s32 func_800A8264();
    if (func_800A8264() == 0) {
        func_800A79D4((s32) (((Obj1E831D0_D_80127760 *)&D_80127760)->unkA), (s32) (((Obj1E831D0_D_80127760 *)&D_80127760)->unkC));
        func_800A7A90(1);
        func_800A7B18(1U);
    }
}

s32 func_800A9C98(void) {
    extern u8 D_80127760;
    return D_80127760 != 0;
}

s32 func_800A9CAC(void) {
    extern u8 D_80127760;
    s32 result;
    result = 0;
    return D_80127760 ? 1 : result;
}

u32 func_800A9CD0(void) {
    extern u8 D_80127760;
    return *&((Obj1E831D0_D_80127760 *)&D_80127760)->unk0;
}

void func_800A9CDC(void) {
    extern u8 D_80127760;
    if ((((Obj1E831D0_D_80127760 *)&D_80127760)->unk2) == 0) {
        (((Obj1E831D0_D_80127760 *)&D_80127760)->unk2) = 1U;
    }
}

void func_800A9D00(void) {
}

void func_800A9D08(void) {
    void func_800D39A8(void);
    void func_800D39DC(s32 arg0);
    void func_800D3A20(s32 arg0);
    void func_800D3A88(void);
    void func_800D3AF0(s32 arg0);
    BT_IDO_ONLY(extern s16 D_8011A47C;)


    s16 *short_ptr;
    u32 i;
    u8 *byte_ptr;
    s16 *short_end;

    func_800D39A8();
    func_800D39DC(0);
    func_800D3A88();
    byte_ptr = D_8011A470;
    i = 0;
    do {
        func_800D3AF0(*byte_ptr);
        i++;
        byte_ptr++;
    } while ((u32)(u64)i < 7U);
    short_ptr = D_8011A478; short_end = BT_DATA_FIELD(D_8011A478 + 2, &D_8011A47C);
    do {
        func_800D3A20(*short_ptr);
        short_ptr++;
    } while (short_ptr != short_end);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80127760 BT_DATA(4, bss_core2bss1_0_1, 0x700);
s8 D_80127763 BT_DATA(4, bss_core2bss1_0_1, 0x703);
#endif

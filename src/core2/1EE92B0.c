#include "common.h"
#include "player_camera_controller.inc"
void func_8010F9C0(BtIntPtr arg0, s32 arg1) {
    void* _ncfixposrot_entrypoint_0(void);
    void _ncfixposrot_entrypoint_1(void* arg0);
    s16 _ncpod_entrypoint_0(s32);
    void _ncpod_entrypoint_1(s16);
    void *func_80110424(s32 *arg0, s32 arg1);
    void func_80110B68(void *, s32);
    void *object;

    if (arg1 != CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16))) {
        switch ((int)CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16))) {
        case 1:
            break;
        case 3:
            _ncfixposrot_entrypoint_1(CAMERA_FIELD(arg0, fixed, *(s32 *)(arg0 + 8)));
            CAMERA_FIELD(arg0, fixed, *(s32 *)(arg0 + 8)) = 0;
            break;
        case 8:
            _ncpod_entrypoint_1(CAMERA_FIELD(arg0, pod, *(s16 *)(arg0 + 0x14)));
            CAMERA_FIELD(arg0, pod, *(s16 *)(arg0 + 0x14)) = 0;
            break;
        case 2:
            object = CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4));
            if (object != NULL) {
                func_80110B68(object, 0);
            }
            break;
        }
        CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16)) = arg1;
        switch ((int)arg1) {
        case 1:
            break;
        case 3:
            CAMERA_FIELD(arg0, fixed, *(s32 *)(arg0 + 8)) = _ncfixposrot_entrypoint_0();
            break;
        case 2:
            object = CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4));
            if (object != NULL) {
                func_80110B68(object, 1);
            } else {
                CAMERA_FIELD(arg0, movement, *(s32 *)(arg0 + 4)) = func_80110424((void *)arg0, CAMERA_FIELD(arg0, player, *(s32 *)(arg0 + 0x1C)));
            }
            break;
        case 8:
            CAMERA_FIELD(arg0, pod, *(s16 *)(arg0 + 0x14)) = _ncpod_entrypoint_0(CAMERA_FIELD(arg0, player, *(s32 *)(arg0 + 0x1C)));
            break;
        }
    }
}

s32 func_8010FAE4(s16 *arg0) {
    return CAMERA_FIELD(arg0, mode, arg0[11]);
}                   typedef struct { u8 pad0[0xC]; s32 unkC; u8 pad10[0xC]; s32 unk1C; } Obj1EE92B0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void func_8010FAEC(BtIntPtr arg0, void *arg1) {
    s32 func_800A9420(s32);
    CAMERA_NATIVE(void func_80114FA4(Gfx **, u8 *);, s32 func_80114FA4(BtIntPtr, s32, void *);)
    if ((CAMERA_FIELD(arg1, effect, (((Obj1EE92B0_arg1 *)arg1)->unkC)) != 0) && (func_800A9420(CAMERA_FIELD(arg1, player, (((Obj1EE92B0_arg1 *)arg1)->unk1C))) != 0)) {
        CAMERA_NATIVE(func_80114FA4((Gfx **)arg0, CAMERA_FIELD(arg1, effect, 0)), func_80114FA4(arg0, (((Obj1EE92B0_arg1 *)arg1)->unkC), arg1));
    }
}    typedef struct { s32 unk0; BtIntPtr unk4; s32 unk8; void * unkC; void * unk10; s16 unk14; s16 unk16; s8 unk18; s8 unk19; u8 pad1A[0x2]; s32 unk1C; s8 unk20; } Obj1EE92B0_func_8010FB34_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void *func_8010FB34(CameraInput arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_8010F9C0(BtIntPtr, s32);
    void *func_80110424(s32 *arg0, s32 arg1);
    void *func_80114BD4(void);
    void *func_80115118(BtIntPtr);
    void *heap_alloc(s32);
    void *temp_v0;

    temp_v0 = heap_alloc(CAMERA_NATIVE(sizeof(PlayerCameraController), 0x40));
    CAMERA_FIELD(temp_v0, camera, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk0)) = arg0;
    CAMERA_FIELD(temp_v0, active, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk18)) = 0;
    CAMERA_FIELD(temp_v0, updating, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk19)) = 0;
    CAMERA_FIELD(temp_v0, command, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk20)) = 0;
    CAMERA_FIELD(temp_v0, projection, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk10)) = func_80114BD4();
    if (func_800DA298(0x6B5) != 0) {
        CAMERA_FIELD(temp_v0, effect, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unkC)) = func_80115118(BT_LP64_ONLY((BtIntPtr)) temp_v0);
    } else {
        CAMERA_FIELD(temp_v0, effect, (*(s32 *)((s8 *)(temp_v0) + (0xC)))) = 0;
    }
    CAMERA_FIELD(temp_v0, player, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk1C)) = arg1;
    CAMERA_FIELD(temp_v0, movement, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk4)) = func_80110424(temp_v0, arg1);
    CAMERA_FIELD(temp_v0, fixed, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk8)) = 0;
    CAMERA_FIELD(temp_v0, pod, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk14)) = 0;
    CAMERA_FIELD(temp_v0, mode, (((Obj1EE92B0_func_8010FB34_temp_v0 *)temp_v0)->unk16)) = 0;
    func_8010F9C0(BT_LP64_ONLY((BtIntPtr)) temp_v0, 1);
    return temp_v0;
} typedef struct { u8 * unk0; struct player_state_s * unk4; u8 pad8[0x4]; union { void * unkC; u8 * unkC_u8p; }; union { u8 * unk10; void * unk10_voidp; }; u8 pad14[0x4]; s8 unk18; u8 pad19[0x3]; s32 unk1C; s8 unk20; u8 pad21[0x1B]; f32 unk3C; } Obj1EE92B0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8010FBD4(void *arg0) {
    struct player_state_s;
    void func_8010F9C0(BtIntPtr, s32);
    void func_801104F4(struct player_state_s *);
    void func_80114C7C(void *);
    void func_801150F8(void *);
    void heap_free(void *);
    struct player_state_s *temp_a0;
    void *temp_a0_2;

    func_8010F9C0(BT_LP64_ONLY((BtIntPtr)) arg0, 1);
    temp_a0 = CAMERA_FIELD(arg0, movement, (((Obj1EE92B0_arg0 *)arg0)->unk4));
    if (temp_a0 != 0) {
        func_801104F4(temp_a0);
    }
    temp_a0_2 = CAMERA_FIELD(arg0, effect, (((Obj1EE92B0_arg0 *)arg0)->unkC));
    if (temp_a0_2 != 0) {
        func_801150F8(temp_a0_2);
    }
    func_80114C7C(CAMERA_FIELD(arg0, projection, (((Obj1EE92B0_arg0 *)arg0)->unk10_voidp)));
    heap_free(arg0);
}

s32 func_8010FC38(u8 *arg0) {
    struct player_state_s;
    void func_80110588(struct player_state_s *);
    void _ncfixposrot_entrypoint_6(BtIntPtr arg0, BtIntPtr arg1);
    void _ncpod_entrypoint_14(s16, void *);
    void func_800CA8B4(f32 *, f32 *, f32 *);
    void func_800E1A58(f32 *, f32 *);
    void func_800CA628(f32 *, f32 *, f32 *);
    void func_801151C4(void *);
    f32 sp3C[3];
    f32 sp30[3];
    s16 var_v0;
    void *temp_a0;

    var_v0 = CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16));
    if (CAMERA_FIELD(arg0, active, arg0[0x18]) == 0 && CAMERA_FIELD(arg0, updating, arg0[0x19]) == 0) {
        var_v0 = 0;
    }
    switch (var_v0) {
        case 2:
            func_80110588(CAMERA_FIELD(arg0, movement, *(struct player_state_s **)(arg0 + 4)));
            break;
        case 3:
            _ncfixposrot_entrypoint_6(BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, fixed, *(void **)(arg0 + 8)), BT_LP64_ONLY((BtIntPtr)) arg0);
            break;
        case 8:
            _ncpod_entrypoint_14(CAMERA_FIELD(arg0, pod, *(s16 *)(arg0 + 0x14)), arg0);
            break;
    }
    func_800CA8B4(CAMERA_FIELD(arg0, camera, *(f32 **)arg0), sp3C, sp30);
    func_800E1A58(sp3C, sp30);
    func_800CA628(CAMERA_FIELD(arg0, camera, *(f32 **)arg0), sp3C, sp30);
    temp_a0 = CAMERA_FIELD(arg0, effect, *(void **)(arg0 + 0xC));
    if (temp_a0 != 0) {
        func_801151C4(temp_a0); BT_NATIVE_ONLY(return 0;)
    } BT_LP64_ONLY(return 0;)
}

void func_8010FD08(u8 *arg0) { s32 func_8010FC38(u8 *); CAMERA_FIELD(arg0, updating, arg0[0x19]) = 1; func_8010FC38(arg0); CAMERA_FIELD(arg0, updating, arg0[0x19]) = 0; }

void func_8010FD38(BtIntPtr arg0, f32 arg1) {
    void func_80114CB0(void *arg0, f32 arg1);
    func_80114CB0(CAMERA_FIELD(arg0, projection, (((Obj1EE92B0_arg0 *)arg0)->unk10)), arg1);
}

void func_8010FD60(BtIntPtr arg0, f32 arg1) {
    void func_80114CC0(void *arg0, f32 arg1);
    func_80114CC0(CAMERA_FIELD(arg0, projection, (((Obj1EE92B0_arg0 *)arg0)->unk10)), arg1);
}

void func_8010FD88(u8 *arg0)
{
    func_8010FD08(arg0);
}

void func_8010FDA8(u8 *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    CAMERA_FIELD(arg0, command, (((Obj1EE92B0_arg0 *)arg0)->unk20)) = 0x28;
    func_800EE7F8(CAMERA_FIELD(arg0, commandPosition, arg0 + 0x24), arg1);
    func_800EE7F8(CAMERA_FIELD(arg0, commandRotation, arg0 + 0x30), arg2);
}

void func_8010FDEC(void *arg0, f32 arg1) {
    CAMERA_FIELD(arg0, command, (((Obj1EE92B0_arg0 *)arg0)->unk20)) = 0x29;
    CAMERA_FIELD(arg0, commandValue, (((Obj1EE92B0_arg0 *)arg0)->unk3C)) = arg1;
}

void func_8010FE00(void *arg0, s32 arg1, s32 arg2) {
    CAMERA_FIELD(arg0, active, (((Obj1EE92B0_arg0 *)arg0)->unk18)) = (s8) (arg2 == 2);
}

/* extern */

void func_8010FE14(s32 *arg0, f32 *arg1, f32 *arg2) {
    void func_800CA628(f32 *, f32 *, f32 *);
    func_800CA628(CAMERA_FIELD(arg0, camera, *(f32 **)arg0), arg1, arg2);
}

s32 func_8010FE34(BtIntPtr arg0, s32 arg1) {
    struct player_state_s;
    s32 _ncstart_entrypoint_0(s32, f32 *, f32 *);
    void func_800CA5B8(void *camera, f32 *position);
    void func_800CA668();
    void func_800CAF34(void *camera);
    void func_801108A0(void *);
    void func_80110928(void *);
    void func_80110970(void *, f32);
    void func_80110A24(struct player_state_s *, f32 *, f32 *);
    extern f32 D_80137320[3];
    extern f32 D_80137330[3];
    u8 command;

    command = CAMERA_FIELD(arg0, command, *(u8 *)(arg0 + 0x20));
    if (command != 0) {
        CAMERA_FIELD(arg0, command, *(u8 *)(arg0 + 0x20)) = 0;
        if (CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16)) == 2) {
            switch (command) {
                case 40:
                    func_8010FE14((s32 *)arg0, CAMERA_FIELD(arg0, commandPosition, (f32 *)(arg0 + 0x24)), CAMERA_FIELD(arg0, commandRotation, (f32 *)(arg0 + 0x30)));
                    func_801108A0(CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4)));
                    break;
                case 41:
                    func_80110970(CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4)), CAMERA_FIELD(arg0, commandValue, *(f32 *)(arg0 + 0x3C)));
                    break;
            }
            func_8010FD08((u8 *)arg0);
            return BT_LP64_ONLY(0);
        }
    }
    if (_ncstart_entrypoint_0(arg1, D_80137320, D_80137330) == 0) {
        if (CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16)) == 2) {
            func_80110928(CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4)));
        }
        func_8010FD08((u8 *)arg0);
        return BT_LP64_ONLY(0);
    }
    if (CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16)) == 2) {
        func_80110A24(CAMERA_FIELD(arg0, movement, *(struct player_state_s **)(arg0 + 4)), D_80137330, D_80137320);
    }
    func_800CA5B8(CAMERA_FIELD(arg0, camera, *(s32 *)arg0), D_80137320);
    func_800CA668(CAMERA_FIELD(arg0, camera, *(s32 *)arg0), D_80137330);
    func_800CAF34(CAMERA_FIELD(arg0, camera, *(s32 *)arg0));
    if (CAMERA_FIELD(arg0, mode, *(s16 *)(arg0 + 0x16)) == 2) {
        func_801108A0(CAMERA_FIELD(arg0, movement, *(void **)(arg0 + 4)));
        func_8010FD08((u8 *)arg0);
    } BT_NATIVE_ONLY(return 0;)
}

BtIntPtr func_8010FF80(s32 *arg0) {
    return BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, camera, arg0[0]);
}

/* extern */

void func_8010FF88(void *arg0 BT_PASS2(, CAMERA_NATIVE(f32 *,s32) bt_a0) BT_PASS2(, CAMERA_NATIVE(f32 *,s32) bt_a1)) {
    void func_80114C9C();
    func_80114C9C(CAMERA_FIELD(arg0, projection, (((Obj1EE92B0_arg0 *)arg0)->unk10_voidp)) BT_PASS2(, bt_a0) BT_PASS2(, bt_a1));
}

s32 func_8010FFA8(s16 *arg0) {
    return CAMERA_FIELD(arg0, mode, arg0[11]);
}

/* extern */

void func_8010FFB0(f32 **arg0, f32 *arg1, f32 *arg2) {
    void func_800CA8B4(f32 *, f32 *, f32 *);
    func_800CA8B4(CAMERA_FIELD(arg0, camera, *arg0), arg1, arg2);
}

u32 func_8010FFD0(u8 *arg0) {
    return CAMERA_FIELD(arg0, updating, arg0[25]);
}

/* extern */

s32 func_8010FFD8(BtIntPtr arg0) {
    u32 func_801150F0(u8 *);
    u8 *temp_a1;
    s32 var_v1;

    temp_a1 = CAMERA_FIELD(arg0, effect, (((Obj1EE92B0_arg0 *)arg0)->unkC_u8p));
    if (temp_a1 != 0) {
        var_v1 = func_801150F0(temp_a1);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

BtIntPtr func_80110014(s32 *arg0) {
    return BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, movement, arg0[1]);
}

BtIntPtr func_8011001C(s32 *arg0) {
    return BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, fixed, arg0[2]);
}

void *func_80110024(s16 *arg0) {
    void *_ncpod_entrypoint_2(s16);
    s16 temp;
    void *result;
    temp = CAMERA_FIELD(arg0, pod, arg0[10]);
    result = 0;
    if (temp != 0) {
        return _ncpod_entrypoint_2(temp);
    }
    return result;
}

BtIntPtr func_80110060(s32 *arg0) {
    return BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, projection, arg0[4]);
}

/* extern */

void *func_80110068(void *arg0, CameraInput arg1) {
    void *defrag(void *);
    s32 *func_80110FCC(s32 *, BtIntPtr);
    void *func_80114CD4(void *);
    s32 *func_80115324(s32 *, BtIntPtr);
    struct {
        s32 owner;
        s32 *field4;
        s32 field8;
        s32 *fieldC;
        void *field10;
    } *temp_v0;
    s32 *temp_a0;
    void *temp_a0_2;

    temp_v0 = defrag(arg0);
    CAMERA_FIELD(temp_v0, camera, temp_v0->owner) = arg1;
    if (CAMERA_FIELD(temp_v0, movement, temp_v0->field4) != 0) {
        CAMERA_FIELD(temp_v0, movement, temp_v0->field4) = func_80110FCC(CAMERA_FIELD(temp_v0, movement, temp_v0->field4), (BtIntPtr)temp_v0);
    }
    temp_a0 = CAMERA_FIELD(temp_v0, effect, temp_v0->fieldC);
    if (temp_a0 != 0) {
        CAMERA_FIELD(temp_v0, effect, temp_v0->fieldC) = func_80115324(temp_a0, (BtIntPtr)temp_v0);
    }
    temp_a0_2 = CAMERA_FIELD(temp_v0, projection, temp_v0->field10);
    if (temp_a0_2 != 0) {
        CAMERA_FIELD(temp_v0, projection, temp_v0->field10) = func_80114CD4(temp_a0_2);
    }
    return temp_v0;
}

/* extern */

void func_801100E4(s32 *arg0, s32 *arg1) { void func_800CA314(void *destination, void *source); void func_80110770(void *arg0, f32 *arg1); void func_80110790(BtIntPtr, f32 *); void func_80111018(BtIntPtr, BtIntPtr); f32 sp2C[3]; f32 sp20[3]; if (arg0 != arg1) { func_800CA314(CAMERA_FIELD(arg0, camera, arg0[0]), CAMERA_FIELD(arg1, camera, arg1[0])); if (CAMERA_FIELD(arg0, movement, arg0[1]) != 0) { func_8010FFB0(BT_LP64_ONLY((f32 **)) arg1, sp2C, sp20); func_80110770(CAMERA_FIELD(arg0, movement, arg0[1]), sp2C); func_80110790(BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, movement, arg0[1]), sp20); func_80111018(BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg0, movement, arg0[1]), BT_LP64_ONLY((BtIntPtr)) CAMERA_FIELD(arg1, movement, arg1[1])); } } }

/* extern */

void func_80110164(u8 *arg0) {
    void func_800CA6C0(void *arg0, f32 arg1, f32 arg2);
    void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2);
    void func_8011490C(void *arg0, s32 *arg1, s32 arg2);
    f32 sp1C;
    f32 sp18;

    func_8011490C(CAMERA_FIELD(arg0, projection, (*(s32 *)((s8 *)(arg0) + (0x10)))), BT_LP64_ONLY((s32 *)) arg0, CAMERA_FIELD(arg0, player, (((Obj1EE92B0_arg0 *)arg0)->unk1C)));
    func_80114C9C(CAMERA_FIELD(arg0, projection, (((Obj1EE92B0_arg0 *)arg0)->unk10)), &sp1C, &sp18);
    func_800CA6C0(CAMERA_FIELD(arg0, camera, (((Obj1EE92B0_arg0 *)arg0)->unk0)), sp1C, sp18);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 D_80137320 [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1900);
f32 D_80137330 [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1910);
#endif

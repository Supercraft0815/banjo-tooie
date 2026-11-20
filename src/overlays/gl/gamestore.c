#include "common.h"
#ifdef BT_NATIVE
#include "threads.h"
#endif

/* extern */

#ifdef BT_NATIVE
// The N64 code passes its callers' a0/a1 (buffer, size) through to the CRC check.
s32 func_80800000_glgamestore(void *buffer, s32 size) {
    s32 _glcrc_entrypoint_1(void *, BtIntPtr);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = _glcrc_entrypoint_1(buffer, size);
#else
s32 func_80800000_glgamestore(void) {
    s32 _glcrc_entrypoint_1();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = _glcrc_entrypoint_1();
#endif
    var_v1 = temp_v0;
    if (temp_v0 != 0) {
        var_v1 = 3;
    }
    return var_v1;
}

s32 func_80800030_glgamestore(s32 arg0) {
    return arg0 << 7;
}

s32 func_80800038_glgamestore(s32 arg0) {
    return func_80800030_glgamestore(2) + arg0 * 0x1C0;
}

s32 func_8080006C_glgamestore(s32 arg0, BtIntPtr arg1, s32 arg2) {
    BT_IDO_ONLY(s32 _gleeprom_entrypoint_2();) BT_NATIVE_ONLY(s32 _gleeprom_entrypoint_2(s32, u8 *, s32);)
    BT_IDO_ONLY(s32 func_80800000_glgamestore();)
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if (BT_DATA_FIELD(_gleeprom_entrypoint_2(arg0, (u8 *)arg1, arg2), _gleeprom_entrypoint_2(arg0)) != 0) {
        var_v1 = 2;
    }
    if (var_v1 == 0) {
#ifdef BT_NATIVE
        var_v1 = func_80800000_glgamestore((void *)arg1, arg2);
#else
        var_v1 = func_80800000_glgamestore(arg1, arg2);
#endif
    }
    return var_v1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) glgamestore_entrypoint_0(s32 arg0, BtIntPtr arg1) {
    s32 func_8080006C_glgamestore(s32, BtIntPtr, s32);
    BT_NATIVE_ONLY(return) func_8080006C_glgamestore(func_80800038_glgamestore(arg0), arg1, 0x1C0);
}

/* extern */

s32 glgamestore_entrypoint_1(s32 arg0, BtIntPtr arg1) {
    s32 _glglobaldata_entrypoint_1(u8 *arg0);
    s32 func_8080006C_glgamestore(s32, BtIntPtr, s32);
    s32 var_v1;
    s32 sp1C;

    var_v1 = func_8080006C_glgamestore(func_80800030_glgamestore(arg0), arg1, 0x80);
    if (var_v1 == 0) {
        sp1C = var_v1;
        if (_glglobaldata_entrypoint_1(BT_NATIVE_ONLY((u8 *))arg1) == 0) {
            var_v1 = 2;
        }
    }
    return var_v1;
}

#ifdef BT_NATIVE
s32 func_8080013C_glgamestore(s32 bt_a0, BtIntPtr bt_a1, s32 bt_a2) {
#else
s32 func_8080013C_glgamestore() {
#endif
    BT_IDO_ONLY(s32 _gleeprom_entrypoint_1();) BT_NATIVE_ONLY(s32 _gleeprom_entrypoint_1(s32, u8 *, s32);)
    BT_IDO_ONLY(extern s32 D_80079D70;) BT_NATIVE_ONLY(extern u64 D_80079D70[JOY_THREAD_STACK_SIZE64];)
    s32 var_v1;

    var_v1 = 0;
    if ((*(s32 *)((s8 *)BT_DATA_FIELD(D_80079D70, &D_80079D70) + (0x1EC))) == 2) {
        if (BT_DATA_FIELD(_gleeprom_entrypoint_1(bt_a0, (u8 *)bt_a1, bt_a2), _gleeprom_entrypoint_1()) != 0) {
            var_v1 = 1;
        }
    }
    return var_v1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) glgamestore_entrypoint_2(s32 arg0, BtIntPtr arg1) {
    BT_IDO_ONLY(s32 func_8080013C_glgamestore();)
    BT_NATIVE_ONLY(return) func_8080013C_glgamestore(func_80800038_glgamestore(arg0), arg1, 0x1C0);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) glgamestore_entrypoint_3(s32 arg0, BtIntPtr arg1) {
    BT_IDO_ONLY(s32 func_8080013C_glgamestore();)
    BT_NATIVE_ONLY(return) func_8080013C_glgamestore(func_80800030_glgamestore(arg0), arg1, 0x80);
}

s32 func_808001E0_glgamestore(s32 arg0) {
    BT_IDO_ONLY(s32 _gleeprom_entrypoint_1();) BT_NATIVE_ONLY(s32 _gleeprom_entrypoint_1(s32, u8 *, s32);)
    BT_IDO_ONLY(extern s32 B_80800270_glgamestore;) BT_NATIVE_ONLY(extern u8 B_80800270_glgamestore[8];)
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if (_gleeprom_entrypoint_1(arg0, BT_DATA_FIELD(B_80800270_glgamestore, &B_80800270_glgamestore), 8) != 0) {
        var_v1 = 1;
    }
    return var_v1;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) glgamestore_entrypoint_4(BT_NATIVE_ONLY(s32 bt_a0))
{
    BT_IDO_ONLY(s32 func_80800038_glgamestore();)
#ifdef BT_NATIVE
    BT_NATIVE_ONLY(return) func_808001E0_glgamestore(func_80800038_glgamestore(bt_a0));
#else
    func_808001E0_glgamestore(func_80800038_glgamestore());
#endif
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) glgamestore_entrypoint_5(BT_PARAM_OR_VOID(s32 bt_a0)) {
    BT_IDO_ONLY(s32 func_80800030_glgamestore();)
    s32 func_808001E0_glgamestore(s32);
#ifdef BT_NATIVE
    BT_NATIVE_ONLY(return) func_808001E0_glgamestore(func_80800030_glgamestore(bt_a0));
#else
    func_808001E0_glgamestore(func_80800030_glgamestore());
#endif
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 B_80800270_glgamestore[8] BT_DATA(16, bss_gl_gamestore, 0x0);
#endif

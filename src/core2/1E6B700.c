#include "common.h"

s32 func_80091E10(void)
{
	return 0x4;
}

void func_80091E18(BtIntPtr arg0) 
{
}                 typedef struct { u8 pad0[0x48]; u8 * unk48; u8 * unk4C; u8 pad50[0x134]; s32 unk184; } Obj1E6B700_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void func_80091E20(u8 *arg0) {
    s32 func_80091E48(void *, s32);
    (*(s8 *)((s8 *)((((Obj1E6B700_arg0 *)arg0)->unk48)) + (3))) = 0;
    func_80091E48(arg0, 0x7F);
}

s32 func_80091E48(void *arg0, s32 arg1) {
    u8 *data;

    data = *(u8 **)((u8 *)arg0 + 0x48);
    data[data[3]] = arg1;
    data = *(u8 **)((u8 *)arg0 + 0x48);
    data[3]++; BT_NATIVE_ONLY(return 0;)
}    typedef struct { u8 pad0[0x3]; u8 unk3; } Obj1E6B700_func_80091E6C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80091E6C(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x48)));
    (((Obj1E6B700_func_80091E6C_temp_v0 *)temp_v0)->unk3) = (u8) ((((Obj1E6B700_func_80091E6C_temp_v0 *)temp_v0)->unk3) - 1);
}

s32 func_80091E80(u8 *arg0, s32 arg1) {
    struct Data { u8 bytes[256]; };
    struct Data *temp_v1;

    temp_v1 = *(struct Data **)(arg0 + 0x48);
    return arg1 == (temp_v1->bytes[temp_v1->bytes[3] - 1] & arg1);
}

s32 func_80091EA0(void)
{
	return 0x1;
}

void func_80091EA8(BtIntPtr arg0)
{
    func_80091F74(arg0,0);
}

void func_80091EC8(void *arg0) {
    *((Obj1E6B700_arg0 *)arg0)->unk4C = 0;
    func_80091F74(arg0, 1);
}

void func_80091EF0(s32 arg0) {
    s32 func_80091FE4(void);
    if (func_80091FE4() != 0) {
        func_80091F74(arg0, 3);
    } else {
        func_80091F74(arg0, 2);
    }
}

void func_80091F30(void *arg0) {
    s32 func_80091FE4(void);
    if (*((Obj1E6B700_arg0 *)arg0)->unk4C == 2 && func_80091FE4() != 0) {
        func_80091F74(arg0, 3);
    }
}

int func_80091F74(void *arg0, s32 arg1) {
    void func_800A05DC(void *arg0);
    u8 func_800F8B70(void);
    void func_800F9104(s32);
    s32 func_80101238(s32, s32);

    if (arg1 == 3) {
        if (func_800F8B70() == 0) {
            func_800F9104(1);
            if (func_80101238(0x96, ((Obj1E6B700_arg0 *)arg0)->unk184) == 0) {
                func_800A05DC(arg0);
            }
            goto store_state;
        }
    } else {
store_state:
        *((Obj1E6B700_arg0 *)arg0)->unk4C = arg1;
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

s32 func_80091FE4(void) {
    s32 func_800DB9B0();
    return func_800DB9B0() == 0;
}

#include "common.h"

u32 gspropctrl_entrypoint_0(u8 *arg0) {
    return arg0[10];
}                   typedef struct { s16 unk0; s16 unk2; s16 unk4; u16 unk6; u32 unk8; u32 unkC; u32 unk10; } Objpropctrl_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objpropctrl_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

u32 gspropctrl_entrypoint_1(void *arg0, void *arg1) {
    (((Objpropctrl_arg1 *)arg1)->unk0) = (s32) (((Objpropctrl_arg0 *)arg0)->unk0);
    (((Objpropctrl_arg1 *)arg1)->unk4) = (s32) (((Objpropctrl_arg0 *)arg0)->unk2);
    (((Objpropctrl_arg1 *)arg1)->unk8) = (s32) (((Objpropctrl_arg0 *)arg0)->unk4);
    return (u32) (((Objpropctrl_arg0 *)arg0)->unk6) >> 7;
}

u32 gspropctrl_entrypoint_2(void *arg0) {
    return (u32) ((*(s32 *)((s8 *)(arg0) + (4))) << 0x19) >> 0x1A;
}

s32 gspropctrl_entrypoint_3(s32 *arg0) {
    return arg0[3];
}

u32 gspropctrl_entrypoint_4(u16 *arg0) {
    return arg0[4];
}

void gspropctrl_entrypoint_5(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

s32 gspropctrl_entrypoint_6(void *arg0) {
    return ((*(u32 *)((u8 *)arg0 + 16) & 7) << 2) +
        ((*(u32 *)((u8 *)arg0 + 8) << 19) >> 30);
}

s32 gspropctrl_entrypoint_7(s32 arg0) {
    extern s16 D_80800140_gspropctrl[];
    return ((s16 *)&D_80800140_gspropctrl)[arg0];
}

u32 gspropctrl_entrypoint_8(u8 *arg0) {
    return ((u32)*(u16 *)(arg0 + 6)) >> 7;
}

void gspropctrl_entrypoint_9(void *arg0, void *arg1) {
    (((Objpropctrl_arg1 *)arg1)->unk0) = (s32) (((Prop *)arg0)->position[0]);
    (((Objpropctrl_arg1 *)arg1)->unk4) = (s32) (((Prop *)arg0)->position[1]);
    (((Objpropctrl_arg1 *)arg1)->unk8) = (s32) (((Prop *)arg0)->position[2]);
}

void gspropctrl_entrypoint_10(void *arg0, void *arg1) {
    (((Prop *)arg1)->position[0]) = (s16) (((Prop *)arg0)->position[0]);
    (((Prop *)arg1)->position[1]) = (s16) (((Prop *)arg0)->position[1]);
    (((Prop *)arg1)->position[2]) = (s16) (((Prop *)arg0)->position[2]);
}

void gspropctrl_entrypoint_11(void *arg0, void *arg1) {
    (((Vec3f *)arg1)->pos.x) = (f32) (((Prop *)arg0)->position[0]);
    (((Vec3f *)arg1)->pos.y) = (f32) (((Prop *)arg0)->position[1]);
    (((Vec3f *)arg1)->pos.z) = (f32) (((Prop *)arg0)->position[2]);
}

u32 gspropctrl_entrypoint_12(void *arg0) {
    return (u32) (((Objpropctrl_arg0 *)arg0)->unkC) >> 0x17;
}

s32 gspropctrl_entrypoint_13(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0xC))) & 0x7FFFFF;
}
/* data_to_c.py: from asm/data/overlays/gs/propctrl.data.s */
s16 D_80800140_gspropctrl [32] BT_DATA(4, overlays_gs_propctrl, 0x0) = { 0, 50, 100, 200, 350, 500, 650, 800, 950, 1100, 1400, 1700, 2000, 2300, 2600, 2900, 3200, 3500, 3800, 4100, 4400, 4700, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500 };

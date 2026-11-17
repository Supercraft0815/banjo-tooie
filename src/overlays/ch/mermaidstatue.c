#include "common.h"

OSThread *chmermaidstatue_entrypoint_0(void)
{
    extern ActorData D_80800354_chmermaidstatue[];

    return (OSThread *) D_80800354_chmermaidstatue;
}

OSThread *chmermaidstatue_entrypoint_1(void)
{
    extern ActorData D_8080039C_chmermaidstatue[];

    return (OSThread *) D_8080039C_chmermaidstatue;
}                 typedef struct { u8 pad0[0x30]; s32 unk30; u8 pad34[0x42]; u16 unk76; } Objmermaidstatue_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800018_chmermaidstatue(void *arg0) {
    s32 _subaddiesect_entrypoint_1();
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 func_800DA298(s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    void func_80101FDC(Actor *actor,u32 state);
    void func_80109EEC(s16 *arg0, s32 arg1);
    void func_8010A570(Actor *arg0);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1();
    (((Objmermaidstatue_arg0 *)arg0)->unk30) = temp_v0;
    _subaddiesect_entrypoint_2(arg0, temp_v0, 0);
    func_800DA7A8(0x6B1, 0, 3);
    func_80109EEC(arg0, 0x40);
    if (func_800DA298(0x18D) != 0) {
        func_8010A570(arg0);
        func_80101FDC(arg0, 2);
    }
}

void func_80800094_chmermaidstatue(s32 arg0) 
{
}
/* extern */

void func_8080009C_chmermaidstatue(void *arg0, BtIntPtr arg1) {
    void func_800DF744(s32 index,s32 value);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, ((u32) (((Objmermaidstatue_arg0 *)arg0)->unk76) >> 7) - 0x31);
    func_80101870(arg0, arg1);
}

s32 func_808000E0_chmermaidstatue(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800BF744(s32, s32);
    s32 func_80800150_chmermaidstatue(void);
    void func_808001B0_chmermaidstatue(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            func_808001B0_chmermaidstatue(arg0);
            break;
        case 0x95:
            func_800BF744(1, func_80800150_chmermaidstatue() + 1);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

s32 func_80800150_chmermaidstatue(void) {
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_800DC128(s32, s32);
    s32 temp_v0;

    if (func_800DA298(0x6AE) == 0) {
        temp_v0 = func_800DC128(0, 3);
        func_800DA7A8(0x6AF, temp_v0, 2);
        func_800DA544(0x6AE);
        return temp_v0;
    }
    return func_800DA564(0x6AF, 2);
}

void func_808001B0_chmermaidstatue(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    void func_800FC660(u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80800150_chmermaidstatue(void);
    extern s16 D_80800330_chmermaidstatue[][6];
    s32 statue;
    s32 row;
    s32 count;

    statue = arg0->unk74_7 - 0x32;
    count = func_800DA564(0x6B1, 3);
    if (count != 6) {
        row = func_80800150_chmermaidstatue();
        if (statue == D_80800330_chmermaidstatue[row][count]) {
            count++;
            func_800DA7A8(0x6B1, count, 3);
            if (count == 6) {
                if (func_800DA298(0x18D) == 0) {
                    func_800FC660(0x10);
                    _capod_entrypoint_13(arg0->unk0, NULL, 0x1E, 0x10);
                    func_80101180(0x3C1, 7, 0);
                    func_800DA544(0x18D);
                }
            } else {
                func_800FC660(0xE);
            }
        } else {
            func_800DA7A8(0x6B1, 0, 3);
            func_800FC660(0xF);
        }
    }
}

void func_808002C8_chmermaidstatue(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_6(Actor*, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 400.0f, 1, 0x18D) != 0) {
        _chdoormake_entrypoint_8(arg0, 0xDU);
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_6(arg0, 0x40400000);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/mermaidstatue.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
void _chdoor_entrypoint_0();
void func_80101870(Actor* arg0, void* arg1);
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
s16 D_80800330_chmermaidstatue [3] [ 6 ] BT_DATA(4, overlays_ch_mermaidstatue, 0x0) = { { 0, 3, 0, 0, 1, 2 }, { 1, 0, 2, 0, 3, 3 }, { 2, 1, 3, 0, 2, 1 } };
ActorData D_80800354_chmermaidstatue [1] BT_DATA(4, overlays_ch_mermaidstatue, 0x24) = { { 804, 960, 1769, 1, 0, (void (*)(struct Actor *))func_80800094_chmermaidstatue, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8080009C_chmermaidstatue, 98304000, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800018_chmermaidstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9296, (void (*)(struct Actor *, long, long))func_808000E0_chmermaidstatue, 0 } };
ActorData D_8080039C_chmermaidstatue [1] BT_DATA(4, overlays_ch_mermaidstatue, 0x6C) = { { 172, 961, 1791, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808002C8_chmermaidstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };

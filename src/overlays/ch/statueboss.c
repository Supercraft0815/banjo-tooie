#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chstatueboss_entrypoint_0(void)
{
    extern u8 D_80802748_chstatueboss[];

    return (OSThread *) D_80802748_chstatueboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080000C_chstatueboss.s")

void func_80800298_chstatueboss(Actor *arg0) {
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    extern void _chbaddiesetup_entrypoint_10(void);
    s32 _chexploder_entrypoint_5(Actor *, s32, f32 *, s32, f32, s32);
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_80018820(s32, f32, f32);
    s32 func_800CEAD0(s32);
    s32 func_800D0B68(u32, u32);
    void func_800D1254(u32, u32, f32 *);
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800E15CC(s32, f32, f32);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    u32 func_800FDC28(u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80102320(Actor *, f32, f32);
    void func_80108B04(Actor *, u32);
    void func_80800DA8_chstatueboss();
    void func_808011B4_chstatueboss(Actor *);
    void func_8080124C_chstatueboss(Actor *);
    void func_80801448_chstatueboss(Actor *);
    void func_80801804_chstatueboss(Actor *, s32);
    void func_80801A6C_chstatueboss(Actor *, f32);
    void func_80801AC4_chstatueboss(s32, s32);
    void func_80801AF0_chstatueboss(Actor *);
    void func_80801C78_chstatueboss(Actor *);
    void func_8080232C_chstatueboss(Actor *);
    extern u32 D_80802790_chstatueboss;
    extern u32 D_808027AC_chstatueboss;
    struct StatueBossData {
        u8 pad0[0x80];
        s32 effect;
        s16 index;
        s16 selected;
        s16 hits;
        s16 total;
        u8 pad8C[0x142];
        u8 ready;
        u8 active;
        u8 dialog;
    } *data;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 sp44[3];
    f32 sp38[3];

    data = func_80100094(arg0, 0U);
    sp58 = 0;
    sp54 = 0;
    sp50 = 0;
    _sudeflect_entrypoint_1(arg0->position, 400.0f, -100.0f, 550.0f, 2);
    if ((s32)arg0->unk70_10 >= 7) {
        func_800D2498(0xF3, 0x10 - data->total, 0);
    }
    if (!func_800D0B68(1, 1) && _subaddieskeleton_entrypoint_2(arg0->unk0, 10, sp44)) {
        if (sp44[1] < arg0->position[1]) {
            sp44[1] = arg0->position[1];
        }
        func_800D1254(1, 1, sp44);
    }
    switch (arg0->unk70_10) {
    case 1:
        if (!func_800DA298(0x6AD) && !data->dialog) {
            data->dialog = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xF43, 0x44, arg0->position, 0xB2);
        }
        if (data->active && data->ready) {
            func_800F82D4(func_800F54E4(), 0);
            func_80800DA8_chstatueboss(arg0, 2);
        }
        break;
    case 3:
        if (func_80101E14(arg0, 0.1f)) {
            func_80801C78_chstatueboss(arg0);
        }
        func_80801A6C_chstatueboss(arg0, 0.35f);
        if (func_80101DDC(arg0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xF33, 6, arg0->position, 0xB2);
            func_80800DA8_chstatueboss(arg0, 4);
        }
        break;
    case 5:
        if (_subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802790_chstatueboss, &D_808027AC_chstatueboss)) {
            func_800E15CC(0, 10.0f, 0.8f);
            func_80018820(0, 2.0f, 0.25f);
        }
        sp50 = func_80102320(arg0, 0.6f, 0.99f);
        func_80801AC4_chstatueboss((s32)arg0, sp50);
        if (func_80101DDC(arg0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xF34, 6, arg0->position, 0xB2);
            func_80800DA8_chstatueboss(arg0, 6);
        }
        break;
    case 4:
    case 6:
    case 23:
        func_80801AF0_chstatueboss(arg0);
        break;
    case 7:
        if (_subaddieskeleton_entrypoint_0(arg0, 0x2D, sp38)) {
            func_800EF1B8(sp38, func_800F1DF4(sp38, arg0->position), 120.0f);
            _sudeflect_entrypoint_0(sp38, 0.0f, 250.0f, 2);
        }
        if (_subaddieskeleton_entrypoint_0(arg0, 0x2C, sp38)) {
            func_800EF1B8(sp38, func_800F1DF4(sp38, arg0->position), 120.0f);
            _sudeflect_entrypoint_0(sp38, 0.0f, 250.0f, 2);
        }
        sp54 = 1;
        sp58 = 1;
        break;
    case 8:
        func_80801A6C_chstatueboss(arg0, 0.65f);
        if (func_80101DDC(arg0)) {
            func_80800DA8_chstatueboss(arg0, 9);
        }
        break;
    case 9:
        func_80801AF0_chstatueboss(arg0);
        sp54 = 2;
        if (!_subaddiefind_entrypoint_2(0x112, 0)) {
            func_80801C78_chstatueboss(arg0);
            func_80800DA8_chstatueboss(arg0, 11);
        }
        break;
    case 11:
        sp54 = 1;
        sp58 = 1;
        break;
    case 12:
        func_80801A6C_chstatueboss(arg0, 0.7f);
        if (func_80101DDC(arg0)) {
            func_80800DA8_chstatueboss(arg0, 13);
        }
        break;
    case 13:
        func_80801AF0_chstatueboss(arg0);
        sp54 = 2;
        if (!_subaddiefind_entrypoint_2(0x112, 0)) {
            func_80801C78_chstatueboss(arg0);
            func_80800DA8_chstatueboss(arg0, 15);
        }
        break;
    case 15:
        sp54 = 1;
        sp58 = 1;
        break;
    case 16:
        func_80801A6C_chstatueboss(arg0, 0.7f);
        if (func_80101DDC(arg0)) {
            func_80800DA8_chstatueboss(arg0, 17);
        }
        break;
    case 17:
        func_80801AF0_chstatueboss(arg0);
        sp54 = 2;
        if (!_subaddiefind_entrypoint_2(0x112, 0)) {
            func_80801C78_chstatueboss(arg0);
            func_80800DA8_chstatueboss(arg0, 19);
        }
        break;
    case 19:
        sp54 = 1;
        sp58 = 1;
        break;
    case 20:
        func_80801A6C_chstatueboss(arg0, 0.85f);
        if (func_80101DDC(arg0)) {
            func_80800DA8_chstatueboss(arg0, 21);
        }
        break;
    case 21:
        func_8080232C_chstatueboss(arg0);
        func_80801AF0_chstatueboss(arg0);
        sp54 = 2;
        if (!_subaddiefind_entrypoint_2(0x112, 0)) {
            func_80800DA8_chstatueboss(arg0, 23);
        }
        break;
    case 24:
        func_8080232C_chstatueboss(arg0);
        if (func_800CEAD0(0)) {
            func_800E15CC(0, 30.0f, 0.8f);
            func_80018820(0, 3.0f, 0.25f);
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, *(s32 *)&arg0->position[0], *(s32 *)&arg0->position[1], *(s32 *)&arg0->position[2], *(s32 *)&arg0->rotation[1]);
            _chexploder_entrypoint_5(arg0, 0x7CC, arg0->position, data->effect, arg0->scale, 0);
            func_80108B04(arg0, 2);
            func_800DA544(0x36F);
            func_800FDC28(0);
        }
        break;
    case 25:
        if (func_800D9078(&arg0->unk58)) {
            _gcfrontend_entrypoint_10();
        }
        break;
    case 10:
    case 14:
    case 18:
    case 22:
        sp54 = 2;
        break;
    case 26:
        func_80801AF0_chstatueboss(arg0);
        break;
    }
    switch (sp54) {
    case 1:
        func_808011B4_chstatueboss(arg0);
        break;
    case 2:
        func_8080124C_chstatueboss(arg0);
        break;
    }
    if (!sp50) {
        sp50 = sp54 == 1;
    }
    func_80801AC4_chstatueboss((s32)arg0, sp50);
    func_80801804_chstatueboss(arg0, sp58);
    func_80801448_chstatueboss(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800934_chstatueboss.s")

void func_80800B74_chstatueboss(Actor *arg0, s32 arg1)
{
  void func_800DF744(s32, s32);
  s32 func_80101870(s32, s32);
  s32 var_s0;
  u8 *var_s1;
  var_s1 = 1 + ((u8 *) func_80100094(arg0, 0U));
  var_s0 = 1;
  var_s1 += 0;
  do
  {
    func_800DF744(var_s0, *var_s1);
    var_s0 += 1;
    var_s1 += 1;
  }
  while (var_s0 != 0x16);
  func_80101870((s32) arg0, arg1);
}

void func_80800BE0_chstatueboss(Actor *arg0) {
    void func_80801640_chstatueboss(Actor *, s32, s32);
    extern s16 D_808025C0_chstatueboss[][6];
    struct StatueData {
        u8 flags[0x18];
        f32 timers[22];
        f32 angles[5];
        s16 index;
        u8 pad86[0x1A];
        struct { s32 state; f32 x; f32 y; } positions[6];
    } *data;
    s32 i;
    s32 j;
    s32 offset;

    data = func_80100094(arg0, 0U);
    for (i = 0; i != 4; i++) {
        func_80801640_chstatueboss(arg0, i, 0);
    }
    func_80801640_chstatueboss(arg0, 4, 1);
    for (j = 0; j < 4; j++) {
        for (i = 0; D_808025C0_chstatueboss[j][i] != -1; i++) {
            offset = D_808025C0_chstatueboss[j][i];
            data->flags[offset] = 2;
        }
    }
    for (i = 0; i < 5; i++) {
        data->angles[i] = 0.0f;
    }
    for (i = 0; i < 6; i++) {
        data->positions[i].state = 0;
        data->positions[i].x = 0.0f;
        data->positions[i].y = 0.0f;
    }
    for (i = 1; i < 22; i++) {
        data->timers[i] = 0.0f;
    }
    data->index = 0;
}

void func_80800D30_chstatueboss(Actor *arg0) {
    extern s16 D_808025C0_chstatueboss[][6];
    s32 index;
    s32 i;
    s32 offset;
    u8 *data;

    data = func_80100094(arg0, 0U);
    index = *(s16 *)(data + 0x84);
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
        offset = D_808025C0_chstatueboss[index][i];
        data[offset] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800DA8_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_808010A0_chstatueboss.s")

s32 func_808011A0_chstatueboss(s32 arg0) {
    extern s16 D_808027D4_chstatueboss[];
    return ((s16 *)&D_808027D4_chstatueboss)[arg0];
}

void func_808011B4_chstatueboss(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    extern f32 D_80802630_chstatueboss[];
    extern s16 D_80802644_chstatueboss[];
    typedef struct {
        u8 pad[0x70];
        f32 angles[5];
        s16 index;
    } StatueData;
    int temp_v1;
    StatueData *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    for (temp_v1 = temp_v0->index; temp_v1 < 5; temp_v1++) {
        temp_v0->angles[temp_v1] += func_800D8FF8() * D_80802630_chstatueboss[temp_v1];
        temp_v0->angles[temp_v1] = func_800136E4(temp_v0->angles[temp_v1]);
    }
}

void func_8080124C_chstatueboss(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F1F38(f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    f32 mlAbsF(f32);
    extern f32 D_80802630_chstatueboss[];
    typedef struct {
        u8 pad[0x70];
        f32 angles[5];
        s16 index;
    } StatueData;
    StatueData *data;
    s32 i;
    f32 delta;

    data = func_80100094(arg0, 0U);
    for (i = data->index; i < 5; i++) {
        if (!func_800F20BC(data->angles[i], 0.0f, 5.0f)) {
            delta = func_800D8FF8();
            data->angles[i] = func_800F1F38(data->angles[i], 0.0f, mlAbsF(D_80802630_chstatueboss[i]) * delta);
            data->angles[i] = func_800136E4(data->angles[i]);
        }
    }
}

void func_80801320_chstatueboss(Actor *arg0) {
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_800E0B8C(void *, u8, f32, f32, f32, f32);
    void func_800E0C20(void *, u8, f32, f32, f32, f32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    extern u8 D_8080265C_chstatueboss[][2];
    struct StatueData {
        u8 pad[0x70];
        f32 angles[5];
        u8 pad84[0x24];
        f32 positions[6][3];
    };
    union { struct StatueData *ptr; f64 align; } data;
    s32 handle;
    s32 i;

    handle = func_8010262C(arg0->unk0, 0xC);
    if (handle != 0) {
        data.ptr = func_80100094(arg0, 0U);
        for (i = 0; i < 5; i++) {
            func_800E0AFC(handle, func_808011A0_chstatueboss(i), 1.0f, 0.0f, data.ptr->angles[i], 0.0f);
        }
        func_800E0B8C(handle, 0x52, 1.0f, 1.0f, 2.0f, 1.0f);
        for (i = 0; i < 6; i++) {
            func_800E0C20(handle, D_8080265C_chstatueboss[i][1], 1.0f, 0.0f, data.ptr->positions[i][0], 0.0f);
        }
    }
}

void func_80801448_chstatueboss(Actor *arg0) {
    s32 func_800D9078(f32 *);
    extern s16 D_808025C0_chstatueboss[][6];
    struct StatueData {
        u8 flags[0x18];
        f32 timers[27];
        s16 index;
    } *data;
    s32 index;
    s32 i;
    s32 offset;
    u8 *flag;

    data = func_80100094(arg0, 0U);
    index = data->index;
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
            offset = D_808025C0_chstatueboss[index][i];
            flag = &data->flags[offset];
            if (*flag == 2 && func_800D9078(&data->timers[offset]) != 0) {
                *flag = 1;
            }
    }
}

void func_80801518_chstatueboss(Actor *arg0, Unk80132ED0 *arg1) {
    s32 func_800DA298(s32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    void func_800FC660(u32);
    void func_80800DA8_chstatueboss(Actor *, s32, s32);
    extern s16 D_808025C0_chstatueboss[][6];
    extern s16 D_80802644_chstatueboss[];
    extern s16 D_808027E0_chstatueboss[];
    struct StatueData {
        u8 flags[0x18];
        f32 timers[27];
        s16 index;
        s16 selected;
        s16 hits;
        s16 total;
        u8 pad8C[0x5C];
        f32 position[3];
    } *data;
    s32 i;
    s32 selected;
    s32 index;
    s16 limit;

    data = func_80100094(arg0, 0U);
    index = data->index;
    selected = data->selected;
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
            if (selected == D_808025C0_chstatueboss[index][i]) {
                data->flags[selected] = 2;
                data->timers[selected] = 2.5f;
                func_800FC660(0xE);
                data->total++;
                func_800EC398(arg1, data->position);
                data->hits++;
                if (func_800DA298(0x681) == 0) {
                    limit = D_80802644_chstatueboss[index];
                } else {
                    limit = 100;
                }
                if (limit == data->hits) {
                    func_80800DA8_chstatueboss(arg0, D_808027E0_chstatueboss[index], index);
                }
                break;
            }
    }
}

void func_80801640_chstatueboss(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    extern s16 D_80802624_chstatueboss[];
    s8 *data;
    s32 offset;

    data = func_80100094(arg0, 0U);
    offset = D_80802624_chstatueboss[arg1];
    data[offset] = (s8)arg2;
}

OSThread *chstatueboss_entrypoint_1(void)
{
    extern u8 D_808027E8_chstatueboss[];

    return (OSThread *) D_808027E8_chstatueboss;
}

s32 func_80801694_chstatueboss(Actor *arg0) {
    extern s16 D_808025C0_chstatueboss[][6];
    struct StatueBossData {
        u8 pad[0x84];
        s16 index;
    } *data;
    s32 i;
    s16 index;
    s32 offset;
    s32 flags;

    data = func_80100094(arg0, 0U);
    index = data->index;
    flags = 0;
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
        offset = D_808025C0_chstatueboss[index][i];
        if (((u8 *)data)[offset] == 1) {
            flags |= 1 << (offset + 0x1F);
        }
    }
    return -1 ^ flags;
}

/* extern */

s16 func_80801724_chstatueboss(u8 *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    s32 pad;
    void *func_800AE080(s16);
    s32 func_800AE0E8(s16);
    s16 func_800B1F8C(u8 *, f32 *, f32 *, f32, s32, void *, s32, f32, s32, s32);
    u8 *func_800B2824(u8 *);
    u8 *func_80103AA0(u8 *);
    Actor *func_80106790(Unk80132ED0 *);
    struct Resource {
        u8 pad[0x10];
        s16 handle;
    };
    struct StatueBossData {
        u8 pad[0x86];
        s16 handle;
    } *sp48;
    u8 *sp44;
    s32 pad2;
    u8 *sp3C;
    Actor *temp_v0;
    u8 *temp_v0_2;

    temp_v0 = func_80106790((Unk80132ED0 *)arg0);
    sp48 = func_80100094(temp_v0, 0U);
    temp_v0_2 = func_80103AA0(arg0);
    sp44 = temp_v0_2;
    if ((temp_v0_2 == 0) || (func_800AE0E8(((struct Resource *)arg0)->handle) == 0)) {
        return 0;
    }
    arg4 = func_80801694_chstatueboss(temp_v0);
    sp3C = func_800B2824(sp44);
    sp48->handle = func_800B1F8C(sp3C, temp_v0->position, temp_v0->rotation, temp_v0->scale, 0, func_800AE080(((struct Resource *)arg0)->handle), arg1, arg2, arg3, arg4);
    return sp48->handle;
}

void func_80801804_chstatueboss(Actor *arg0, s32 arg1) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_8008FE68(f32 *);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    int func_800F20BC(f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    void func_80108B04(Actor *, u32);
    f32 func_8010CD28(Actor *);
    s32 func_8010D248(void);
    struct Part { s32 state; f32 timer; f32 offset; };
    struct StatueBossData {
        u8 pad[0x84];
        s16 index;
        u8 pad86[0xA];
        f32 position[3];
        f32 distance;
        struct Part parts[6];
    } *data;
    extern s16 D_808025FC_chstatueboss[][4];
    s32 boneIndex;
    s32 index;
    f32 position[3];
    f32 angle;
    f32 player[3];
    int i;
    s32 done;
    struct StatueBossData *part;

    data = func_80100094(arg0, 0U);
    index = data->index;
    if (func_800F6438(func_800F54E4()) != 0) {
        angle = func_8010CD28(arg0);
        i = 0;
        do {
            switch (data->parts[i].state) {
                case 1:
                    done = func_800D90A4(&data->parts[i].timer);
                    data->parts[i].offset = func_800F10B4(data->parts[i].timer, 0.0f, 0.6f, -2.0f, 0.0f);
                    if (done) {
                        data->parts[i].state = 2;
                        data->parts[i].timer = 1.2f;
                    }
                    break;
                case 2:
                    done = func_800D90A4(&data->parts[i].timer);
                    data->parts[i].offset = func_800F10B4(data->parts[i].timer, 0.0f, 1.2f, 0.0f, -2.0f);
                    if (done) {
                        data->parts[i].state = 0;
                    }
                    break;
            }
        } while (++i < 6);
        if (arg1 && func_8010D248()) {
            func_8008FE68(player);
            for (i = 0; D_808025FC_chstatueboss[index][i] != -1; i++) {
                boneIndex = D_808025FC_chstatueboss[index][i] - 4;
                part = (struct StatueBossData *)((u8 *)data + boneIndex * 12);
                func_800D9078(&part->parts[0].timer);
                if (part->parts[0].state != 0) continue;
                if (_subaddieskeleton_entrypoint_2(arg0->unk0, D_808025FC_chstatueboss[index][i], position) &&
                    func_800F20BC(func_800F1DF4(arg0->position, position), angle, 25.0f)) {
                    func_80108B04(arg0, 0);
                    func_800EE7F8(data->position, position);
                    data->distance = func_800F1DF4(position, player);
                    part->parts[0].timer = 0.6f;
                    part->parts[0].state = 1;
                }
            }
        }
    }
}

void func_80801A6C_chstatueboss(Actor *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80802790_chstatueboss;
    if (_subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 4), &D_80802790_chstatueboss, arg1) != 0) {
        func_800E15CC(0, 20.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
    }
}

void func_80801AC4_chstatueboss(s32 arg0, s32 arg1) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808027F8_chstatueboss;
    _subaddieaudioloop_entrypoint_4((Actor *) arg0, (f32 *) ((u8 *) arg0 + 4), arg1, &D_808027F8_chstatueboss);
}

void func_80801AF0_chstatueboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    struct Times { f32 values[6]; };
    struct Levels { f32 values[5]; };
    extern struct Times D_80802804_chstatueboss;
    extern struct Levels D_8080281C_chstatueboss;
    extern struct Levels D_80802830_chstatueboss;
    extern s32 D_80802844_chstatueboss;
    struct Times times;
    struct Levels pitches;
    struct Levels volumes;
    s32 i;

    times = D_80802804_chstatueboss;
    pitches = D_8080281C_chstatueboss;
    volumes = D_80802830_chstatueboss;
    for (i = 0; times.values[i] != -1.0f; i++) {
        if (func_80101E14(arg0, times.values[i])) {
            func_800C4B64(pitches.values[i] + func_800DC178(-0.05f, 0.05f));
            func_800C4B70((s32) volumes.values[i]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802844_chstatueboss);
            return;
        }
    }
}

void func_80801C78_chstatueboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s32 D_80802850_chstatueboss;
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802850_chstatueboss);
}

void func_80801CA0_chstatueboss(Actor *arg0) {
    void _chexploder_entrypoint_12(Actor *, s32);
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    void _chexploder_entrypoint_15(Actor *, u32, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_8080285C_chstatueboss;
    extern s32 D_80802894_chstatueboss;
    s32 offset;
    struct StatueBossData {
        u8 pad[0x8C];
        Unk80132ED0 *marker;
    } *sp38;
    Actor *sp34;

    offset = 0;
    sp38 = func_80100094(arg0, 0);
    sp34 = func_80106790(func_80101080());
    _chexploder_entrypoint_12(sp34, 40);
    _chexploder_entrypoint_6(sp34, 1200.0f, 1600.0f);
    _chexploder_entrypoint_15(sp34, 1, 1.25f);
    switch (arg0->unk70_10) {
        case 8:
            offset = 80;
            func_80801640_chstatueboss(arg0, 0, 0);
            break;
        case 12:
            offset = 80;
            func_80801640_chstatueboss(arg0, 1, 0);
            break;
        case 16:
            offset = 80;
            func_80801640_chstatueboss(arg0, 2, 0);
            break;
        case 20:
            offset = 80;
            func_80801640_chstatueboss(arg0, 3, 0);
            break;
        case 24:
            offset = 80;
            func_80801640_chstatueboss(arg0, 4, 0);
            break;
    }
    _subaddieaudioquick_entrypoint_2(sp34, sp34->position, &D_80802894_chstatueboss);
    func_800BBCB8(sp34->position, sp34->position, 1.0f, 6, &D_8080285C_chstatueboss);
    sp34 = func_80106790(sp38->marker);
    sp34->position[1] -= arg0->scale * (f32)offset;
}

void func_80801E24_chstatueboss(Actor *arg0, u32 arg1, u32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        arg2 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg0->unk0, NULL, arg1, arg2);
    (*(s8 *)((s8 *)(sp1C) + (0x1CD))) = 1;
}

void func_80801E90_chstatueboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x1CD))) = 0;
    }
}

void func_80801ECC_chstatueboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x84];
        s16 index;
        u8 pad86[0xA];
        f32 position[3];
        f32 yaw;
    } StatueBossData;
    s32 func_800DA298(s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern f32 D_8080264C_chstatueboss[];
    extern u8 D_80802668_chstatueboss[];
    StatueBossData *sp1C;
    Actor *sp18;
    StatueBossData *temp_v0;
    Actor *temp_v0_2;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    temp_v0_2 = func_80108528(0x448, temp_v0->position, (s32) temp_v0->yaw, &arg0);
    temp_v0_2->rotation[1] = sp1C->yaw;
    sp18 = temp_v0_2;
    if (func_800DA298(0x682) == 0) {
        *(f32 *)&sp18->actorData[3] = D_8080264C_chstatueboss[sp1C->index];
    } else {
        *(f32 *)&sp18->actorData[3] = 10000.0f;
    }
    _subaddieaudioquick_entrypoint_2(arg0, sp1C->position, D_80802668_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801F74_chstatueboss.s")

void func_808020EC_chstatueboss(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    Actor* func_801084B0(s32, Actor**);
    u8 *sp1C;
    Actor *sp18;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x44F, &arg0);
    sp18 = temp_v0;
    func_80102FDC(temp_v0, arg0->scale);
    (*(Unk80132ED0 **)((s8 *)(sp1C) + (0x8C))) = (Unk80132ED0 *) sp18->unk0;
}

void func_80802144_chstatueboss(Actor *arg0) {
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    void _sucoaster_entrypoint_4(Actor *);
    void func_80100120(Actor *);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    typedef struct {
        f32 position[3];
        f32 unkC;
        f32 yaw;
        f32 unk14;
    } StatuePart;
    typedef struct {
        u8 pad[0x10C];
        StatuePart parts[4];
    } StatueData;
    s32 i;
    s32 count;
    StatueData *data;
    Actor *actor;

    data = func_80100094(arg0, 0U);
    count = 1;
    switch (arg0->unk70_10) {
        case 13: count = 2; break;
        case 17: count = 3; break;
        case 21: count = 4; break;
    }
    for (i = 0; i < count; i++) {
            actor = func_80108528(0x112, data->parts[i].position, (s32)data->parts[i].yaw, &arg0);
            _chappearfx_entrypoint_1(actor, 0x2A, 0, 0.6f);
            func_80100120(actor);
            _sucoaster_entrypoint_4(actor);
            actor->unk74_17 = 0;
    }
}

/* extern */

void func_80802268_chstatueboss(Actor *arg0) {
    void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
    Actor *func_80108474(u32, f32 *, s32);
    typedef struct {
        f32 position[3];
        f32 unkC;
        f32 yaw;
        f32 unk14;
    } StatuePart;
    typedef struct {
        u8 pad[0x16C];
        StatuePart parts[4];
        u8 flag;
    } StatueData;
    s32 offset;
    StatueData *data;
    Actor *actor;

    data = func_80100094(arg0, 0U);
    offset = 0;
    do {
        actor = func_80108474(0x1C8, ((StatueData *)((u8 *)data + offset))->parts[0].position,
                             (s32)((StatueData *)((u8 *)data + offset))->parts[0].yaw);
        actor->unk74_7 = 0x33;
        if (data->flag == 0) {
            _chappearfx_entrypoint_2(actor, 0x20, 0, 1.0f);
        }
        offset += 0x18;
    } while (offset != 0x60);
}

void func_8080232C_chstatueboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 position[3];

    if (_subaddieskeleton_entrypoint_0(arg0, 0x1E, position)) {
        func_800EF1B8(position, func_800F1DF4(arg0->position, position), 80.0f);
        position[1] = arg0->position[1];
        _sudeflect_entrypoint_1(position, 300.0f, -50.0f, 250.0f, 2);
    }
    if (_subaddieskeleton_entrypoint_0(arg0, 0x10, position)) {
        func_800EF1B8(position, func_800F1DF4(arg0->position, position), 80.0f);
        position[1] = arg0->position[1];
        _sudeflect_entrypoint_1(position, 300.0f, -50.0f, 250.0f, 2);
    }
}

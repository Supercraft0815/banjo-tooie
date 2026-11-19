#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif

extern u16 D_808045A4_chflysaucer[];
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
s32 func_8080185C_chflysaucer();
void func_808024E0_chflysaucer(Actor *arg0);
void func_80802ED8_chflysaucer(Actor *arg0);
void func_80803150_chflysaucer(Actor *arg0);
void func_808035C4_chflysaucer();
void func_80803B60_chflysaucer(Actor *arg0);
void func_80803BE8_chflysaucer(s32 arg0);
void func_80803C3C_chflysaucer(Actor *arg0);
s32 func_80803D30_chflysaucer(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80804260_chflysaucer[] = {
    0x001305E7, 0x000A00B3, 0x00164268, 0x000104E2,
    0x09C40000,
};

u32 D_80804274_chflysaucer[] = {
    0xBF800000, 0x3F63D70A, 0x3F68F5C3, 0x3F7851EC,
    0x3F6E147B, 0x3F733333, 0xBF800000, 0xBF800000,
};

u32 D_80804294_chflysaucer[] = {
    0x04467FBC, 0x3F800000, 0x04397FBC, 0x3F800000,
    0x04367FBC, 0x3F800000, 0x043A7FBC, 0x3F800000,
    0x043B7FBC, 0x3F800000, 0x043C7FBC, 0x3F800000,
    0x043D7FBC, 0x3F800000, 0x04207FBC, 0x3F800000,
};

u32 D_808042D4_chflysaucer[] = {
    0x00000201, 0x00000000, 0x33330100, 0x40000000,
    0x51EB0100, 0x40000000, 0x61470100, 0x40000000,
    0x73320100, 0x40000000, 0x851E0100, 0x40000000,
    0x9E340100, 0x40000000, 0xAB840100, 0x40000000,
    0xB5C10100, 0x400CCCCD, 0xC51D0100, 0x40200000,
};

u32 D_80804324_chflysaucer[] = {
    0x0CCC0100, 0x4079999A, 0x19990100, 0x40400000,
    0x33330100, 0x400CCCCD, 0x3FFF0100, 0x400CCCCD,
    0x46660100, 0x4019999A, 0x4CCC0100, 0x40000000,
    0x53320100, 0x40000000, 0x59990100, 0x40000000,
    0x5FFF0100, 0x40000000, 0x66660100, 0x40000000,
    0x73320100, 0x40880000, 0x7FFF0100, 0x40800000,
    0x97090100, 0x3F800000, 0x99990301, 0x00000000,
    0x9EB70100, 0x3F800000, 0xB3320100, 0x40000000,
    0xBFFF0100, 0x40533333, 0xCCCC0100, 0x4039999A,
    0xD47A0100, 0x4019999A,
};

u32 D_808043BC_chflysaucer[] = {
    0x06660100, 0x40000000, 0x11260100, 0x40000000,
    0x1FFF0100, 0x40000000, 0x26660100, 0x40000000,
    0x2A3D0100, 0x40200000, 0x2E140100, 0x40266666,
    0x31EB0100, 0x400CCCCD, 0x347A0100, 0x400CCCCD,
    0x39990100, 0x40266666, 0x3FFF0100, 0x40000000,
    0x57090701, 0x00000000, 0x59990400, 0x3FC00000,
    0x73320100, 0x3FB33333, 0x78510100, 0x3FD9999A,
    0x7D700100, 0x40000000, 0x828E0100, 0x4019999A,
    0x851E0100, 0x40200000, 0x8A3C0100, 0x40200000,
    0xAF5B0100, 0x3F99999A, 0xBD6F0100, 0x3F99999A,
    0xC8F40100, 0x3F99999A, 0xD8510101, 0x00000000,
    0xD9980100, 0x40000000,
};

u32 D_80804474_chflysaucer[] = {
    0x0CCC0100, 0x4059999A, 0x13330100, 0x4059999A,
    0x19990100, 0x40533333, 0x1FFF0100, 0x404CCCCD,
    0x26660100, 0x404CCCCD, 0x2CCC0100, 0x40333333,
    0x33330100, 0x40333333, 0x3FFF0100, 0x3FD9999A,
    0x4CCC0100, 0x3FD9999A, 0x59990100, 0x3FC00000,
    0x66660100, 0x3FC00000, 0x73320100, 0x3FC00000,
    0x7FFF0100, 0x3FC00000, 0x8CCC0100, 0x3FC00000,
    0x99990100, 0x3FC00000, 0xA6650100, 0x3FC00000,
    0xB3320100, 0x3FC00000, 0xBFFF0100, 0x3FC00000,
    0xCCCC0100, 0x400CCCCD, 0xD47A0100, 0x400CCCCD,
};

u32 D_80804514_chflysaucer[] = {
    0x0F5C0100, 0x40000000, 0x1EB80100, 0x3FE66666,
    0x28F50100, 0x3FE66666, 0x33330100, 0x3FC00000,
    0x3FFF0100, 0x3FE66666, 0x4CCC0100, 0x40000000,
    0x59990100, 0x3FCCCCCD, 0x70A30001, 0x00000000,
    0x73320400, 0x3FC00000, 0x8CCC0100, 0x3FC00000,
    0x99990100, 0x3FE66666, 0xA6650100, 0x3FE66666,
    0xB3320100, 0x3FE66666, 0xBFFF0100, 0x3FE66666,
    0xCCCC0100, 0x3FE66666, 0xD6440100, 0x3FF33333,
    0xDFFF0100, 0x400CCCCD, 0xF3320401, 0x00000000,
};

u16 D_808045A4_chflysaucer[] = {
    0x0000, 0x0000, 0x0000, 0x0000,
    0x4006, 0x6666, 0x0091, 0x0041,
    0x4082, 0x8F5C, 0x0092, 0x0042,
    0x3F54, 0x7AE1, 0x0093, 0x0041,
    0x3F54, 0x7AE1, 0x0093, 0x0001,
    0x3F54, 0x7AE1, 0x0093, 0x0001,
    0x4006, 0x6666, 0x0091, 0x0041,
    0x005B, 0x000F, 0x0008, 0x0014,
    0x004E, 0x0000,
};

u32 D_808045E8_chflysaucer[] = {
    0xFFFF0064, 0x0019006E, 0x001B006A, 0xFFFFFFFF,
};

u32 D_808045F8_chflysaucer[] = {
    0x42FA0000, 0x432F0000, 0x432F0000, 0x42480000,
};

u32 D_80804608_chflysaucer[] = {
    0x43480000, 0x437A0000, 0x437A0000, 0x00000000,
};

u32 D_80804618_chflysaucer[] = {
    0xC5E5B800, 0x44CE4000, 0xC5224000,
};

u32 D_80804624_chflysaucer[] = {
    0xFFFF0066, 0x001B006C, 0x001D0068, 0xFFFFFFFF,
};

u32 D_80804634_chflysaucer[] = {
    0x02060013, 0x04E00016, 0x27100001, 0x00C807D0,
    0x00000000,
};

u32 D_80804648_chflysaucer[] = {
    0x02060013, 0x06720016, 0x7530001D, 0x000100C8,
    0x07D00000,
};

u32 D_8080465C_chflysaucer[] = {
    0x3F4CCCCD, 0x3F400000, 0x3F59999A,
};

BtFnWord D_80804668_chflysaucer[] = {
    0x020202A2, 0x06900001, (BtFnWord)D_808045A4_chflysaucer, (BtFnWord)func_808024E0_chflysaucer,
    (BtFnWord)func_80105834, (BtFnWord)func_808035C4_chflysaucer, 0x09C40000, 0x4019999A,
    0x00000000, 0x00080024, (BtFnWord)func_80803150_chflysaucer, 0x00000000,
    0x00300000, (BtFnWord)func_80802ED8_chflysaucer, (BtFnWord)func_80107C2C, 0x84000002,
    (BtFnWord)func_8080185C_chflysaucer, 0x00000000,
};

u32 D_808046B0_chflysaucer[] = {
    0x00000002, 0x00000001, 0x00000000, 0x00000001,
    0x00000002,
};

u32 D_808046C4_chflysaucer[] = {
    0x00000050, 0x00000028, 0x00000000, 0xFFFFFFD8,
    0xFFFFFFB0, 0xFFFFFFFF,
};

u32 D_808046DC_chflysaucer[] = {
    0x00161200, 0x00150000, 0x00CC002B, 0x0073008C,
    0x0022004C, 0x00590026, 0x0033002D, 0x01900258,
    0x000E000A, 0x00140000,
};

u32 D_80804704_chflysaucer[] = {
    0x09E409E8, 0x09E00000,
};

BtFnWord D_8080470C_chflysaucer[] = {
    0x020402A4, 0x08250001, 0x00000000, (BtFnWord)func_80803C3C_chflysaucer,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (BtFnWord)func_80803BE8_chflysaucer, (BtFnWord)func_80108ED0,
    0x00000000, (BtFnWord)func_80803B60_chflysaucer, (BtFnWord)func_80107C2C, 0x00000000,
    (BtFnWord)func_80803D30_chflysaucer, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};

/* extern */

s32 func_80800000_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    sp1C[0x26] = func_800DA564(0xA34, 3);
    return sp1C[0x26];
}    typedef struct { u8 pad0[0x26]; s8 unk26; } Objflysaucer_func_8080003C_chflysaucer_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_8080003C_chflysaucer(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_800DA7A8(0xA34, arg1, 3);
    (((Objflysaucer_func_8080003C_chflysaucer_sp1C *)sp1C)->unk26) = (s8) arg1;
}

s32 func_80800080_chflysaucer(Actor *arg0, s32 **arg1) {
    void *func_80100094(Actor *, u32);
    s32 result;
    u8 *data;

    data = func_80100094(arg0, 0U);
    result = 0;
    switch (data[0x26]) {
        case 1:
            *arg1 = &(*(s32 *)D_808042D4_chflysaucer);
            return 0xA;
        case 2:
            *arg1 = &(*(s32 *)D_80804324_chflysaucer);
            return 0x13;
        case 3:
            *arg1 = &(*(s32 *)D_808043BC_chflysaucer);
            return 0x17;
        case 4:
            *arg1 = &(*(s32 *)D_80804474_chflysaucer);
            return 0x14;
        case 5:
            *arg1 = &(*(s32 *)D_80804514_chflysaucer);
            return 0x12;
        default:
            break;
    }
    return result;
}

void func_8080013C_chflysaucer(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    struct FlysaucerEntry {
        u16 value;
        u8 pad[6];
    };
    struct {
        u8 pad[0x2A];
        s16 index;
    } *sp24;
    s32 *sp20;
    s16 index;
    s32 count;

    sp24 = func_80100094(arg0, 0U);
    sp20 = NULL;
    count = func_80800080_chflysaucer(arg0, &sp20);
    if (count != 0) {
        index = sp24->index;
        if (index < count) {
            count = arg1;
            if (((struct FlysaucerEntry *)sp20)[index].value < count) {
                func_80108B04(arg0, count);
            }
        }
    }
}

void func_808001B4_chflysaucer(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_800C4140(u32, f32 *, u32);
    void func_80803AF0_chflysaucer(s32 *, s32, s32, f32);
    struct FlysaucerEvent {
        u16 time;
        u8 id;
        u8 flags;
        f32 value;
    };
    struct FlysaucerSound {
        s16 id;
        s16 pitch;
        f32 volume;
    };
    struct { u8 pad[0x2A]; s16 index; } *data;
    s32 *entries;
    s32 count;
    struct FlysaucerEvent *event;
    register u8 id;

    data = func_80100094(arg0, 0U);
    entries = NULL;
    count = func_80800080_chflysaucer(arg0, &entries);
    while (data->index < count && (event = &((struct FlysaucerEvent *)entries)[data->index])->time < arg1) {
        if (event->flags & 1) {
            id = event->id;
            func_800C4140((((struct FlysaucerSound *)D_80804294_chflysaucer)[id].id & 0x7FF) +
                (((((struct FlysaucerSound *)D_80804294_chflysaucer)[id].pitch >> 5) & 0x3FF) << 11) +
                (((u32)(((struct FlysaucerSound *)D_80804294_chflysaucer)[id].volume * 1023.0f) & 0x7FF) << 21),
                arg0->position, 0x09C404E2);
        } else {
            func_80803AF0_chflysaucer((s32 *)arg0, event->id, event->flags, event->value);
        }
        data->index++;
    }
}

void func_80800388_chflysaucer(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32 arg0);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    u8 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x28]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 5, 0);
        case 2:
            _capod_entrypoint_8(1);
            data[0x28] = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800424_chflysaucer(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void *func_80100094(Actor *, u32);
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);
    u8 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x28]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 5, arg2);
        case 1:
            data[0x28] = 2;
        case 2:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}    typedef struct { u8 pad0[0x28]; u8 unk28; } Objflysaucer_func_808004B0_chflysaucer_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_808004B0_chflysaucer(Actor *arg0) {
    s32 _capod_entrypoint_3(s32 arg0);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objflysaucer_func_808004B0_chflysaucer_temp_v0 *)temp_v0)->unk28) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0U);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x28))) = 0;
    }
}    typedef struct { u8 pad0[0x434]; s16 unk434; } Objflysaucer_D_80127194; /* offsets.py genstruct: fields from raw offsets on &D_80127194; rename once understood */

#ifdef BT_NATIVE
void func_808004F0_chflysaucer(s32 bt_a0) {
#else
void func_808004F0_chflysaucer(void) {
#endif
    void func_808017D0_chflysaucer();
    extern s32 D_80127194;
    (((Objflysaucer_D_80127194 *)&D_80127194)->unk434) = 0;
    func_808017D0_chflysaucer();
}

void func_80800514_chflysaucer(Actor *arg0) {
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void func_800FE850(void);
    void *func_80100094(Actor *, u32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    arg0->unk64_19 = 1;
    func_800FE850();
    switch (sp24[0x26]) {
        case 1:
            _gcgoto_entrypoint_1(0x124, 8);
            return;
        case 2:
            _gcgoto_entrypoint_1(0x13C, 1);
            return;
        case 3:
            _gcgoto_entrypoint_1(0x124, 8);
            return;
        case 4:
            _gcgoto_entrypoint_1(0x13B, 1);
            return;
        case 5:
            _gcgoto_entrypoint_1(0x124, 1);
            return;
        case 6:
            _gcgoto_entrypoint_1(0xD6, 8);
            arg0->unk64_19 = 0;
            break;
    }
}

void func_808005FC_chflysaucer(Actor *arg0) {
    s32 func_800D395C(void);
    void *func_80100094(Actor *, u32);
    void func_808009DC_chflysaucer(Actor *, s32);
    void func_808012A4_chflysaucer(Actor *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (data[0x26]) {
        case 0:
            func_808012A4_chflysaucer(arg0, 1);
            func_808009DC_chflysaucer(arg0, 3);
            func_8080003C_chflysaucer(arg0, 1);
            if (func_800D395C() == 0) {
                func_80800514_chflysaucer(arg0);
            }
            break;
        case 1:
            func_8080003C_chflysaucer(arg0, 2);
            func_80800514_chflysaucer(arg0);
            break;
        case 2:
            func_8080003C_chflysaucer(arg0, 3);
            func_80800514_chflysaucer(arg0);
            break;
        case 3:
            func_8080003C_chflysaucer(arg0, 4);
            func_80800514_chflysaucer(arg0);
            break;
        case 4:
            func_8080003C_chflysaucer(arg0, 5);
            func_80800514_chflysaucer(arg0);
            break;
        case 5:
            func_8080003C_chflysaucer(arg0, 6);
            func_80800514_chflysaucer(arg0);
            break;
        case 6:
            func_8080003C_chflysaucer(arg0, 0);
            break;
    }
}

s16 func_80800728_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return ((s16 *)D_808045A4_chflysaucer + 27)[*((u8 *)func_80100094(arg0, 0U) + 0x26)];
}

/* extern */

s32 func_80800758_chflysaucer(s16 arg0) {
    u8 *func_800A5800(s32 id);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0 != -1) {
        do {
            func_800A5800(arg0);
            _cadbfunc_entrypoint_16(&arg0);
            var_s0 += 1;
        } while (arg0 != -1);
    }
    return var_s0;
}

void func_808007C4_chflysaucer(Actor *arg0, s16 arg1) {
    void *func_80100094(Actor *, u32);
    u8 *func_800A5800(s32 id);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F0EF0(s32, f32 *);
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(f32 *arg0);
    s32 _cadbfunc_entrypoint_10(f32 *);
    s32 _cadbfunc_entrypoint_12(f32 *);
    s32 _cadbfunc_entrypoint_14(f32 *);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    void _suspline_entrypoint_0(void *, s32, s32);
    void *_suspline_entrypoint_10(void *, s32);
    f32 *_suspline_entrypoint_11(void *, s32);
    void _suspline_entrypoint_20(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    s16 i;
    f32 *vectors[2];
    f32 *values[3];
    s32 count;
    u8 *data;
    void *spline;
    s32 first;
    s32 flags;

    data = func_80100094(arg0, 0);
    count = func_80800758_chflysaucer(arg1);
    if (data[0x26] == 1) {
        first = 1;
    } else {
        first = 0;
    }
    _suspline_entrypoint_20(arg0, count, 2, 3, 0, 0);
    spline = func_80100094(arg0, 1);
    for (i = 0; i < 2; i++) {
        vectors[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 3; i++) {
        values[i] = _suspline_entrypoint_11(spline, i);
    }
    i = 0;
    while (arg1 != -1) {
        func_800A5800(arg1);
        if (i == 0 && first != 0) {
            func_800EE7F8(vectors[0], arg0->position);
            vectors[0][1] += 175.0f;
        } else {
            _cadbfunc_entrypoint_0((u8 *)vectors[0]);
        }
        _cadbfunc_entrypoint_2((BtIntPtr)vectors[1]);
        _cadbfunc_entrypoint_10(values[0]);
        _cadbfunc_entrypoint_12(values[1]);
        _cadbfunc_entrypoint_14(values[2]);
        _cadbfunc_entrypoint_29(8, &flags);
        _suspline_entrypoint_0(spline, i, flags);
        vectors[0] += 3;
        vectors[1] += 3;
        values[0]++;
        values[1]++;
        values[2]++;
        i++;
        _cadbfunc_entrypoint_16(&arg1);
    }
    func_800F0EF0(count, _suspline_entrypoint_10(spline, 1));
}

struct anctrl_s;
enum asset_e;
void func_808009DC_chflysaucer(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_800904F4(s32, Unk80132ED0 *);
    void func_800904C8(s32);
    void func_800F4CEC(BtIntPtr, u32);
    void func_800F4CC0(BtIntPtr);
    u32 func_800F54E4(void);
    void func_800BF4A4(s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_8008FFE8(void);
    void func_8010FD38(BtIntPtr, f32);
    struct anctrl_s *func_80104200(s16);
    struct anctrl_s *func_80104268(u32 *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_80801428_chflysaucer(Actor *);
    void func_8080149C_chflysaucer(Actor *);
    void func_80802CF0_chflysaucer(Actor *);
    struct {
        union {
            u32 packed;
            s16 index[2];
        } anim;
        u8 pad[0x20];
        u8 state;
    } *data;
    struct FlysaucerFlags {
        u8 pad[0x74];
        BT_BITFIELD_ORDER(u32 before : 11, u32 : 20);
        BT_BITFIELD_ORDER(u32 active : 1, u32 active : 1; u32 before : 11);
    };
    s32 pad;
    struct anctrl_s *control;
    struct anctrl_s *control1;
    struct anctrl_s *control0;

    data = func_80100094(arg0, 0);
    if (arg1 != data->state) {
        switch (data->state) {
        case 0:
            if (arg1 == 1U || arg1 == 3U) {
                func_800904F4(0x27, arg0->unk0);
                func_80104268(&data->anim.packed);
                func_80801428_chflysaucer(arg0);
                func_800F4CEC(func_800F54E4(), 0x71);
                func_80802CF0_chflysaucer(arg0);
            }
            break;
        case 2:
            if (arg1 == 1 || arg1 == 3) {
                func_800904C8(0x4B);
                func_800F4CC0(func_800F54E4());
                func_800BF4A4(0, 1);
                func_800BF4A4(1, 1);
                ((struct FlysaucerFlags *)arg0)->active = 1;
                func_8010FD38(func_8008FFE8(), 0.0f);
                control = func_80104200(data->anim.index[0]);
                anctrl_setIndex(control, 0x486);
                anctrl_setDuration(control, 1.0f);
                anctrl_setPlaybackType(control, 3);
                anctrl_start(control);
            }
            break;
        case 1:
        case 3:
            if (arg1 != 0) {
                if (arg1 == 2) {
                    func_800F4CEC(func_800F54E4(), 0x60);
                    func_800BF4A4(0, 0);
                    func_800BF4A4(1, 0);
                    ((struct FlysaucerFlags *)arg0)->active = 0;
                    func_800904C8(0x4B);
                    func_80802CF0_chflysaucer(arg0);
                    func_8010FD38(func_8008FFE8(), 75.0f);
                    control1 = func_80104200(data->anim.index[1]);
                    control0 = func_80104200(data->anim.index[0]);
                    anctrl_setIndex(control1, 0x484);
                    anctrl_setIndex(control0, 0x489);
                    anctrl_setPlaybackType(control1, 3);
                    anctrl_start(control1);
                    anctrl_setPlaybackType(control0, 3);
                    anctrl_start(control0);
                }
            } else {
                func_800904C8(0x28);
                func_800F4CC0(func_800F54E4());
                func_8080149C_chflysaucer(arg0);
            }
            break;
        }
        data->state = arg1;
    }
}

s32 func_80800C3C_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _suspline_entrypoint_1(void *);
    void _suspline_entrypoint_14(void *);
    void _suspline_entrypoint_16(void *);
    void _suspline_entrypoint_17(void *);
    void _suspline_entrypoint_3(void *, s32, f32 *);
    void _suspline_entrypoint_5(void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_808012A4_chflysaucer(Actor *, s32);
    u8 *sp3C;
    void *sp38;
    s32 sp34;
    f32 sp28[3];

    sp3C = func_80100094(arg0, 0);
    sp38 = func_80100094(arg0, 1);
    sp34 = 0;
    _suspline_entrypoint_14(sp38);
    _suspline_entrypoint_17(sp38);
    _suspline_entrypoint_3(sp38, 0, (f32 *)&arg0->actorData[4]);
    _suspline_entrypoint_3(sp38, 1, arg0->rotation);
    arg0->rotation[1] += 180.0f;
    arg0->rotation[0] = -arg0->rotation[0];
    _suspline_entrypoint_5(sp38, (f32 *)&arg0->actorData[4]);
    if (_suspline_entrypoint_1(sp38)) {
        if (sp3C[0x26] == 5) {
            func_808012A4_chflysaucer(arg0, 3);
            func_808009DC_chflysaucer(arg0, 1);
        } else {
            func_808009DC_chflysaucer(arg0, 1);
            func_808012A4_chflysaucer(arg0, 4);
            func_808005FC_chflysaucer(arg0);
        }
        sp34 = 1;
    }
    _suspline_entrypoint_16(sp38);
    if (arg0->unk74_29) {
        func_800EFB24(sp28, (f32 *)&arg0->actorData[4], arg0->position);
        func_800EF334(sp28, 0.3f);
        func_800EF04C(arg0->position, sp28);
    } else {
        func_800EE7F8(arg0->position, (f32 *)&arg0->actorData[4]);
        arg0->unk74_29 = 1;
    }
    return sp34;
}

s32 func_80800DAC_chflysaucer(Actor *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void *func_80100094(Actor *, u32);
    f32 _suspline_entrypoint_6(void *);
    void _suspline_entrypoint_15(void *, f32);
    void _suspline_entrypoint_17(void *);
    void _suspline_entrypoint_3(void *, s32, f32 *);
    void _suspline_entrypoint_8(void *, f32);
    void *data;
    f32 sp20;

    data = func_80100094(arg0, 1U);
    sp20 = _suspline_entrypoint_6(data);
    _suspline_entrypoint_15(data, arg3);
    _suspline_entrypoint_17(data);
    _suspline_entrypoint_3(data, 0, arg1);
    _suspline_entrypoint_3(data, 1, arg2);
    arg2[1] += 180.0f;
    _suspline_entrypoint_8(data, sp20);
    return 1;
}

u32 func_80800E48_chflysaucer(BtIntPtr arg0) {
    s32 func_800D0A9C(u32, u32);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    extern s32 D_80127194;
    if (func_800D395C() != 0) {
        if (func_800D211C(0x8D) < ((Objflysaucer_D_80127194 *)&D_80127194)->unk434) {
            return 4;
        }
        return 5;
    }
    if (func_800D0A9C(0x18, 1) == 0 && func_800D0A9C(9, 4) == 0) {
        if (((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x1F4 &&
            ((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x190) {
            return 3;
        }
        if (((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x1F4) {
            return 1;
        }
        if (((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x190) {
            return 2;
        }
        return 0;
    }
    if (func_800D0A9C(0x18, 1) == 0) {
        if (((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x1F4) {
            return 1;
        }
        return 0;
    }
    if (func_800D0A9C(9, 4) == 0) {
        if (((Objflysaucer_D_80127194 *)&D_80127194)->unk434 >= 0x190) {
            return 2;
        }
        return 0;
    }
    if (func_800D211C(0x8D) < ((Objflysaucer_D_80127194 *)&D_80127194)->unk434) {
        return 4;
    } else {
        return 5;
    }
}

/* extern */

#ifdef BT_NATIVE
void func_80800F98_chflysaucer(BtIntPtr bt_a0) {
#else
void func_80800F98_chflysaucer() {
#endif
    void func_800FC6B0(u32 track_id);
    u32 func_80800E48_chflysaucer();
    u32 temp_v0;

#ifdef BT_NATIVE
    temp_v0 = ((u32 (*)())func_80800E48_chflysaucer)();
#else
    temp_v0 = func_80800E48_chflysaucer();
#endif
    switch (temp_v0) {
    case 0:
    case 5:
        func_800FC6B0(0x17);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        func_800FC6B0(0x16);
        /* fallthrough */
    default:
        return;
    }
}

s32 func_80800FF0_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 temp_v1;

    temp_v1 = (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x24)));
    switch (temp_v1) {
    case 1:
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}

void func_80801034_chflysaucer(void *arg0) {
    (((Actor *)arg0)->position[0]) = -7800.0f;
    (((Actor *)arg0)->position[1]) = 1700.0f;
    (((Actor *)arg0)->position[2]) = -2900.0f;
}

/* extern */

void func_8080105C_chflysaucer(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_80800388_chflysaucer(Actor *, s32, s32);
    arg2 |= 6;
    if (func_80800FF0_chflysaucer(arg0) == 0) {
        arg2 |= 8;
    }
    switch (arg1) {
    case 0x10C6:
    case 0x10C7:
    case 0x10C8:
    case 0x10C9:
    case 0x10E2:
    case 0x10E3:
    case 0x10E4:
    case 0x10E5:
    case 0x10E6:
    case 0x10E7:
    case 0x10E8:
        func_80800388_chflysaucer(arg0, 2, 1);
        break;
    case 0x10DB:
    case 0x10DD:
        func_80800388_chflysaucer(arg0, 4, 0);
        break;
    case 0x10DC:
    case 0x10DE:
        func_80800388_chflysaucer(arg0, 2, 1);
        break;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x41);
    arg0->unk74_30 = 1;
}

void func_80801130_chflysaucer(BtIntPtr arg0) {
    s32 func_800D2054(s32, s32, s32);
    s32 func_800DA9E4(s32, s32);
    void func_808012A4_chflysaucer(Actor *, s32);
    extern s32 D_80127194;
    u32 state;

    state = func_80800E48_chflysaucer(arg0);
    switch (state) {
    case 0:
        if (func_800DA9E4(0x415, 1) == 0) {
            func_8080105C_chflysaucer((Actor *)arg0, 0x10C6, 1);
            return;
        }
        func_8080105C_chflysaucer((Actor *)arg0, 0x10C7, 1);
        return;
    case 1:
        func_808012A4_chflysaucer((Actor *)arg0, 7);
        func_800D2054(0, 0x8D, ((Objflysaucer_D_80127194 *)&D_80127194)->unk434);
        return;
    case 2:
        func_808012A4_chflysaucer((Actor *)arg0, 8);
        func_800D2054(0, 0x8D, ((Objflysaucer_D_80127194 *)&D_80127194)->unk434);
        return;
    case 3:
        func_808012A4_chflysaucer((Actor *)arg0, 9);
        func_800D2054(0, 0x8D, ((Objflysaucer_D_80127194 *)&D_80127194)->unk434);
        return;
    case 4:
        func_800D2054(0, 0x8D, ((Objflysaucer_D_80127194 *)&D_80127194)->unk434);
        func_8080105C_chflysaucer((Actor *)arg0, 0x10E4, 1);
        return;
    case 5:
        if (func_800DA9E4(0x416, 1) == 0) {
            func_8080105C_chflysaucer((Actor *)arg0, 0x10E2, 1);
            return;
        }
        func_8080105C_chflysaucer((Actor *)arg0, 0x10E3, 1);
    }
}

void func_808012A4_chflysaucer(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80090658(s32);
    u32 func_800FDC28(u32);
    u8 *data;
    u8 state;

    data = func_80100094(arg0, 0);
    state = data[0x25];
    if (state != 2 && (state == 5 || state == 6)) {
        func_80090658(0);
    }
    data[0x25] = arg1;
    switch (data[0x25]) {
    case 2:
        break;
    case 5:
    case 6:
        func_80090658(1);
        break;
    case 3:
        arg0->unk58 = 2.0f;
        func_800FDC28(0);
        func_80800F98_chflysaucer(arg0);
        break;
    case 7:
        func_8080105C_chflysaucer(arg0, 0x10C8, 1);
        break;
    case 8:
        func_8080105C_chflysaucer(arg0, 0x10C9, 1);
        break;
    case 9:
        func_8080105C_chflysaucer(arg0, 0x10E5, 1);
        break;
    }
}

struct anctrl_s;
enum asset_e;
void func_808013B4_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B188(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    s16 *data;
    struct anctrl_s *control;

    data = func_80100094(arg0, 0);
    control = func_80104200(data[1]);
    anctrl_reset(control);
    anctrl_setPlaybackType(control, 3);
    anctrl_setIndex(control, 0x481);
    anctrl_setDuration(control, 1.0f);
    func_8008B188(control, 1);
    anctrl_start(control);
}

void func_80801428_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B188(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    s16 *data;
    struct anctrl_s *control;

    data = func_80100094(arg0, 0);
    control = func_80104200(data[0]);
    anctrl_reset(control);
    anctrl_setPlaybackType(control, 3);
    anctrl_setIndex(control, 0x486);
    anctrl_setDuration(control, 1.0f);
    func_8008B188(control, 1);
    anctrl_start(control);
}

void func_8080149C_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_801042D8(s16 *handle);
    s16 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*temp_v0 != 0) {
        func_801042D8((BtIntPtr) temp_v0);
    }
}

/* extern */

struct anctrl_s;

void chflysaucer_entrypoint_0(Unk80132ED0 *arg0, f32 arg1) {
    int anctrl_getIndex(struct anctrl_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    Actor *func_80106790(Unk80132ED0 *);
    struct anctrl_s *sp1C[3];
    s16 *temp_v0;
    struct anctrl_s *temp_v0_2;
    Actor *actor;

    actor = func_80106790(arg0);
    temp_v0 = func_80100094(actor, 0);
    if (*temp_v0 != 0) {
        temp_v0_2 = func_80104200(*temp_v0);
        sp1C[0] = temp_v0_2;
        if (anctrl_getIndex(temp_v0_2) == 0x486) {
            func_8008B10C(sp1C[0], arg1);
        }
    }
}    typedef struct { u8 pad0[0x2]; s16 unk2; } Objflysaucer_func_80801534_chflysaucer_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80801534_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_801042D8(s16 *handle);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objflysaucer_func_80801534_chflysaucer_temp_v0 *)temp_v0)->unk2) != 0) {
        func_801042D8((BtIntPtr) (temp_v0 + 2));
    }
}

void func_80102424(Actor *, s32);
void func_80801568_chflysaucer(Actor *arg0, s32 arg1) {
    void func_808004F0_chflysaucer();
    void _gcfrontend_entrypoint_9(s32 arg0);
    void _subaddieDll_entrypoint_0(void *arg0);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D395C(void);
    s32 func_800DA9E4(s32, s32);
    u32 func_800F54E4(void);
    s32 func_800F7C0C(BtIntPtr, s32, f32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    struct anctrl_s *func_80104268(u32 *);
    struct {
        s16 anim[2];
        u8 pad4[0x14];
        f32 speed;
        u8 pad1C[0xE];
        s16 index;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 5:
            func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
            func_80801534_chflysaucer(arg0);
            break;
        case 4:
            func_808004B0_chflysaucer(arg0);
            break;
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
        case 6:
            arg0->unk64_20 = 1;
            break;
        case 2:
            func_80800424_chflysaucer(arg0, 0x9C, 0x4020, NULL);
            data->speed = 0.3f;
            func_808012A4_chflysaucer(arg0, 1);
            func_808009DC_chflysaucer(arg0, 3);
            break;
        case 4:
            if (func_800D395C() == 0 &&
                (func_800D0A9C(0x18, 1) == 0 || func_800D0A9C(9, 4) == 0)) {
                if (func_800DA9E4(0x417, 1) == 0) {
                    func_8080105C_chflysaucer(arg0, 0x10C5, 1);
                    _gcfrontend_entrypoint_9(0x69);
                } else {
                    func_8080105C_chflysaucer(arg0, 0x1102, 1);
                }
            } else {
                if (func_800DA9E4(0x418, 1) == 0) {
                    func_8080105C_chflysaucer(arg0, 0x10E1, 1);
                    return;
                }
#ifdef BT_NATIVE
                ((void (*)())func_808004F0_chflysaucer)(arg0);
#else
                func_808004F0_chflysaucer(arg0);
#endif
                func_80801568_chflysaucer(arg0, 5);
            }
            break;
        case 5:
            data->index = 0;
            data->speed = 0.8f;
            _subaddieDll_entrypoint_4(arg0, 1);
            _subaddieDll_entrypoint_0(arg0);
            func_800FDC28(0x11);
            func_808007C4_chflysaucer(arg0, func_80800728_chflysaucer(arg0));
            func_808012A4_chflysaucer(arg0, 1);
            func_808009DC_chflysaucer(arg0, 1);
            func_80800C3C_chflysaucer(arg0);
            func_800F7C0C(func_800F54E4(), 0x5F, -1.0f);
            func_80104268((u32 *)&data->anim[1]);
            func_808013B4_chflysaucer(arg0);
            break;
    }
}

void func_808017D0_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80801568_chflysaucer(Actor *, s32);
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_808012A4_chflysaucer(Actor *, s32);
    void func_808009DC_chflysaucer(Actor *, s32);
    s32 entry;
    s32 index;

    index = ((u8 *)func_80100094(arg0, 0))[0x26];
    func_80801568_chflysaucer(arg0, 5);
    entry = ((s16 *)D_808045E8_chflysaucer)[index];
    if (entry != -1) {
        _capod_entrypoint_13(arg0->unk0, NULL, entry, 0x2C21);
    } else {
        func_808012A4_chflysaucer(arg0, 2);
        func_808009DC_chflysaucer(arg0, 2);
    }
}

union PackedArg { s32 word; struct { s16 a; s16 b; } h; };
s32 func_8080185C_chflysaucer(Actor *arg0, s32 arg1, union PackedArg arg2) {
    s32 _capod_entrypoint_14(void);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcfrontend_entrypoint_10(void);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    s32 func_800D0A9C(u32, u32);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    void *func_80100094(Actor *, u32);
    Unk80132ED0 *func_80101080(void);
    void func_80108BD4(Actor *, s32);
    void func_808001B4_chflysaucer(Actor *, s32);
    void func_80800424_chflysaucer(Actor *, s32, s32, Unk80132ED0 *);
    void func_808004B0_chflysaucer(Actor *);
    void func_808004F0_chflysaucer();
    void func_808005FC_chflysaucer(Actor *);
    void func_808009DC_chflysaucer(Actor *, s32);
    void func_8080105C_chflysaucer(Actor *, s32, s32);
    void func_808012A4_chflysaucer(Actor *, s32);
    struct SaucerData { u8 pad[0x24]; u8 camera; u8 state; u8 mode; };
    struct SaucerData *data;
    struct PackedDialog { BT_BITFIELD_ORDER(s32 id : 16, s32 choice : 16); BT_BITFIELD_ORDER(s32 choice : 16, s32 id : 16); };
    s16 *result;
    s32 value;
    data = func_80100094(arg0, 0);
    value = arg2.word;
    switch (arg1) {
        default:
        return 0;
        case 0x52:
        if (data->camera == 0) {
            _gcdialogcamera_entrypoint_3(D_808045F8_chflysaucer, arg0->scale);
        } else {
            _gcdialogcamera_entrypoint_3(D_80804608_chflysaucer, arg0->scale);
        }
        break;
        case 0x2E:
        switch (arg2.h.a) {
            case 0xCEB:
            case 0x10C5:
            case 0x10C8:
            case 0x10C9:
            case 0x10E5:
            case 0x10E6:
            case 0x1102:
            break;
            case 0x10E2:
            case 0x10E3:
            case 0x10E4:
            if (func_800D395C() != 0) {
                break;
            }
            default:
            func_808004B0_chflysaucer(arg0);
            break;
        }
        if (data->mode == 6) {
            switch (arg2.h.a) {
                case 0x10C8:
                case 0x10C9:
                case 0x10E5:
                case 0x10E6:
                break;
                case 0xCEB:
                if (arg2.h.b == 1) {
                    func_8080003C_chflysaucer(arg0, 0);
                    _gcgoto_entrypoint_1(0x124, 8);
                } else {
                    _gcfrontend_entrypoint_10();
                }
                break;
                case 0x10E2:
                case 0x10E3:
                case 0x10E4:
                if (func_800D395C() != 0) {
                    func_8080105C_chflysaucer(arg0, 0xCEB, 0x40);
                    break;
                }
                default:
                func_808005FC_chflysaucer(arg0);
                func_808012A4_chflysaucer(arg0, 0);
                break;
            }
        } else if (arg0->unk70_10 == 4) {
            switch (arg2.h.a) {
                case 0x10C5:
                case 0x1102:
                if (func_800D0A9C(9, 4) == 0) {
                    func_8080105C_chflysaucer(arg0, 0x1103, 1);
                } else {
                    func_8080105C_chflysaucer(arg0, 0x1104, 1);
                }
                break;
                case 0x1103:
                case 0x1104:
#ifdef BT_NATIVE
                ((void (*)())func_808004F0_chflysaucer)(arg0);
#else
                func_808004F0_chflysaucer(arg0);
#endif
                break;
                case 0x10E1:
#ifdef BT_NATIVE
                ((void (*)())func_808004F0_chflysaucer)(arg0);
#else
                func_808004F0_chflysaucer(arg0);
#endif
                break;
            }
            if (1) {}
        }
        arg0->unk74_30 = 0;
        break;
        case 0x30:
        result = (s16 *) &arg2;
        switch (result[0]) {
            case 0x10C5:
            case 0x1103:
            switch (result[1]) {
                case 0:
                return 500;
                case 1:
                return 400;
            }
            break;
            case 0x1104:
            return 500;
            case 0x10E4:
            return func_800D211C(0x8D);
            case 0x10E2:
            case 0x10E3:
            return func_800D211C(0x8D);
        }
        break;
        case 0x2F:
        switch (arg2.h.a) {
            case 0x10C8:
            case 0x10E6:
            func_800D1000(0x18, 1, NULL, 1, *(void **)arg0);
            break;
            case 0x10C9:
            case 0x10E5:
            func_800D1000(9, 4, D_80804618_chflysaucer, 1, *(void **)arg0);
            break;
        }
        break;
        case 0x56:
        switch (arg2.word) {
            case 0x1B:
            case 0x1D:
            case 0x66:
            case 0x68:
            case 0x6A:
            case 0x6C:
            func_808009DC_chflysaucer(arg0, 1);
            func_808012A4_chflysaucer(arg0, 1);
            break;
        }
        break;
        case 0xB:
        switch (value) {
            case 0x19:
            case 0x1B:
            case 0x64:
            case 0x6A:
            case 0x6E:
            func_80108BD4(arg0, arg2.word);
            return 3;
            case 0x70:
            switch (data->state) {
                case 9:
                func_8080105C_chflysaucer(arg0, 0x10E6, 1);
                return 4;
                case 8:
                if (func_800D0A9C(0x18, 1) != 0) {
                    func_8080105C_chflysaucer(arg0, 0x10E8, 1);
                } else {
                    func_8080105C_chflysaucer(arg0, 0x10E7, 1);
                }
                return 4;
            }
            break;
            case 0x72:
            switch (data->state) {
                case 7:
                if (func_800D0A9C(9, 4) != 0) {
                    func_8080105C_chflysaucer(arg0, 0x10E8, 1);
                } else {
                    func_8080105C_chflysaucer(arg0, 0x10E7, 1);
                }
                return 4;
                case 9:
                func_8080105C_chflysaucer(arg0, 0x10E8, 1);
                return 4;
            }
            break;
        }
        return 3;
        case 0x59:
        switch (arg2.word) {
            case 0x19:
            case 0x1B:
            case 0x64:
            case 0x6A:
            case 0x6E:
            _capod_entrypoint_14();
            func_808012A4_chflysaucer(arg0, 2);
            func_808009DC_chflysaucer(arg0, 2);
            return 4;
        }
        return 3;
        case 0x3D:
        func_808001B4_chflysaucer(arg0, arg2.word);
        break;
        case 0xD:
        switch ((arg2.word >> 16) & 0xFFFF) {
            case 0x18:
            func_80800424_chflysaucer(arg0, 0x72, 0x418, func_80101080());
            break;
            case 9:
            func_80800424_chflysaucer(arg0, 0x70, 0x418, func_80101080());
            break;
        }
        break;
    }
    return 1;
}

void func_80801E98_chflysaucer(Actor *arg0) {
    s32 func_80016B30(s32, s32);
    s32 func_8008FA2C(s32, s32);
    s32 func_8008FA60(s32, s32);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_800DA298(s32);
    void func_800DA544(GameFlag);
    s32 func_800DA9E4(s32, s32);
    int func_800DB9B0(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_8010CAC0(f32 *, u32);
    f32 sp1C[3];

    if (!arg0->unk74_30 && func_8010CAC0(arg0->position, 250) && !func_800DB9B0()) {
        if (arg0->unk64_20) {
            if (!func_800DA298(0x414)) {
                if (func_8008FA2C(1, 0)) {
                    func_800DA544(0x414);
                    func_8080105C_chflysaucer(arg0, 0x10DB, 1);
                }
            } else if (func_80090178(1)) {
                func_800EE7F8(sp1C, arg0->position);
                sp1C[1] += 150.0f;
                if (func_8010CAC0(sp1C, 120)) {
                    func_808012A4_chflysaucer(arg0, 5);
                    return;
                }
                if (func_8008FA60(1, 0) && func_80016B30(0, 1) == 1) {
                    func_8080105C_chflysaucer(arg0, 0x10DC, 1);
                }
            }
        } else {
            if (!func_800DA9E4(0x413, 1)) {
                func_8080105C_chflysaucer(arg0, 0x10DD, 1);
                return;
            }
            if (func_80016B30(0, 1) == 1) {
                func_8080105C_chflysaucer(arg0, 0x10DE, 1);
            }
        }
    }
}

/* extern */

void func_80802014_chflysaucer(BtIntPtr arg0) {
    s32 func_8008FB10(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    func_8008FB10(arg0 + 4, 65.0f, 0.0f, 90.0f);
}

void func_80802044_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _suspline_entrypoint_2(void *, f32);
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_808012A4_chflysaucer(Actor *, s32);
    void func_808009DC_chflysaucer(Actor *, s32);
    u8 *sp34;
    void *spline;
    u8 index;
    s16 *entry;

    sp34 = func_80100094(arg0, 0);
    spline = func_80100094(arg0, 1);
    index = sp34[0x26];
    entry = &((s16 *)D_80804624_chflysaucer)[index];
    if (((f32 *)D_80804274_chflysaucer)[index] != -1.0f && *entry != -1) {
        if (_suspline_entrypoint_2(spline, ((f32 *)D_80804274_chflysaucer)[index])) {
            _capod_entrypoint_13(arg0->unk0, NULL, *entry, 0x4C21);
            func_808012A4_chflysaucer(arg0, 1);
            func_808009DC_chflysaucer(arg0, 1);
        }
    }
}

void func_80802114_chflysaucer(Actor *arg0, f32 arg1) {
    void func_800C31DC(u8, f32);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    u8 index;

    index = arg0->unk5F;
    if (index == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &(*(s32 *)D_80804634_chflysaucer));
    } else {
        if (arg1 < 0.5f) {
            arg1 = 0.5f;
        }
        if (arg1 > 1.5f) {
            arg1 = 1.5f;
        }
        func_800C31DC(index, arg1);
        func_800C4350(arg0->unk5F, arg0->position, NULL);
    }
}

void func_808021C0_chflysaucer(Actor *arg0, u8 *arg1, s32 arg2) {
    s32 func_800C2FDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    void func_800C4B64(f32);
    if (arg2 == arg1[0x2D]) {
        if (arg2 != 3) {
            func_800C4350(arg1[0x2C], arg0->position, NULL);
        }
    } else {
        if ((arg2 != 0) && (arg2 != 1) && (arg2 != 2)) {
            if (arg2 == 3) {
                func_800C2FDC(arg1[0x2C]);
                arg1[0x2C] = 0;
            }
        } else {
            func_800C4B64(((f32 *)D_8080465C_chflysaucer)[arg2]);
            arg1[0x2C] = func_800C4350(arg1[0x2C], arg0->position, &(*(s32 *)D_80804648_chflysaucer));
        }
        arg1[0x2D] = arg2;
    }
}

void func_80802290_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8008ADE4(struct anctrl_s *);
    void func_80016068(u32, f32 *);
    struct {
        s16 control0;
        s16 control1;
        f32 stick[2];
        u8 padC[0x18];
        u8 mode;
        u8 pad25[2];
        u8 direction;
    } *data;
    struct anctrl_s *control1;
    struct anctrl_s *control0;
    f32 stick[2];
    f32 x;
    f32 y;
    f32 absX;
    f32 absY;
    s32 direction;

    data = func_80100094(arg0, 0);
    if (data->mode == 2) {
        control1 = func_80104200(data->control1);
        control0 = func_80104200(data->control0);
        direction = 0;
        func_80016068(0, stick);
        x = stick[0] - data->stick[0];
        y = stick[1] - data->stick[1];
        absX = x > 0.0f ? x : -x;
        absY = y > 0.0f ? y : -y;
        if (absX > absY) {
            if (x > 0.25f) {
                direction = 4;
            } else if (x < -0.25f) {
                direction = 3;
            }
        } else if (y > 0.25f) {
            direction = 2;
        } else if (y < -0.25f) {
            direction = 1;
        }
        if (direction != data->direction) {
            switch (direction) {
                case 0:
                    break;
                case 3:
                    anctrl_setIndex(control1, 0x484);
                    anctrl_setIndex(control0, 0x489);
                    break;
                case 4:
                    anctrl_setIndex(control1, 0x485);
                    anctrl_setIndex(control0, 0x48A);
                    break;
                case 1:
                    anctrl_setIndex(control1, 0x482);
                    anctrl_setIndex(control0, 0x487);
                    break;
                case 2:
                    anctrl_setIndex(control1, 0x483);
                    anctrl_setIndex(control0, 0x488);
                    break;
            }
            if (direction != 0) {
                anctrl_setPlaybackType(control1, 1);
                anctrl_start(control1);
                anctrl_setPlaybackType(control0, 1);
                anctrl_start(control0);
            }
            data->direction = direction;
        }
        func_8008ADE4(control1);
        func_8008ADE4(control0);
    }
}

void func_808024E0_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_8008FF40(f32 *);
    void func_800904C8(s32);
    void func_800904F4(s32, Unk80132ED0 *);
    void func_800906B0(f32 *);
    void func_800906DC(f32 *);
    void func_8010D254(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_80101F24(Actor *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80802CF0_chflysaucer(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void _suspline_entrypoint_13(void *);
    f32 _suspline_entrypoint_6(void *);
    void _suspline_entrypoint_9(void *, f32);
    f32 func_800D8FF8(void);
    void func_800D2770(s32, s32);
    s32 func_800D24E8(s32, s32, u32);
    extern s32 D_80127194;
    struct {
        u8 pad0[0x18];
        f32 speed;
        u8 pad1C[9];
        u8 mode;
        u8 stage;
        u8 pad27[7];
        u8 started;
    } *data;
    struct FlysaucerCounter {
        u8 pad0[0x434];
        s16 count;
    };
    f32 position[3];
    f32 rotation[3];
    f32 angle;
    f32 delta[3];
    f32 destination[3];
    f32 progress;
    f32 pathProgress;
    void *spline;
    s32 pad[2];

    data = func_80100094(arg0, 0);
    if (arg0->unk64_20) {
    } else if (func_800DA298(0xEB)) {
        arg0->unk64_20 = 1;
    }
    switch (arg0->unk70_10) {
        case 1:
            switch (data->stage) {
                case 0:
                    switch (data->mode) {
                        case 0:
                            func_80801E98_chflysaucer(arg0);
                            func_80802014_chflysaucer((BtIntPtr)arg0);
                            break;
                        case 5:
                            func_808012A4_chflysaucer(arg0, 6);
                            func_800904F4(0x27, arg0->unk0);
                            break;
                        case 6:
                            func_8008FF40(rotation);
                            angle = func_800F1DCC(arg0->rotation[1], rotation[1]);
                            rotation[1] += angle * 0.45f;
                            func_800906DC(rotation);
                            func_8010D254(position);
                            func_800EE7F8(destination, arg0->position);
                            destination[1] += 90.0f;
                            func_800EFB24(delta, destination, position);
                            func_800EF334(delta, 0.45f);
                            func_800EF04C(position, delta);
                            func_800906B0(position);
                            if (func_800EEB40(position, destination) < 2500.0f && angle > -5.0f && angle < 5.0f) {
                                func_800904C8(0x28);
                                func_808005FC_chflysaucer(arg0);
                            }
                            break;
                    }
                    break;
                case 6:
                    func_80802014_chflysaucer((BtIntPtr)arg0);
                    break;
            }
            break;
        case 2:
            progress = func_80101F24(arg0);
            if (func_80101DDC(arg0)) {
                func_80801568_chflysaucer(arg0, 3);
            }
            if (progress > 0.05f && progress < 0.14f && data->speed < 0.4f) {
                data->speed += 0.02f;
            }
            if (progress > 0.14f && progress < 0.31f && data->speed > 0.2f) {
                data->speed -= 0.03f;
            }
            if (progress > 0.31f && progress < 0.46f && data->speed < 0.55f) {
                data->speed += 0.02f;
            }
            if (progress > 0.46f && progress < 0.55f && data->speed > 0.45f) {
                data->speed -= 0.03f;
            }
            if (progress > 0.55f && progress < 0.58f && data->speed < 0.7f) {
                data->speed += 0.02f;
            }
            if (progress > 0.58f && progress < 0.65f && data->speed > 0.6f) {
                data->speed -= 0.03f;
            }
            if (progress > 0.65f && progress < 0.71f && data->speed < 0.85f) {
                data->speed += 0.02f;
            }
            if (progress > 0.71f && progress < 0.85f && data->speed > 0.8f) {
                data->speed -= 0.03f;
            }
            func_80802CF0_chflysaucer(arg0);
            func_80802114_chflysaucer(arg0, data->speed);
            if (func_80101E14(arg0, 0.62f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_80804260_chflysaucer));
                func_808021C0_chflysaucer(arg0, data->pad0, 3);
            } else if (progress < 0.21f) {
                func_808021C0_chflysaucer(arg0, data->pad0, 0);
            } else if (progress > 0.3f && progress < 0.44f) {
                func_808021C0_chflysaucer(arg0, data->pad0, 1);
            } else if (progress > 0.5f && progress < 0.62f) {
                func_808021C0_chflysaucer(arg0, data->pad0, 2);
            }
            break;
        case 3:
            if (data->speed <= 0.99f) {
                data->speed += 0.01f;
            } else {
                func_80801568_chflysaucer(arg0, 4);
            }
            func_80802CF0_chflysaucer(arg0);
            func_80802114_chflysaucer(arg0, data->speed);
            break;
        case 4:
            func_80802CF0_chflysaucer(arg0);
            func_80802114_chflysaucer(arg0, data->speed);
            break;
        case 5:
            switch (data->mode) {
                case 3:
                    arg0->unk58 -= func_800D8FF8();
                    if (arg0->unk58 <= 0.0f) {
                        func_808005FC_chflysaucer(arg0);
                    }
                    break;
                case 4:
                    break;
                default:
                    spline = func_80100094(arg0, 1);
                    _suspline_entrypoint_13(spline);
                    pathProgress = _suspline_entrypoint_6(spline);
                    _suspline_entrypoint_9(spline, pathProgress);
                    if (!func_80800C3C_chflysaucer(arg0)) {
                        pathProgress = _suspline_entrypoint_6(spline);
                        func_8080013C_chflysaucer(arg0, 65535.0f * pathProgress);
                    }
                    break;
            }
            func_80802CF0_chflysaucer(arg0);
            func_80802114_chflysaucer(arg0, data->speed);
            if (!data->started && func_80800000_chflysaucer(arg0) == 1) {
                func_800D2770(0xC0, 0);
                data->started = 1;
            } else {
                func_800D24E8(0xC0, ((struct FlysaucerCounter *)&D_80127194)->count, 0);
            }
            func_80802044_chflysaucer(arg0);
            break;
    }
    func_80802290_chflysaucer(arg0);
}

void func_80802CF0_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800906B0(f32 *);
    void func_800906DC(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F81D4(BtUIntPtr, f32 *);
    f32 distance;
    f32 position[3];
    f32 rotation[3];
    f32 temp[3];
    struct {
        u8 pad0[0x10];
        f32 distance;
        u8 pad14[8];
        f32 roll;
        u8 pad20[4];
        u8 mode;
    } *data;

    data = func_80100094(arg0, 0);
    rotation[0] = arg0->rotation[0];
    rotation[1] = arg0->rotation[1];
    rotation[2] = arg0->rotation[2] - data->roll;
    switch (data->mode) {
        case 2:
            position[0] = arg0->position[0];
            position[1] = arg0->position[1] - 100.0f;
            position[2] = arg0->position[2];
            rotation[1] += 180.0f;
            rotation[0] = -rotation[0];
            rotation[2] = arg0->rotation[2];
            func_800F81D4(func_800F54E4(), rotation);
            rotation[1] -= 180.0f;
            rotation[0] = -rotation[0];
            break;
        case 1:
            func_800EE7F8(temp, arg0->rotation);
            temp[2] = -temp[2];
            func_800EF6A8(position, temp, 0.0f, -70.0f, 0.0f);
            func_800EF04C(position, arg0->position);
            rotation[2] = -rotation[2];
            break;
        case 0:
            func_800EF4E4(position, arg0->rotation[0], arg0->rotation[1], 0.0f, 90.0f, 0.0f);
            func_800EF04C(position, arg0->position);
            rotation[2] = -rotation[2];
            break;
        case 3:
            distance = data->distance;
            distance += 40.0f;
            func_800EF4E4(position, arg0->rotation[0], arg0->rotation[1], 0.0f, distance, 0.0f);
            func_800EF04C(position, arg0->position);
            rotation[2] = -rotation[2];
            break;
    }
    func_800906B0(position);
    func_800906DC(rotation);
}

void func_80802ED8_chflysaucer(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D2054(s32, s32, s32);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    int func_800DC298(f32);
    s32 func_800EA05C();
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    u8 *sp24;
    s32 sp20;

    sp24 = func_80100094(arg0, 0);
    sp20 = func_800EA05C();
    sp24[0x2D] = 3;
    if (func_800D211C(0x8D) < 0x226) {
        func_800D2054(0, 0x8D, 0x226);
    }
    func_800EFA4C((f32 *)(sp24 + 0xC), 0.0f, 110.0f, 0.0f);
    switch (func_80800000_chflysaucer(arg0)) {
    case 0:
        if (_glcutDll_entrypoint_20()) {
            func_80801568_chflysaucer(arg0, 6);
            return;
        }
        if (func_800D395C() && sp20 == 0x124) {
            func_80801034_chflysaucer(arg0);
            func_808005FC_chflysaucer(arg0);
            func_80801568_chflysaucer(arg0, 2);
            return;
        }
        if (sp20 == 0xD6 && func_800DA298(0x94)) {
            func_80801034_chflysaucer(arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 6:
        if (sp20 == 0xD6) {
            func_80801034_chflysaucer(arg0);
            func_80801130_chflysaucer((BtIntPtr)arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 2:
        if (sp20 == 0x13C) {
            func_808017D0_chflysaucer(arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 3:
        if (sp20 == 0x124) {
            func_808017D0_chflysaucer(arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 4:
        if (sp20 == 0x13B) {
            func_808017D0_chflysaucer(arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 5:
        if (sp20 == 0x124) {
            func_808017D0_chflysaucer(arg0);
            return;
        }
        func_800FFAB0(arg0);
        return;
    case 1:
        if (sp20 == 0x124) {
            func_800DA3B8(0x6E9, func_800DC298(0.001f) ? 1 : 0);
            func_80801568_chflysaucer(arg0, 2);
        }
        break;
    }
}

void func_80803150_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808009DC_chflysaucer(Actor *, s32);
    void func_808012A4_chflysaucer(Actor *, s32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_8080149C_chflysaucer(arg0);
    func_80801534_chflysaucer(arg0);
    if (!arg0->unk64_19) {
        func_808009DC_chflysaucer(arg0, 0);
    }
    func_808012A4_chflysaucer(arg0, 0);
    func_808021C0_chflysaucer(arg0, sp24, 3);
}

void func_808031C8_chflysaucer(Actor *arg0) {
    BT_IDO_ONLY(u8 func_800D731C(u16);) BT_NATIVE_ONLY(s32 func_800D731C(s32);)
    s32 func_800DBE60(u8, s32, s32);
    u8 sp1F;

    if ((sp1F = func_800D731C(arg0->unk0->unk14)) != 0) {
        func_800DBE60(sp1F, 0, 0);
        func_800DBE60(sp1F, 1, 4);
        func_800DBE60(sp1F, 2, 8);
    }
}

/* extern */

f32 func_80803224_chflysaucer(Actor *arg0) {
    void * func_800AE080(s16 handle);
    f32 func_800F1828(f32*, f32*);
    BtIntPtr func_801039E4(BtIntPtr);
    s32 func_800AE630(void *list, void *skeleton, s32 index, f32 *output);
    u8 *func_800B27E0(u8 *);
    u8 *sp3C;
    f32 sp30[3];
    f32 sp24[3];
    s32 pad;
    BtIntPtr sp1C;

    sp3C = func_800B27E0(func_801039E4((BtIntPtr)arg0->unk0));
    sp1C = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    func_800AE630(sp1C, sp3C, 0x2A, sp30);
    func_800AE630(sp1C, sp3C, 0x2B, sp24);
    BT_NATIVE_ONLY(return) func_800F1828(sp30, sp24);
}

typedef union FlySaucerRenderActor {
    Actor actor;
    struct {
        u8 pad0[0x7A];
        BT_BITFIELD_ORDER(u16 renderMode : 2, u16 remainingFlags : 14);
        BT_BITFIELD_ORDER(u16 remainingFlags : 14, u16 renderMode : 2);
    } flags;
} FlySaucerRenderActor;

void func_8080329C_chflysaucer(FlySaucerRenderActor *arg0, f32 *arg1, f32 *arg2, BtIntPtr arg3) {
    void *func_8008AEDC(void *);
    void func_8008B304(BtIntPtr);
    BtIntPtr func_8008C27C();
    struct ImageStruct;
    struct ImageStruct *func_800D674C(s32);
    s32 func_800D70F8(s32, s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF41C(BtIntPtr);
    void func_800DF440(s32);
    void func_800DF830(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    struct {
        s16 unk0;
        s16 unk2;
        u8 pad4[0xC];
        f32 unk10;
        u8 pad14[8];
        f32 unk1C;
        u8 pad20[4];
        u8 unk24;
    } *sp74;
    struct ImageStruct *sp70;
    struct ImageStruct *sp6C;
    f32 sp60[3];
    f32 sp5C;
    f32 sp50[3];
    struct anctrl_s *sp4C;
    f32 sp40[3];
    struct anctrl_s *sp3C;
    f32 sp30[3];
    struct anctrl_s *sp2C;

    sp74 = func_80100094(&arg0->actor, 0);
    sp70 = func_800D674C(0x829);
    sp6C = func_800D674C(0x82A);
    func_800D70F8(0x829, 1);
    func_800D70F8(0x82A, 1);
    sp5C = func_80803224_chflysaucer(&arg0->actor);
    sp74->unk1C = sp5C;
    func_800EE7F8(sp60, arg2);
    sp60[2] += sp5C;
    switch (sp74->unk24) {
    case 2:
        if (sp6C != NULL) {
            sp4C = func_80104200(sp74->unk0);
            func_800EF6A8(sp50, arg2, 0.0f, 105.0f, 8.0f);
            func_800EF04C(sp50, arg1);
            func_8008B304((BtIntPtr)sp4C);
            func_800DF41C(func_8008C27C(func_8008AEDC(sp4C)));
            func_800DF440(0);
            func_800DF830(arg0->flags.renderMode);
            func_800DE448(sp50, sp60, arg0->actor.scale * 0.95f, NULL, (BtIntPtr)sp6C);
        }
        break;
    case 1:
    case 3:
        if (sp6C != NULL) {
            sp3C = func_80104200(sp74->unk0);
            func_800EF6A8(sp40, arg2, 0.0f, sp74->unk10 + 35.0f, 15.0f);
            func_800EF04C(sp40, arg1);
            func_8008B304((BtIntPtr)sp3C);
            func_800DF41C(func_8008C27C(func_8008AEDC(sp3C)));
            func_800DF440(0);
            func_800DF830(arg0->flags.renderMode);
            func_800DE448(sp40, sp60, arg0->actor.scale * 0.95f, NULL, (BtIntPtr)sp6C);
        }
        break;
    }
    if (sp74->unk24 == 2 && sp70 != NULL) {
        sp2C = func_80104200(sp74->unk2);
        func_800EF6A8(sp30, arg2, 0.0f, 105.0f, 11.0f);
        func_800EF04C(sp30, arg1);
        func_8008B304((BtIntPtr)sp2C);
        func_800DF41C(func_8008C27C(func_8008AEDC(sp2C)));
        func_800DF440(0);
        func_800DF830(arg0->flags.renderMode);
        func_800DE448(sp30, sp60, arg0->actor.scale * 0.95f, NULL, (BtIntPtr)sp70);
    }
    func_800D70F8(0x829, 0);
    func_800D70F8(0x82A, 0);
}

void func_808035C4_chflysaucer(Actor *arg0, Gfx **arg1) {
    void * func_800AE080(s16 handle);
    s32 func_800AE630(void *list, void *skeleton, s32 index, f32 *output);
    u8 *func_800B27E0(u8 *);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF47C(s32, BtIntPtr);
    void func_800DF744(s32, s32);
    void func_800E3BAC(f32 *);
    void func_800E3C30(f32 *);
    void func_800E3CE8(void);
    void func_800E41CC(void);
    void func_800E4208(void);
    int func_800E44FC(void *frame);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    f32 *func_801018D8(Actor *);
    int func_80101970(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    BtIntPtr func_801039E4(BtIntPtr);
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    struct {
        u8 pad0[0xC];
        f32 unkC[3];
        u8 pad18[0xC];
        u8 unk24;
    } *sp44;
    f32 sp38[3];
    u8 *sp34;

    sp44 = func_80100094(arg0, 0);
    func_800DF744(1, 0);
    switch (sp44->unk24) {
    case 2:
        func_800E41CC();
        func_800EFA4C(sp54, 0.0f, 0.0f, 300.0);
        func_800EFD24(sp48);
        func_800E3BAC(sp54);
        func_800E3C30(sp48);
        func_800E3CE8();
        func_800E44FC(arg1);
        func_800EFA4C(sp60, -10.0, -180.0, 0.0f);
        func_800EFA4C(sp6C, 0, -180.0f, 163.0f);
        break;
    case 1:
        func_800EE7F8(sp60, arg0->rotation);
        func_800EE7F8(sp38, arg0->rotation);
        sp38[2] = -sp38[2];
        func_800EF6A8(sp6C, sp38, 0, -180.0f, 0);
        func_800EF04C(sp6C, arg0->position);
        sp60[2] = -sp60[2];
        break;
    case 0:
        func_800DF744(1, 1);
    case 3:
        func_800EE7F8(sp6C, arg0->position);
        func_800EE7F8(sp60, arg0->rotation);
        sp60[2] = -sp60[2];
        break;
    }
    if (!arg0->unk64_20) {
        func_808031C8_chflysaucer(arg0);
    }
    func_80101970(arg0);
    func_800DF47C((BtIntPtr)func_801015D0, (BtIntPtr)arg0);
    func_800DE448(sp6C, sp60, arg0->scale, func_801018D8(arg0), func_8010347C(arg0->unk0));
    sp60[0] -= 5.0f;
    if (arg0->unk7C_12) {
        sp34 = func_800B27E0(func_801039E4((BtIntPtr)arg0->unk0));
        func_8080329C_chflysaucer((FlySaucerRenderActor *)arg0, sp6C, sp60, (BtIntPtr)arg1);
        func_800AE630(func_800AE080(*(s16 *)&arg0->unk0->unk10), sp34, 3, sp44->unkC);
    }
    if (sp44->unk24 == 2) {
        func_800E4208();
        func_800E44FC(arg1);
    }
}

OSThread *chflysaucer_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_80804668_chflysaucer);
}

/* extern */

int func_80803844_chflysaucer(void) {
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    f32 sp1C;

    sp1C = func_800DC0C0();
    if (func_800DA298(0x6E9) != 0) {
        return 2;
    }
    if (sp1C < 0.5f) {
        return 0;
    }
    if (sp1C < 0.8333333f) {
        return 1;
    }
    return 2;
}

/* extern */

void func_808038C4_chflysaucer(Unk80132ED0 *arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4, f32 arg5) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 sp24[3];
    Actor *sp20;

    sp20 = func_80108474(0x2A4, arg1, (s32)(arg2[1] + 180.0f));
    sp24[0] = arg2[0];
    sp24[1] = arg2[1];
    sp24[2] = (f32)arg3 - arg2[2];
    sp20->unk3C = arg0;
    sp20->rotation[0] = -sp24[0];
    sp20->unk79_4 = arg4;
    func_800EF6A8(sp20->position, sp24, 0.0f, 150.0f, 1000.0f);
    func_800EF04C(sp20->position, arg1);
    func_800EE7F8((f32 *)&sp20->actorData[4], arg1);
    sp20->unk58 = arg5;
}

s32 func_808039B8_chflysaucer(BtIntPtr arg0, s32 *arg1, f32 *arg2, s32 *arg3, s32 arg4, f32 arg5)
{
  s32 *p;
  s32 color;
  s32 i;
  s32 angle;
  s32 mode;
  s32 *modep = &arg4;
  Unk80132ED0 *owner = (Unk80132ED0 *) arg0;
  f32 *position = (f32 *) arg1;
 do { if ((*arg3) != (-1)) { mode = *modep; i = 0; p = arg3; do { switch (mode) { case 1: color = func_80803844_chflysaucer(); angle = *p; break; case 2: color = 0; angle = *p; break; case 3: color = 1; angle = *p; break; case 4: color = 2; angle = *p; break; case 5: color = *((s32 *) (((u8 *) (&(*(s32 *)D_808046B0_chflysaucer))) + i)); angle = *p; break; default: angle = *p; break; } func_808038C4_chflysaucer(owner, position, arg2, angle, color, arg5); i += 4; p++; } while ((*p) != (-1)); } } while (0); BT_NATIVE_ONLY(return 0;)
}

void func_80803AF0_chflysaucer(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 func_80800DAC_chflysaucer(Actor *, f32 *, f32 *, f32);
    s32 func_808039B8_chflysaucer(BtIntPtr, s32 *, f32 *, s32 *, s32, f32);
    s32 sp34[3];
    f32 sp28[3];
    s32 sp20[2];

    sp20[0] = *arg0;
    func_80800DAC_chflysaucer(arg0, sp34, sp28, 1000.0f);
    sp28[0] = -sp28[0];
    func_808039B8_chflysaucer(sp20[0], sp34, sp28, &(*(s32 *)D_808046C4_chflysaucer), arg1, arg3);
}

void func_80803B60_chflysaucer(Actor *arg0) {
    s32 func_80103140(Actor *, u32, u16);

    switch (arg0->unk79_4) {
        case 1:
            func_80103140(arg0, 0x826, arg0->unk0->unk16);
            break;
        case 2:
            func_80103140(arg0, 0x827, arg0->unk0->unk16);
            break;
    }
    arg0->scale = 0.3f;
    ((f32 *)arg0->actorData)[3] = 100000000.0f;
}

void func_80803BE8_chflysaucer(s32 arg0) 
{
}
void func_80803BF0_chflysaucer(Actor *arg0, s32 arg1) {
    func_80102424(arg0, arg1);
    if (arg0->unk70_10 == 2) {
        _subaddiefade_entrypoint_3(arg0);
        func_8010A800(arg0, 2);
    }
}

void func_80803C3C_chflysaucer(Actor *arg0) {
    f32 func_800D8FF8(void);
    void _subaddiefade_entrypoint_6(Actor *, s32);

    switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_80803BF0_chflysaucer(arg0, 2);
            }
            break;
        case 2:
            _subaddiefade_entrypoint_6(arg0, -0x3C);
            break;
    }
}

void func_80803CC4_chflysaucer(BtIntPtr arg0, s32 arg1) {
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s32);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    BtIntPtr sp24;
    BtIntPtr temp_a1;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(6);
    temp_a1 = arg0 + 4;
    sp24 = temp_v0;
    func_800BABB8(temp_v0, BT_NATIVE_ONLY((f32 *))(temp_a1), BT_NATIVE_ONLY((f32 *))(temp_a1), BT_DATA_FIELD(1.4f, 0x3FB33333), BT_DATA_FIELD((s16 *)D_808046DC_chflysaucer, &(*(s32 *)D_808046DC_chflysaucer)));
    func_800BA3FC(sp24, arg1);
    func_800BA22C(sp24, 6);
}

s32 func_80803D30_chflysaucer(Actor *arg0, s32 arg1, s32 arg2) {
    void _chscorepoints_entrypoint_2(s32, BtIntPtr, f32 *, s32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_8010A570(Actor *);
    extern s32 D_80127194;
    int sp24[1];
    s32 *sp20;
    s16 *temp_v0;
    BtIntPtr temp_a0;

    switch (arg1) {
        case 0x40:
            sp20 = &arg2;
            sp24[0] = *sp20;
            if (_subaddiefade_entrypoint_0(arg0) >= 0x61) {
                func_80803CC4_chflysaucer((BtIntPtr) arg0, ((s16 *)D_80804704_chflysaucer)[arg0->unk79_4]);
                _chscorepoints_entrypoint_2(arg0->unk79_4 + 1, 0, arg0->position, 1);
                temp_v0 = (s16 *)&D_80127194;
                temp_v0 += 0x21A;
                *temp_v0 = *temp_v0 + arg0->unk79_4 + 1;
                func_80803BF0_chflysaucer(arg0, 2);
                func_8010A570(arg0);
            }
            temp_a0 = sp24[0];
            if (((u16 *)temp_a0)[12] & 1) {
                func_8010114C(temp_a0, 0x98, 0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chflysaucer_entrypoint_2(void)
{
    return (OSThread *) ((u8 *)D_8080470C_chflysaucer);
}

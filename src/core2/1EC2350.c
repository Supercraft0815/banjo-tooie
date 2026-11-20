#include "core2/1EC2350.h"
#include "frame_cache_settings.inc"
struct StateView {
    u8 flags[80];
    s32 times[80];
    s16 slots[80];
    s16 offsets[80];
    u8 padding[0x4EC8 - 0x2D0];
    s32 counts[2];
};

typedef char StateView_size_check[(sizeof(struct StateView) == 0x4ED0) ? 1 : -1];

struct StateView D_8012D690;     

void func_800E8A60(void) {
}

void func_800E8A68(void) {
    FRAME_RETAIL(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) freelist_capacity(s32);)
    FRAME_RETAIL(s32 freelist_is_element_alive(s32, s32);)
    f32 func_800D8FF8(void);
    void *func_800E8CB0(u8);
    void func_800E8DE4(u8 *, f32);
    extern FrameCurveList D_8012D680;
    f32 delta;
    s32 i;

    delta = func_800D8FF8();
    if (D_8012D680 != 0) {
        i = 1;
        if (freelist_capacity(D_8012D680) >= 2) {
            do {
                if (freelist_is_element_alive(D_8012D680, i) != 0) {
                    func_800E8DE4(func_800E8CB0(i), delta);
                }
                i++;
            } while (i < freelist_capacity(D_8012D680));
        }
    }
}

void func_800E8B04(void) {
    FRAME_RETAIL(s32 freelist_free(s32);)
    extern FrameCurveList D_8012D680;
    if (D_8012D680 != 0) {
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

void func_800E8B3C(void) {
    FRAME_RETAIL(BtIntPtr freelist_defrag(BtIntPtr);)
    extern FrameCurveList D_8012D680;
    if (D_8012D680 != 0) {
        D_8012D680 = freelist_defrag(D_8012D680);
    }
}

u8 func_800E8B74(u32 arg0) {
    FRAME_RETAIL(s32 freelist_new(s32, s32);)
    FRAME_RETAIL(void *freelist_next(s32 *, s32 *);)
    BtIntPtr func_800D674C(s32);
    extern void func_800E8CDC(u8);
    extern FrameCurveList D_8012D680;
    s16 *temp;
    s32 index;
    s16 *entry;

    if (D_8012D680 == 0) {
        D_8012D680 = freelist_new(0x50, 2);
    }
    temp = freelist_next(&D_8012D680, &index);
    if (arg0 != 0) {
        entry = temp;
        *entry = *(s16 *)func_800D674C(arg0);
    } else {
        bzero(temp, 0x50);
    }
    func_800E8CDC((u8)index);
    return index;
}

void func_800E8C08(u8 arg0) {
    FRAME_RETAIL(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) freelist_erase(s32, s32);)
    FRAME_RETAIL(s32 freelist_free(s32);)
    FRAME_RETAIL(s32 freelist_used_count(s32);)
    extern FrameCurveList D_8012D680;
    freelist_erase(D_8012D680, arg0);
    if (freelist_used_count(D_8012D680) == 0) {
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

s32 func_800E8C58(u8 arg0) {
    void *func_800E8CB0(u8);
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = func_800E8CB0(arg0);
    var_v1 = (s32) ((f32) *(s16 *)temp_v0 * *(f32 *)(temp_v0 + 0xC));
    if (var_v1 >= *(s16 *)temp_v0) {
        var_v1 = *(s16 *)temp_v0 - 1;
    }
    return var_v1;
}

void *func_800E8CB0(u8 arg0) {
    extern FrameCurveList D_8012D680;
    FRAME_RETAIL(void * freelist_at(void *list, s32 index);)
    return freelist_at(D_8012D680, arg0);
}

void func_800E8CDC(u8 arg0) {
    void *func_800E8CB0(u8);

    (*(f32 *)((s8 *)(func_800E8CB0(arg0)) + (4))) = 0.0f;
    func_800E8D28(arg0, 1.0f);
    func_800E8D5C(arg0, D_80123500, 2U);
}

void func_800E8D28(u8 arg0, f32 arg1) {
    void *func_800E8CB0(u8);
    (*(f32 *)((s8 *)(func_800E8CB0(arg0)) + (8))) = arg1;
}    typedef struct { u8 pad0[0x2]; s16 unk2; } Obj1EC2350_func_800E8D5C_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_800E8D5C(u8 arg0, void *arg1, s16 arg2) {
    void func_800E8E3C(u8 *);
    void *sp1C;
    sp1C = func_800E8CB0(arg0);
    ((Obj1EC2350_func_800E8D5C_sp1C *)sp1C)->unk2 = (s16)arg2;
    rare_memcpy((u8 *)sp1C + 0x10, arg1, (s16)arg2 * 8);
    func_800E8E3C(sp1C);
}

void func_800E8DB0(u8 arg0, s32 arg1) {
    void *func_800E8CB0(u8);
    *(s16 *)func_800E8CB0(arg0) = arg1;
}

void func_800E8DE4(u8 *arg0, f32 arg1) {
    void func_800E8E3C(u8 *);
    f32 temp_f0;
    f32 temp_f2;

    temp_f2 = arg1 / *(f32 *)(arg0 + 8);
    *(f32 *)(arg0 + 4) = *(f32 *)(arg0 + 4) + temp_f2;
    temp_f0 = *(f32 *)(arg0 + 4);
    *(f32 *)(arg0 + 4) = temp_f0 - (f32)(s32)temp_f0;
    func_800E8E3C(arg0);
}                 typedef struct { u8 pad0[0x2]; s16 unk2; f32 unk4; u8 pad8[0x4]; f32 unkC; u8 pad10[0x10]; s32 unk20; s32 unk24; } Obj1EC2350_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800E8E3C(u8 *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    (((Obj1EC2350_arg0 *)arg0)->unkC) = func_800F3780((((Obj1EC2350_arg0 *)arg0)->unk4), arg0 + 0x10, (((Obj1EC2350_arg0 *)arg0)->unk2));
}

void func_800E8E70(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3) {
    void *func_80012EE8(void);
    void *func_80012EF4(void);
    void *func_80012F60(void);
    void *func_80012F6C(void);
    s32 pad;
    OSIoMesg *sp30;

    if (arg3 == 0) {
        osWritebackDCache((void *)arg0, arg2);
        sp30 = func_80012F6C();
        osPiStartDma(sp30, 1, 0, (BtUIntPtr)arg1, (void *)arg0, (u32) arg2, func_80012F60());
        osRecvMesg(func_80012F60(), NULL, 1);
        osInvalDCache((void *)arg0, arg2);
        return;
    }
    osWritebackDCache((void *)arg0, arg2);
    sp30 = func_80012EF4();
    osPiStartDma(sp30, 1, 0, (BtUIntPtr)arg1, (void *)arg0, (u32) arg2, func_80012EE8());
    osRecvMesg(func_80012EE8(), NULL, 1);
    osInvalDCache((void *)arg0, arg2);
}

u8 *func_800E8F68(u8 *arg0) {
    if ((*(s32 *)((s8 *)(arg0) + (0x24))) != (*(s32 *)((s8 *)(arg0) + (0x20)))) {
        return arg0 + 0x20;
    }
    return NULL;
}

void func_800E8F8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800E8E70(BtIntPtr, void *, s32, s32);

    extern struct StateView D_8012D690;
    FRAME_RETAIL(extern s32 D_8012D960;)
    extern s16 D_80132560[];
    extern s32 unknown3_ROM_START;
    s32 index;
    u8 *saved;
    u8 *dest;

    index = (u16)D_80132560[arg1] + arg2;
    func_800E8E70((BtIntPtr)FRAME_VIEW(D_8012D690.padding, &D_8012D960),
                  FRAME_VIEW((void *)(BtUIntPtr)(D_80123524 + (u32)index * 0xD8u), (u8 *)D_80123524 + index * 0xD8),
                  0xD8, arg3);
    dest = (u8 *)(arg0 * 0xD8 + 0x3A8 + (BtIntPtr)&D_8012D690);
    saved = dest;
    rare_memcpy(dest, FRAME_VIEW(D_8012D690.padding, &D_8012D960), 0xD8);
    FRAME_VIEW(*(u32 *)(saved + 0x18) = bank_word(saved + 0x18) + (u32)(BtUIntPtr)&unknown3_ROM_START, *(s32 *)(saved + 0x18) += (BtIntPtr)&unknown3_ROM_START);
}

s32 func_800E9048(void) {
    FRAME_RETAIL(extern s16 D_80131CE0;)

    return FRAME_VIEW((s16)bank_halfword((u8 *)&D_8012D690 + 0x4650), D_80131CE0);
}

s16 func_800E9054(s32 arg0) {
    extern s16 D_80131CF6;
    s32 index = arg0;
    index *= 9;
    index *= 2;
    return FRAME_VIEW((s16)bank_halfword((u8 *)&D_8012D690 + 0x4666 + index), *(s16 *)((u8 *)&D_80131CF6 + index));
}

void func_800E9070(BtIntPtr arg0, s32 arg1) {
    extern struct StateView D_8012D690;
    BtIntPtr offset = arg0 - (BtIntPtr)&D_8012D690;
    u8 *p = (u8 *)&D_8012D690 + ((offset - 0x3A8) / 216);
    *p = *p + 1;
}

void func_800E90A4(BtIntPtr arg0, s32 arg1) {
    extern struct StateView D_8012D690;
    BtIntPtr offset = FRAME_VIEW((u32)arg0 - (u32)(BtUIntPtr)&D_8012D690, arg0 - (BtIntPtr)&D_8012D690);
    u8 *p = (u8 *)&D_8012D690 + ((offset - 0x3A8) / 216);
    *p = *p - 1;
}

u8 *func_800E90D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8001211C(void);
    void func_800E95AC(u32, s32);


    extern struct StateView D_8012D690;
    extern s16 D_80132560[];
    extern u8 D_80132650[];
    s32 index;
    s32 cached;
    s32 lookup;

    lookup = (u16)D_80132560[arg0] + arg1;
    cached = D_80132650[lookup * 2 + arg2];
    if (cached != 0xFF) {
        D_8012D690.times[cached] = func_8001211C();
        return (u8 *)&D_8012D690 + cached * 0xD8 + 0x3A8;
    }
    if (D_8012D690.counts[arg2] >= D_80123514[arg2] - D_8012351C[arg2]) {
        func_800E95AC(0, arg2);
        if (D_8012D690.counts[arg2] >= D_80123514[arg2] - D_8012351C[arg2]) {
            D_8012D690.times[D_8012351C[arg2]] = func_8001211C();
            return &D_8012D690.padding[D_8012351C[arg2] * 0xD8 + 0xD8];
        }
    }
    for (index = D_8012351C[arg2]; index < D_80123514[arg2]; index++) {
        if (D_8012D690.slots[index] == -1) break;
    }
    func_800E8F8C(index, arg0, arg1, arg2);
    D_8012D690.slots[index] = arg0;
    D_8012D690.offsets[index] = arg1;
    D_8012D690.times[index] = func_8001211C();
    (D_8012D690.counts[arg2])++;
    D_80132650[lookup * 2 + arg2] = index;
    return (u8 *)&D_8012D690 + index * 0xD8 + 0x3A8;
}

#ifdef BT_NATIVE // callers use the v0 that func_800E90D8 leaves behind
u8 *func_800E9300(s32 arg0, s32 arg1) { return func_800E90D8(arg0, arg1, 0x1); }
u8 *func_800E9320(s32 arg0, s32 arg1) { return func_800E90D8(arg0, arg1, 0); }
#else
void func_800E9300(s32 arg0,s32 arg1)
{
    func_800E90D8(arg0,arg1,0x1);
}

void func_800E9320(s32 arg0, s32 arg1) {
    func_800E90D8(arg0, arg1, 0);
}
#endif

void func_800E9340(void *arg0, s32 arg1, s32 arg2) {
    void func_800E8E70(BtIntPtr, void *, s32, s32);
    extern struct StateView D_8012D690;
    extern s32 unknown2_ROM_START;
    s32 temp_v0;
    temp_v0 = arg1 * 0x12;
    func_800E8E70((BtIntPtr)arg0, (void *)((BtIntPtr)&unknown2_ROM_START + temp_v0 + 8), 0x12, arg2);
    rare_memcpy((void *)((BtIntPtr)&D_8012D690 + temp_v0 + 0x4658), arg0, 0x12);
}

void *func_800E93AC(s32 arg0) {
    extern struct StateView D_8012D690;
    return (void *) ((arg0 * 0x12) + 0x4658 + (BtIntPtr) &D_8012D690);
}

void func_800E93CC(s32 arg0) {
    void func_800E8E70(BtIntPtr, void *, s32, s32);
    FRAME_RETAIL(extern s16 D_80131CE0;)

    extern s32 unknown2_ROM_START;
    u8 *sp1C[2];

    sp1C[1] = (u8 *)&unknown2_ROM_START;
    func_800E8E70((BtIntPtr)FRAME_VIEW((u8 *)&D_8012D690 + 0x4650, &D_80131CE0), (void *)sp1C[1], 8, arg0);
    D_80123524 = (FRAME_VIEW((s16)bank_halfword((u8 *)&D_8012D690 + 0x4650), D_80131CE0) * 0x12 + 0xB) & ~3;
    D_80123524 += (BtIntPtr)sp1C[1];
}

void func_800E9438(s32 arg0) {
    void *heap_alloc(s32);
    void heap_free(void *);
    extern struct StateView D_8012D690;
    extern s16 D_80132560[];
    s32 var_s1;
    s32 var_s0;
    s16 *temp_s3;

    var_s1 = 0;
    temp_s3 = heap_alloc(0x12);
    var_s0 = 0;
    if (FRAME_VIEW(func_800E9048(), *(s16 *)((u8 *)&D_8012D690 + 0x4650)) > 0) {
        do {
            func_800E9340(temp_s3, var_s0, arg0);
            D_80132560[var_s0] = var_s1;
            var_s0++;
            var_s1 += FRAME_VIEW((s16)bank_halfword(temp_s3 + 7), temp_s3[7]);
        } while (var_s0 < FRAME_VIEW(func_800E9048(), *(s16 *)((u8 *)&D_8012D690 + 0x4650)));
    }
    heap_free(temp_s3);
}

void func_800E94E4(void) {
    extern u8 D_80132650[];
    struct StateView *data;
    s32 i;
    data = &D_8012D690;
    for (i = 0; i < 79; i++) {
        data->flags[i] = 0;
        data->times[i] = 0;
        data->slots[i] = -1;
        data->offsets[i] = -1;
    }
    for (data->counts[0] = 0, data->counts[1] = 0, i = 0; i < 0x3AC; i++) {
        D_80132650[i * 2] = 0xFF;
        D_80132650[i * 2 + 1] = 0xFF;
    }
}

void func_800E9574(void) {
    void func_800E93CC(s32);
    void func_800E9438(s32);

    func_800E94E4();
    func_800E93CC(0);
    func_800E9438(0);
    D_80123510 = 1;
}

void func_800E95AC(u32 arg0, s32 arg1) {
    s32 func_8001211C(void);


    extern s16 D_80132560[];
    extern u8 D_80132650[];
    extern struct StateView D_8012D690;
    s32 temp_a0;
    struct StateView *cursor;
    s32 temp_t5;
    s16 temp_a2;
    s32 var_a3;
    u8 *temp_v1_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_ra;
    u32 empty_slot;

    temp_v0 = func_8001211C();
    temp_t5 = arg1 * 4;
    temp_v1 = *(s32 *)((u8 *)D_8012351C + temp_t5);
    temp_ra = *(s32 *)((u8 *)D_80123514 + temp_t5);
    empty_slot = -1;
    for (var_a3 = temp_v1; var_a3 < temp_ra; var_a3++) {
            if (empty_slot == (u32)(temp_a2 = D_8012D690.slots[var_a3])) continue;
            if (D_8012D690.flags[var_a3]) continue;
            if (arg0 < (u32)(temp_v0 - D_8012D690.times[var_a3])) {
                temp_a0 = (u16)D_80132560[temp_a2] + D_8012D690.offsets[var_a3];
                D_80132650[temp_a0 * 2 + arg1] = 0xFF;
                D_8012D690.slots[var_a3] = empty_slot;
                D_8012D690.counts[arg1] -= 1;
            }
    }
}

/* extern */

void func_800E96B0(s32 arg0) {
    void func_800E95AC(u32, s32);
    func_800E95AC(200, arg0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
FrameCurveList D_8012D680 BT_DATA(4, bss_core2bss2_1, 0xD40);
s16 D_80132560 [ 120 ] BT_DATA(16, bss_core2bss2_1_reset_tail, 0x0);
u8 D_80132650 [ 1880 ] BT_DATA(4, bss_core2bss2_1_reset_tail, 0xF0);
#endif

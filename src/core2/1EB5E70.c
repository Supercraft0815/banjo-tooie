#include "core2/1EB5E70.h"

s32 D_8012C850[60];

typedef void (*GeoCommandFunction)(s32, u8 *);
extern GeoCommandFunction *D_8012CF8C;

typedef struct {
    u32 header[2];
    Gfx commands[1];
} DisplayListView;

extern DisplayListView *D_8012C960;

extern s32 D_8012C824;
extern s32 D_8012C940;

void func_800DC580(void *arg0, void *arg1) {
    extern f32 D_8012C948;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg1) + (0))) * D_8012C948);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) * D_8012C948);
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg1) + (8))) * D_8012C948);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DC5BC.s")

void func_800DC61C(s32 arg0, s32 arg1) {
}
void func_800DC628(s32 arg0, s32 arg1) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DC634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DC740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DC84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DC958.s")

void func_800DCB58(s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800EF3DC(s32 *, s32 *);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    extern s32 D_8012CE98;
    extern f32 D_8012CEFC;
    extern s32 D_8012CF00;
    extern s32 D_8012CF10;
    extern s32 D_8012CF20;
    f32 temp_f0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;

    func_800DC580(&D_8012CF10, arg1 + 8);
    func_800DC580(&D_8012CF20, arg1 + 0x14);
    func_800EFB24(&D_8012CF00, &D_8012CF20, &D_8012CF10);
    func_800EF3DC(&D_8012CF10, &D_8012CE98);
    temp_f0 = -(((f32 *)&D_8012CF00)[0] * ((f32 *)&D_8012CF10)[0]
              + ((f32 *)&D_8012CF00)[1] * ((f32 *)&D_8012CF10)[1]
              + ((f32 *)&D_8012CF00)[2] * ((f32 *)&D_8012CF10)[2]);
    if ((*(u8 *)((s8 *)(arg1) + (0x21))) & 1) {
        if (temp_f0 >= 0.0f) {
            temp_v0 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0 != 0) {
                D_8012CEFC = temp_f0;
                func_800DE2A4(arg0, arg1 + temp_v0);
                return;
            }
        }
        D_8012CEFC = temp_f0;
        if (temp_f0 < 0.0f) {
            temp_v0_2 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_2 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_2);
            }
        }
    } else {
        D_8012CEFC = temp_f0;
        if (temp_f0 >= 0.0f) {
            temp_v0_3 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_3 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_3);
            }
            temp_v0_4 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0_4 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_4);
            }
        } else {
            temp_v0_5 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0_5 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_5);
            }
            temp_v0_6 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_6 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_6);
            }
        }
    }
}

void func_800DCD10(s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800EF3DC(s32 *, s32 *);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    extern s32 D_8012CE98;
    extern f32 D_8012CF2C;
    extern s32 D_8012CF30;
    extern s32 D_8012CF40;
    extern s32 D_8012CF50;
    f32 temp_f0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;

    func_800DC5BC(&D_8012CF40, arg1 + 8);
    func_800DC5BC(&D_8012CF50, arg1 + 0x14);
    func_800EFB24(&D_8012CF30, &D_8012CF50, &D_8012CF40);
    func_800EF3DC(&D_8012CF40, &D_8012CE98);
    temp_f0 = -(((f32 *)&D_8012CF30)[0] * ((f32 *)&D_8012CF40)[0]
              + ((f32 *)&D_8012CF30)[1] * ((f32 *)&D_8012CF40)[1]
              + ((f32 *)&D_8012CF30)[2] * ((f32 *)&D_8012CF40)[2]);
    if ((*(u8 *)((s8 *)(arg1) + (0x21))) & 1) {
        if (temp_f0 >= 0.0f) {
            temp_v0 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0 != 0) {
                D_8012CF2C = temp_f0;
                func_800DE2A4(arg0, arg1 + temp_v0);
                return;
            }
        }
        D_8012CF2C = temp_f0;
        if (temp_f0 < 0.0f) {
            temp_v0_2 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_2 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_2);
            }
        }
    } else {
        D_8012CF2C = temp_f0;
        if (temp_f0 >= 0.0f) {
            temp_v0_3 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_3 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_3);
            }
            temp_v0_4 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0_4 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_4);
            }
        } else {
            temp_v0_5 = (*(s32 *)((s8 *)(arg1) + (0x24)));
            if (temp_v0_5 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_5);
            }
            temp_v0_6 = (*(s16 *)((s8 *)(arg1) + (0x22)));
            if (temp_v0_6 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_6);
            }
        }
    }
}

void func_800DCEC8(Gfx **gfx, u8 *data) {
    extern s32 D_8012C820;
    struct Command { u8 padding[8]; s32 mode; };
    struct Command *cmd = (struct Command *) data;

    switch (cmd->mode) {
        case 1:
            gSPDisplayList((*gfx)++, D_8012C820 + 0x80000068);
            break;
        case 2:
            gSPDisplayList((*gfx)++, D_8012C820 + 0x80000000);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DCF48.s")

void func_800DD024(Gfx **gfx, u8 *data) {
    struct Command { u8 padding[8]; s16 index; };
    struct Command *cmd = (struct Command *)data;
    Gfx *gfx_sub_list;

    gfx_sub_list = &D_8012C960->commands[cmd->index];
    gSPDisplayList((*gfx)++, osVirtualToPhysical(gfx_sub_list));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD07C.s")

void func_800DD19C(s32 arg0, u8 *commands) {
    void func_800DE2A4(s32, u8 *);
    commands += *(s32 *)(commands + 8);
    func_800DE2A4(arg0, commands);
}

void func_800DD1C0(Gfx **gfx, u8 *data) {
    struct Command { u8 padding[0xA]; s16 index; };
    gSPDisplayList((*gfx)++, osVirtualToPhysical(&D_8012C960->commands[((struct Command *)data)->index]));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD37C.s")

void func_800DD410(s32 arg0, u8 *arg1) {
    void func_800193C4(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800DC028(s32, s32, s32);
    void mlMtxPop(void);
    extern s32 D_8012C844;
    extern s32 D_8012C968;
    extern s32 D_8012CE58;
    struct Command { u8 padding[8]; s16 index; s16 anim_mtx_id; f32 point[3]; };
    f32 sp20[4];

    if (D_8012C844 != 0) {
        if (D_8012C968 != 0) {
            func_80019AA0(&D_8012CE58, func_800ADE2C(D_8012C968, ((struct Command *)arg1)->anim_mtx_id));
            func_800193C4(sp20, ((struct Command *)arg1)->point);
            mlMtxPop();
        } else {
            func_800193C4(sp20, ((struct Command *)arg1)->point);
        }
        func_800DC028(D_8012C844, ((struct Command *)arg1)->index, sp20);
    }
}

/* extern */

void func_800DD4AC(s32 arg0, u8 *arg1) {
    extern s32 D_8012C844;
    extern f32 D_8012C948;
    void func_800EFA20(void *arg0, void *arg1, f32 arg2);
    void func_800DC028(s32, s32, s32);
    f32 sp18[4];

    if (D_8012C844 != 0) {
        func_800EFA20(sp18, arg1 + 0xC, D_8012C948);
        func_800DC028(D_8012C844, (*(s16 *)((s8 *)(arg1) + (8))), sp18);
    }
}

void func_800DD504(s32 arg0, u8 *arg1) { extern s32 D_8012C844; extern f32 D_8012C948; void func_800EF04C(f32[3], f32[3]); void func_800EFA20(void *, void *, f32); void func_800DC028(s32, s32, s32); extern f32 *D_8012C94C; f32 sp18[4]; if (D_8012C844 != 0) { func_800EFA20(sp18, arg1 + 0xC, D_8012C948); func_800EF04C(sp18, D_8012C94C); func_800DC028(D_8012C844, (*(s16 *)((s8 *)(arg1) + (8))), sp18); } }
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DD998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DDB38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DDC28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DDD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DDDC4.s")

void func_800DDF14(volatile s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF334(f32 *, f32);
    extern f32 D_8012C948;
    f32 sp2C[3];
    f32 radius;
    s32 offset;
    s32 model;

    func_800EE88C(sp2C, (s16 *)(arg1 + 8));
    func_800EF334(sp2C, D_8012C948);
    radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948;
    if (func_800E3E8C(sp2C, radius) == 0) {
        return;
    }
    offset = *(s16 *)(arg1 + 0x10);
    model = arg0;
    if (offset == 0) {
        return;
    }
    arg1 += offset; func_800DE2A4(model, arg1);
}

void func_800DDFA0(volatile s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    extern f32 D_8012C948;
    extern f32 *D_8012C94C;
    f32 sp2C[3];
    f32 radius;
    s32 offset;
    s32 model;

    func_800EE88C(sp2C, (s16 *)(arg1 + 8));
    func_800EF334(sp2C, D_8012C948);
    func_800EF04C(sp2C, D_8012C94C);
    radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948;
    if (func_800E3E8C(sp2C, radius) == 0) {
        return;
    }
    offset = *(s16 *)(arg1 + 0x10);
    model = arg0;
    if (offset == 0) {
        return;
    }
    arg1 += offset; func_800DE2A4(model, arg1);
}

void func_800DE03C(s32 arg0, u8 *arg1) {
    struct camera_command { u8 pad[12]; unsigned int zone : 8; };
    void func_800DE2A4(s32, u8 *);
    s32 _dbzone_entrypoint_0(s32, u8 *, u8, u8 *);
    s32 _glzone_entrypoint_3(s32, s32);
    extern s32 D_8012C848;
    extern s32 D_8012C970;
    s32 temp_v0;

    temp_v0 = _dbzone_entrypoint_0(D_8012C970, arg1 + 0xD, (*(u8 *)((s8 *)(arg1) + (0xA))), arg1);
    if (((temp_v0 == 0) && ((*(u8 *)((s8 *)(arg1) + (0xB))) & 1)) || ((temp_v0 != 0) && ((*(u8 *)((s8 *)(arg1) + (0xB))) & 2))) {
        if (D_8012C848 != 0) {
            if (((struct camera_command *)arg1)->zone != 0) {
                _glzone_entrypoint_3(D_8012C848, ((struct camera_command *)arg1)->zone);
            }
        }
        arg1 += *(s16 *)(arg1 + 8);
        func_800DE2A4(arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DE0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DE1C4.s")

void func_800DE2A4(s32 model, u8 *commands) {
    s32 next;
    while (1) {
        D_8012CF8C[*(s32 *)commands](model, commands);
        next = *(s32 *)(commands + 4);
        if (next == 0) {
            return;
        }
        commands += next;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DE318.s")

typedef struct {
    Gfx* gfx;
    Mtx* mtx;
} GraphicsBuffers;

GraphicsBuffers* func_800A7180();

void* func_800DE498(GraphicsBuffers*, f32*, f32*, f32, f32*, s32);

// modelRender_draw?
void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4) {
    return func_800DE498(func_800A7180(), position, arg1, scale, arg3, arg4);
}

// the real modelRender_draw?
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DE498.s")

s32 func_800DF324()
{
    return D_8012C824;
}

void * func_800DF330(void) {
    extern u8 D_8012C840;
    return &D_8012C840;
}

s32 func_800DF33C(s32 arg0) {
    return ((s32 *)&D_8012C850)[arg0];
}

s32 func_800DF350()
{
    return D_8012C940;
}

void func_800DF35C(void) {
    void func_800ADF5C(void *);
    void func_8010E390(void);
    extern u8 D_8012C840;
    func_800ADF5C(*(s32 *)&D_8012C840);
    *(s32 *)&D_8012C840 = 0;
    func_8010E390();
}

void func_800DF38C(void) {
    typedef struct { u8 buffer[0x400]; u8 *current; u8 *end; } LookAtBuffer;
    extern LookAtBuffer D_8012CA40;
    extern f32 D_8012CE48[3];
    extern u8 D_8012C840;
    s32 func_800ADF98(void);
    s32 func_8010E334(void);
    void func_800EFD24(f32 *);
    LookAtBuffer *buffer;
    void func_800DE318(void);
    func_800DE318();
    buffer = &D_8012CA40;
    buffer->current = buffer->buffer;
    buffer->end = buffer->current + sizeof(buffer->buffer);
    func_800EFD24(D_8012CE48);
    *(s32 *)&D_8012C840 = func_800ADF98();
    func_8010E334();
}

void func_800DF3E0(void) {
    s32 i;
    for(i = 0; i < 0x3C; i++){
        D_8012C850[i] = 0;
    }
}

void func_800DF410(s32 arg0) {
    extern s32 D_8012C9A4;
    *(s32 *)((u8 *)&D_8012C9A4 + 0) = arg0;
}

void func_800DF41C(s32 arg0) {
    *(s32 *)((u8 *)&D_8012C824 + 0) = arg0;
}

f32 func_800DF428(f32 arg0) {
    extern f32 D_8012C82C;
    f32 temp_f2;

    temp_f2 = D_8012C82C;
    D_8012C82C = arg0;
    return temp_f2;
}

void func_800DF440(s32 arg0) {
    extern s32 D_8012C828;
    if (arg0 != 0) {
        D_8012C828 = 1;
        return;
    }
    D_8012C828 = 0;
}

void func_800DF464(f32 arg0) {
    extern f32 D_8012C830;
    *(f32 *)((u8 *)&D_8012C830 + 0) = arg0;
}

void func_800DF470(s32 arg0) {
    extern s32 D_8012C834;
    *(s32 *)((u8 *)&D_8012C834 + 0) = arg0;
}

void func_800DF47C(s32 arg0, s32 arg1) {
    extern s32 D_8012C9A8;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (0))) = arg0;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (4))) = arg1;
}

void func_800DF490(s32 arg0, s32 arg1) {
    extern s32 D_8012C9A8;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (8))) = arg0;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (0xC))) = arg1;
}

void func_800DF4A4(s32 arg0)
{

    D_8012C960 = (DisplayListView *)arg0;
}

void func_800DF4B0(s32 arg0) {
    extern s32 D_80123198[];
    D_8012CF8C = (GeoCommandFunction *)D_80123198[arg0];
}

void func_800DF4CC(s32 arg0) {
    s32 func_800EE7F8(s32 *, s32);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9BC;
    D_8012C9B8 = 1;
    func_800EE7F8(&D_8012C9BC, arg0);
}

void func_800DF500(f32 arg0, f32 arg1, f32 arg2) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9BC;
    D_8012C9B8 = 2;
    func_800EFA4C((f32 *)&D_8012C9BC, arg0, arg1, arg2);
}

void func_800DF540(s32 arg0) {
    s32 func_800F293C(s32 *, s32);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9C8;
    D_8012C9B8 = 3;
    func_800F293C(&D_8012C9C8, arg0);
}

void func_800DF574(s32 arg0) {
    extern s16 D_8012CA38;
    *(s16 *)((u8 *)&D_8012CA38 + 0) = arg0;
}

void func_800DF580(void *arg0, void *arg1) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    D_8012C83C = 1;
    (*(s32 *)((s8 *)(&D_8012C988) + (0x10))) = (s32) (*(s32 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x14))) = (s32) (*(s32 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x18))) = (s32) (*(s32 *)((s8 *)(arg0) + (8)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x1C))) = (s32) (*(s32 *)((s8 *)(arg0) + (0xC)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(&D_8012C988) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(&D_8012C988) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0xC))) = (s32) (*(s32 *)((s8 *)(arg1) + (0xC)));
}

void func_800DF5D8(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    D_8012C83C = 2;
    if ((s32) arg0 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x10))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x10))) = arg0;
    }
    if ((s32) arg1 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x14))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x14))) = arg1;
    }
    if ((s32) arg2 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x18))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x18))) = arg2;
    }
    func_800DF410(arg3);
}

void func_800DF660(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 D_8012C838;
    extern s32 D_8012CA08;
    if ((arg1 == 0) && (arg2 == 0)) {
        D_8012C838 = 0;
        return;
    }
    D_8012C838 = 1;
    (*(s32 *)((s8 *)(&D_8012CA08) + (0))) = arg1;
    (*(s32 *)((s8 *)(&D_8012CA08) + (4))) = arg2;
    (*(s8 *)((s8 *)(&D_8012CA08) + (9))) = (s8) arg0;
    func_800DF410(arg3);
}

void func_800DF6BC(s32 arg0, s32 arg1) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    s32 var_v0;

    D_8012C83C = 3;
    if (arg0 >= 0x100) {
        var_v0 = 0xFF;
    } else {
        var_v0 = arg0;
    }
    (*(s32 *)((s8 *)(&D_8012C988) + (0xC))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (8))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (4))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (0))) = var_v0;
    func_800DF410(arg1);
}

void func_800DF714(s32 arg0)
{
    extern s32 D_8012C980;

    D_8012C980 = arg0;
}

void func_800DF720(s32 arg0)
{
    extern s32 D_8012C974;

    D_8012C974 = arg0;
}

void func_800DF72C(s32 arg0)
{
    extern s32 D_8012C968;

    D_8012C968 = arg0;
}

void func_800DF738(s32 arg0)
{
    extern s32 D_8012C844;

    D_8012C844 = arg0;
}

void func_800DF744(s32 arg0, s32 arg1) {
    D_8012C850[arg0] = arg1;
}

void func_800DF758(s32 *arg0) {
    s32 i;

    for (i = 1; i < 60; i++) {
        D_8012C850[i] = arg0[i];
    }
}

void func_800DF7C4(s32 arg0, s32 arg1) {
    D_8012C850[arg0] = -arg1;
}

void func_800DF7DC(s32 arg0)
{
    extern s32 D_8012C95C;

    D_8012C95C = arg0;
}

void func_800DF7E8(s8 arg0) {
    extern s8 D_8012C96C;
    D_8012C96C = arg0;
}

void func_800DF7F8(s32 arg0, f32 arg1, f32 arg2) {
    extern s32 D_8012CA18;
    (*(s32 *)((s8 *)(&D_8012CA18) + (0))) = arg0;
    (*(f32 *)((s8 *)(&D_8012CA18) + (4))) = arg1;
    (*(f32 *)((s8 *)(&D_8012CA18) + (8))) = arg2;
}

void func_800DF818(s32 arg0)
{
    extern s32 D_8012C964;

    D_8012C964 = arg0;
}

void func_800DF824(s32 arg0)
{
    extern s32 D_8012C978;

    D_8012C978 = arg0;
}

void func_800DF830(s32 arg0)
{
    extern s32 D_8012CA28;

    D_8012CA28 = arg0;
}

void func_800DF83C(s32 arg0)
{
    extern s32 D_8012C848;

    D_8012C848 = arg0;
}

void func_800DF848(s32 arg0, s32 arg1) {
    extern s32 D_80122DC8[];
    extern s32 D_8012CA28;
    D_8012CA28 = 4;
    D_80122DC8[D_8012CA28 * 2] = arg0;
    D_80122DC8[D_8012CA28 * 2 + 1] = arg1;
}

void func_800DF874(void) {
    extern u8 D_8012C840;
    u8 *temp = *(u8 **) &D_8012C840;
    if (temp != 0) {
        *(s32 *) &D_8012C840 = func_800AE5F0(temp);
    }
    (void) func_8010E358();
}

s32 func_800DF8B4(s32 *arg0) {
    return arg0[7];
}

s32 func_800DF8BC(s32 *arg0) {
    return arg0[11];
}

f32 func_800DF8C4(f32 *arg0) {
    return arg0[0];
}

s32 func_800DF8CC(s32 *arg0) {
    return arg0[12];
}

int func_800DF8D4(s32 *arg0) {
    return arg0[8] != 0 && arg0[13] == 0;
}

s32 func_800DF8F8(s32 *arg0) {
    return arg0[1];
}

/* extern */

void func_800DF900(u8 *arg0) {
    void mlMtx_push_translation(f32 x, f32 y, f32 z);
    s32 func_8001980C(s32, s32, s32, s32);
    mlMtx_push_translation(0.0f, 0.0f, 0.0f);
    func_8001980C((*(s32 *)((s8 *)(arg0) + (4))), (*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (0xC))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5E70/func_800DF944.s")

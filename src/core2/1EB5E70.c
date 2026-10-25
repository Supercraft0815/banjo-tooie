#include "core2/1EB5E70.h"

typedef struct {
    s32 header;
    s32 geometry;
    s16 textures;
    s16 flags;
    s32 display_list;
    s32 vertices;
    s32 unk14;
    s32 animation;
    s32 unk1C;
    s32 zones;
    s32 unk24;
    s32 animated_vertices;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 normals;
} ModelData;

typedef struct {
    LookAt buffer[32];
    LookAt *current;
    LookAt *end;
    f32 position[3];
} LookAtBuffer;

s32 D_8012C850[60];

typedef void (*GeoCommandFunction)(s32, u8 *);
extern GeoCommandFunction *D_8012CF8C;

typedef struct {
    u32 header[2];
    Gfx commands[1];
} DisplayListView;

typedef struct {
    f32 scale;
    f32 *position;
    f32 *rotation;
    f32 *origin;
    f32 *extra_rotation;
    u8 *textures;
    DisplayListView *display_list;
    u8 *vertices;
    u8 *animation;
    u8 texture_animation;
    u8 pad25[3];
    u8 *zones;
    s32 unk2C;
    u8 *normals;
    u8 *animated_vertices;
    Mtx *matrices;
} RenderData;

extern DisplayListView *D_8012C960;

extern s32 D_8012C824;
extern s32 D_8012C940;

void func_800DC580(void *arg0, void *arg1) {
    extern RenderData D_8012C948;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg1) + (0))) * D_8012C948.scale);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) * D_8012C948.scale);
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg1) + (8))) * D_8012C948.scale);
}

void func_800DC5BC(void *arg0, void *arg1) {
    extern RenderData D_8012C948;
    ((f32 *)arg0)[0] = ((f32 *)arg1)[0] * D_8012C948.scale + (*(f32 **)((u8 *)&D_8012C948 + 4))[0];
    ((f32 *)arg0)[1] = ((f32 *)arg1)[1] * D_8012C948.scale + (*(f32 **)((u8 *)&D_8012C948 + 4))[1];
    ((f32 *)arg0)[2] = ((f32 *)arg1)[2] * D_8012C948.scale + (*(f32 **)((u8 *)&D_8012C948 + 4))[2];
}

void func_800DC61C(s32 arg0, s32 arg1) {
}
void func_800DC628(s32 arg0, s32 arg1) {
}
struct GeoCommand800DC634 {
    u32 header[2];
    s16 branch_offset;
    s16 do_pitch_rotate;
    f32 position[3];
};

void func_800DC634(s32 model, struct GeoCommand800DC634 *cmd) {
    void func_800193C4(f32 *, f32 *);
    void func_800DE2A4(s32, u8 *);
    void mlMtxApply(Mtx *);
    void mlMtxPop(void);
    void mlMtxRotPitch(f32);
    void mlMtxRotYaw(f32);
    void mlMtxScale(f32);
    void mlMtxTranslate(f32, f32, f32);
    void mlMtx_push_translation(f32, f32, f32);
    extern RenderData D_8012C948;
    extern f32 D_8012CEA8;
    extern f32 D_8012CEAC;
    struct ModelContext {
        Gfx *gfx;
        Mtx *mtx;
    };
    struct ModelContext *context = (struct ModelContext *)model;
    f32 transformed_pos[3];
    Gfx *gfx;

    if (cmd->branch_offset) {
        func_800193C4(transformed_pos, cmd->position);
        mlMtx_push_translation(transformed_pos[0], transformed_pos[1], transformed_pos[2]);
        mlMtxRotYaw(D_8012CEAC);
        if (!cmd->do_pitch_rotate) {
            mlMtxRotPitch(D_8012CEA8);
        }
        mlMtxScale(D_8012C948.scale);
        mlMtxTranslate(-cmd->position[0], -cmd->position[1], -cmd->position[2]);
        mlMtxApply(context->mtx);
        gfx = context->gfx++;
        gfx->words.w0 = 0xDA380002;
        gfx->words.w1 = (u32)context->mtx;
        context->mtx++;
        func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
        mlMtxPop();
        gSPPopMatrix(context->gfx++, G_MTX_MODELVIEW);
    }
}

void func_800DC740(s32 model, struct GeoCommand800DC634 *cmd) {
    void func_800DE2A4(s32, u8 *);
    void mlMtxApply(Mtx *);
    void mlMtxPop(void);
    void mlMtxRotPitch(f32);
    void mlMtxRotYaw(f32);
    void mlMtxScale(f32);
    void mlMtxTranslate(f32, f32, f32);
    void mlMtx_push_translation(f32, f32, f32);
    extern RenderData D_8012C948;
    extern f32 D_8012CEA8;
    extern f32 D_8012CEAC;
    struct ModelContext {
        Gfx *gfx;
        Mtx *mtx;
    };
    struct ModelContext *context = (struct ModelContext *)model;
    f32 transformed_pos[3];
    Gfx *gfx;

    if (cmd->branch_offset) {
        func_800DC580(transformed_pos, cmd->position);
        mlMtx_push_translation(transformed_pos[0], transformed_pos[1], transformed_pos[2]);
        mlMtxRotYaw(D_8012CEAC);
        if (!cmd->do_pitch_rotate) {
            mlMtxRotPitch(D_8012CEA8);
        }
        mlMtxScale(D_8012C948.scale);
        mlMtxTranslate(-cmd->position[0], -cmd->position[1], -cmd->position[2]);
        mlMtxApply(context->mtx);
        gfx = context->gfx++;
        gfx->words.w0 = 0xDA380002;
        gfx->words.w1 = (u32)context->mtx;
        context->mtx++;
        func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
        mlMtxPop();
        gSPPopMatrix(context->gfx++, G_MTX_MODELVIEW);
    }
}

void func_800DC84C(s32 model, struct GeoCommand800DC634 *cmd) {
    void func_800DE2A4(s32, u8 *);
    void mlMtxApply(Mtx *);
    void mlMtxPop(void);
    void mlMtxRotPitch(f32);
    void mlMtxRotYaw(f32);
    void mlMtxScale(f32);
    void mlMtxTranslate(f32, f32, f32);
    void mlMtx_push_translation(f32, f32, f32);
    extern RenderData D_8012C948;
    extern f32 D_8012CEA8;
    extern f32 D_8012CEAC;
    struct ModelContext {
        Gfx *gfx;
        Mtx *mtx;
    };
    struct ModelContext *context = (struct ModelContext *)model;
    f32 transformed_pos[3];
    Gfx *gfx;

    if (cmd->branch_offset) {
        func_800DC5BC(transformed_pos, cmd->position);
        mlMtx_push_translation(transformed_pos[0], transformed_pos[1], transformed_pos[2]);
        mlMtxRotYaw(D_8012CEAC);
        if (!cmd->do_pitch_rotate) {
            mlMtxRotPitch(D_8012CEA8);
        }
        mlMtxScale(D_8012C948.scale);
        mlMtxTranslate(-cmd->position[0], -cmd->position[1], -cmd->position[2]);
        mlMtxApply(context->mtx);
        gfx = context->gfx++;
        gfx->words.w0 = 0xDA380002;
        gfx->words.w1 = (u32)context->mtx;
        context->mtx++;
        func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
        mlMtxPop();
        gSPPopMatrix(context->gfx++, G_MTX_MODELVIEW);
    }
}

void func_800DC958(s32 arg0, u8 *arg1) {
    void func_800193C4(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800DE2A4(s32, u8 *);
    s32 func_800EF3DC(s32 *, s32 *);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    void mlMtxPop(void);
    extern s32 D_8012C968;
    extern s32 D_8012CE58;
    extern s32 D_8012CE98;
    extern f32 D_8012CEC8;
    extern s32 D_8012CED0;
    extern s32 D_8012CEE0;
    extern s32 D_8012CEF0;
    f32 *diff;
    f32 *pos;
    f32 temp_f0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;

    if (arg1[0x21] & 2) {
        func_80019AA0(&D_8012CE58, func_800ADE2C(D_8012C968, *(s8 *)(arg1 + 0x20)));
    }
    func_800193C4((f32 *)&D_8012CEE0, (f32 *)(arg1 + 8));
    func_800193C4((f32 *)&D_8012CEF0, (f32 *)(arg1 + 0x14));
    if (arg1[0x21] & 2) {
        mlMtxPop();
    }
    func_800EFB24(&D_8012CED0, &D_8012CEF0, &D_8012CEE0);
    func_800EF3DC(&D_8012CEE0, &D_8012CE98);
    goto transformed;
transformed:
    diff = (f32 *)&D_8012CED0;
    pos = (f32 *)&D_8012CEE0;
    temp_f0 = -(diff[0] * pos[0] + diff[1] * pos[1] + diff[2] * pos[2]);
    if (arg1[0x21] & 1) {
        if (temp_f0 >= 0.0f) {
            temp_v0 = *(s32 *)(arg1 + 0x24);
            if (temp_v0 != 0) {
                D_8012CEC8 = temp_f0;
                func_800DE2A4(arg0, arg1 + temp_v0);
                return;
            }
        }
        D_8012CEC8 = temp_f0;
        if (temp_f0 < 0.0f) {
            temp_v0_2 = *(s16 *)(arg1 + 0x22);
            if (temp_v0_2 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_2);
            }
        }
    } else {
        D_8012CEC8 = temp_f0;
        if (temp_f0 >= 0.0f) {
            temp_v0_3 = *(s16 *)(arg1 + 0x22);
            if (temp_v0_3 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_3);
            }
            temp_v0_4 = *(s32 *)(arg1 + 0x24);
            if (temp_v0_4 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_4);
            }
        } else {
            temp_v0_5 = *(s32 *)(arg1 + 0x24);
            if (temp_v0_5 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_5);
            }
            temp_v0_6 = *(s16 *)(arg1 + 0x22);
            if (temp_v0_6 != 0) {
                func_800DE2A4(arg0, arg1 + temp_v0_6);
            }
        }
    }
}

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

void func_800DCF48(s32 model, u8 *data) {
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800DE2A4(s32, u8 *);
    void mlMtxApply(Mtx *);
    void mlMtxPop(void);
    extern s32 D_8012C968;
    extern s32 D_8012CE58;
    struct ModelContext {
        Gfx *gfx;
        Mtx *mtx;
    };
    struct ModelContext *context = (struct ModelContext *)model;
    struct Command {
        u8 padding[8];
        u8 branch_offset;
        s8 matrix_id;
    };
    struct Command *cmd = (struct Command *)data;

    if (D_8012C968) {
        func_80019AA0(&D_8012CE58, func_800ADE2C(D_8012C968, cmd->matrix_id));
        mlMtxApply(context->mtx);
        gSPMatrix(context->gfx++, context->mtx++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }
    if (cmd->branch_offset) {
        func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
    }
    if (D_8012C968) {
        mlMtxPop();
        gSPPopMatrix(context->gfx++, G_MTX_MODELVIEW);
    }
}

void func_800DD024(Gfx **gfx, u8 *data) {
    struct Command { u8 padding[8]; s16 index; };
    struct Command *cmd = (struct Command *)data;
    Gfx *gfx_sub_list;

    gfx_sub_list = &D_8012C960->commands[cmd->index];
    gSPDisplayList((*gfx)++, osVirtualToPhysical(gfx_sub_list));
}

void func_800DD07C(void *model, u8 *data) {
    void mlMtxApply(Mtx *);
    extern RenderData D_8012C948;
    struct ModelContext {
        Gfx *gfx;
        Mtx *mtx;
    };
    struct Command { u8 padding[8]; s16 gfx_index[1]; };
    struct ModelContext *context = (struct ModelContext *)model;
    struct Command *cmd = (struct Command *)data;
    Gfx *gfx = context->gfx;
    int i;
    struct RenderState { u8 padding[0x18]; DisplayListView *list; };

    gSPDisplayList(gfx++, osVirtualToPhysical(cmd->gfx_index[0] + ((struct RenderState *)&D_8012C948)->list->commands));
    mlMtxApply(context->mtx);
    for (i = 1; cmd->gfx_index[i] != 0; i++) {
        gSPMatrix(gfx++, context->mtx, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, osVirtualToPhysical(cmd->gfx_index[i] + ((struct RenderState *)&D_8012C948)->list->commands));
    }
    context->gfx = gfx;
    context->mtx++;
}

void func_800DD19C(s32 arg0, u8 *commands) {
    void func_800DE2A4(s32, u8 *);
    commands += *(s32 *)(commands + 8);
    func_800DE2A4(arg0, commands);
}

void func_800DD1C0(Gfx **gfx, u8 *data) {
    struct Command { u8 padding[0xA]; s16 index; };
    gSPDisplayList((*gfx)++, osVirtualToPhysical(&D_8012C960->commands[((struct Command *)data)->index]));
}

void func_800DD214(s32 model, u8 *data) {
    void func_800193C4(f32 *, f32 *);
    void func_800DE2A4(s32, u8 *);
    f32 func_800EEB40(f32 *, f32 *);
    extern s16 D_8012CA38;
    extern s32 D_8012CE98;
    extern f32 D_8012CF60[3];
    struct Command {
        u8 padding[8];
        f32 max;
        f32 min;
        f32 position[3];
        s32 branch_offset;
    };
    struct Command *cmd = (struct Command *)data;
    f32 dist;

    if (cmd->branch_offset) {
        if (D_8012CA38) {
            (&D_8012CA38)[1]++;
            if (D_8012CA38 == (&D_8012CA38)[1]) {
                func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
            }
        } else {
            func_800193C4(D_8012CF60, cmd->position);
            dist = func_800EEB40(D_8012CF60, (f32 *)&D_8012CE98);
            if ((cmd->min * cmd->min < dist) && (dist <= cmd->max * cmd->max)) {
                func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
            }
        }
    }
}

void func_800DD2E8(s32 model, u8 *data) {
    void func_800DE2A4(s32, u8 *);
    f32 func_800EEB40(f32 *, f32 *);
    extern s32 D_8012CE98;
    extern f32 D_8012CF70[3];
    struct Command {
        u8 padding[8];
        f32 max;
        f32 min;
        f32 position[3];
        s32 branch_offset;
    };
    struct Command *cmd = (struct Command *)data;
    f32 dist;

    if (cmd->branch_offset) {
        func_800DC580(D_8012CF70, cmd->position);
        dist = func_800EEB40(D_8012CF70, (f32 *)&D_8012CE98);
        if ((cmd->min * cmd->min < dist) && (dist <= cmd->max * cmd->max)) {
            func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
        }
    }
}

void func_800DD37C(s32 model, u8 *data) {
    void func_800DE2A4(s32, u8 *);
    f32 func_800EEB40(f32 *, f32 *);
    extern s32 D_8012CE98;
    extern f32 D_8012CF80[3];
    struct Command {
        u8 padding[8];
        f32 max;
        f32 min;
        f32 position[3];
        s32 branch_offset;
    };
    struct Command *cmd = (struct Command *)data;
    f32 dist;

    if (cmd->branch_offset) {
        func_800DC5BC(D_8012CF80, cmd->position);
        dist = func_800EEB40(D_8012CF80, (f32 *)&D_8012CE98);
        if ((cmd->min * cmd->min < dist) && (dist <= cmd->max * cmd->max)) {
            func_800DE2A4(model, (u8 *)cmd + cmd->branch_offset);
        }
    }
}

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
    extern RenderData D_8012C948;
    void func_800EFA20(void *arg0, void *arg1, f32 arg2);
    void func_800DC028(s32, s32, s32);
    f32 sp18[4];

    if (D_8012C844 != 0) {
        func_800EFA20(sp18, arg1 + 0xC, D_8012C948.scale);
        func_800DC028(D_8012C844, (*(s16 *)((s8 *)(arg1) + (8))), sp18);
    }
}

void func_800DD504(s32 arg0, u8 *arg1) { extern s32 D_8012C844; extern RenderData D_8012C948; void func_800EF04C(f32[3], f32[3]); void func_800EFA20(void *, void *, f32); void func_800DC028(s32, s32, s32); extern f32 *D_8012C94C; f32 sp18[4]; if (D_8012C844 != 0) { func_800EFA20(sp18, arg1 + 0xC, D_8012C948.scale); func_800EF04C(sp18, D_8012C94C); func_800DC028(D_8012C844, (*(s16 *)((s8 *)(arg1) + (8))), sp18); } }
void func_800DD56C(s32 model, u8 *data) {
    struct SelectorCommand {
        u32 header[2];
        s16 branch_offset_count;
        s16 index;
        s32 branch_offsets[1];
    };
    void func_800DE2A4(s32, u8 *);
    struct SelectorCommand *cmd = (struct SelectorCommand *)data;
    s32 sub_cmd_addr;
    s32 selection;
    int i;
    s32 s1;
    s32 *offset;

    selection = D_8012C850[cmd->index];
    if (cmd->index == 0)
        return;
    if (selection == 0)
        return;
    if (selection > 0) {
        if (selection <= cmd->branch_offset_count) {
            offset = cmd->branch_offsets;
            sub_cmd_addr = (s32)cmd;
            sub_cmd_addr += *(s32 *)(data + (((u32)selection - 1) << 2) + 0xC);
            func_800DE2A4(model, (u8 *)sub_cmd_addr);
        }
    } else {
        s1 = -selection;
        offset = cmd->branch_offsets;
        for (i = 0; i < cmd->branch_offset_count; i++) {
            if (s1 & 1) {
                sub_cmd_addr = (s32)cmd;
                sub_cmd_addr += *offset;
                func_800DE2A4(model, (u8 *)sub_cmd_addr);
            }
            s1 >>= 1;
            offset++;
        }
    }
}

typedef struct { f32 m[4][4]; } MtxF;
void func_800DD65C(Gfx **arg0, void *arg1) {
    s32 func_8010F070(MtxF *, s32 *, s16);
    MtxF *mlMtx_get_stack_pointer(void);
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    s32 sp38[2];
    MtxF *mtx;
    s32 sp2C[2];
    Gfx *packet;
    Gfx *list;

    sp38[0] = *(s16 *)((u8 *)arg1 + 0xA);
    mtx = mlMtx_get_stack_pointer();
    if (*(s16 *)((u8 *)arg1 + 0xE)) {
        sp2C[0] = sp38[0];
        if (*(s16 *)((u8 *)arg1 + 0xE) & 1) {
            func_8010F070(mtx, sp2C, *(s16 *)((u8 *)arg1 + 0xC));
        }
    }
    if (D_8012CEC4 != NULL) {
        D_8012CEC4(mtx, sp38, *(s16 *)((u8 *)arg1 + 0xC));
    }
    list = &D_8012C960->commands[*(s16 *)((u8 *)arg1 + 8)];
    packet = (*arg0)++;
    packet->words.w0 = 0xDE000000;
    packet->words.w1 = osVirtualToPhysical(list);
}

struct GeoContext800DD728 { Gfx *gfx; Mtx *mtx; };
void func_800DD728(struct GeoContext800DD728 *context, void *arg1) {
    MtxF *func_80018BB4(void);
    s32 func_8010F070(MtxF *, s32 *, s16);
    void mlMtxApply(Mtx *);
    MtxF *mlMtx_get_stack_pointer(void);
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    struct DrawCommand {
        s32 header[2];
        s16 indices[6];
        s16 counts1[6];
        s16 counts2[6];
        s16 start;
        s16 flags;
    } *command = arg1;
    s32 start[2];
    s32 start2;
    MtxF *mtx;
    MtxF *mtx2;
    Gfx *packet;
    Gfx *matrixPacket;
    Gfx *listPacket;
    s32 i;

    start[0] = command->start;
    start2 = start[0];
    mtx = mlMtx_get_stack_pointer();
    mtx2 = func_80018BB4();
    mlMtxApply(context->mtx);
    if (command->flags && (command->flags & 1)) {
        if (command->counts2[0]) {
            func_8010F070(mtx, &start2, command->counts2[0]);
        }
        if (command->counts1[0]) {
            func_8010F070(mtx2, &start2, command->counts1[0]);
        }
    }
    if (D_8012CEC4 != NULL) {
        if (command->counts2[0]) {
            D_8012CEC4(mtx, start, command->counts2[0]);
        }
        if (command->counts1[0]) {
            D_8012CEC4(mtx2, start, command->counts1[0]);
        }
    }
    packet = context->gfx++;
    packet->words.w0 = 0xDE000000;
    packet->words.w1 = osVirtualToPhysical(command->indices[0] + D_8012C960->commands);
    for (i = 1; command->indices[i]; i++) {
            if (command->flags && (command->flags & 1)) {
                if (command->counts2[i]) {
                    func_8010F070(mtx, &start2, command->counts2[i]);
                }
                if (command->counts1[i]) {
                    func_8010F070(mtx2, &start2, command->counts1[i]);
                }
            }
            if (D_8012CEC4 != NULL) {
                if (command->counts2[i]) {
                    D_8012CEC4(mtx, start, command->counts2[i]);
                }
                if (command->counts1[i]) {
                    D_8012CEC4(mtx2, start, command->counts1[i]);
                }
            }
            matrixPacket = context->gfx++;
            matrixPacket->words.w0 = 0xDA380002;
            matrixPacket->words.w1 = (u32)context->mtx;
            listPacket = context->gfx++;
            listPacket->words.w0 = 0xDE000000;
            listPacket->words.w1 = osVirtualToPhysical(command->indices[i] + D_8012C960->commands);
    }
    context->mtx++;
}

struct GeoContext800DD998 {
    Gfx *gfx;
    Mtx *mtx;
};

void func_800DD998(struct GeoContext800DD998 *context, u8 *arg1) {
    MtxF *func_80018BB4(void);
    s32 func_8010F070(MtxF *, s32 *, s16);
    void mlMtxApply(Mtx *);
    MtxF *mlMtx_get_stack_pointer(void);
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    Gfx *packet;
    Gfx *list;
    s32 sp64;
    s32 sp60;
    MtxF *sp5C;
    MtxF *sp58;
    struct DrawCommand {
        s32 header[2];
        s16 indices[6];
        s16 counts1[6];
        s16 counts2[6];
        s16 start;
        s16 flags;
    } *command = (struct DrawCommand *)arg1;
    s32 i;

    sp64 = command->start;
    sp60 = sp64;
    sp5C = mlMtx_get_stack_pointer();
    sp58 = func_80018BB4();
    mlMtxApply(context->mtx);
    i = 0;
    do {
        if (*(s16 *)(arg1 + 0x2E) != 0 && (*(s16 *)(arg1 + 0x2E) & 1)) {
            if (command->counts2[i] != 0) {
                func_8010F070(sp5C, &sp60, command->counts2[i]);
            }
            if (command->counts1[i] != 0) {
                func_8010F070(sp58, &sp60, command->counts1[i]);
            }
        }
        if (D_8012CEC4 != NULL) {
            if (command->counts2[i] != 0) {
                D_8012CEC4(sp5C, &sp64, command->counts2[i]);
            }
            if (command->counts1[i] != 0) {
                D_8012CEC4(sp58, &sp64, command->counts1[i]);
            }
        }
        list = context->gfx++;
        list->words.w0 = 0xDE000000;
        list->words.w1 = osVirtualToPhysical(command->indices[i] * 8 + (u8 *)D_8012C960 + 8);
        packet = context->gfx++;
        packet->words.w0 = 0xDA380002;
        i++;
        packet->words.w1 = (u32)context->mtx;
    } while (command->indices[i] != 0);
    context->mtx++;
}

void func_800DDB38(void *arg0, u8 *arg1) {
    void mlMtxApply(Mtx *);
    extern RenderData D_8012C948;
    struct DrawContext {
        Gfx *gfx;
        Mtx *mtx;
    } *context = arg0;
    Gfx *packet;
    Gfx *list;
    struct DrawCommand {
        s32 header[2];
        s16 indices[1];
    } *command = (struct DrawCommand *)arg1;
    u8 *cursor = (u8 *)&command->header[0];
    s32 i;

    mlMtxApply(context->mtx);
    i = 0;
    do {
        list = context->gfx++;
        list->words.w0 = 0xDE000000;
        list->words.w1 = osVirtualToPhysical(*(u8 **)((u8 *)&D_8012C948 + 0x18) + command->indices[i] * 8 + 8);
        packet = context->gfx++;
        i++;
        packet->words.w0 = 0xDA380002;
        packet->words.w1 = (u32)context->mtx;
    } while (*(s16 *)(cursor + i * 2 + 8) != 0);
    context->mtx++;
}

void func_800DDC28(volatile s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3D0C(f32 *, f32 *);
    extern RenderData D_8012C948;
    f32 scaled_min[3];
    f32 scaled_max[3];
    s32 i;
    struct DrawDistance {
        s32 header[2];
        s16 min[3];
        s16 max[3];
        s16 branch_offset;
    } *cmd = (struct DrawDistance *)arg1;

    if (cmd->branch_offset != 0) {
        for (i = 0; i < 3; i++) {
            scaled_min[i] = cmd->min[i] * D_8012C948.scale;
            scaled_max[i] = cmd->max[i] * D_8012C948.scale;
        }
        if (func_800E3D0C(scaled_min, scaled_max) != 0) {
            func_800DE2A4(arg0, (u8 *)cmd + cmd->branch_offset);
        }
    }
}

void func_800DDD14(volatile s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3D0C(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    extern RenderData D_8012C948;
    extern f32 *D_8012C94C;
    f32 sp34[3];
    f32 sp28[3];
    s32 pad[2];

    if (*(s16 *)(arg1 + 0x14) != 0) {
        func_800EE88C(sp34, (s16 *)(arg1 + 8));
        func_800EE88C(sp28, (s16 *)(arg1 + 0xE));
        func_800EF334(sp34, D_8012C948.scale);
        func_800EF334(sp28, D_8012C948.scale);
        func_800EF04C(sp34, D_8012C94C);
        func_800EF04C(sp28, D_8012C94C);
        if (func_800E3D0C(sp34, sp28) != 0) {
            arg1 += *(s16 *)(arg1 + 0x14);
            func_800DE2A4(arg0, arg1);
        }
    }
}

void func_800DDDC4(volatile s32 arg0, u8 *arg1) {
    void func_80019224(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF334(f32 *, f32);
    void mlMtxPop(void);
    extern RenderData D_8012C948;
    extern s32 D_8012CE58;
    f32 pos[3];
    f32 radius;
    s32 offset;
    s32 model;

    if (*(s16 *)(arg1 + 0x12) == -1) {
        func_800EE88C(pos, (s16 *)(arg1 + 8));
        func_800EF334(pos, D_8012C948.scale);
        radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948.scale;
        if (func_800E3E8C(pos, radius)) {
            offset = *(s16 *)(arg1 + 0x10);
            model = arg0;
            if (offset) {
                arg1 += offset; func_800DE2A4(model, arg1);
            }
        }
    } else {
        func_800EE88C(pos, (s16 *)(arg1 + 8));
        radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948.scale;
        if (*(s32 *)((u8 *)&D_8012C948 + 0x20)) {
            func_80019AA0(&D_8012CE58, func_800ADE2C(*(s32 *)((u8 *)&D_8012C948 + 0x20), *(s16 *)(arg1 + 0x12)));
            func_80019224(pos, pos);
            mlMtxPop();
        } else {
            func_80019224(pos, pos);
        }
        if (func_800E3E8C(pos, radius)) {
            offset = *(s16 *)(arg1 + 0x10);
            model = arg0;
            if (offset) {
                arg1 += offset; func_800DE2A4(model, arg1);
            }
        }
    }
}

void func_800DDF14(volatile s32 arg0, u8 *arg1) {
    void func_800DE2A4(s32, u8 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF334(f32 *, f32);
    extern RenderData D_8012C948;
    f32 sp2C[3];
    f32 radius;
    s32 offset;
    s32 model;

    func_800EE88C(sp2C, (s16 *)(arg1 + 8));
    func_800EF334(sp2C, D_8012C948.scale);
    radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948.scale;
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
    extern RenderData D_8012C948;
    extern f32 *D_8012C94C;
    f32 sp2C[3];
    f32 radius;
    s32 offset;
    s32 model;

    func_800EE88C(sp2C, (s16 *)(arg1 + 8));
    func_800EF334(sp2C, D_8012C948.scale);
    func_800EF04C(sp2C, D_8012C94C);
    radius = (f32)*(s16 *)(arg1 + 0xE) * D_8012C948.scale;
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

void func_800DE0D8(s32 arg0, u8 *arg1) {
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    MtxF *mlMtx_get_stack_pointer(void);
    void mlMtxPop(void);
    extern RenderData D_8012C948;
    extern s32 D_8012CE58;
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    struct command { s32 header[2]; s16 count; s16 id; struct { s16 bone; s16 tag; } entries[1]; };
    s32 sp48[2];
    s32 i;
    struct command *command = (struct command *)arg1;

    sp48[0] = command->id;
    if (D_8012CEC4 != NULL) {
        for (i = 0; i < command->count; i++) {
                func_80019AA0(&D_8012CE58, func_800ADE2C(*(s32 *)((u8 *)&D_8012C948 + 0x20), command->entries[i].bone));
                D_8012CEC4(mlMtx_get_stack_pointer(), sp48, command->entries[i].tag);
                mlMtxPop();
        }
    }
}

void func_800DE1C4(s32 arg0, u8 *arg1) {
    MtxF *func_80018BB4(void);
    s32 func_8010F070(MtxF *, s32 *, s16);
    MtxF *mlMtx_get_stack_pointer(void);
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    s32 sp38[2];
    MtxF *sp34;
    MtxF *sp30;
    s32 sp2C;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_a2_3;
    s16 temp_a2_4;

    sp38[0] = *(s16 *)(arg1 + 8);
    sp34 = mlMtx_get_stack_pointer();
    sp30 = func_80018BB4();
    if (*(s16 *)(arg1 + 0xE) != 0) {
        sp2C = sp38[0];
        if (*(s16 *)(arg1 + 0xE) & 1) {
            temp_a2 = *(s16 *)(arg1 + 0xA);
            if (temp_a2 != 0) {
                func_8010F070(sp34, &sp2C, temp_a2);
            }
            temp_a2_2 = *(s16 *)(arg1 + 0xC);
            if (temp_a2_2 != 0) {
                func_8010F070(sp30, &sp2C, temp_a2_2);
            }
        }
    }
    if (D_8012CEC4 != NULL) {
        temp_a2_3 = *(s16 *)(arg1 + 0xA);
        if (temp_a2_3 != 0) {
            D_8012CEC4(sp34, sp38, temp_a2_3);
        }
        temp_a2_4 = *(s16 *)(arg1 + 0xC);
        if (temp_a2_4 != 0) {
            D_8012CEC4(sp30, sp38, temp_a2_4);
        }
    }
}

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

void func_800DE318(void) {
    extern GeoCommandFunction *D_80123198[];
    extern f32 D_80125D50;
    extern s32 D_8012C828;
    extern f32 D_8012C82C;
    extern f32 D_8012C830;
    extern s32 D_8012C834;
    extern s32 D_8012C838;
    extern s32 D_8012C83C;
    extern s32 D_8012C844;
    extern s32 D_8012C848;
    extern RenderData D_8012C948;
    extern s32 D_8012C988;
    extern s32 D_8012C9A8;
    extern s32 D_8012C9B8;
    extern s32 D_8012CA18;
    extern s32 D_8012CA28;
    extern s16 D_8012CA38;
    D_8012C824 = 0;
    D_8012C82C = D_80125D50;
    D_8012C828 = 1;
    D_8012C830 = 1.0f;
    D_8012C834 = 0;
    D_8012C838 = 0;
    D_8012C83C = 0;
    D_8012C844 = 0;
    D_8012C848 = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x18) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x20) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x14) = 0;
    *(s8 *)((u8 *)&D_8012C948 + 0x24) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x1C) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x28) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x30) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x34) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x2C) = 0;
    *(s32 *)((u8 *)&D_8012C948 + 0x38) = 0;
    D_8012C9A8 = 0;
    *(s32 *)((u8 *)&D_8012C9A8 + 8) = 0;
    D_8012C9B8 = 0;
    D_8012CA18 = 0;
    D_8012CA28 = 0;
    *(&D_8012CA38 + 1) = 0;
    D_8012CA38 = *(&D_8012CA38 + 1);
    D_8012CF8C = D_80123198[0];
    func_800DF744(1, 1);
    func_800DF744(2, 0);
    *(s32 *)((u8 *)&D_8012C988 + 0xC) = 0;
    *(s32 *)((u8 *)&D_8012C988 + 8) = 0;
    *(s32 *)((u8 *)&D_8012C988 + 4) = 0;
    D_8012C988 = 0;
    *(s32 *)((u8 *)&D_8012C988 + 0x10) =
    *(s32 *)((u8 *)&D_8012C988 + 0x14) =
    *(s32 *)((u8 *)&D_8012C988 + 0x18) =
    *(s32 *)((u8 *)&D_8012C988 + 0x1C) = 0xFF;
}

typedef struct {
    Gfx* gfx;
    Mtx* mtx;
} GraphicsBuffers;

GraphicsBuffers* func_800A7180();

void* func_800DE498(GraphicsBuffers*, f32*, f32*, f32, f32*, ModelData*);

// modelRender_draw?
void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, u8* arg4) {
    return func_800DE498(func_800A7180(), position, arg1, scale, arg3, (ModelData *)arg4);
}

// the real modelRender_draw?
// the real modelRender_draw?
// the real modelRender_draw?
// the real modelRender_draw?
void *func_800DE498(GraphicsBuffers *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, ModelData *arg5) {


    typedef struct {
        void (*draw)(RenderData *, s32, s32, void *);
        s32 value;
        void (*finish)(void);
    } RenderCallback;
    typedef struct {
        s32 prim[4];
        s32 env[4];
    } RenderColors;
    typedef struct {
        s32 size;
        s16 count;
        s16 padding;
        u8 data[1][8];
    } TextureData;
    extern RenderData D_8012C948;
    extern s32 D_8012C988;
    extern s32 D_8012C828, D_8012C834, D_8012C838, D_8012C83C;
    extern f32 D_8012C82C, D_8012C830;
    extern u8 D_8012C840;
    extern s32 D_8012C848, D_8012C9A4;
    extern s32 D_8012C9A8;
    extern s32 D_8012C9AC;
    extern void (*D_8012C9B0)(s32);
    extern s32 D_8012C9B4, D_8012C9B8, D_8012C9BC, D_8012C9C8;
    extern s32 D_8012CA08, D_8012CA0C, D_8012CA18, D_8012CA28;
    extern u8 D_8012CA11;
    extern f32 D_8012CA1C, D_8012CA20;
    extern f32 D_8012CE48[3];
    extern LookAtBuffer D_8012CA40;
    extern s32 D_8012CE58;
    extern s32 D_8012CE98;
    extern f32 D_8012CEB8[3];
    extern f32 D_8012CEA8;
    extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);
    extern s32 D_8012C820;
    extern Gfx D_80122DB0[], D_80122DF0[], D_80122EB0[], D_80122F70[];
    extern s32 D_80122DC8[], D_80122DCC[];
    extern RenderCallback D_80123030[], D_80123038[];
    extern f32 D_80125D54, D_80125D58, D_80125D5C, D_80125D60, D_80125D64;
    void func_800E39A8(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800DE318(void);
    void func_800EFD24(f32 *);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    f32 mlAbsF(f32);
    f32 func_800EEF94(f32 *);
    f32 func_800E42C0(void);
    s32 func_800E3E8C(f32 *, f32);
    s32 func_800DB9FC(u8, s32, s32 *);
    void func_80013C80(Mtx *, LookAt *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
    void func_800D2C54(Gfx **);
    u8 *func_800B27E0(u8 *);
    void func_800ADCD0(u8 **, u8 *);
    void func_800AE160(u8 **, u8 *, s32);
    void _dbzone_entrypoint_1(u8 *, void *, f32, f32 *);
    void _glzone_entrypoint_2(s32);
    void _dbanim_entrypoint_1(u8 *, u8 *, u8 *, u8 *);
    void _dbanim_entrypoint_0(u8 *, u8 *, u8 *);
    s32 func_80019CD4(void);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_800AE598(u8 *, Mtx **);
    void func_8010EF70(RenderData *, s32, s32, void *);
    void func_800E4640(Gfx **);
    void func_8010F270(void);
    void mlMtxRotatePYR(f32, f32, f32);
    void mlMtxScale_xyz(f32, f32, f32);
    void func_80018C50(void *);
    void mlMtxGet(void *);
    void mlMtxApply(Mtx *);
    f32 camera_focus[3];
    f32 object_position[3];
    f32 distance;
    f32 local_norm;
    f32 global_norm;
    void *opaque_mode;
    Gfx *gfx;
    u8 *verts;
    s32 alpha;
    f32 tmp_f0;
    void *translucent_mode;

    D_8012C940 = 0;
    func_800E39A8((s32)&D_8012CE98, (s32)&D_8012CEA8);
    if (arg1 != NULL) {
        func_800EE7F8(object_position, arg1);
    } else {
        func_800EFD24(object_position);
    }
    func_800EFB24((s32 *)camera_focus, (s32 *)object_position, &D_8012CE98);
    if (D_80125D54 < mlAbsF(camera_focus[0]) ||
        D_80125D58 < mlAbsF(camera_focus[1]) ||
        D_80125D5C < mlAbsF(camera_focus[2])) {
        func_800DE318();
        return NULL;
    }
    if (arg5) {
        verts = D_8012C948.vertices ? D_8012C948.vertices : ((u8 *)arg5 + arg5->vertices);
        global_norm = (u32)*(u16 *)(verts + 0x14);
        local_norm = (u32)*(u16 *)(verts + 0x12);
    } else {
        global_norm = D_8012CA20;
        local_norm = D_8012CA1C;
    }
    distance = func_800EEF94(camera_focus);
    if (4000.0f <= distance && D_8012C82C == D_80125D60) {
        if (local_norm * arg3 * D_8012C830 * 50.0f < D_8012C82C) {
            D_8012C82C = local_norm * arg3 * D_8012C830 * 50.0f;
        }
    }
    D_8012C82C *= func_800E42C0();
    if (D_8012C82C <= distance) {
        func_800DE318();
        return NULL;
    }
    D_8012C940 = D_8012C828 ? func_800E3E8C(object_position, global_norm * arg3) : 1;
    if (!D_8012C940) {
        func_800DE318();
        return NULL;
    }
    if (D_8012C9A8 != NULL) {
        ((void (*)(s32))D_8012C9A8)(D_8012C9AC);
    }
    if (arg5 == 0) {
        arg5 = (ModelData *)func_800D674C(D_8012CA18);
        if (arg5 == 0) {
            func_800DE318();
            return NULL;
        }
    }
    if (!D_8012C948.display_list) {
        D_8012C948.display_list = (DisplayListView *)((u8 *)arg5 + arg5->display_list);
    }
    if (!D_8012C948.textures) {
        D_8012C948.textures = ((u8 *)arg5 + arg5->textures);
    }
    if (!D_8012C948.vertices) {
        D_8012C948.vertices = ((u8 *)arg5 + arg5->vertices);
    }
    D_8012C948.zones = arg5->zones == 0 ? NULL : ((u8 *)arg5 + arg5->zones);
    if (!D_8012C948.normals) {
        D_8012C948.normals = arg5->normals == 0 ? NULL : ((u8 *)arg5 + arg5->normals);
    }
    if (D_8012C834) {
        tmp_f0 = D_8012C82C - 700.0f;
        if (tmp_f0 < distance) {
            alpha = (s32)((1.0f - (distance - tmp_f0) / 700.0f) * 256.0f);
            ((RenderColors *)&D_8012C988)->env[3] = (D_8012C9A4 * alpha) / 256;
        }
    }
    gfx = arg0->gfx;
    gSPSegment(gfx++, 1, osVirtualToPhysical(D_8012C948.vertices + 0x18));
    gSPSegment(gfx++, 2, osVirtualToPhysical(((TextureData *)D_8012C948.textures)->data[((TextureData *)D_8012C948.textures)->count]));
    if (D_8012C948.texture_animation) {
        s32 i;
        s32 offset;
        for (i = 0; i != 7; i++) {
            if (func_800DB9FC(D_8012C948.texture_animation, i, &offset)) {
                gSPSegment(gfx++, 15 - i, osVirtualToPhysical(((TextureData *)D_8012C948.textures)->data[((TextureData *)D_8012C948.textures)->count] + offset));
            }
        }
    }
    if (((RenderColors *)&D_8012C988)->prim[3] && D_8012C83C != 3) {
        ((RenderColors *)&D_8012C988)->env[3] = ((RenderColors *)&D_8012C988)->env[3] + (((RenderColors *)&D_8012C988)->prim[3] * (255 - ((RenderColors *)&D_8012C988)->env[3])) / 255;
        ((RenderColors *)&D_8012C988)->prim[3] = 0;
    }
    gDPPipeSync(gfx++);
    gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetBlendColor(gfx++, 0, 0, 0, 128);
    gDPSetPrimColor(gfx++, 0, 0, ((RenderColors *)&D_8012C988)->prim[0], ((RenderColors *)&D_8012C988)->prim[1], ((RenderColors *)&D_8012C988)->prim[2], ((RenderColors *)&D_8012C988)->prim[3]);
    gDPSetEnvColor(gfx++, ((RenderColors *)&D_8012C988)->env[0], ((RenderColors *)&D_8012C988)->env[1], ((RenderColors *)&D_8012C988)->env[2], ((RenderColors *)&D_8012C988)->env[3]);
    if (D_8012CA28) {
        gSPSetGeometryMode(gfx++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(gfx++, G_ZBUFFER);
    }
    if (((RenderColors *)&D_8012C988)->env[3] == 255) {
        {
            Gfx *packet = gfx++;
            packet->words.w0 = _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(G_MW_SEGMENT, 16, 8) | (3 * 4);
            opaque_mode = (void *)D_80122DC8[D_8012CA28 * 2];
            packet->words.w1 = osVirtualToPhysical(opaque_mode);
        }
    } else {
        {
            Gfx *packet = gfx++;
            packet->words.w0 = _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(G_MW_SEGMENT, 16, 8) | (3 * 4);
            translucent_mode = (void *)D_80122DCC[D_8012CA28 * 2];
            packet->words.w1 = osVirtualToPhysical(translucent_mode);
        }
    }
    if (arg5->flags & 2) {
        D_8012C820 = (s32)D_80122DF0;
    } else if (arg5->flags & 0x80) {
        D_8012C820 = (s32)D_80122EB0;
    } else if (arg5->flags & 0x100) {
        D_8012C820 = (s32)D_80122F70;
    } else {
        D_8012C820 = NULL;
    }
    if (D_8012C820) {
        gSPDisplayList(gfx++, (u32)D_8012C820 - 0x80000000);
    }
    if (arg5->flags & 4) {
        if (camera_focus[2] == 0.0f) {
            camera_focus[2] = D_80125D64;
        }
        func_80013C80(arg0->mtx, (LookAt *)D_8012CA40.current, D_8012CA40.position[0], D_8012CA40.position[1], D_8012CA40.position[2],
            camera_focus[0], camera_focus[1], camera_focus[2], 0.0f, 1.0f, 0.0f);
        gSPLookAt(gfx++, D_8012CA40.current);
        osWritebackDCache(D_8012CA40.current, 0x20);
        D_8012CA40.current++;
        if (D_8012CA40.current == D_8012CA40.end) {
            D_8012CA40.current = D_8012CA40.buffer;
        }
    }
    if (arg5->flags & 0x20) {
        func_800D2C54(&gfx);
    }
    if (D_8012C948.animation && !arg5->animation) {
        D_8012C948.animation = NULL;
    } else if (!D_8012C948.animation && arg5->animation) {
        if (D_8012C824 == 0) {
            func_800ADCD0((u8 **)&D_8012C840, func_800B27E0((u8 *)arg5));
        } else {
            func_800AE160((u8 **)&D_8012C840, func_800B27E0((u8 *)arg5), D_8012C824);
        }
        D_8012C948.animation = *(u8 **)&D_8012C840;
    }
    if (D_8012C948.zones) {
        _dbzone_entrypoint_1(D_8012C948.zones, &D_8012CE98, arg3, object_position);
        if (D_8012C848) {
            _glzone_entrypoint_2(D_8012C848);
        }
    }
    if (arg5->animated_vertices && D_8012C948.animation) {
        D_8012C948.animated_vertices = ((u8 *)arg5 + arg5->animated_vertices);
        if (D_8012C948.normals && D_8012C838 == 1 && D_8012CA11 != 2 && D_8012CA11 != 3) {
            _dbanim_entrypoint_1(D_8012C948.animated_vertices, D_8012C948.vertices, D_8012C948.animation, D_8012C948.normals);
        } else {
            _dbanim_entrypoint_0(D_8012C948.animated_vertices, D_8012C948.vertices, D_8012C948.animation);
        }
    }
    func_80019CD4();
    func_80019750(object_position, arg2, arg3, arg4);
    switch (D_8012C9B8) {
        case 1:
            mlMtxRotatePYR(((f32 *)&D_8012C9B8)[1], ((f32 *)&D_8012C9B8)[2], ((f32 *)&D_8012C9B8)[3]);
            break;
        case 2:
            mlMtxScale_xyz(((f32 *)&D_8012C9B8)[1], ((f32 *)&D_8012C9B8)[2], ((f32 *)&D_8012C9B8)[3]);
            break;
        case 3:
            func_80018C50(&D_8012C9C8);
            break;
    }
    mlMtxGet(&D_8012CE58);
    mlMtxApply(arg0->mtx);
    if (arg5->flags & 0x40) {
        gSPMatrix(gfx++, (u32)arg0->mtx - 0x80000000, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
        arg0->mtx++;
        if (!D_8012C948.matrices) {
            Mtx *matrices = arg0->mtx;
            func_800AE598(D_8012C948.animation, &arg0->mtx);
            D_8012C948.matrices = matrices + 1;
        }
        gSPSegment(gfx++, 5, osVirtualToPhysical(D_8012C948.matrices));
        if (D_8012C820) {
            gSPSegment(gfx++, 6, osVirtualToPhysical((void *)D_8012C820));
        }
    } else {
        gSPMatrix(gfx++, arg0->mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
        arg0->mtx++;
    }
    D_8012C948.position = object_position;
    D_8012C948.rotation = arg2;
    D_8012C948.scale = arg3;
    D_8012C948.origin = arg4;
    D_8012C948.extra_rotation = D_8012C9B8 == 1 ? (f32 *)&D_8012C9BC : NULL;
    if (arg2) {
        func_800EE7F8(D_8012CEB8, arg2);
    } else {
        func_800EFD24(D_8012CEB8);
    }
    arg0->gfx = gfx;
    if (arg5->flags & 0x10) {
        func_8010EF70(&D_8012C948, 0, 0, &D_8012CE98);
    }
    if (D_8012C838 == 1) {
        if (D_80123030[D_8012CA11].draw) {
            D_80123030[D_8012CA11].draw(&D_8012C948, D_8012CA08, D_8012CA0C, &D_8012CE98);
        }
        D_8012CEC4 = (s32 (*)(MtxF *, s32 *, s16))D_80123030[D_8012CA11].value;
    }
    func_800DE2A4((s32)arg0, ((u8 *)arg5 + arg5->geometry));
    if (arg5->flags & 0x40) {
        func_800E4640(&arg0->gfx);
    } else {
        gSPPopMatrix(arg0->gfx++, G_MTX_MODELVIEW);
    }
    if (arg5->flags & 0x182) {
        gSPDisplayList(arg0->gfx++, OS_K0_TO_PHYSICAL(D_80122DB0));
    }
    if (D_8012C838 == 1) {
        if (D_80123038[D_8012CA11].draw) {
            ((void (*)(void))D_80123038[D_8012CA11].draw)();
        }
        D_8012CEC4 = 0;
    }
    if (arg5->flags & 0x10) {
        func_8010F270();
    }
    if (D_8012C9B0) {
        D_8012C9B0(D_8012C9B4);
    }
    if (arg5->flags & 4) {
        LookAt *current = D_8012CA40.current;

        /* IDO retains the original empty reflection branch with this aggregate self-copy. */
        *current = *current;
    }
    func_800DE318();
    return (void *)arg5;
}

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
    buffer->end = buffer->current + 32;
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
    extern GeoCommandFunction *D_80123198[];
    D_8012CF8C = D_80123198[arg0];
}

void func_800DF4CC(s32 arg0) {
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9BC;
    D_8012C9B8 = 1;
    func_800EE7F8((f32 *)&D_8012C9BC, (f32 *)arg0);
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

void func_800DF7E8(u8 arg0) {
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

ImageStruct *func_800DF944(void *a0, f32 *coords, f32 a2, f32 a3, f32 *a4, s32 a5, ImageStruct *a6) {
    s32 func_800A89F8();
    f32 func_800A8AF0(s32);
    void func_800E42F0();
    void func_800E4640(Gfx **);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    extern f32 D_80125D68;
    extern s16 widescreen_enabled;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_800E42F0(a0, a5);
    if (coords != NULL) {
        func_800EFA4C(sp44, coords[0] * 4.0f - 608.0f, 456.0f - coords[1] * 4.0f, -10.0f);
    } else {
        func_800EFA4C(sp44, 0.0f, 0.0f, -10.0f);
    }
    if (a5 != 0 && widescreen_enabled != 0) {
        sp44[0] *= func_800A8AF0(func_800A89F8()) / D_80125D68;
    }
    func_800EFA4C(sp38, 0.0f, 0.0f, a2);
    if (a4 != NULL) {
        func_800EFA4C(sp2C, a4[0], a4[1], 0.0f);
    } else {
        func_800EFD24(sp2C);
    }
    func_800DF830(0);
    func_800DF440(0);
    a6 = func_800DE498(a0, sp44, sp38, 4.0f * a3, sp2C, (ModelData *)a6);
    func_800E4640(a0);
    return a6;
}

#include "gc/newoption.h"

s32 func_80800000_gcnewoption(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (2)));
    var_v1 = (*(s16 *)((s8 *)(arg0) + (0xA))) + arg1;
    if (var_v1 >= temp_v0) {
        var_v1 -= temp_v0;
    } else if (var_v1 < 0) {
        var_v1 += temp_v0;
    }
    return var_v1;
}

s32 func_80800038_gcnewoption(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 - (*(s16 *)((s8 *)(arg0) + (8)));
    if (temp_v1 >= (*(s16 *)((s8 *)(arg0) + (2)))) {
        return -1;
    }
    if (temp_v1 < 0) {
        return -1;
    }
    return temp_v1;
}

s32 func_80800070_gcnewoption(void *arg0, s32 arg1) {
    return (*(s16 *)((s8 *)(arg0) + (8))) + arg1;
}

void gcnewoption_entrypoint_0(void *arg0) {
    struct Option {
        s16 state;
        s16 count;
        s16 unk4;
        s16 selected;
        s16 unk8;
        s16 unkA;
        s32 unkC;
        f32 timer;
        u8 unk14[8];
        u32 flag80 : 1;
        u32 flag40 : 1;
        u32 flag20 : 1;
        u32 flag10 : 1;
        u32 flag08 : 1;
        u32 kind : 3;
        u32 flagsRest : 24;
        s32 box;
        u8 boxState;
        u8 unk25[0x17];
        s32 boxes[29];
        s16 items[202];
        void (*callback)(s32, void *, s32, s32);
        s32 unk248;
        s32 context;
        s8 controller;
    };
    void func_80800D28_gcnewoption(void *);
    void func_8080103C_gcnewoption(u8 *);
    s32 func_80801114_gcnewoption(void *);
    s32 func_80801190_gcnewoption(void *);
    void func_808019D0_gcnewoption(void *);
    void func_80801B5C_gcnewoption(void *);
    s32 func_80801E68_gcnewoption(void *);
    s32 func_808020C4_gcnewoption(void *);
    s32 func_808022E0_gcnewoption(void *);
    s32 func_8080241C_gcnewoption(void *);
    s32 func_80802534_gcnewoption(u8 *);
    s32 func_80802674_gcnewoption(void *);
    void func_808027DC_gcnewoption(void *, s32);
    void func_80802998_gcnewoption(void *);
    s32 func_80802A9C_gcnewoption(u8 *);
    void func_80802B24_gcnewoption(void *, s32);
    s32 _gczoombox_entrypoint_4();
    void func_80015E80(u32, void *);
    void func_80016068(u32, f32 *);
    f32 func_800D8FF8(void);
    f32 mlAbsF(f32);
    u8 previousState;
    s32 i;
    s32 index;
    s32 buttons[6];
    f32 stick[2];
    s32 controller;
    s32 selection;
    s32 event;

    ((struct Option *)arg0)->flag80 = 0;
    if (((struct Option *)arg0)->box) {
        previousState = ((struct Option *)arg0)->boxState;
    }

    i = 3;
    switch (((struct Option *)arg0)->state) {
        case 0:

            break;
        case 1:
            func_80800D28_gcnewoption(arg0);
            ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, selection = ((struct Option *)arg0)->selected, event = 0);
            ((struct Option *)arg0)->state = 2;

            break;
        case 2:
            ((struct Option *)arg0)->state = i;

            break;
        case 3:
            if (func_80801E68_gcnewoption(arg0)) {
                if (((struct Option *)arg0)->kind == i) {
                    ((struct Option *)arg0)->state = 4;
                } else {
                    ((struct Option *)arg0)->state = 5;
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 8);
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 10);
                }
            }
            func_808019D0_gcnewoption(arg0);

            break;
        case 4:
            for (i = 0; i < ((struct Option *)arg0)->count; i++) {
                index = func_80800000_gcnewoption((u8 *)arg0, i);
                func_808027DC_gcnewoption(arg0, i);
                _gczoombox_entrypoint_4(((struct Option *)arg0)->boxes[index]);
            }
            func_80801B5C_gcnewoption(arg0);
            if (((struct Option *)arg0)->box) {
                _gczoombox_entrypoint_4(((struct Option *)arg0)->box);
            }
            func_80802998_gcnewoption(arg0);
            i = 3;
        
                    break;
        case 5:
            func_808019D0_gcnewoption(arg0);
            func_80802998_gcnewoption(arg0);
            if (((struct Option *)arg0)->timer <= 0.0f) {
                if (((struct Option *)arg0)->controller < 0) {
                    goto update_timer;
                }
                func_80015E80(((struct Option *)arg0)->controller, buttons);
                if (buttons[1] == 1) {
                    if (((struct Option *)arg0)->kind == 2) {
                        if (((struct Option *)arg0)->callback) {
                            ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 5);
                        }
                    } else {
                        ((struct Option *)arg0)->flag20 = 1;
                        func_80802A9C_gcnewoption((u8 *)arg0);
                        ((struct Option *)arg0)->state = 6;
                    }
                } else if (buttons[0] == 1) {
                    switch ((s32)((struct Option *)arg0)->kind) {
                        case 0:
                            if (((struct Option *)arg0)->items[((struct Option *)arg0)->selected] == -1) {
                                if (((struct Option *)arg0)->callback) {
                                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 3);
                                    return;
                                }
                            } else {
                                func_80802A9C_gcnewoption((u8 *)arg0);
                                ((struct Option *)arg0)->state = 6;
                            }

                            break;
                        case 1:
                            if (((struct Option *)arg0)->callback) {
                                ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 1);
                            }

                            break;
                        case 2:
                            if (((struct Option *)arg0)->callback) {
                                ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 4);
                            }

                            break;
                    }
                    ((struct Option *)arg0)->timer = 0.6f;
                }
                if (((struct Option *)arg0)->state != 5) {

                    break;
                }
                if (!((struct Option *)arg0)->flag80 && !((struct Option *)arg0)->flag08 && (controller = ((struct Option *)arg0)->controller) >= 0) {
                    func_80016068(controller, stick);
                    if (stick[1] > 0.8f) {
                        if (func_80801114_gcnewoption(arg0)) {
                            ((struct Option *)arg0)->timer = 0.2f;
                        }
                    } else if (stick[1] < -0.8f) {
                        if (func_80801190_gcnewoption(arg0)) {
                            ((struct Option *)arg0)->timer = 0.2f;
                        }
                    }
                }
                if (((struct Option *)arg0)->kind == 2 && ((struct Option *)arg0)->flag08) {
                    func_80016068(((struct Option *)arg0)->controller, stick);
                    if (((struct Option *)arg0)->flag40) {
                        if (mlAbsF(stick[0]) < 0.8f) {
                            ((struct Option *)arg0)->flag40 = 0;
                        }
                    } else if (stick[0] > 0.8f) {
                        if (((struct Option *)arg0)->callback) {
                            ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 7);
                        }
                        ((struct Option *)arg0)->flag40 = 1;
                    } else if (stick[0] < -0.8f) {
                        if (((struct Option *)arg0)->callback) {
                            ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 6);
                        }
                        ((struct Option *)arg0)->flag40 = 1;
                    }
                }
            } else {
update_timer:
                if (((struct Option *)arg0)->timer > 0.0f) {
                    ((struct Option *)arg0)->timer -= func_800D8FF8();
                }
            }

            break;
        case 6:
            func_808019D0_gcnewoption(arg0);
            if (func_808020C4_gcnewoption(arg0)) {
                ((struct Option *)arg0)->state = 11;
            }

            break;
        case 7:
            func_808019D0_gcnewoption(arg0);
            if (func_808022E0_gcnewoption(arg0)) {
                func_80802A9C_gcnewoption((u8 *)arg0);
                ((struct Option *)arg0)->state = 8;
            }

            break;
        case 8:
            func_808019D0_gcnewoption(arg0);
            if (func_80802674_gcnewoption(arg0)) {
                ((struct Option *)arg0)->state = 11;
            }

            break;
        case 11:
            func_8080103C_gcnewoption((u8 *)arg0);
            ((struct Option *)arg0)->state = 12;

            break;
        case 12:
            ((struct Option *)arg0)->state = 13;
            if (((struct Option *)arg0)->callback) {
                if (((struct Option *)arg0)->flag20) {
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 2);
                    return;
                } else {
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 3);
                    return;
                }
            }

            break;
        case 13:

            break;
        case 9:
            func_808019D0_gcnewoption(arg0);
            if (func_8080241C_gcnewoption(arg0)) {
                ((struct Option *)arg0)->state = 5;
                if (((struct Option *)arg0)->callback) {
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 10);
                }
            }

            break;
        case 10:
            func_808019D0_gcnewoption(arg0);
            if (func_80802534_gcnewoption(arg0)) {
                ((struct Option *)arg0)->state = 5;
                func_80802B24_gcnewoption(arg0, 0);
                if (((struct Option *)arg0)->callback) {
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 10);
                }
            }

            break;
        default:
            break;
    }
    if (((struct Option *)arg0)->box) {
        if (i == ((struct Option *)arg0)->state || ((struct Option *)arg0)->state == 5 || ((struct Option *)arg0)->state == 10) {
                if (previousState != i && ((struct Option *)arg0)->boxState == i) {
                    ((struct Option *)arg0)->callback(((struct Option *)arg0)->context, arg0, ((struct Option *)arg0)->selected, 9);
                }

        }
    }
}

/* extern */

void gcnewoption_entrypoint_1(u8 *arg0, s32 arg1) {
    struct RenderOption {
        s16 state;
        s16 count;
        u8 pad4[0x10];
        f32 spacing;
        u8 pad18[8];
        s32 box;
        u8 pad24[0x10];
        s16 height;
        u8 pad36[6];
        s32 boxes[17];
        f32 positions[17];
        u8 padC4[0x192];
        s16 offset;
    };
    s32 _gczoombox_entrypoint_2(s32, s32);
    void _gczoombox_entrypoint_28(s32, s16);
    s32 _gczoombox_entrypoint_29(s32);
    s32 _gczoombox_entrypoint_38(s32, s32);
    f32 savedPosition;
    s32 savedHeight;
    s32 index;
    s32 i;
    int count;
    struct RenderOption *box;
    struct RenderOption *entry;

    if (((struct RenderOption *)arg0)->state >= 2 && ((struct RenderOption *)arg0)->state < 12) {
        i = 0;
        box = ((struct RenderOption *)arg0);
        if (((struct RenderOption *)arg0)->count > 0) {
            do {
                index = func_80800000_gcnewoption((u8 *)((struct RenderOption *)arg0), i);
                _gczoombox_entrypoint_2(box->boxes[0], arg1);
                entry = (struct RenderOption *)((u8 *)((struct RenderOption *)arg0) + index * 4);
                if (entry->positions[0] < ((struct RenderOption *)arg0)->spacing) {
                    savedPosition = entry->positions[0];
                    savedHeight = _gczoombox_entrypoint_29(entry->boxes[0]);
                    _gczoombox_entrypoint_28(entry->boxes[0], ((struct RenderOption *)arg0)->height);
                    _gczoombox_entrypoint_38(entry->boxes[0], entry->positions[0] + ((struct RenderOption *)arg0)->spacing * ((struct RenderOption *)arg0)->count + ((struct RenderOption *)arg0)->offset);
                    _gczoombox_entrypoint_2(entry->boxes[0], arg1);
                    _gczoombox_entrypoint_38(entry->boxes[0], ((struct RenderOption *)arg0)->offset + savedPosition);
                    _gczoombox_entrypoint_28(entry->boxes[0], (s16)savedHeight);
                }
                count = ((struct RenderOption *)arg0)->count;
                if (((struct RenderOption *)arg0)->spacing * count < entry->positions[0]) {
                    savedPosition = entry->positions[0];
                    savedHeight = _gczoombox_entrypoint_29(entry->boxes[0]);
                    _gczoombox_entrypoint_28(entry->boxes[0], ((struct RenderOption *)arg0)->height);
                    _gczoombox_entrypoint_38(entry->boxes[0], entry->positions[0] - ((struct RenderOption *)arg0)->spacing * ((struct RenderOption *)arg0)->count + ((struct RenderOption *)arg0)->offset);
                    _gczoombox_entrypoint_2(entry->boxes[0], arg1);
                    _gczoombox_entrypoint_38(entry->boxes[0], ((struct RenderOption *)arg0)->offset + savedPosition);
                    _gczoombox_entrypoint_28(entry->boxes[0], (s16)savedHeight);
                }
                count = ((struct RenderOption *)arg0)->count;
                i++;
                box = (struct RenderOption *)((u8 *)box + 4);
            } while (i < count);
        }
        if (((struct RenderOption *)arg0)->box != 0) {
            _gczoombox_entrypoint_2(((struct RenderOption *)arg0)->box, arg1);
        }
    }
}

int gcnewoption_entrypoint_2(void)
{
	return 0x260;
}

s32 gcnewoption_entrypoint_3(u8 *arg0) {
    s32 offset;
    u8 *text;

    offset = 3;
    text = *(u8 **)((s8 *)arg0 + 0x23C);
    if (text[offset] != 0x8D) {
        do {
            offset += text[offset + 1];
            offset += 2;
        } while (text[offset] != 0x8D);
    }
    return (text + offset)[2] - 0x31;
}

/* extern */

void gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void gcnewoption_entrypoint_5(void *, s32, s32, s32, Unk80132ED0 *);
    func_80100074(arg0, arg1, 0x260);
    gcnewoption_entrypoint_5(func_80100094(arg0, arg1), arg2, arg3, arg4, arg0->unk0);
}

/* extern */

void gcnewoption_entrypoint_5(void *arg0, s32 arg1, s32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    struct OptionInit {
        s16 state;
        u8 pad2[10];
        s16 dialog;
        u8 padE[10];
        f32 timer;
        u8 flag80 : 1;
        u8 flag40 : 1;
        u8 flag20 : 1;
        u8 flag10 : 1;
        u8 flag08 : 1;
        u8 kind : 3;
        u8 flag180 : 1;
        u8 flag140 : 1;
        u8 flag120 : 1;
        u8 flag110 : 1;
        u8 flag108 : 1;
        u8 flag104 : 1;
        u8 flag102 : 1;
        u8 flag101 : 1;
        u16 rest;
        u8 pad20[0x90];
        s16 values[30];
        s16 positions[30];
        s16 colors[30][3];
        s16 sizes[30];
        s8 enabled[30];
        s16 mode;
        s16 count;
        s16 pad23A;
        u32 *text;
        s16 textId;
        s16 pad242;
        s32 callback;
        s32 parameter;
        Unk80132ED0 *context;
        s8 controller;
    };
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    s16 _gldialog_entrypoint_0();
    void gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
    struct OptionInit *option = arg0;
    s32 i;

    option->state = 0;
    option->text = _gldbstring_entrypoint_0(option->text, arg3);
    option->textId = arg3;
    option->callback = arg1;
    option->parameter = arg2;
    option->context = arg4;
    option->flag10 = 0;
    option->flag08 = 0;
    option->flag110 = 0;
    option->flag140 = 0;
    option->flag180 = 0;
    option->flag120 = 0;
    option->flag108 = 0;
    option->count = 0;
    option->flag104 = 0;
    option->mode = 13;
    option->dialog = _gldialog_entrypoint_0();
    option->flag102 = 0;
    gcnewoption_entrypoint_40(arg0, 44, 28, 50, 1.0f, 1.0f);
    option->controller = 0;
    option->timer = 0.0f;
    for (i = 0; i < 30; i++) {
        option->values[i] = 0;
        option->positions[i] = -1;
        option->colors[i][0] = 255;
        option->colors[i][1] = 255;
        option->colors[i][2] = 255;
        option->sizes[i] = 12;
        option->enabled[i] = 0;
    }
}

/* extern */

void gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1) {
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    gcnewoption_entrypoint_7(func_80100094(arg0, arg1));
    func_80100074(arg0, arg1, 0);
}

/* extern */

void gcnewoption_entrypoint_7(OptionState *a0) {
    void _gldbstring_entrypoint_2(s16 a0);
    void func_8080103C_gcnewoption(u8 *);
    if (((*(s16 *)((s8 *)(a0) + (0))) != 0xD) || ((*(s32 *)((s8 *)(a0) + (0x20))) != 0)) {
        func_8080103C_gcnewoption(a0->data);
    }
    _gldbstring_entrypoint_2(*(s16 *)((s8 *)a0 + 0x240));
}

void gcnewoption_entrypoint_8(s16 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void gcnewoption_entrypoint_9(s16 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

void gcnewoption_entrypoint_10(void *arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x1C];
        u8 upper : 5;
        u8 value : 3;
    };
    ((struct Fields *)arg0)->value = arg1;
}

void gcnewoption_entrypoint_11(s16 *arg0) {
    *arg0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800D28_gcnewoption.s")

void func_8080103C_gcnewoption(u8 *arg0)
{
  s32 _gczoombox_entrypoint_0(s32);
  s16 var_v0;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 var_s1;
  u8 *var_s0;
  var_v0 = *((s16 *) (((s8 *) arg0) + 2));
  var_s0 = arg0;
  var_s1 = 0;
  if (var_v0 > 0)
  {
    do
    {
      temp_a0 = *((s32 *) (((s8 *) var_s0) + 0x3C));
      if (temp_a0 != 0)
      {
        _gczoombox_entrypoint_0(temp_a0);
        *((s32 *) (((s8 *) var_s0) + 0x3C)) = 0;
        *((s8 *) (((s8 *) (arg0 + var_s1)) + 0x94)) = -1;
        var_v0 = *((s16 *) (((s8 *) arg0) + 2));
      }
      var_s1 += 1;
      var_s0 += 4;
    }
    while (var_s1 < var_v0);
  }
  temp_a0_2 = *((s32 *) (((s8 *) arg0) + 0x20));
  if (temp_a0_2 != 0)
  {
    _gczoombox_entrypoint_0(temp_a0_2);
    *((s32 *) (((s8 *) arg0) + 0x20)) = 0;
    var_v0 = 0xFF;
    *((s8 *) (((s8 *) arg0) + 0x24)) = var_v0;
  }
}

/* extern */

void func_808010E0_gcnewoption(u8 *arg0, s32 arg1) {
    s32 _gczoomboxdata_entrypoint_0(s16);
    u8 *temp;
    temp = (u8 *)((s8 *)arg0 + arg1 * 2);
    if ((*(s16 *)((s8 *)(arg0) + (0x238))) == 0) {
        _gczoomboxdata_entrypoint_0((*(s16 *)((s8 *)(temp) + (0x1DC))));
    }
}

s32 func_80801114_gcnewoption(void *arg0) {
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (6)));
    if (temp_v0 <= 0) {
        return 0;
    }
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (temp_v0 - 1);
    if (func_80800038_gcnewoption(arg0, (s32) (*(s16 *)((s8 *)(arg0) + (6)))) == -1) {
        (*(s16 *)((s8 *)(arg0) + (8))) = (s16) ((*(s16 *)((s8 *)(arg0) + (8))) - 1);
        (*(s16 *)((s8 *)(arg0) + (0xA))) = (s16) ((*(s16 *)((s8 *)(arg0) + (0xA))) - 1);
        if ((*(s16 *)((s8 *)(arg0) + (0xA))) < 0) {
            (*(s16 *)((s8 *)(arg0) + (0xA))) = (s16) ((*(s16 *)((s8 *)(arg0) + (2))) - 1);
        }
    }
    return 1;
}

s32 func_80801190_gcnewoption(void *arg0) {
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (6)));
    if (temp_v0 >= ((*(s16 *)((s8 *)(arg0) + (4))) - 1)) {
        return 0;
    }
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (temp_v0 + 1);
    if (func_80800038_gcnewoption(arg0, (s32) (*(s16 *)((s8 *)(arg0) + (6)))) == -1) {
        (*(s16 *)((s8 *)(arg0) + (8))) = (s16) ((*(s16 *)((s8 *)(arg0) + (8))) + 1);
        (*(s16 *)((s8 *)(arg0) + (0xA))) = (s16) ((*(s16 *)((s8 *)(arg0) + (0xA))) + 1);
        if ((*(s16 *)((s8 *)(arg0) + (0xA))) >= (*(s16 *)((s8 *)(arg0) + (2)))) {
            (*(s16 *)((s8 *)(arg0) + (0xA))) = 0;
        }
    }
    return 1;
}

void gcnewoption_entrypoint_12(OptionState *a0, u32 optionIndex, s16 textIndex) {
    s16 *temp_v0;

    temp_v0 = (s16 *)((s8 *)a0 + optionIndex * 2 + 0xEC);
    if (textIndex != *temp_v0) {
        *temp_v0 = textIndex;
    }
}

void gcnewoption_entrypoint_13(s32 arg0, s32 arg1, void *arg2) {
    s16 temp_v0;
    void *temp_v1;

    if (((temp_v0 = *(s16 *)arg2) != (*(s16 *)((s8 *)(temp_v1 = (s8 *)arg0 + arg1 * 6) + (0x128)))) || ((*(s16 *)((s8 *)(arg2) + (2))) != (*(s16 *)((s8 *)(temp_v1) + (0x12A)))) || ((*(s16 *)((s8 *)(arg2) + (4))) != (*(s16 *)((s8 *)(temp_v1) + (0x12C))))) {
        (*(s16 *)((s8 *)(temp_v1) + (0x128))) = temp_v0;
        (*(s16 *)((s8 *)(temp_v1) + (0x12A))) = (s16) (*(s16 *)((s8 *)(arg2) + (2)));
        (*(s16 *)((s8 *)(temp_v1) + (0x12C))) = (s16) (*(s16 *)((s8 *)(arg2) + (4)));
    }
}

void gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    (*(s16 *)((s8 *)(arg0) + (0x26))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg3;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg4;
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg4;
}

void func_808012C8_gcnewoption(s32 arg0) {
    void func_800FC6B0(u32 track_id);
    s32 track_id = 0;

    switch (arg0) {
        case 0:
            track_id = 0x96;
            break;
        case 1:
            track_id = 0x97;
            break;
        case -1:
            track_id = 0xF;
            break;
    }
    if (track_id != 0) {
        func_800FC6B0(track_id);
    }
}

void gcnewoption_entrypoint_15(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s16 *state;

    if (arg3 == 1) {
        state = (s16 *)((s8 *)arg1 + arg2 * 2);
        switch (state[0x58]) {
            case 0:
                state[0x58] = 1;
                (*(s32 (**)(s32, void *, s32))((s8 *)arg1 + 0x248))(*(s32 *)((s8 *)arg1 + 0x24C), arg1, arg2);
                break;
            case 1:
                state[0x58] = 0;
                (*(s32 (**)(s32, void *, s32))((s8 *)arg1 + 0x248))(*(s32 *)((s8 *)arg1 + 0x24C), arg1, arg2);
                break;
            case -1:
                (*(s32 (**)(s32, void *, s32))((s8 *)arg1 + 0x248))(*(s32 *)((s8 *)arg1 + 0x24C), arg1, arg2);
                break;
        }
        func_808012C8_gcnewoption(state[0x58]);
    } else {
        (*(s32 (**)(s32, void *, s32))((s8 *)arg1 + 0x248))(*(s32 *)((s8 *)arg1 + 0x24C), arg1, arg2);
    }
}

void gcnewoption_entrypoint_16(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    if (arg3 != 1) {
        (*(s32 (**)(s32, void *, s32))((s8 *)(arg1) + (0x248)))((*(s32 *)((s8 *)(arg1) + (0x24C))), arg1, arg2);
    }
}

s32 gcnewoption_entrypoint_17(s32 arg0, s32 arg1) {
    return (*(s16 *)((s8 *)(arg0) + ((arg1 * 2) + 0xB0))) == 0;
}

s32 gcnewoption_entrypoint_18(s32 arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x58] == 1;
}

s32 gcnewoption_entrypoint_19(s32 arg0, s32 arg1) {
    return ((*(s16 *)((s8 *)(arg0) + ((arg1 * 2) + 0xB0))) + 1) == 0;
}

s16 gcnewoption_entrypoint_20(s32 arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x58];
}

void gcnewoption_entrypoint_21(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 0;
}

void gcnewoption_entrypoint_22(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 1;
}

void gcnewoption_entrypoint_23(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = -1;
}

void gcnewoption_entrypoint_24(s32 arg0, s32 arg1, s32 arg2) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = arg2;
}

void gcnewoption_entrypoint_25(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 upper : 1;
        u8 flag : 1;
        u8 lower : 6;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 0;
        return;
    }
    ((struct Flags *)arg0)->flag = 1;
}

/* extern */

void gcnewoption_entrypoint_26(u8 *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 flag : 1;
        u8 lower : 7;
    };
    s32 _gczoombox_entrypoint_44(s32, s32);
    s32 func_80800000_gcnewoption(u8 *, s32);
    s32 var_a1;
    s32 temp_v0;
    s32 var_s1;

    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 0;
    } else {
        ((struct Flags *)arg0)->flag = 1;
    }
    var_s1 = 0;
    if ((*(s16 *)((s8 *)(arg0) + (2))) > 0) {
        do {
            temp_v0 = func_80800000_gcnewoption(arg0, var_s1);
            if (*(s32 *)((s32)arg0 + temp_v0 * 4 + 0x3C) != 0) {
                var_a1 = arg1 ? 0 : 1;
                _gczoombox_entrypoint_44(*(s32 *)((s32)arg0 + temp_v0 * 4 + 0x3C), var_a1);
            }
            var_s1 += 1;
        } while (var_s1 < (*(s16 *)((s8 *)(arg0) + (2))));
    }
}

/* extern */

void gcnewoption_entrypoint_27(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _gczoombox_entrypoint_40(s32, s32);
    s32 pad;
    s32 sp20;
    s32 temp_v0;
    s32 temp_v0_2;

    (*(s8 *)((s8 *)((arg0 + arg1)) + (0x218))) = arg2;
    temp_v0 = func_80800038_gcnewoption(arg0, arg1);
    sp20 = temp_v0;
    func_80800000_gcnewoption(arg0, temp_v0);
    if (sp20 != -1) {
        temp_v0_2 = func_80800000_gcnewoption(arg0, sp20);
        if (*(s32 *)((s32)arg0 + temp_v0_2 * 4 + 0x3C) != 0) {
            _gczoombox_entrypoint_40(*(s32 *)((s32)arg0 + temp_v0_2 * 4 + 0x3C), arg2);
        }
    }
}

void gcnewoption_entrypoint_28(void *arg0) {
    void gcnewoption_entrypoint_42(void *, f32);
    s32 _gczoombox_entrypoint_20(s32, f32, s32, s32, f32, s32, s32);
    struct Flags28 {
        u8 padding[0x1D];
        u8 upper : 2;
        u8 flag : 1;
        u8 lower : 5;
    };
    s32 temp_a0;
    s32 i;
    u8 *ptr;

    gcnewoption_entrypoint_42(arg0, 0.1f);
    temp_a0 = *(s32 *)((u8 *)arg0 + 0x20);
    ((struct Flags28 *)arg0)->flag = 1;
    if (temp_a0 != 0) {
        _gczoombox_entrypoint_20(temp_a0, 30.0f, 0, 2, 0.1f, 0, 0);
    }
    i = 0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        ptr = arg0;
        do {
            temp_a0 = *(s32 *)(ptr + 0x3C);
            if (temp_a0 != 0) {
                _gczoombox_entrypoint_20(temp_a0, 100.0f, 0, 2, 0.1f, 0, 0);
            }
            i++;
            ptr += 4;
        } while (i < *(s16 *)((u8 *)arg0 + 2));
    }
}

void gcnewoption_entrypoint_29(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 upper : 4;
        u8 flag : 1;
        u8 lower : 3;
    };
    ((struct Flags *)arg0)->flag = arg1;
}

void gcnewoption_entrypoint_30(s32 arg0, s16 *arg1) {
    s32 func_800DC128(s32, s32);
    u16 _gczoomboxdata_entrypoint_5(s32);
    s32 _gczoomboxdata_entrypoint_6(s32);
    void gcnewoption_entrypoint_31(s32, s32, s16);
    s16 chosen[30];
    s32 value;
    u16 key;
    s32 valid;
    s32 i;
    s32 previous;

    for (i = 0; i < *(s16 *)(arg0 + 4); i++) {
            valid = 0;
            do {
                value = func_800DC128(12, 210);
                if (_gczoomboxdata_entrypoint_6(value)) {
                    key = (u16)_gczoomboxdata_entrypoint_5(value);
                    if (key != _gczoomboxdata_entrypoint_5(*(s16 *)(arg0 + 0x236))) {
                        valid = 1;
                        if (arg1 != NULL) {
                            for (previous = 0; arg1[previous] != -1; previous++) {
                                if (key == _gczoomboxdata_entrypoint_5(arg1[previous])) {
                                    valid = 0;
                                    break;
                                }
                            }
                        }
                        if (valid) {
                            for (previous = i - 1; previous >= 0; previous--) {
                                if (key == _gczoomboxdata_entrypoint_5(chosen[previous])) {
                                    valid = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            } while (!valid);
            gcnewoption_entrypoint_31(arg0, i, value);
            chosen[i] = value;
    }
}

void gcnewoption_entrypoint_31(s32 arg0, s32 arg1, s16 arg2) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0x1DC))) = arg2;
}

/* extern */

void gcnewoption_entrypoint_32(void *arg0, s16 arg1) {
    s32 _gczoombox_entrypoint_37(s32, s16);
    (*(s16 *)((s8 *)(arg0) + (0x236))) = arg1;
    _gczoombox_entrypoint_37((*(s32 *)((s8 *)(arg0) + (0x20))), arg1);
}

void gcnewoption_entrypoint_33(void *arg0) {
    s32 _gczoombox_entrypoint_23(s32, s32);
    s32 temp_a2;
    s32 var_s0;
    u8 *var_s1;

    temp_a2 = *(s32 *)((u8 *)arg0 + 0x20);
    *(s16 *)((u8 *)arg0 + 0x238) = 1;
    if (temp_a2 != 0) {
        _gczoombox_entrypoint_23(temp_a2, 0);
    }
    var_s0 = 0;
    var_s1 = arg0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        do {
            _gczoombox_entrypoint_23(*(s32 *)(var_s1 + 0x3C), 0);
            var_s0 += 1;
            var_s1 += 4;
        } while (var_s0 < *(s16 *)((u8 *)arg0 + 2));
    }
}

/* extern */

void gcnewoption_entrypoint_34(void *arg0, s16 arg1) {
    struct Flags {
        u8 pad[0x1D];
        u8 unused : 5;
        u8 active : 1;
        u8 rest : 2;
    };
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_8();
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    s32 temp_a2;

    temp_a2 = (*(s32 *)((s8 *)(arg0) + (0x20)));
    if (temp_a2 != 0) {
        _gczoombox_entrypoint_32(temp_a2);
        _gczoombox_entrypoint_8((*(s32 *)((s8 *)(arg0) + (0x20))), _gldbstring_entrypoint_1((*(u32 **)((s8 *)(arg0) + (0x23C))), arg1));
        ((struct Flags *)arg0)->active = 1;
        (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x2C)));
    } else {
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808019D0_gcnewoption.s")

void func_80801B5C_gcnewoption(void *arg0) {
    struct Flags {
        u8 pad[0x1C];
        u8 moving : 1;
        u8 rest : 7;
    };
    void _gczoombox_entrypoint_28(s32, s16);
    s32 _gczoombox_entrypoint_29(s32);
    s32 _gczoombox_entrypoint_38(s32, s32);
    s32 i;
    s32 index;
    s32 next;
    u8 *entry;
    f32 target;
    f32 spacing;
    f32 limit;
    f32 delta;
    s16 height;
    s32 value;

    i = 0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        do {
            index = func_80800000_gcnewoption((u8 *)arg0, i);
            next = i + 1;
            target = (f32)next;
            target *= *(f32 *)((u8 *)arg0 + 0x14);
            limit = *(f32 *)((u8 *)arg0 + 0x14) * 1.9f;
            delta = target - *(f32 *)(((u8 *)arg0 + index * 4) + 0x80);
            if (limit < delta) {
                entry = (u8 *)arg0 + index * 4;
                *(f32 *)(entry + 0x80) = *(f32 *)((u8 *)arg0 + 0x14) * (f32)(*(s16 *)((u8 *)arg0 + 2) + 1);
                _gczoombox_entrypoint_28(*(s32 *)(entry + 0x3C), 0);
                *(s16 *)((u8 *)arg0 + 0x34) = 255;
            } else if (delta < -limit) {
                entry = (u8 *)arg0 + index * 4;
                *(f32 *)(entry + 0x80) = 0.0f;
                _gczoombox_entrypoint_28(*(s32 *)(entry + 0x3C), 0);
                *(s16 *)((u8 *)arg0 + 0x34) = 255;
            }
            entry = (u8 *)arg0 + index * 4;
            spacing = *(s16 *)((u8 *)arg0 + 0x34);
            if (spacing >= 20.0f) {
                *(s16 *)((u8 *)arg0 + 0x34) = spacing - 20.0f;
            }
            if ((*(f32 *)((u8 *)arg0 + 0x14)) * 0.66f < (*(f32 *)(entry + 0x80)) && (*(f32 *)(entry + 0x80)) < ((f32)*(s16 *)((u8 *)arg0 + 2) + 0.66f) * (*(f32 *)((u8 *)arg0 + 0x14))) {
                height = value = _gczoombox_entrypoint_29(*(s32 *)(entry + 0x3C));
                if (value < 236) {
                    _gczoombox_entrypoint_28(*(s32 *)(entry + 0x3C), (s16)height + 20);
                }
            } else {
                height = value = _gczoombox_entrypoint_29(*(s32 *)(entry + 0x3C));
                if (value >= 20) {
                    _gczoombox_entrypoint_28(*(s32 *)(entry + 0x3C), (s16)height - 20);
                }
            }
            if (target != (*(f32 *)(entry + 0x80))) {
                if (target < (*(f32 *)(entry + 0x80))) {
                    *(f32 *)(entry + 0x80) = (f32)((*(f32 *)(entry + 0x80)) - 4.0f);
                    if (*(volatile f32 *)(entry + 0x80) <= target) {
                        *(f32 *)(entry + 0x80) = target;
                    } else {
                        ((struct Flags *)arg0)->moving = 1;
                    }
                } else if ((*(f32 *)(entry + 0x80)) < target) {
                    *(f32 *)(entry + 0x80) = (f32)((*(f32 *)(entry + 0x80)) + 4.0f);
                    if (target <= *(volatile f32 *)(entry + 0x80)) {
                        *(f32 *)(entry + 0x80) = target;
                    } else {
                        ((struct Flags *)arg0)->moving = 1;
                    }
                }
                    _gczoombox_entrypoint_38(*(s32 *)(entry + 0x3C), (f32)*(s16 *)((u8 *)arg0 + 0x256) + (*(f32 *)(entry + 0x80)));
            }
            i = next;
        } while (next < *(s16 *)((u8 *)arg0 + 2));
    }
}

s32 func_80801E68_gcnewoption(void *arg0) {
    int _gczoombox_entrypoint_11();
    s32 _gczoombox_entrypoint_3();
    s32 _gczoombox_entrypoint_9(s32);
    s32 func_800D9078(f32 *);
    s32 pad;
    s32 result;
    s32 state;
    s32 box;
    s32 headerBox;
    s32 i;
    s32 headerState;
    u8 *ptr;
    u8 *stateptr;

    result = 1;
    ptr = arg0;
    i = 0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        stateptr = arg0;
        do {
            state = _gczoombox_entrypoint_3(*(s32 *)(ptr + 0x3C));
            switch (state) {
            case 0:
                if (i == 0) {
                    box = *(s32 *)((u8 *)arg0 + 0x20);
                    if (box == 0 || _gczoombox_entrypoint_3(box) == 1 ||
                        _gczoombox_entrypoint_3(*(s32 *)((u8 *)arg0 + 0x20)) == 2 ||
                        _gczoombox_entrypoint_3(*(s32 *)((u8 *)arg0 + 0x20)) == 3 ||
                        func_800D9078((f32 *)((u8 *)arg0 + 0x38))) {
                        _gczoombox_entrypoint_9(*(s32 *)(ptr + 0x3C));
                        if (*(f32 *)(ptr + 0x9C) == 0.0f) {
                            *(f32 *)(ptr + 0x9C) = *(f32 *)((u8 *)arg0 + 0x18);
                        }
                    }
                } else if (_gczoombox_entrypoint_3(*(s32 *)(ptr + 0x38)) == 1 ||
                           _gczoombox_entrypoint_3(*(s32 *)(ptr + 0x38)) == 2 ||
                           _gczoombox_entrypoint_3(*(s32 *)(ptr + 0x38)) == 3 ||
                           func_800D9078((f32 *)(ptr + 0x98))) {
                    _gczoombox_entrypoint_9(*(s32 *)(ptr + 0x3C));
                    if (*(f32 *)(ptr + 0x9C) == 0.0f) {
                        *(f32 *)(ptr + 0x9C) = *(f32 *)((u8 *)arg0 + 0x18);
                    }
                }
                break;
            case 1:
                _gczoombox_entrypoint_11(*(s32 *)(ptr + 0x3C));
                *(s8 *)(stateptr + 0x94) = state;
                break;
            case 2:
            case 3:
                *(s8 *)(stateptr + 0x94) = state;
                break;
            }
            if (*(s8 *)(stateptr + 0x94) <= 0) {
                result = 0;
            }
            i++;
            ptr += 4;
            stateptr++;
        } while (i < *(s16 *)((u8 *)arg0 + 2));
    }
    headerBox = *(s32 *)((u8 *)arg0 + 0x20);
    if (headerBox != 0) {
        headerState = _gczoombox_entrypoint_3(headerBox);
        switch (headerState) {
        case 2:
        case 3:
            break;
        case 0:
            result = 0;
            if (headerState != *((u8 *)arg0 + 0x24)) {
                _gczoombox_entrypoint_9(*(s32 *)((u8 *)arg0 + 0x20));
                _gczoombox_entrypoint_11(*(s32 *)((u8 *)arg0 + 0x20));
                if (*(f32 *)((u8 *)arg0 + 0x38) == 0.0f) {
                    *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)arg0 + 0x18);
                }
            }
            break;
        }
        *((u8 *)arg0 + 0x24) = headerState;
    }
    return result;
}

s32 func_808020C4_gcnewoption(void *arg0) {
    int _gczoombox_entrypoint_10();
    s32 _gczoombox_entrypoint_3();
    s32 _gczoombox_entrypoint_33(s32);
    s32 i;
    s32 busy;
    s32 result;
    s32 state;
    s32 firstState;
    s32 headerState;
    s32 finalState;
    s32 box;
    u8 *ptr;
    s8 *stateptr;

    result = 1;
    busy = 0;
    i = 0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        ptr = arg0;
        do {
            firstState = _gczoombox_entrypoint_3(*(s32 *)(ptr + 0x3C));
            if (firstState == 0 || firstState == 2 || firstState == 3) {
                busy = 1;
            }
            i++;
            ptr += 4;
        } while (i < *(s16 *)((u8 *)arg0 + 2));
        i = 0;
    }
    box = *(s32 *)((u8 *)arg0 + 0x20);
    if (box != 0) {
        headerState = _gczoombox_entrypoint_3(box);
        switch (headerState) {
            case 0:
            case 2:
            case 3:
                busy = 1;
                break;
        }
    }
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        ptr = arg0;
        do {
            state = _gczoombox_entrypoint_3(*(s32 *)(ptr + 0x3C));
            switch (state) {
                case 0:
                case 2:
                case 3:
                    stateptr = (s8 *)arg0 + i;
                    result = 0;
                    if (state != stateptr[0x94]) {
                        _gczoombox_entrypoint_33(*(s32 *)(ptr + 0x3C));
                    }
                    stateptr[0x94] = state;
                    break;
                case 4:
                    result = 0;
                    if (busy == 0) {
                        stateptr = (s8 *)arg0 + i;
                        if (state != stateptr[0x94]) {
                            _gczoombox_entrypoint_10(*(s32 *)(ptr + 0x3C));
                        }
                        stateptr[0x94] = state;
                    }
                    break;
                case 5:
                    ((u8 *)arg0 + i)[0x94] = state;
                    break;
                default:
                    ((u8 *)arg0 + i)[0x94] = state;
                    break;
            }
            i++;
            ptr += 4;
        } while (i < *(s16 *)((u8 *)arg0 + 2));
    }
    box = *(s32 *)((u8 *)arg0 + 0x20);
    if (box != 0) {
        finalState = _gczoombox_entrypoint_3(box);
        switch (finalState) {
            case 1:
            case 5:
            case 6:
                break;
            case 0:
            case 2:
            case 3:
                result = 0;
                if (finalState != ((u8 *)arg0)[0x24]) {
                    _gczoombox_entrypoint_33(*(s32 *)((u8 *)arg0 + 0x20));
                }
                break;
            case 4:
                result = 0;
                if (finalState != ((u8 *)arg0)[0x24]) {
                    _gczoombox_entrypoint_10(*(s32 *)((u8 *)arg0 + 0x20));
                }
                break;
        }
        ((u8 *)arg0)[0x24] = finalState;
    }
    return result;
}

s32 func_808022E0_gcnewoption(void *arg0) {
    int _gczoombox_entrypoint_10();
    void _gczoombox_entrypoint_12();
    s32 _gczoombox_entrypoint_3();
    s32 index;
    s32 state;
    s32 i;
    s32 result;
    u8 *ptr;
    s8 *stateptr;

    result = 1;
    i = 0;
    if (*(s16 *)((u8 *)arg0 + 2) > 0) {
        do {
            if (func_80800070_gcnewoption(arg0, i) != *(s16 *)((u8 *)arg0 + 6)) {
                index = func_80800000_gcnewoption((u8 *)arg0, i);
                state = _gczoombox_entrypoint_3(((s32 *)arg0 + index)[15]);
                stateptr = (s8 *)arg0 + index;
                switch (state) {
                    case 0:
                    case 2:
                    case 3:
                        result = 0;
                        ptr = (u8 *)((s32 *)arg0 + index);
                        if (state != stateptr[0x94]) {
                            _gczoombox_entrypoint_12(*(s32 *)(ptr + 0x3C));
                            _gczoombox_entrypoint_10(*(s32 *)(ptr + 0x3C));
                        }
                        break;
                    case 4:
                        if (state != stateptr[0x94]) {
                            _gczoombox_entrypoint_10(((s32 *)arg0 + index)[15]);
                        }
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
                stateptr[0x94] = state;
            }
            i++;
        } while (i < *(s16 *)((u8 *)arg0 + 2));
    }
    return result;
}

s32 func_8080241C_gcnewoption(void *arg0) {
    s32 _gczoombox_entrypoint_3();
    s32 _gczoombox_entrypoint_33(s32);
    s32 index;
    s32 state;
    s32 i;
    s32 result;

    result = 1;
    i = 0;
    if (*(s16 *)(((u8 *)arg0) + 2) > 0) {
        do {
            if (func_80800070_gcnewoption(((u8 *)arg0), i) != *(s16 *)(((u8 *)arg0) + 6)) {
                index = func_80800000_gcnewoption(((u8 *)arg0), i);
                state = _gczoombox_entrypoint_3(((s32 *)((u8 *)arg0) + index)[15]);
                switch (state) {
                    case 0:
                    case 2:
                    case 3:
                        result = 0;
                        if (state != *(s8 *)(((u8 *)arg0) + index + 0x94)) {
                            _gczoombox_entrypoint_33(((s32 *)((u8 *)arg0) + index)[15]);
                            ((s16 *)((u8 *)arg0) + index)[40] = -1;
                        }
                        break;
                    case 4:
                    case 5:
                        break;
                    default:
                    case 1:
                        break;
                }
                ((u8 *)arg0)[index + 0x94] = state;
            }
            i++;
        } while (i < *(s16 *)(((u8 *)arg0) + 2));
    }
    return result;
}

s32 func_80802534_gcnewoption(u8 *arg0) {
    s32 _gczoombox_entrypoint_3();
    s32 _gczoombox_entrypoint_9(s32);
    int _gczoombox_entrypoint_11();
    s32 index;
    s32 state;
    s32 i;
    s32 result;
    u8 *ptr;

    result = 1;
    i = 0;
    if (*(s16 *)(arg0 + 2) > 0) {
        do {
            if (func_80800070_gcnewoption(arg0, i) != *(s16 *)(arg0 + 6)) {
                index = func_80800000_gcnewoption(arg0, i);
                state = _gczoombox_entrypoint_3(((s32 *)arg0 + index)[15]);
                switch (state) {
                    case 0:
                        result = 0;
                        ptr = (u8 *)((s32 *)arg0 + index);
                        if (state != *(s8 *)(arg0 + index + 0x94)) {
                            _gczoombox_entrypoint_9(*(s32 *)(ptr + 0x3C));
                            _gczoombox_entrypoint_11(*(s32 *)(ptr + 0x3C));
                        }
                        break;
                    case 4:
                        result = 0;
                        if (state != *(s8 *)(arg0 + index + 0x94)) {
                            _gczoombox_entrypoint_11(((s32 *)arg0 + index)[15]);
                        }
                        break;
                    case 2:
                        break;
                }
                *(s8 *)(arg0 + index + 0x94) = state;
            }
            i++;
        } while (i < *(s16 *)(arg0 + 2));
    }
    return result;
}

s32 func_80802674_gcnewoption(void *arg0) {
    int _gczoombox_entrypoint_10();
    s32 _gczoombox_entrypoint_3();
    s32 result;
    s32 index;
    s32 state;

    result = 1;
    index = func_80800000_gcnewoption(((u8 *)arg0), func_80800038_gcnewoption(((u8 *)arg0), *(s16 *)(((u8 *)arg0) + 6)));
    state = _gczoombox_entrypoint_3(((s32 *)((u8 *)arg0) + index)[15]);
    switch (state) {
        case 0:
        case 3:
            if (state != *(s8 *)(((u8 *)arg0) + index + 0x94)) {
                _gczoombox_entrypoint_34(((s32 *)((u8 *)arg0) + index)[15]);
            }
            result = 0;
            break;
        case 4:
            if (state != *(s8 *)(((u8 *)arg0) + index + 0x94)) {
                _gczoombox_entrypoint_10(((s32 *)((u8 *)arg0) + index)[15]);
            }
            result = 0;
            break;
        case 5:
        case 6:
            break;
        default:
        case 1:
        case 2:
            break;
    }
    *(s8 *)(((u8 *)arg0) + index + 0x94) = state;
    if (*(s32 *)(((u8 *)arg0) + 0x20)) {
        state = _gczoombox_entrypoint_3(*(s32 *)(((u8 *)arg0) + 0x20));
        switch (state) {
            case 0:
            case 2:
            case 3:
            case 6:
                result = 0;
                if (state != ((u8 *)arg0)[0x24]) {
                    _gczoombox_entrypoint_34(*(s32 *)(((u8 *)arg0) + 0x20));
                }
                break;
            case 4:
                result = 0;
                if (state != ((u8 *)arg0)[0x24]) {
                    _gczoombox_entrypoint_10(*(s32 *)(((u8 *)arg0) + 0x20));
                }
                break;
        }
        ((u8 *)arg0)[0x24] = state;
    }
    return result;
}

void func_808027DC_gcnewoption(void *arg0, s32 arg1) {
    void _gczoombox_entrypoint_27(s32, s16 *);
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_36();
    s32 _gczoombox_entrypoint_40(s32, s32);
    int _gczoombox_entrypoint_8();
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    s16 _gldialog_entrypoint_0();
    s32 source;
    s32 dest;
    s32 text;
    s32 language;

    source = func_80800070_gcnewoption(arg0, arg1);
    dest = func_80800000_gcnewoption(arg0, arg1);
    text = *(s16 *)(((u8 *)arg0 + source * 2) + 0xEC);
    language = _gldialog_entrypoint_0();
    if (text != ((s16 *)arg0)[func_80800000_gcnewoption(arg0, arg1) + 0x28] ||
        (*(s16 *)(((u8 *)arg0 + dest * 6) + 0x5A) != *(s16 *)(((u8 *)arg0 + source * 6) + 0x128)) ||
        *(s16 *)(((u8 *)arg0 + dest * 6) + 0x5C) != *(s16 *)(((u8 *)arg0 + source * 6) + 0x12A) ||
        *(s16 *)(((u8 *)arg0 + dest * 6) + 0x5E) != *(s16 *)(((u8 *)arg0 + source * 6) + 0x12C) ||
        ((u8 *)arg0)[dest + 0x78] != *(s16 *)(((u8 *)arg0 + source * 2) + 0x1DC) ||
        language != *(s16 *)((u8 *)arg0 + 0xC)) {
        _gczoombox_entrypoint_32(*(s32 *)(((u8 *)arg0 + dest * 4) + 0x3C));
        _gczoombox_entrypoint_27(*(s32 *)(((u8 *)arg0 + dest * 4) + 0x3C), (s16 *)(((u8 *)arg0 + source * 6) + 0x128));
        _gczoombox_entrypoint_8(*(s32 *)(((u8 *)arg0 + dest * 4) + 0x3C), _gldbstring_entrypoint_1(*(u32 **)((u8 *)arg0 + 0x23C), text));
        _gczoombox_entrypoint_40(*(s32 *)(((u8 *)arg0 + dest * 4) + 0x3C), ((u8 *)arg0)[source + 0x218]);
        _gczoombox_entrypoint_36(*(s32 *)(((u8 *)arg0 + dest * 4) + 0x3C), *(s16 *)(((u8 *)arg0 + source * 2) + 0x1DC));
        *(s16 *)((u8 *)arg0 + dest * 2 + 0x50) = text;
        *(s16 *)(((u8 *)arg0 + dest * 6) + 0x5A) = *(s16 *)(((u8 *)arg0 + source * 6) + 0x128);
        *(s16 *)(((u8 *)arg0 + dest * 6) + 0x5C) = *(s16 *)(((u8 *)arg0 + source * 6) + 0x12A);
        *(s16 *)(((u8 *)arg0 + dest * 6) + 0x5E) = *(s16 *)(((u8 *)arg0 + source * 6) + 0x12C);
        ((u8 *)arg0 + dest)[0x78] = *(s16 *)(((u8 *)arg0 + source * 2) + 0x1DC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802998_gcnewoption.s")

s32 func_80802A9C_gcnewoption(u8 *arg0) {
    s32 i;
    u8 *ptr;
    i = 0;
    ptr = arg0;
    if (*(s16 *)(arg0 + 2) > 0) {
        do {
            * (s8 *)(ptr + 0x94) = -1;
            i++;
            ptr++;
        } while (i < *(s16 *)(arg0 + 2));
    }
    *(u8 *)(arg0 + 0x24) = 0xFF;
}

/* extern */

void gcnewoption_entrypoint_35(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_80101074(s32);
    s32 func_8010114C(s32, s32, s32);
    s16 local[2];
    s32 saved;

    saved = arg0;
    local[0] = (u16)arg2;
    local[1] = (u16)arg3;
    func_80101074(arg1);
    func_8010114C(saved, 0x20, *(s32 *)&local[0]);
}

void gcnewoption_entrypoint_36(void *arg0) {
    struct Flags {
        u8 pad[0x1C];
        u8 upper : 3;
        u8 enabled : 1;
        u8 lower : 4;
    };
    ((struct Flags *)arg0)->enabled = 1;
}

void func_80802B24_gcnewoption(void *arg0, s32 arg1) {
    struct Flags {
        u8 pad[0x1C];
        u8 upper : 4;
        u8 enabled : 1;
        u8 lower : 3;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->enabled = 1;
        return;
    }
    ((struct Flags *)arg0)->enabled = 0;
}

/* extern */

u32 gcnewoption_entrypoint_37(OptionState *a0, u32 a1) {
    s32 func_80802A9C_gcnewoption(u8 *);
    struct Flags {
        u8 pad[0x1C];
        u8 upper : 2;
        u8 enabled : 1;
        u8 lower : 5;
    };
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(a0) + (0)));
    if ((temp_v0 == 5) || (temp_v0 == 4)) {
        if (a1 != 0) {
            ((struct Flags *)a0)->enabled = 1;
        } else {
            ((struct Flags *)a0)->enabled = 0;
        }
        func_80802A9C_gcnewoption(a0->data);
        (*(s16 *)((s8 *)(a0) + (0))) = 6;
        return 1U;
    }
    return 0U;
}

/* extern */

s32 gcnewoption_entrypoint_38(u8 *arg0, s32 arg1) {
    s32 _gczoombox_entrypoint_41(s32, s32);
    s32 sp24;
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (0)));
    if ((temp_v0 == 5) || (temp_v0 == 0xA)) {
        sp24 = func_80800000_gcnewoption(arg0, func_80800038_gcnewoption(arg0, (s32) (*(s16 *)((s8 *)(arg0) + (6)))));
        func_80802A9C_gcnewoption(arg0);
        (*(s16 *)((s8 *)(arg0) + (0))) = 9;
        func_80802B24_gcnewoption(arg0, 1);
        if (arg1 != 0) {
            _gczoombox_entrypoint_41((*(s32 *)((s8 *)(((0, arg0) + (sp24 * 4))) + (0x3C))), 0x447A0000);
        }
        return 1;
    }
    return 0;
}

s32 gcnewoption_entrypoint_39(u8 *arg0)
{
  s32 _gczoombox_entrypoint_41(s32, s32);
  s32 func_80800000_gcnewoption(u8 *, s32);
  s32 func_80802A9C_gcnewoption(u8 *);
  s32 sp24;
  s16 temp_v0;
  temp_v0 = *((s16 *) (((s8 *) arg0) + 0));
  if ((temp_v0 == 5) || (temp_v0 == 9))
  {
    sp24 = func_80800000_gcnewoption(arg0, func_80800038_gcnewoption(arg0, (s32) (*((s16 *) (((s8 *) arg0) + 6)))));
    func_80802A9C_gcnewoption(arg0);
    *((s16 *) (((s8 *) arg0) + 0)) = 0xA;
    _gczoombox_entrypoint_41(*((s32 *) (((s8 *) (((0, arg0)) + (sp24 * 4))) + 0x3C)), 0x42340000);
    return 1;
  }
  return 0;
}

void gcnewoption_entrypoint_40(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    (*(s16 *)((s8 *)(arg0) + (0x254))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x256))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) arg3;
    (*(f32 *)((s8 *)(arg0) + (0x258))) = arg4;
    (*(f32 *)((s8 *)(arg0) + (0x25C))) = arg5;
}

/* extern */

void gcnewoption_entrypoint_41(OptionState *arg0, s32 arg1) {
    s32 temp_a2;

    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) arg1;
    (*(s16 *)((s8 *)(arg0) + (0xA))) = 0;
    (*(s16 *)((s8 *)(arg0) + (8))) = (s16) (arg1 - ((s32) ((*(s16 *)((s8 *)(arg0) + (2))) - 1) / 2));
    if ((*(s16 *)((s8 *)(arg0) + (8))) < 0) {
        (*(s16 *)((s8 *)(arg0) + (8))) = 0;
    }
    temp_a2 = (*(s16 *)((s8 *)(arg0) + (4))) - (*(s16 *)((s8 *)(arg0) + (2)));
    if (temp_a2 < (*(s16 *)((s8 *)(arg0) + (8)))) {
        (*(s16 *)((s8 *)(arg0) + (8))) = temp_a2;
    }
    func_808010E0_gcnewoption(arg0->data, arg1);
}

void gcnewoption_entrypoint_42(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 24) = arg1;
}

/* extern */

s32 gcnewoption_entrypoint_43(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _gczoombox_entrypoint_21(s32, s32);
    s32 func_80800000_gcnewoption(u8 *, s32);
    s32 temp_v0;
    s32 temp_v1;
    u8 *temp_ptr;

    temp_v0 = func_80800038_gcnewoption(arg0, arg1);
    if (temp_v0 != -1) {
        temp_v1 = func_80800000_gcnewoption(arg0, temp_v0);
        temp_ptr = (u8 *)((s32 *)arg0 + temp_v1);
        _gczoombox_entrypoint_21((*(s32 *)((s8 *)temp_ptr + 0x3C)), arg2);
        return 1;
    }
    return 0;
}

/* extern */

void gcnewoption_entrypoint_44(void *arg0, s32 arg1) {
    s32 _gczoombox_entrypoint_20(s32, f32, s32, s32, f32, s32, s32);
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_8();
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    struct Flags {
        u8 padding[0x1C];
        u32 upper : 10;
        u32 wide : 1;
        u32 hidden : 1;
        u32 middle : 1;
        u32 initialized : 1;
        u32 lower : 18;
    };
    ((struct Flags *)arg0)->hidden = arg1;
    if (arg1 != 0) {
        _gczoombox_entrypoint_20((*(s32 *)((s8 *)(arg0) + (0x20))), 0.0f, 0, 2, 0.1f, 0, 0);
        return;
    }
    if (!((struct Flags *)arg0)->initialized) {
        _gczoombox_entrypoint_32((*(s32 *)((s8 *)(arg0) + (0x20))));
        _gczoombox_entrypoint_8((*(s32 *)((s8 *)(arg0) + (0x20))), _gldbstring_entrypoint_1((*(u32 **)((s8 *)(arg0) + (0x23C))), (*(s16 *)((s8 *)(arg0) + (0x26)))));
        ((struct Flags *)arg0)->initialized = 1;
    }
    if (((struct Flags *)arg0)->wide) {
        _gczoombox_entrypoint_20((*(s32 *)((s8 *)(arg0) + (0x20))), 30.0f, 0, 2, 0.1f, 0, 0);
        return;
    }
    _gczoombox_entrypoint_20((*(s32 *)((s8 *)(arg0) + (0x20))), 15.0f, 0, 2, 0.1f, 0, 0);
}

s32 gcnewoption_entrypoint_45(s16 *arg0) {
    return arg0[3];
}

void gcnewoption_entrypoint_46(s8 *arg0, s32 arg1) {
    arg0[592] = arg1;
}

s32 gcnewoption_entrypoint_47(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x24))) == 3;
}

int gcnewoption_entrypoint_48(s16 *arg0) {
    return *arg0 >= 3 && *arg0 < 0xB;
}

void gcnewoption_entrypoint_49(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 upper : 6;
        u8 flag : 1;
        u8 lower : 1;
    };
    ((struct Flags *)arg0)->flag = arg1;
}

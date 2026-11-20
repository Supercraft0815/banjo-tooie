#include "common.h"
#ifdef BT_NATIVE
#include "gc/dialog_state.h"
typedef GcDialogState DialogInit;
#else
typedef struct {
    u8 pad0[0x100];
    s32 unk100;
    s32 unk104[2];
    s32 unk10C[2];
    s8 unk114[2];
    s8 unk116[2];
    s16 unk118[2];
    struct { BT_BITFIELD_ORDER(u8 a:2, u8 c : 4); u8 b:2; BT_BITFIELD_ORDER(u8 c:4, u8 a : 2); } unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    u8 pad128[0x30];
    s8 unk158;
    s8 unk159;
    s16 unk15A;
    s8 unk15C;
    s8 unk15D;
    u16 flag7:1;
    u32 flag6:1;
    u32 flag5:1;
    u32 flag4:1;
    u8 flag3:1;
    u32 flag2:1;
    u32 flag1:1;
    u32 flag0:1;
    u8 mode3:2;
    u8 mode2:2;
    u8 mode1:2;
    u32 mode0:2;
    s8 unk160;
    u8 nibble1:4;
    u16 nibble0:4;
    s16 unk162;
    s16 unk164;
    s8 unk166;
    u8 pad167;
    s32 unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s8 unk180;
    u8 pad181[3];
    struct {
        s16 unk0;
        s16 unk2;
        f32 vec[3];
        s32 unk10;
        s16 unk14;
        u8 pad16[2];
        s32 unk18;
        s32 unk1C;
        s32 unk20;
        s32 unk24;
        s32 unk28;
    } entries[4];
} DialogInit;
#endif
void gcdialogDll_entrypoint_0(DialogInit *arg0) {
    void func_800EFD24(f32 *);
    DialogInit *dialog;
    s32 i;
    u32 mode;

    arg0->unk100 = 0;
#if defined(BT_NATIVE)
    arg0->unk12C = 0;
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (arg0 == &gc_dialog_state) {
        s32 n;
        for (n = 0; n < 2; n++) { gc_dialog_set_text_entry(arg0, n, NULL); gc_dialog_set_text_data(arg0, n, NULL); }
        for (n = 0; n < 3; n++) gc_dialog_set_box(arg0, n, NULL);
        gc_dialog_set_caller(arg0, NULL);
        for (n = 0; n < 3; n++) gc_dialog_set_callback(arg0, n, NULL);
        gc_dialog_set_source(arg0, NULL);
        for (n = 0; n < 4; n++) {
            gc_dialog_native_state.requests[n].actor = NULL;
            gc_dialog_native_state.requests[n].callback = NULL;
            gc_dialog_native_state.requests[n].callback2 = NULL;
            gc_dialog_native_state.requests[n].callback3 = NULL;
        }
    }
#endif
    for (i = 0; i < 2; i++) {
        arg0->unk104[i] = 0;
        arg0->unk114[i] = 0;
        arg0->unk120[i] = 0;
        arg0->unk116[i] = 0;
        arg0->unk118[i] = -1;
        arg0->unk10C[i] = 0;
        arg0->unk11C[i].a = 0;
        arg0->unk11C[i].b = 0;
    }
    for (i = 0; i < 4; i++) {
        arg0->entries[i].unk0 = -1;
        arg0->entries[i].unk2 = 0;
        arg0->entries[i].unk10 = 0;
        arg0->entries[i].unk14 = 0;
        arg0->entries[i].unk18 = 0;
        arg0->entries[i].unk1C = 0;
        arg0->entries[i].unk20 = 0;
        arg0->entries[i].unk24 = 0;
        func_800EFD24(arg0->entries[i].vec);
    }
#if defined(BT_NATIVE)
    arg0->status15C = 0;
#else
    arg0->unk15C = 0;
#endif
    arg0->unk15A = arg0->flag5 = 0;
    dialog = arg0;
    dialog->mode0 = 0;
    dialog->mode3 = dialog->mode2 = dialog->mode1 = dialog->mode0;
#if defined(BT_NATIVE)
    dialog->count15D = dialog->flag7 = 0;
#else
    dialog->unk15D = dialog->flag7 = 0;
#endif
    dialog->unk160 = -1;
    dialog->flag6 = 1;
    dialog->nibble0 = 0;
    mode = dialog->nibble0;
    dialog->nibble1 = mode;
    dialog->unk162 = -1;
    dialog->unk164 = -1;
    dialog->unk168 = 0;
    dialog->unk170 = 0;
    dialog->unk174 = 0;
    dialog->unk178 = 0;
    dialog->unk166 = 12;
    dialog->unk159 = 0;
    dialog->unk158 = -1;
    dialog->flag3 = 1;
    dialog->unk180 = 1;
}

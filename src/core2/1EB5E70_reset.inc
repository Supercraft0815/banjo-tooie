#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EB5E70_reset_native.inc"
#else
void func_800DE318(void) {
    extern GeoCommandFunction *D_80123198[];

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
    D_8012C82C = 30000.0f;
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

#endif

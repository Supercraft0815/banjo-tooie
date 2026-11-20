typedef struct {
    s16 actor_id, expression;
    struct { s16 id, rate, volume, fraction; } sounds[7];
    s32 collision, flags40, flags44;
    s16 field48, radius;
    f32 acceleration;
    s16 minimum, maximum, field54, field56, field58, field5a;
} CoasterTrackConfig;
typedef char bt_assert_coaster_track_size[sizeof(CoasterTrackConfig) == 0x5C ? 1 : -1];
extern CoasterTrackConfig coasterTracks[9];

#ifdef BT_NATIVE
s32 sucoasterdata_entrypoint_0(Actor *actor) {
    u32 id = actor->unk0->unk24 >> 22;
    s32 i;
    for (i = 0; i < (s32)ARRLEN(coasterTracks); i++) {
        if (id == (u16)coasterTracks[i].actor_id) return i;
    }
    return 0;
}
#else
s32 sucoasterdata_entrypoint_0(void **arg0) { extern s32 D_808003C0_sucoasterdata[23]; extern s32 D_8080041C_sucoasterdata[184]; u8 *var_a0; s32 var_v1; u32 temp_t7; temp_t7 = *(u32 *)((u8 *)*arg0 + 0x24) >> 22; var_v1 = 1; if (temp_t7 == *(u16 *)D_808003C0_sucoasterdata) { return 0; } var_a0 = (u8 *)D_8080041C_sucoasterdata; loop_3: if (temp_t7 == *(u16 *)var_a0) { return var_v1; } if (temp_t7 == *(u16 *)(var_a0 + 0x5C)) { return var_v1 + 1; } if (temp_t7 == *(u16 *)(var_a0 + 0xB8)) { return var_v1 + 2; } if (temp_t7 == *(u16 *)(var_a0 + 0x114)) { return var_v1 + 3; } var_v1 += 4; var_a0 += 0x170; if (var_v1 == 9) { return 0; } goto loop_3; }
#endif

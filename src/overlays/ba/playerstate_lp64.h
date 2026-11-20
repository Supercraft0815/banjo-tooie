typedef struct { void (*callback)(s32); s32 argument; u8 active; } PlayerLifecycle;
typedef struct player_state_s {
 union { void *component_slots[86]; struct {
 struct ba_alarm_s *alarm; struct ba_anim_s *anim; struct ba_attach_s *attach;
 struct ba_unknown_c_s *unkC; struct ba_babykaz_s *babykaz; struct ba_backpack_s *backpack;
 f32 *unk18; struct ba_bee_s *bee; struct ba_unknown_20_s *unk20;
 struct ba_boost_s *boost; struct ba_bounce_s *bounce; struct ba_unknown_2C_s *unk2C;
 union { void *component30; s32 unk30; }; struct ba_buzz_s *buzz; u8 pad38[8];
 struct ba_state_timer_list_s *state_timer; struct ba_key_s *key; struct ba_cough_s *cough;
 union { u8 pad48[24]; struct { u8 *action_flags; u8 *death_state; void *model; }; };
 struct ba_drone_s *drone;
 union { u8 pad58[80]; struct { void *pad[3]; PlayerEggSelection *slot; } eggSelection; };
 struct ba_flag_s *flag; u8 pad84[16]; union { void *component8C; f32 unk8C; };
 u8 pad90[8]; union { f32 **unk94; struct PlayerCollisionState *collisionState; }; f32 *unk98; struct ba_unk_9C *unk9C; f32 *unkA0;
 struct ba_input_s *input; union { u8 padA8[48]; struct { u8 prefixA8[32]; PlayerLifecycle *lifecycle; u8 suffixBC[8]; }; }; struct ba_unknown_C0_s *unkC0;
 union { u8 padC4[8]; u8 *physics_flags; }; union { void *physics; s32 unkC8; }; u8 padCC[32]; f32 *unkDC;
 u8 padE0[8]; f32 *unkE4; u8 padE8[16]; u8 *unkF0; struct ba_roll_s *roll;
 struct ba_yaw_s *yaw; s32 *unkFC; u8 pad100[8]; u8 *unk104; u8 *unk108;
 u8 pad10C[16]; u8 pad114[8]; u8 pad118[16]; struct bs_state_s *state;
 s32 *unk124; struct ba_stick_s *stick; s32 *unk12C; u8 pad130[16];
 u8 *unk138; struct ba_timer_s *timer; struct ba_translate_s *translate;
 struct ba_van_s *van; struct ba_wandglow_s *wandglow; struct ba_washer_s *washer;
 u8 *unk150; struct ba_wobble_s *wobble;
 }; };
    s32 unk158;
    union {
        s32 word;
        u8 bytes[4];
    } unk15C; // Some sort of state
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    union {
        s32 word;
        u8 bytes[4];
    } unk164;
    union {
        s32 word;
        u8 bytes[4];
    } unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x4]; s32 unk17C; u8 pad180[0x4];
    s32 unk184;
    /* 0x188 */ union {
        void *state_mem; // per-state memory, see bastatemem_entrypoint_0
        struct bs_kazfly_s *kazfly;
    };
} PlayerState;

typedef struct {
    s32 kind;
    f32 speed, minimum, maximum;
} FirstpEggConfig;
typedef struct {
    s16 id, flags;
    f32 duration;
} FirstpAnimation;
typedef struct {
    s16 id, volume;
    f32 pitch;
} FirstpSound;
typedef struct {
    s16 id, pad;
    f32 duration, scale;
} FirstpAnimationScale;
typedef struct {
    f32 *parameters[6];
    u8 equipment[28];
} FirstpEquipment;
typedef struct {
    FirstpSound sounds[12];
    FirstpSound *sets[5];
} FirstpSoundSets;
typedef struct {
    u8 scores[7][7][2];
    u8 padding[2];
} FirstpScores;

extern FirstpConfig D_8080A6C8_bsfirstp;
extern FirstpConfig D_8080A714_bsfirstp;
extern FirstpConfig D_8080A760_bsfirstp;
extern FirstpConfig D_8080A7AC_bsfirstp;
extern FirstpConfig D_8080A7F8_bsfirstp;
extern FirstpConfig D_8080A844_bsfirstp;
extern f32 D_8080A8A8_bsfirstp[35];
extern f32 D_8080A934_bsfirstp[35];
extern f32 D_8080A9C0_bsfirstp[35];
extern f32 D_8080AA4C_bsfirstp[35];
extern f32 D_8080AAD8_bsfirstp[35];
extern f32 D_8080AB64_bsfirstp[35];
extern FirstpAnimation D_8080AEE4_bsfirstp[10];
extern FirstpAnimation D_8080AF34_bsfirstp[3];
extern FirstpAnimation D_8080AF4C_bsfirstp[3];
extern FirstpAnimation D_8080AF64_bsfirstp[10];
extern FirstpSound D_8080B280_bsfirstp[12];
extern FirstpSound D_8080B2E0_bsfirstp[12];
extern FirstpSound D_8080B340_bsfirstp[12];
extern FirstpSound D_8080B3A0_bsfirstp[12];
extern FirstpSoundSets D_8080B400_bsfirstp;

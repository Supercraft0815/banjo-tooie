#include "core2/actor_animation_entry.h"

typedef struct {
    s32 model;
    f32 scale;
    s32 alternateModel;
    f32 alternateScale;
    ActorAnimationEntry *animations;
    f32 speed;
} QuizContestant;
typedef struct {
    s8 camera, transition, group, padding;
    f32 duration;
} QuizCameraStep;
typedef struct {
    QuizCameraStep steps[38];
    s8 scoreDeltas[6];
    u8 padding[2];
} QuizCameraScript;
typedef struct {
    s32 values[3];
} QuizChoices;
typedef struct {
    f32 values[4];
} QuizTimes4;
typedef struct {
    f32 values[6];
} QuizTimes6;

extern ActorAnimationEntry D_80806D00_chquiz[16];
extern ActorAnimationEntry D_80806D80_chquiz[16];
extern ActorAnimationEntry D_80806E00_chquiz[16];
extern ActorAnimationEntry D_80806E80_chquiz[16];
extern ActorAnimationEntry D_80806F00_chquiz[16];
extern ActorAnimationEntry D_80806F80_chquiz[16];
extern QuizContestant D_80807000_chquiz[7];
extern s16 D_808070A8_chquiz[4];
extern s16 D_808070B0_chquiz[3];
extern QuizChoices D_808070B8_chquiz;
extern s8 D_808070C4_chquiz[3][10];
extern QuizCameraScript D_808070E4_chquiz;
extern ActorAnimationEntry D_8080721C_chquiz[4];
extern ActorAnimationEntry D_8080737C_chquiz[5];
extern ActorAnimationEntry D_808073A4_chquiz[5];
extern ActorAnimationEntry D_808073CC_chquiz[10];
extern ActorAnimationEntry D_8080741C_chquiz[5];
extern ActorAnimationEntry D_80807444_chquiz[5];
extern ActorAnimationEntry D_80807524_chquiz[7];
extern ActorData D_808072CC_chquiz;
extern ActorData D_80807334_chquiz;
extern ActorData D_80807480_chquiz;
extern ActorData D_808074DC_chquiz;
extern s32 D_8080723C_chquiz[14];
extern s32 D_80807274_chquiz[18];
extern s32 D_808075C0_chquiz[11];
extern s32 D_808075EC_chquiz[14];
extern u16 D_808072BC_chquiz[8];
extern u16 D_808075B0_chquiz[8];
extern u16 D_80807624_chquiz[14];
extern f32 D_80807314_chquiz[2];
extern f32 D_8080746C_chquiz[2];
extern f32 D_808074C8_chquiz[2];
extern f32 D_8080755C_chquiz[2];
extern u32 D_8080731C_chquiz[3];
extern u32 D_80807474_chquiz[3];
extern u32 D_808074D0_chquiz[3];
extern u32 D_80807564_chquiz[3];
extern f32 D_80807328_chquiz[3];
extern QuizTimes4 D_80807570_chquiz;
extern QuizTimes6 D_80807580_chquiz;
extern QuizTimes6 D_80807598_chquiz;

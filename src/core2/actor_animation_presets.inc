/* The upper fourteen bits select the animation, the lower two the rendering mode. */
#define ACTOR_ANIMATION(animation, mode) (((animation) << 2) | (mode))

AnimationEntry D_80124740[11] BT_DATA(4, actor_animation_presets, 0) = {
    {2.0f, ACTOR_ANIMATION(0x114, 0), 0x09},
    {1.0f, ACTOR_ANIMATION(0x1CC, 0), 0x09},
    {1.0f, ACTOR_ANIMATION(0x20C, 0), 0x09},
    {3.93f, ACTOR_ANIMATION(0x1FC, 0), 0x09},
    {1.0f, ACTOR_ANIMATION(0x207, 2), 0x09},
    {1.0f, ACTOR_ANIMATION(0x3C9, 1), 0x09},
    {0.75f, ACTOR_ANIMATION(0x3CA, 1), 0x09},
    {4.0f, ACTOR_ANIMATION(0x362, 1), 0x09},
    {4.0f, ACTOR_ANIMATION(0x362, 1), 0x09},
    {4.0f, ACTOR_ANIMATION(0x362, 1), 0x09},
    {0.35f, ACTOR_ANIMATION(0x3CC, 2), 0x09},
};

#ifdef BT_NATIVE
#define ACTOR_ANIMATION_ID(preset) ((preset).animation_and_mode >> 2)
#else
/* IDO reads the original aligned word across both packed halfwords. */
#define ACTOR_ANIMATION_ID(preset) (*(u32 *) &(preset).animation_and_mode >> 18)
#endif

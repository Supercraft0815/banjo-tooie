/* The player physics and spline readers index the same five movement settings. */
typedef struct {
    u8 mode;
    u8 flags;
    u8 padding[2];
    f32 value;
} MovementDefault;

MovementDefault playerMovementDefaults[5] BT_DATA(4, player_movement_defaults, 0) = {
    {0, 0, {0, 0}, 0.0f},
    {1, 0, {0, 0}, 0.07f},
    {2, 1, {0, 0}, 0.29f},
    {3, 2, {0, 0}, 0.15f},
    {4, 1, {0, 0}, 0.05f},
};

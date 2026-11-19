#if defined(BT_NATIVE) && !defined(BT_ILP32)
typedef struct PlayerCameraController {
    void *camera, *movement, *fixed, *effect, *projection;
    s16 pod, mode;
    u8 active, updating;
    s32 player;
    u8 command;
    f32 commandPosition[3], commandRotation[3], commandValue;
} PlayerCameraController;
#define CAMERA_FIELD(p, field, retail) (((PlayerCameraController *)(p))->field)
#define CAMERA_NATIVE(native, retail) native
typedef void *CameraInput;
#else
#define CAMERA_FIELD(p, field, retail) (retail)
#define CAMERA_NATIVE(native, retail) retail
typedef s32 CameraInput;
#endif

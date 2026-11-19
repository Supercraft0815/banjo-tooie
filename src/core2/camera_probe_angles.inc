/* Each collision search tries these yaw offsets in order, accepting the first clear endpoint. */
typedef struct {
    f32 *angles;
    s32 count;
} CameraProbeAngles;

f32 D_801249C0[1] BT_DATA(4, camera_probe_angles, 0) = {0};
f32 D_801249C4[11] BT_DATA(4, camera_probe_angles, 4) = {0, -25, 25, -50, 50, -80, 80, -120, 120, -140, 140};
f32 D_801249F0[18] BT_DATA(4, camera_probe_angles, 48) = {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340,
};
CameraProbeAngles D_80124A38 BT_DATA(4, camera_probe_angles, 120) = {D_801249C0, 1};
CameraProbeAngles D_80124A40 BT_DATA(4, camera_probe_angles, 128) = {D_801249C4, 11};
CameraProbeAngles D_80124A48 BT_DATA(4, camera_probe_angles, 136) = {D_801249F0, 18};

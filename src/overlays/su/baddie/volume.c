#include "common.h"

s32 subaddievolume_entrypoint_0(u8 *arg0, f32 arg1[][3], s32 arg2, s32 arg3, s32 *arg4) {
    typedef struct {
        u32 unused:19;
        u32 enabled:1;
        u32 remaining:12;
    } Flags;
    typedef struct {
        s16 min[3];
        s16 max[3];
        s16 position[3];
        u8 rotation[3];
        u8 unk15;
        s8 bone;
        u8 unk17;
    } Box;
    typedef struct {
        s16 radius;
        s16 height;
        s16 position[3];
        u8 rotation[3];
        u8 unkD;
        s8 bone;
        u8 unkF;
    } Cylinder;
    typedef struct {
        s16 radius;
        s16 position[3];
        u8 unk8;
        s8 bone;
        u8 unkA[2];
    } Sphere;
    typedef struct {
        s16 boxes;
        s16 cylinders;
        s16 spheres;
        s16 unk6;
    } Volumes;
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_800198D4(f32 *, f32 *);
    void func_80019994(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    void func_80019CD4(void);
    s32 func_800ADE2C(s32, s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800DC298(f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800F1418(s32, s32);
    f32 *func_801027F4(u8 *);
    Volumes *func_80103D98(s32);
    f32 func_80103F38(u8 *, f32 *);
    s32 func_801040A8(u8 *);
    void mlMtxGet(void *);
    void mlMtxPop(void);
    void mlMtxTranslate(f32, f32, f32);
    f32 matrix[4][4];
    s32 count;
    s32 i;
    s32 bones;
    Volumes *volumes;
    s32 j;
    Cylinder *cylinders;
    Sphere *spheres;
    s32 index;
    s32 total;
    f32 center[3];
    f32 radius;
    Box *box;
    f32 boxPosition[3];
    f32 boxRotation[3];
    s32 axis;
    Cylinder *cylinder;
    f32 angle;
    f32 cylinderPosition[3];
    f32 cylinderRotation[3];
    Sphere *sphere;
    f32 spherePosition[3];
    s32 fallbackCount;
    f32 sphereAngle;

    if (arg0 == NULL) {
        return 0;
    }
    if (!((Flags *)(arg0 + 0x7C))->enabled) {
        return -1;
    }
    volumes = func_80103D98(*(s32 *)arg0);
    bones = func_801040A8(arg0);
    if (bones == 0 || volumes == NULL) {
        fallbackCount = func_800F1418(arg2 * 3, arg3);
        radius = func_80103F38(arg0, center);
        for (count = 0; count < fallbackCount; count++) {
            angle = func_800DC178(0.0f, 359.0f);
            func_800EEC30(arg1[count], angle, func_800DC178(0.0f, 359.0f), radius);
            func_800EF04C(arg1[count], center);
        }
        return fallbackCount;
    }
    cylinders = (Cylinder *)(volumes->boxes * 24 + (u8 *)volumes + 8);
    spheres = (Sphere *)(cylinders + volumes->cylinders);
    total = volumes->boxes + volumes->cylinders + volumes->spheres;
    if (arg4 != NULL) {
        index = *arg4;
    } else {
        index = 0;
    }
    if (index >= total) {
        index = 0;
    }
    func_80019CD4();
    func_80019750((f32 *)(arg0 + 4), func_801027F4(arg0), *(f32 *)(arg0 + 0x38), NULL);
    mlMtxGet(matrix);
    count = 0;
    while (count < arg3) {
        i = 0;
        if (arg4 != NULL) {
            *arg4 = index + 1;
        }
        if (index < volumes->boxes) {
            box = (Box *)((volumes->boxes - index) * 24 + (u8 *)volumes - 16);
            if (arg2 > 0) do {
                func_800EE88C(boxPosition, box->position);
                boxRotation[0] = 2.0f * box->rotation[0];
                boxRotation[1] = 2.0f * box->rotation[1];
                boxRotation[2] = 2.0f * box->rotation[2];
                func_80019AA0(matrix, func_800ADE2C(bones, box->bone));
                func_80019994(boxPosition, boxRotation);
                for (j = 0; j < 3; j++) {
                    arg1[count][j] = func_800DC178(box->min[j], box->max[j]);
                }
                axis = func_800DC128(0, 3);
                if (func_800DC298(0.5f)) {
                    arg1[count][axis] = box->min[axis];
                } else {
                    arg1[count][axis] = box->max[axis];
                }
                func_80019224(arg1[count], arg1[count]);
                count++;
                if (count >= arg3) {
                    return count;
                }
                mlMtxPop();
            } while (++i != arg2);
        } else if (index < volumes->boxes + volumes->cylinders) {
            cylinder = cylinders + (volumes->boxes + volumes->cylinders - index - 1);
            if (arg2 > 0) do {
                func_800EE88C(cylinderPosition, cylinder->position);
                cylinderRotation[0] = 2.0f * cylinder->rotation[0];
                cylinderRotation[1] = 2.0f * cylinder->rotation[1];
                cylinderRotation[2] = 2.0f * cylinder->rotation[2];
                cylinderRotation[0] += 90.0f;
                func_80019AA0(matrix, func_800ADE2C(bones, cylinder->bone));
                func_800198D4(cylinderPosition, cylinderRotation);
                func_800EEB9C(arg1[count], func_800DC178(0.0f, 359.0f), cylinder->radius);
                arg1[count][1] = func_800DC178(cylinder->height * -0.5f, cylinder->height * 0.5f);
                func_80019224(arg1[count], arg1[count]);
                count++;
                if (count >= arg3) {
                    return count;
                }
                mlMtxPop();
            } while (++i != arg2);
        } else {
            sphere = spheres + (total - index - 1);
            if (arg2 > 0) do {
                func_800EE88C(spherePosition, sphere->position);
                func_80019AA0(matrix, func_800ADE2C(bones, sphere->bone));
                mlMtxTranslate(spherePosition[0], spherePosition[1], spherePosition[2]);
                sphereAngle = func_800DC178(0.0f, 359.0f);
                func_800EEC30(arg1[count], sphereAngle, func_800DC178(0.0f, 359.0f), sphere->radius);
                func_80019224(arg1[count], arg1[count]);
                count++;
                if (count >= arg3) {
                    return count;
                }
                mlMtxPop();
            } while (++i != arg2);
        }
        index++;
        if (index >= total) {
            index = 0;
        }
    }
    return count;
}

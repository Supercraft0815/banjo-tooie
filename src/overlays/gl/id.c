#include "core2/model_mesh.h"

void glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3) {
    void *func_800B2190(void *);
    s32 temp_a0;
    u8 *temp_s4;
    u32 var_v1;
    u8 *temp_s3;
    u8 *var_s0;
    u8 *var_s1;
    u8 *var_s2;

    temp_s4 = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, *(void **)(arg0 + 0x14)));
    temp_a0 = *(s32 *)(arg0 + 4);
    var_s1 = BT_DATA_FIELD(((ModelMesh *)arg0)->meshes, arg0 + 0x1C);
    var_v1 = 0;
    while ((s32)var_v1 < temp_a0) {
        var_v1 += 1;
        if (arg1 == *(s16 *)(var_s1 + 0)) {
            var_s0 = var_s1 + 8;
            temp_s3 = (*(s16 *)(var_s1 + 2) * 4) + var_s1 + 8;
            var_s2 = temp_s3;
            if ((BtUIntPtr)var_s0 < (BtUIntPtr)temp_s3) {
                do {
                    arg2(*(s16 *)(var_s1 + 0), var_s2, (*(s16 *)(var_s0 + 0) * 0x10) + temp_s4, *(s16 *)(var_s0 + 2), arg3);
                    var_s2 += *(s16 *)(var_s0 + 2) * 0x10;
                    var_s0 += 4;
                } while ((BtUIntPtr)var_s0 < (BtUIntPtr)temp_s3);
            }
            break;
        } else {
            var_s1 += *(s32 *)(var_s1 + 4);
        }
    }
}    typedef struct { s16 unk0; s16 unk2; } Objid_glid_entrypoint_1_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ typedef struct { u8 pad0[0x4]; s32 unk4; } Objid_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { s16 unk0; s16 unk2; s32 unk4; } Objid_glid_entrypoint_1_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

/* extern */

void glid_entrypoint_1(u8 *arg0, s32 arg1, BT_IDO_ONLY(s32 (*arg2)(u8 *, u8 *, u8 *, s16, s32)) BT_NATIVE_ONLY(void (*arg2)(u8 *, BtUIntPtr, u8 *, s32, u8 *)), BtIntPtr arg3) {
    void *func_800B2190(void *);
    s32 temp_a1;
    u8 *temp_s3;
    u8 *temp_s4;
    s32 temp_t9;
    u32 var_a0;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *var_s1;
    u8 *var_v1;

    temp_s3 = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, *(void **)(arg0 + 0x14)));
    temp_s4 = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->other_vertices, *(void **)(arg0 + 0x18)));
    temp_a1 = (((Objid_arg0 *)arg0)->unk4);
    var_v1 = BT_DATA_FIELD(((ModelMesh *)arg0)->meshes, arg0 + 0x1C);
    var_a0 = 0;
    while ((s32)var_a0 < temp_a1) {
        var_a0++;
        if (arg1 == (((Objid_glid_entrypoint_1_var_v1 *)var_v1)->unk0)) {
            var_s0 = var_v1 + 8;
            temp_s2 = ((((Objid_glid_entrypoint_1_var_v1 *)var_v1)->unk2) * 4) + var_v1 + 8;
            var_s1 = temp_s2;
            if ((BtUIntPtr) var_s0 < (BtUIntPtr) temp_s2) {
                do {
                    temp_t9 = (((Objid_glid_entrypoint_1_var_s0 *)var_s0)->unk0) * 0x10;
                    arg2(var_s1, BT_NATIVE_ONLY((BtUIntPtr)) (temp_t9 + temp_s3), temp_t9 + temp_s4, (((Objid_glid_entrypoint_1_var_s0 *)var_s0)->unk2), BT_NATIVE_ONLY((u8 *)) arg3);
                    var_s1 += (((Objid_glid_entrypoint_1_var_s0 *)var_s0)->unk2) * 0x10;
                    var_s0 += 4;
                } while ((BtUIntPtr) var_s0 < (BtUIntPtr) temp_s2);
            }
            break;
        }
        var_v1 += (((Objid_glid_entrypoint_1_var_v1 *)var_v1)->unk4);
    }
}    typedef struct { s16 unk0; s16 unk2; s32 unk4; } Objid_glid_entrypoint_2_var_s3; /* offsets.py genstruct: fields from raw offsets on var_s3; rename once understood */ typedef struct { s16 unk0; s16 unk2; } Objid_glid_entrypoint_2_var_s6; /* offsets.py genstruct: fields from raw offsets on var_s6; rename once understood */

/* extern */

void glid_entrypoint_2 BT_IDO_ONLY((u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s32), BtIntPtr arg3)) BT_NATIVE_ONLY((u8 *arg0, s32 arg1, MeshVertexVisitor arg2, u8 *arg3)) {
    void *func_800B2190(void *);
    s32 temp_a0;
    u8 *temp_fp;
    s32 var_v1;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *temp_s7;
    u8 *var_s1;
    u8 *var_s3;
    u8 *var_s6;

    temp_fp = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, *(void **)(arg0 + 0x14)));
    temp_a0 = (((Objid_arg0 *)arg0)->unk4);
    var_s3 = BT_DATA_FIELD(((ModelMesh *)arg0)->meshes, arg0 + 0x1C);
    var_v1 = 0;
    if (temp_a0 > 0) {
loop_1:
        var_v1 += 1;
        if (arg1 == (((Objid_glid_entrypoint_2_var_s3 *)var_s3)->unk0)) {
            var_s6 = var_s3 + 8;
            temp_s7 = ((((Objid_glid_entrypoint_2_var_s3 *)var_s3)->unk2) * 4) + var_s3 + 8;
            var_s1 = temp_s7;
            if ((BtUIntPtr) var_s6 < (BtUIntPtr) temp_s7) {
                do {
                    var_s0 = ((((Objid_glid_entrypoint_2_var_s6 *)var_s6)->unk0) * 0x10) + temp_fp;
                    temp_s2 = ((((Objid_glid_entrypoint_2_var_s6 *)var_s6)->unk2) * 0x10) + var_s0;
                    if (var_s0 < temp_s2) {
                        do {
                            arg2((((Objid_glid_entrypoint_2_var_s3 *)var_s3)->unk0), BT_NATIVE_ONLY((s16 *))var_s1, var_s0, arg3);
                            var_s0 += 0x10;
                            var_s1 += 0x10;
                        } while (var_s0 < temp_s2);
                    }
                    var_s6 += 4;
                } while ((BtUIntPtr) var_s6 < (BtUIntPtr) temp_s7);
            }
        } else {
            var_s3 += (((Objid_glid_entrypoint_2_var_s3 *)var_s3)->unk4);
            if (var_v1 < *(s32 *)(arg0 + 4)) {
                goto loop_1;
            }
        }
    }
}

void glid_entrypoint_3(u8 *arg0, s32 arg1, s32 (*arg2)(u8 *, u8 *, s32, s32), BtIntPtr arg3) {
    void *func_800B2190(void *);
    u8 *func_800B27A0(u8 *); BT_NATIVE_ONLY(struct ImageStruct *func_800D674C(s32);)
    s8 *_dbvtxnormal_entrypoint_0(BtIntPtr, s32);
    u8 * volatile sp44;
    s32 temp_a1_2;
    s32 temp_a1;
    BtIntPtr temp_fp;
    u32 var_a0;
    s8 *var_s1;
    u8 *temp_s3;
    u8 *temp_s7;
    u8 *var_s2;
    u8 *var_s6;
    u8 *var_v1;

    sp44 = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, *(void **)(arg0 + 0x14)));
    temp_fp = (BtIntPtr)func_800B27A0((u8 *)func_800D674C(*(s32 *)arg0));
    temp_a1 = *(s32 *)(arg0 + 4);
    var_v1 = BT_DATA_FIELD(((ModelMesh *)arg0)->meshes, arg0 + 0x1C);
    var_a0 = 0;
    while ((s32)var_a0 < temp_a1) {
        var_a0 += 1;
        if (arg1 == *(s16 *)var_v1) {
            var_s6 = var_v1 + 8;
            temp_s7 = (*(s16 *)(var_v1 + 2) * 4) + var_v1 + 8;
            var_s2 = temp_s7;
            if ((BtUIntPtr)var_s6 < (BtUIntPtr)temp_s7) {
                do {
                    u8 *var_s0;
                    temp_a1_2 = *(s16 *)var_s6;
                    var_s0 = temp_a1_2 * 0x10 + sp44;
                    temp_s3 = *(s16 *)(var_s6 + 2) * 0x10 + var_s0;
                    var_s1 = _dbvtxnormal_entrypoint_0(temp_fp, temp_a1_2);
                    if (var_s0 < temp_s3) {
                        do {
                            arg2(var_s2, (u8 *)var_s0, arg3, (BtIntPtr)var_s1);
                            var_s2 += 0x10;
                            var_s1 += 4;
                            var_s0 += 0x10;
                        } while (var_s0 < temp_s3);
                    }
                    var_s6 += 4;
                } while ((BtUIntPtr)var_s6 < (BtUIntPtr)temp_s7);
            }
            break;
        }
        var_v1 += *(s32 *)(var_v1 + 4);
        temp_a1 = *(s32 *)(arg0 + 4);
    }
}    typedef struct { s16 unk0; s16 unk2; s32 unk4; } Objid_glid_entrypoint_4_var_s3; /* offsets.py genstruct: fields from raw offsets on var_s3; rename once understood */ typedef struct { s16 unk0; s16 unk2; } Objid_glid_entrypoint_4_var_s6; /* offsets.py genstruct: fields from raw offsets on var_s6; rename once understood */

/* extern */

void glid_entrypoint_4(u8 *arg0, s32 (*arg1)(s16, u8 *, u8 *, s32), s32 arg2) {
    void *func_800B2190(void *);
    s32 sp44[5];
    u8 *temp_v0;
    s32 var_v1;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *temp_s7;
    u8 *var_s1;
    u8 *var_s3;
    u8 *var_s6;

    temp_v0 = func_800B2190(BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, *(void **)(arg0 + 0x14)));
    sp44[0] = 0;
    var_v1 = (((Objid_arg0 *)arg0)->unk4);
    var_s3 = BT_DATA_FIELD(((ModelMesh *)arg0)->meshes, arg0 + 0x1C);
    if (var_v1 > 0) {
        do {
            var_s6 = var_s3 + 8;
            temp_s7 = ((((Objid_glid_entrypoint_4_var_s3 *)var_s3)->unk2) * 4) + var_s3 + 8;
            var_s1 = temp_s7;
            if ((BtUIntPtr) var_s6 < (BtUIntPtr) temp_s7) {
                do {
                    var_s0 = ((((Objid_glid_entrypoint_4_var_s6 *)var_s6)->unk0) * 0x10) + temp_v0;
                    temp_s2 = ((((Objid_glid_entrypoint_4_var_s6 *)var_s6)->unk2) * 0x10) + var_s0;
                    if (var_s0 < temp_s2) {
                        do {
                            arg1((((Objid_glid_entrypoint_4_var_s3 *)var_s3)->unk0), var_s1, var_s0, arg2);
                            var_s0 += 0x10;
                            var_s1 += 0x10;
                        } while (var_s0 < temp_s2);
                    }
                    var_s6 += 4;
                } while ((BtUIntPtr) var_s6 < (BtUIntPtr) temp_s7);
                var_v1 = (((Objid_arg0 *)arg0)->unk4);
            }
            var_s3 += (((Objid_glid_entrypoint_4_var_s3 *)var_s3)->unk4);
            sp44[0]++;
        } while (sp44[0] < var_v1);
    }
}

void glid_entrypoint_5(BT_IDO_ONLY(s32 *) BT_NATIVE_ONLY(void *) arg0, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *) arg1) {
    BT_DATA_FIELD(((ModelMesh *)arg0)->vertices, arg0[5]) = arg1;
}

void glid_entrypoint_6(BT_IDO_ONLY(s32 *) BT_NATIVE_ONLY(void *) arg0, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *) arg1) {
    BT_DATA_FIELD(((ModelMesh *)arg0)->other_vertices, arg0[6]) = arg1;
}

#include "common.h"

typedef struct { s16 uid; s16 vtx_count; s16 vertices[1]; } MeshRecord;
typedef struct { s16 count; MeshRecord data[1]; } MeshList;

s32 dbid_entrypoint_0(s16 *arg0, s32 arg1) {
    s16 temp_a2;
    s32 var_a0;
    s32 var_v1;
    s32 end;
    s16 *var_a2;
    s16 *var_v0;

    var_v0 = arg0 + 1;
    var_v1 = 0;
    temp_a2 = *arg0;
    if (temp_a2 > 0) {
        var_a0 = 2;
loop_1:
        if (arg1 == var_v0[0]) {
            arg1 = var_v0[1];
            var_v1 = 0;
            var_a2 = var_v0 + 1;
            end = arg1 * 2;
            if (arg1 >= 2) {
                do {
                    var_a0 += 2;
                    if (var_a2[2] != var_a2[1] + 1) {
                        var_v1 += 1;
                    }
                    var_a2 += 1;
                } while (var_a0 < end);
            }
            return var_v1 + 1;
        }
        var_v1 += 1;
        var_v0 += var_v0[1];
        var_v0 += 2;
        if (var_v1 < temp_a2) {
            goto loop_1;
        }
    }
    return 0;
}

s32 dbid_entrypoint_1(s16 *arg0) {
    s32 sum = 0;
    s16 *p = arg0 + 1;
    s32 i;
    for (i = 0; i < arg0[0]; i++) {
        s32 value = p[1];
        p += value;
        p += 2;
        sum += value;
    }
    return sum;
}

MeshRecord *dbid_entrypoint_2(MeshList *this, s32 mesh_id) {
    int i;
    MeshRecord *mesh = this->data;

    for (i = 0; i < this->count; i++) {
        if (mesh->uid == mesh_id) {
            return mesh;
        }
        mesh = (MeshRecord *) &mesh->vertices[mesh->vtx_count];
    }

    return NULL;
}

int dbid_entrypoint_3(MeshList *this, s32 mesh_id, u16 *vtx_id) {
    int i;
    MeshRecord *mesh = dbid_entrypoint_2(this, mesh_id);

    if (mesh) {
        for (i = 0; i < mesh->vtx_count; i++) {
            if (mesh->vertices[i] == *vtx_id) {
                return 1;
            }
        }
    }

    return 0;
}

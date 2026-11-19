#include "common.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_world_grid.h"
#include "core2/1EC8070.h"
#include "memory.h"
typedef NativeWorldGrid Bounds;
NativeWorldGrid native_world_grid;
#define D_80128410 native_world_grid
static NativeWorldCell *model_neighbors[28], *dynamic_neighbors[28], *all_neighbors[29];
void _gccubeDll_entrypoint_0(NativeWorldGrid *);
void _gccubeDll_entrypoint_1(NativeWorldGrid *);
void _gccubeDll_entrypoint_2(NativeWorldGrid *);
void _gccubeDll_entrypoint_3(NativeWorldGrid *,void *);
void _gccubeDll_entrypoint_4(NativeWorldGrid *,void *);
s32 _gccubeDll_entrypoint_5(NativeWorldGrid *);
void _gccubeDll_entrypoint_6(NativeWorldGrid *);
s32 func_800D3104(BtIntPtr,void *);
void func_800D2EE4(void);
s32 func_800EA068(s32);
void func_8010A874(BtIntPtr);
#elif defined(BT_ILP32)
#include "native_world_grid_data.h"
typedef NativeWorldGrid Bounds;
Bounds D_80128410;
NativeWorldCell *D_80128458[28], *D_801284C8[28], *D_80128538[29];
_Static_assert(sizeof(Bounds) == 0x48 && sizeof(NativeWorldCell) == 8, "world grid layout");
#else
typedef struct { s32 unk0; s32 lower[3]; s32 upper[3]; s32 pad[9]; f32 scale; } Bounds;
extern Bounds D_80128410;
extern s32 D_80128434;

#endif

#define WORLD_MODEL_NEIGHBORS BT_DATA_FIELD((s32 *)D_80128458, &D_80128458)
#define WORLD_DYNAMIC_NEIGHBORS BT_DATA_FIELD((s32 *)D_801284C8, &D_801284C8)
#define WORLD_ALL_NEIGHBORS BT_DATA_FIELD((s32 *)D_80128538, &D_80128538)
void func_800BD570()
{
    _gccubeDll_entrypoint_1(&D_80128410);
}

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BD594(BtIntPtr mode) {
    if (func_800EA068(0x200)) func_8010A874(mode);
    else func_800D3104(mode,&native_world_grid);
}
#else
void func_800BD594(s32 arg0) {
    s32 func_800D3104(s32, s32 *);
    s32 func_800EA068(s32);
    s32 func_8010A874(s32);
    if (func_800EA068(0x200) != 0) {
        func_8010A874(arg0);
        return;
    }
    func_800D3104(arg0, &D_80128410);
}
#endif

void func_800BD5DC()
{
    _gccubeDll_entrypoint_2(&D_80128410);
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BD600(void) {
    native_world_grid.cells=defrag(native_world_grid.cells);
    native_world_grid.model_counts=defrag(native_world_grid.model_counts);
    func_800E9DF8();func_800D2EE4();
}
#else
void func_800BD600(void) {
    s32 defrag(s32);
    s32 func_800D2EE4();
    s32 func_800E9DF8();
    BT_IDO_ONLY(extern s32 D_80128454;)
    BT_DATA_FIELD(D_80128410.cells = (void *)defrag((s32)D_80128410.cells), D_80128410.unk0 = defrag(D_80128410.unk0));
    BT_DATA_FIELD(D_80128410.model_counts, D_80128454) = defrag((*(s32 *)((s8 *)(&D_80128410) + (0x44))));
    func_800E9DF8();
    func_800D2EE4();
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BD64C(s32 *out,f32 *position) {
    for(s32 i=0;i<3;++i) {
        out[i]=(s32)(position[i]*native_world_grid.scale+(position[i]<0 ? -1.0f : 0.0f));
        if(out[i]<native_world_grid.lower[i]) out[i]=native_world_grid.lower[i];
        if(out[i]>native_world_grid.upper[i]) out[i]=native_world_grid.upper[i];
    }
}
#else
void func_800BD64C(s32 *arg0, f32 *arg1) {
    BT_IDO_ONLY(extern s32 D_8012841C;)
    struct { s32 words[16]; volatile f32 scale; } *base = (void *)&D_80128410;
    s32 *bounds = BT_DATA_FIELD((s32 *)&D_80128410, &D_8012841C - 3);
    s32 i;
    for (i = 0; i < 3; i++) {
        if (arg1[i] >= 0.0f) {
            arg0[i] = (s32)(arg1[i] * base->scale);
        } else {
            arg0[i] = (s32)(arg1[i] * base->scale + -1.0f);
        }
        if (arg0[i] < bounds[i + 1]) {
            arg0[i] = bounds[i + 1];
        }
        if (bounds[i + 4] < arg0[i]) {
            arg0[i] = bounds[i + 4];
        }
    }
}
#endif

void func_800BD708(s32 *arg0, s32 *arg1, f32 *arg2, f32 *arg3, f32 arg4) {
    s32 i;
    s32 limit;
    f32 x;
    f32 y;
    f32 value;
    f32 temp;

    for (i = 0; i < 3; i++) {
        x = arg3[i];
        y = arg2[i];
        value = y <= x ? y : x;
        if ((temp = value - arg4) >= 0.0f) {
            arg0[i] = (s32)(1.0f * temp * ((Bounds *)&D_80128410)->scale);
        } else {
            arg0[i] = (s32)(temp * D_80128410.scale + -1.0f);
        }
        limit = D_80128410.lower[i];
        if (arg0[i] < limit) {
            arg0[i] = limit;
        }
        y = arg2[i];
        x = arg3[i];
        value = x <= y ? y : x;
        if ((temp = value + arg4) >= 0.0f) {
            arg1[i] = (s32)(temp * D_80128410.scale);
        } else {
            arg1[i] = (s32)(temp * D_80128410.scale + -1.0f);
        }
        limit = D_80128410.upper[i];
        if (limit < arg1[i]) {
            arg1[i] = limit;
        }
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BD860(NativeWorldCell *cell,s32 *out) {
    s32 index=func_800BD948(cell), remainder;
    if(index<0 || !native_world_grid.row_stride || !native_world_grid.plane_stride) {
        func_800EE830(out,native_world_grid.lower);return;
    }
    out[2]=index/native_world_grid.plane_stride;
    remainder=index-out[2]*native_world_grid.plane_stride;
    out[1]=remainder/native_world_grid.row_stride;
    out[0]=remainder-out[1]*native_world_grid.row_stride;
    for(s32 i=0;i<3;++i) out[i]+=native_world_grid.lower[i];
}
#else
void func_800BD860(s32 arg0, s32 *arg1) {
    BT_IDO_ONLY(extern s32 D_8012841C;)
    s32 i;
    s32 offset;
    s32 remainder;

    offset = (arg0 - BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0)) >> 3;
    arg1[2] = offset / BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]);
    remainder = offset - arg1[2] * BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]);
    arg1[1] = remainder / BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]);
    arg1[0] = remainder - arg1[1] * BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]);
    for (i = 0; i < 3; i++) {
        arg1[i] += BT_DATA_FIELD(D_80128410.lower[i], ((s32 *)&D_80128410)[i + 1]);
    }
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BD948(void *cell) {
    uintptr_t offset=(uintptr_t)cell-(uintptr_t)native_world_grid.cells;
    if(cell==&native_world_grid.fallback || !native_world_grid.cells ||
       offset%sizeof(NativeWorldCell) || offset/sizeof(NativeWorldCell)>=(u32)native_world_grid.count) return -1;
    return offset/sizeof(NativeWorldCell);
}
#else
s32 func_800BD948(s32 arg0) {
    s32 base = (s32)&D_80128410;
    s32 result;
    if (arg0 == base + 0x34) {
        result = -1;
    } else {
        result = (arg0 - *(s32 *)base) >> 3;
    }
    return result;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BD97C(s32 *position) {
    s32 relative[3];
    if(!native_world_grid.cells || native_world_grid.count<=0) return -1;
    for(s32 i=0;i<3;++i) {
        s32 coordinate=(s32)((f32)position[i]*native_world_grid.scale+(position[i]<0 ? -1.0f : 0.0f));
        if(coordinate<native_world_grid.lower[i] || coordinate>native_world_grid.upper[i]) return -1;
        relative[i]=coordinate-native_world_grid.lower[i];
    }
    return relative[0]+relative[1]*native_world_grid.row_stride+relative[2]*native_world_grid.plane_stride;
}
#else
s32 func_800BD97C(s32 *arg0) {
    void func_800EFB58(void *, void *, void *);
    BT_IDO_ONLY(extern s32 D_80128414;)
    BT_IDO_ONLY(extern f32 D_80128450;)
    s32 position[3];
    s32 relative[3];
    s32 i;
    f32 scale = BT_DATA_FIELD(D_80128410.scale, D_80128450);

    for (i = 0; i < 3; i++) {
        if (arg0[i] >= 0) {
            position[i] = (s32)((f32)arg0[i] * scale);
        } else {
            position[i] = (s32)((f32)arg0[i] * scale + -1.0f);
        }
    }
    if ((position[0] < BT_DATA_FIELD(D_80128410.lower[0], ((s32 *)&D_80128410)[1])) ||
        (position[1] < BT_DATA_FIELD(D_80128410.lower[1], ((s32 *)&D_80128410)[2])) ||
        (position[2] < BT_DATA_FIELD(D_80128410.lower[2], ((s32 *)&D_80128410)[3])) ||
        (BT_DATA_FIELD(D_80128410.upper[0], ((s32 *)&D_80128410)[4]) < position[0]) ||
        (BT_DATA_FIELD(D_80128410.upper[1], ((s32 *)&D_80128410)[5]) < position[1]) ||
        (BT_DATA_FIELD(D_80128410.upper[2], ((s32 *)&D_80128410)[6]) < position[2])) {
        return -1;
    }
    func_800EFB58(relative, position, &BT_DATA_FIELD(D_80128410.lower[0], D_80128414));
    return relative[0] + relative[1] * BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]) +
        relative[2] * BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell *func_800BDAD4(s32 *position) {
    s32 relative[3];
    for(s32 i=0;i<3;++i) {
        if(position[i]<native_world_grid.lower[i] || position[i]>native_world_grid.upper[i]) return &native_world_grid.fallback;
        relative[i]=position[i]-native_world_grid.lower[i];
    }
    return func_800BDB9C(relative[0]+relative[1]*native_world_grid.row_stride+relative[2]*native_world_grid.plane_stride);
}
#else
s32 func_800BDAD4(s32 position[3]) {
    BT_IDO_ONLY(extern u8 D_80128444;)
    if ((position[0] < BT_DATA_FIELD(D_80128410.lower[0], ((s32 *)&D_80128410)[1])) ||
        (position[1] < BT_DATA_FIELD(D_80128410.lower[1], ((s32 *)&D_80128410)[2])) ||
        (position[2] < BT_DATA_FIELD(D_80128410.lower[2], ((s32 *)&D_80128410)[3])) ||
        (BT_DATA_FIELD(D_80128410.upper[0], ((s32 *)&D_80128410)[4]) < position[0]) ||
        (BT_DATA_FIELD(D_80128410.upper[1], ((s32 *)&D_80128410)[5]) < position[1]) ||
        (BT_DATA_FIELD(D_80128410.upper[2], ((s32 *)&D_80128410)[6]) < position[2])) {
        return (s32)&BT_DATA_FIELD(D_80128410.fallback, D_80128444);
    }
    return BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (position[0] - BT_DATA_FIELD(D_80128410.lower[0], ((s32 *)&D_80128410)[1])) * 8 +
        (position[1] - BT_DATA_FIELD(D_80128410.lower[1], ((s32 *)&D_80128410)[2])) * BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]) * 8 +
        (position[2] - BT_DATA_FIELD(D_80128410.lower[2], ((s32 *)&D_80128410)[3])) * BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]) * 8;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell *func_800BDB9C(s32 index) {
    return index<0 || index>=native_world_grid.count || !native_world_grid.cells ? &native_world_grid.fallback : native_world_grid.cells+index;
}
#else
s32 func_800BDB9C(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_80128444;)
    s32 result;
    if (arg0 < 0) {
        result = (s32)&BT_DATA_FIELD(D_80128410.fallback, D_80128444);
    } else {
        result = arg0 * 8 + BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0);
    }
    return result;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell *func_800BDBC4(s32 *position) { return func_800BDB9C(func_800BD97C(position)); }
#else
s32 func_800BDBC4(s32 arg0)
{
    return func_800BDB9C(func_800BD97C(arg0));
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell *func_800BDBEC(f32 *position) {
    s32 out[3];func_800EE904(out,position);return func_800BDBC4(out);
}
#else
void func_800BDBEC(f32 *arg0) {
    s32 pos[3];
    pos[0] = (s32)arg0[0];
    pos[1] = (s32)arg0[1];
    pos[2] = (s32)arg0[2];
    func_800BDBC4((s32)pos);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell *func_800BDC44(void) { return &native_world_grid.fallback; }
#else
void * func_800BDC44(void) {
    BT_IDO_ONLY(extern u8 D_80128444;)
    return &BT_DATA_FIELD(D_80128410.fallback, D_80128444);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BDC50(void) { return native_world_grid.count; }
#else
s32 func_800BDC50()
{
    return BT_DATA_FIELD(D_80128410.count, D_80128434);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BDC5C(void) { return native_world_grid.cell_size; }
#else
s32 func_800BDC5C(void) {
    BT_IDO_ONLY(extern s16 D_8012844C;)
    return *(s16 *)((u8 *)&BT_DATA_FIELD(D_80128410.cell_size, D_8012844C) + 0);
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BDC68(void *stream) { _gccubeDll_entrypoint_3(&native_world_grid,stream); }
#else
void func_800BDC68(s32 arg0) {
    s32 _gccubeDll_entrypoint_3(s32 *, s32);
    _gccubeDll_entrypoint_3(&D_80128410, arg0);
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BDC90(void *stream) { _gccubeDll_entrypoint_4(&native_world_grid,stream); }
#else
void func_800BDC90(s32 arg0) {
    s32 _gccubeDll_entrypoint_4(s32 *, s32);
    _gccubeDll_entrypoint_4(&D_80128410, arg0);
}
#endif

void func_800BDCB8()
{
    _gccubeDll_entrypoint_0(&D_80128410);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800BDCDC()
{
    BT_NATIVE_ONLY(return) _gccubeDll_entrypoint_5(&D_80128410);
}

void func_800BDD00()
{
    _gccubeDll_entrypoint_6(&D_80128410);
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
static s32 native_world_neighbors(NativeWorldCell **out,s32 *position,s32 models) {
    s32 pos[3],iter[3],index,count=0;
    for(s32 i=0;i<3;++i) pos[i]=(s32)((f32)position[i]*native_world_grid.scale-native_world_grid.lower[i]);
    if(!native_world_grid.cells) return 0;
    /* Interior and boundary scans deliberately retain their different original orders. */
    if(pos[0]>0 && pos[0]<native_world_grid.dimensions[0]-1 &&
       pos[1]>0 && pos[1]<native_world_grid.dimensions[1]-1 &&
       pos[2]>0 && pos[2]<native_world_grid.dimensions[2]-1) {
        for(iter[2]=pos[2]-1;iter[2]<=pos[2]+1;++iter[2])
            for(iter[1]=pos[1]-1;iter[1]<=pos[1]+1;++iter[1])
                for(iter[0]=pos[0]-1;iter[0]<=pos[0]+1;++iter[0]) {
                    index=iter[0]+iter[1]*native_world_grid.row_stride+iter[2]*native_world_grid.plane_stride;
                    NativeWorldCell *cell=func_800BDB9C(index);
                    if(models ? func_800E9DC4(cell) : func_800E9DCC(cell)) out[count++]=cell;
                }
    } else {
        for(iter[0]=pos[0]-1;iter[0]<=pos[0]+1;++iter[0]) {
            if(iter[0]<0 || iter[0]>=native_world_grid.dimensions[0]) continue;
            for(iter[1]=pos[1]-1;iter[1]<=pos[1]+1;++iter[1]) {
                if(iter[1]<0 || iter[1]>=native_world_grid.dimensions[1]) continue;
                for(iter[2]=pos[2]-1;iter[2]<=pos[2]+1;++iter[2]) {
                    if(iter[2]<0 || iter[2]>=native_world_grid.dimensions[2]) continue;
                    index=iter[0]+iter[1]*native_world_grid.row_stride+iter[2]*native_world_grid.plane_stride;
                    NativeWorldCell *cell=func_800BDB9C(index);
                    if(models ? func_800E9DC4(cell) : func_800E9DCC(cell)) out[count++]=cell;
                }
            }
        }
    }
    return count;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell **func_800BDD24(s32 *position) {
    model_neighbors[native_world_neighbors(model_neighbors,position,1)]=NULL;
    return model_neighbors;
}
#else
s32 *func_800BDD24(s32 *arg0)
{
    s32 func_800E9DC4(s16 *);
    BT_IDO_ONLY(extern s32 D_8012841C;)
    BT_IDO_ONLY(extern f32 D_80128450;)
    BT_IDO_ONLY(extern s32 D_80128458;)
    s32 index;
    s32 base;
    s32 count;
    s32 pos[3];
    s32 iter[3];
    int new_var;
    f32 value;

    for (index = 0; index < 3; index++) {
        if (arg0[index] >= 0) {
            value = (f32)arg0[index] * BT_DATA_FIELD(D_80128410.scale, D_80128450);
        } else {
            value = (f32)arg0[index] * BT_DATA_FIELD(D_80128410.scale, D_80128450);
        }
        pos[index] = (s32)(value - BT_DATA_FIELD(D_80128410.lower[index], ((s32 *)&D_80128410)[index + 1]));
    }
    count = 0;
    if (pos[0] > 0 && pos[0] < BT_DATA_FIELD(D_80128410.dimensions[0], ((s32 *)&D_80128410)[10]) - 1 &&
        pos[1] > 0 && pos[1] < BT_DATA_FIELD(D_80128410.dimensions[1], ((s32 *)&D_80128410)[11]) - 1 &&
        pos[2] > 0 && pos[2] < BT_DATA_FIELD(D_80128410.dimensions[2], ((s32 *)&D_80128410)[12]) - 1) {
        base = (pos[0] + (pos[1] - 1) * BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]) +
            (pos[2] - 1) * BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8])) - 1;
        index = base;
        iter[0] = 0; do {
            for (iter[1] = 0; iter[1] < 3; iter[1]++) {
                for (iter[2] = 0; iter[2] < 3; iter[2]++) {
                    if (func_800E9DC4((s16 *)(BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3)))) {
                        (WORLD_MODEL_NEIGHBORS)[count++] = BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3);
                    }
                    index++;
                }
                index = (index + BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7])) - (new_var = 3);
            }
            base += BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]);
            index = base;
        } while (++iter[0] < 3);
    } else {
        for (iter[0] = pos[0] - 1; iter[0] < pos[0] + 2; iter[0]++) {
            if (iter[0] >= 0 && iter[0] < BT_DATA_FIELD(D_80128410.dimensions[0], ((s32 *)&D_80128410)[10])) {
                for (iter[1] = pos[1] - 1; iter[1] < pos[1] + 2; iter[1]++) {
                    if (iter[1] >= 0 && iter[1] < BT_DATA_FIELD(D_80128410.dimensions[1], ((s32 *)&D_80128410)[11])) {
                        for (iter[2] = pos[2] - 1; iter[2] < pos[2] + 2; iter[2]++) {
                            if (iter[2] >= 0 && iter[2] < BT_DATA_FIELD(D_80128410.dimensions[2], ((s32 *)&D_80128410)[12])) {
                                index = iter[0] + iter[1] * BT_DATA_FIELD(D_80128410.row_stride, ((s32 *)&D_80128410)[7]) +
                                    iter[2] * BT_DATA_FIELD(D_80128410.plane_stride, ((s32 *)&D_80128410)[8]);
                                if (func_800E9DC4((s16 *)(BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3)))) {
                                    (WORLD_MODEL_NEIGHBORS)[count++] = BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    (WORLD_MODEL_NEIGHBORS)[count] = 0;
    return WORLD_MODEL_NEIGHBORS;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BE09C(NativeWorldCell **out,s32 *position) { return native_world_neighbors(out,position,0); }
#else
s32 func_800BE09C(s32 *arg0, s32 *arg1)
{
  s32 func_800E9DCC(s16 *);
  BT_IDO_ONLY(extern s32 D_8012841C;)
  BT_IDO_ONLY(extern f32 D_80128450;)
  s32 index;
  s32 base;
  s32 count;
  s32 pos[3];
  s32 iter[3];
  int new_var;
  f32 value;
  for (index = 0; index < 3; index++)
  {
    if (arg1[index] >= 0)
    {
      value = ((f32) arg1[index]) * BT_DATA_FIELD(D_80128410.scale, D_80128450);
    }
    else
    {
      value = ((f32) arg1[index]) * BT_DATA_FIELD(D_80128410.scale, D_80128450);
    }
    pos[index] = (s32) (value - BT_DATA_FIELD(D_80128410.lower[index], ((s32 *)&D_80128410)[index + 1]));
  }

  count = 0;
  if ((((((pos[0] > 0) && (pos[0] < ((BT_DATA_FIELD(D_80128410.dimensions[0], D_80128410.pad[3])) - 1))) && (pos[1] > 0)) && (pos[1] < ((BT_DATA_FIELD(D_80128410.dimensions[1], D_80128410.pad[4])) - 1))) && (pos[2] > 0)) && (pos[2] < ((BT_DATA_FIELD(D_80128410.dimensions[2], D_80128410.pad[5])) - 1)))
  {
    base = ((pos[0] + ((pos[1] - 1) * (BT_DATA_FIELD(D_80128410.row_stride, D_80128410.pad[0])))) + ((pos[2] - 1) * (BT_DATA_FIELD(D_80128410.plane_stride, D_80128410.pad[1])))) - 1;
    index = base;
    iter[0] = 0;
    do
    {
      for (iter[1] = 0; iter[1] < 3; iter[1]++)
      {
        for (iter[2] = 0; iter[2] < 3; iter[2]++)
        {
          if (func_800E9DCC((s16 *) (BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3))))
          {
            arg0[count++] = BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3);
          }
          index++;
        }

        index = (index + (BT_DATA_FIELD(D_80128410.row_stride, D_80128410.pad[0]))) - (new_var = 3);
      }

      base += BT_DATA_FIELD(D_80128410.plane_stride, D_80128410.pad[1]);
      index = base;
    } while (++iter[0] < 3);

  }
  else
  {
    for (iter[0] = pos[0] - 1; iter[0] < (pos[0] + 2); iter[0]++)
    {
      if ((iter[0] >= 0) && (iter[0] < (BT_DATA_FIELD(D_80128410.dimensions[0], D_80128410.pad[3]))))
      {
        for (iter[1] = pos[1] - 1; iter[1] < (pos[1] + 2); iter[1]++)
        {
          if ((iter[1] >= 0) && (iter[1] < (BT_DATA_FIELD(D_80128410.dimensions[1], D_80128410.pad[4]))))
          {
            for (iter[2] = pos[2] - 1; iter[2] < (pos[2] + 2); iter[2]++)
            {
              if ((iter[2] >= 0) && (iter[2] < (BT_DATA_FIELD(D_80128410.dimensions[2], D_80128410.pad[5]))))
              {
                index = (iter[0] + (iter[1] * (BT_DATA_FIELD(D_80128410.row_stride, D_80128410.pad[0])))) + (iter[2] * (BT_DATA_FIELD(D_80128410.plane_stride, D_80128410.pad[1])));
                if (func_800E9DCC((s16 *) (BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3))))
                {
                  arg0[count++] = BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0) + (index << 3);
                }
              }
            }

          }
        }

      }
    }

  }
  return count;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell **func_800BE3F8(f32 *position) {
    s32 pos[3];func_800EE904(pos,position);
    dynamic_neighbors[func_800BE09C(dynamic_neighbors,pos)]=NULL;
    return dynamic_neighbors;
}
#else
s32 *func_800BE3F8(u8 *arg0) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    s32 func_800BE09C(s32 *, s32 *);
    BT_IDO_ONLY(extern s32 D_801284C8;)
    s32 sp1C[3];

    func_800EE904(sp1C, (f32 *) arg0);
    (WORLD_DYNAMIC_NEIGHBORS)[func_800BE09C(WORLD_DYNAMIC_NEIGHBORS, sp1C)] = 0;
    return WORLD_DYNAMIC_NEIGHBORS;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeWorldCell **func_800BE444(f32 *position) {
    s32 pos[3],count;func_800EE904(pos,position);
    count=func_800BE09C(all_neighbors,pos);
    if(func_800E9DCC(&native_world_grid.fallback)) all_neighbors[count++]=&native_world_grid.fallback;
    all_neighbors[count]=NULL;return all_neighbors;
}
#else
s32 *func_800BE444(f32 *arg0) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    s32 func_800BE09C(s32 *, s32 *);
    s32 func_800E9DCC(s16 *);
    BT_IDO_ONLY(extern u8 D_80128444;)
    BT_IDO_ONLY(extern s32 D_80128538;)
    s32 sp1C[3];
    s32 count;

    func_800EE904(sp1C, arg0);
    count = func_800BE09C(WORLD_ALL_NEIGHBORS, sp1C);
    if (func_800E9DCC((s16 *)&BT_DATA_FIELD(D_80128410.fallback, D_80128444))) {
        (WORLD_ALL_NEIGHBORS)[count] = (s32)&BT_DATA_FIELD(D_80128410.fallback, D_80128444);
        count++;
    }
    (WORLD_ALL_NEIGHBORS)[count] = 0;
    return WORLD_ALL_NEIGHBORS;
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800BE4C4(void) {
    for(s32 i=0;i<native_world_grid.count;++i) func_800E9CF4(native_world_grid.cells+i);
    func_800E9CF4(&native_world_grid.fallback);return 0;
}
#else
s32 func_800BE4C4(void) {
    BT_IDO_ONLY(extern u8 D_80128444;)
    s32 func_800E9CF4(u8 *);
    u8 *var_s0;
    u8 *temp_s1;

    temp_s1 = *(u8 **)&D_80128410 + (BT_DATA_FIELD(D_80128410.count, D_80128410.pad[2])) * 8;
    var_s0 = *(u8 **)&D_80128410;
    for (; var_s0 < temp_s1; var_s0 += 8) {
        func_800E9CF4(var_s0);
    }
    return func_800E9CF4(&BT_DATA_FIELD(D_80128410.fallback, D_80128444));
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BE52C(NativeWorldCell **begin,NativeWorldCell **end) {
    *begin=native_world_grid.cells;
    *end=*begin ? *begin+native_world_grid.count : NULL;
}
#else
void func_800BE52C(s32 *arg0, s32 *arg1) {
    *arg0 = (BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0));
    *arg1 = (BT_DATA_FIELD((s32)D_80128410.cells, D_80128410.unk0)) + ((BT_DATA_FIELD(D_80128410.count, D_80128410.pad[2])) << 3);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BE554(s32 *lower,s32 *upper) {
    func_800EE830(lower,native_world_grid.lower);func_800EE830(upper,native_world_grid.upper);
}
#else
void func_800BE554(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    BT_IDO_ONLY(extern s32 D_80128414;)
    BT_IDO_ONLY(extern s32 D_80128420;)
    func_800EE830(arg0, &BT_DATA_FIELD(D_80128410.lower[0], D_80128414));
    func_800EE830(arg1, &BT_DATA_FIELD(D_80128410.upper[0], D_80128420));
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800BE58C(s32 *dimensions,s32 *strides) {
    func_800EE830(dimensions,native_world_grid.dimensions);
    strides[0]=native_world_grid.row_stride;strides[1]=native_world_grid.plane_stride;strides[2]=native_world_grid.count;
}
#else
void func_800BE58C(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    BT_IDO_ONLY(extern s32 D_80128438;)
    BT_IDO_ONLY(extern s32 D_8012842C;)
    func_800EE830(arg0, &BT_DATA_FIELD(D_80128410.dimensions[0], D_80128438));
    func_800EE830(arg1, &BT_DATA_FIELD(D_80128410.row_stride, D_8012842C));
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
u8 *func_800BE5C4(void *cell) {
    s32 index=func_800BD948(cell);
    return index<0 ? &native_world_grid.fallback_models : native_world_grid.model_counts+index;
}
#else
u8 *func_800BE5C4(u8 *arg0) {
    BT_IDO_ONLY(extern u8 D_8012844E;)
    if (arg0 == (u8 *)&D_80128410 + 0x34) {
        return &BT_DATA_FIELD(D_80128410.fallback_models, D_8012844E);
    }
    return *(u8 **)((u8 *)&D_80128410 + 0x44) + ((arg0 - *(u8 **)&D_80128410) >> 3);
}
#endif

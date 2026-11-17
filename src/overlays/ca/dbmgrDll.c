#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_camera_db.h"
#include "memory.h"

void cadbmgrDll_entrypoint_0(NativeCameraDatabase **database,s32 maximum) {
    s32 i;
    if(maximum<0 || maximum>(INT32_MAX-(s32)sizeof(NativeCameraDatabase))/2-1) return;
    if(*database) cadbmgrDll_entrypoint_1(database);
    *database=heap_alloc(sizeof(NativeCameraDatabase)+(maximum+1)*sizeof(NativeCameraEntry));
    rare_memset(*database,0,sizeof(NativeCameraDatabase));
    (*database)->maximum=maximum;(*database)->selected=-1;
    for(i=0;i<=maximum;++i) (*database)->entries[i]=(NativeCameraEntry){0,255};
}
void cadbmgrDll_entrypoint_1(NativeCameraDatabase **database) {
    s32 i;
    if(!database || !*database) return;
    for(i=0;i<8;++i) if((*database)->handles[i]) func_8001B754((*database)->handles[i]);
    heap_free(*database);*database=NULL;
}

s32 func_808003D8_cadbmgrDll(NativeCameraDatabase *database,s32 type,s32 count) {
    s32 size=func_800A57EC(type);
    s16 handle;
    if(!database || !size || count<0 || count>256) return 0;
    handle=database->handles[type-1];
    if(count) {
        if(handle) func_8001B710(handle,size*count);
        else {handle=func_8001B668(0,size*count);if(!handle)return 0;}
    } else if(handle) {func_8001B754(handle);handle=0;}
    database->handles[type-1]=handle;database->counts[type-1]=count;
    database->selected=-1;database->current=NULL;
    return 1;
}

s32 func_808004C4_cadbmgrDll(NativeCameraDatabase *database,s32 type,s32 id) {
    s32 i,index=database->counts[type-1];
    for(i=database->maximum;i>=0;--i)
        if(database->entries[i].type==type && id<i && index>=database->entries[i].index)
            index=database->entries[i].index;
    return index;
}
void func_808005AC_cadbmgrDll(NativeCameraDatabase *database,s32 type,s32 source,s32 destination) {
    s32 size=func_800A57EC(type);
    u8 *base=func_8001B798(database->handles[type-1]);
    rare_memcpy(base+destination*size,base+source*size,size);
}
void func_80800528_cadbmgrDll(NativeCameraDatabase *database,s32 type,s32 index) {
    s32 i;
    for(i=database->counts[type-1]-1;index<i;--i) func_808005AC_cadbmgrDll(database,type,i-1,i);
}
s32 cadbmgrDll_entrypoint_2(NativeCameraDatabase *database,s32 type,s32 id) {
    s32 index,i,count;
    if(!database || type<1 || type>8 || id<0 || id>database->maximum || database->entries[id].type) return 0;
    count=database->counts[type-1];if(count==256)return 0;
    index=func_808004C4_cadbmgrDll(database,type,id);
    if(!func_808003D8_cadbmgrDll(database,type,count+1)) return 0;
    for(i=0;i<=database->maximum;++i)
        if(database->entries[i].type==type && database->entries[i].index>=index) ++database->entries[i].index;
    database->entries[id]=(NativeCameraEntry){type,index};
    func_80800528_cadbmgrDll(database,type,index);
    rare_memset((u8 *)func_8001B798(database->handles[type-1])+index*func_800A57EC(type),0,func_800A57EC(type));
    return func_808000F4_cadbmgrDll(id);
}

s32 func_808000F4_cadbmgrDll(s32 arg0) {
    s32 _cadbfunc_entrypoint_1(f32 *);
    s32 _cadbfunc_entrypoint_3(f32 *);
    s32 _cadbfunc_entrypoint_5(f32 *);
    s32 _cadbfunc_entrypoint_7(f32, f32);
    s32 _cadbfunc_entrypoint_9(f32, f32);
    s32 _cadbfunc_entrypoint_11(f32);
    s32 _cadbfunc_entrypoint_13(f32);
    s32 _cadbfunc_entrypoint_15(f32);
    s32 _cadbfunc_entrypoint_17(s16);
    s32 _cadbfunc_entrypoint_19(f32);
    s32 _cadbfunc_entrypoint_21(f32);
    s32 _cadbfunc_entrypoint_23(s32);
    s32 _cadbfunc_entrypoint_25(s32);
    s32 _cadbfunc_entrypoint_27(s32);
    s32 _cadbfunc_entrypoint_28(s32, s32);
    s32 _cadbfunc_entrypoint_31(s32);
    s32 _cadbfunc_entrypoint_33(f32);
    s32 _cadbfunc_entrypoint_35(s32);
    u8 *func_800A5800(s32);
    s32 func_800A5854(s32);
    void func_800E3980(f32 *);
    void func_800E3A58(f32 *);
    struct CadbmgrVector { f32 v[3]; } sp24;
    const struct CadbmgrVector D_80800630_cadbmgrDll = {{0, 0, 0}};
    s32 sp20;

    sp24 = D_80800630_cadbmgrDll;
    sp20 = func_800A5854(arg0);
    if (!func_800A5800(arg0)) return 0;
    if (sp20 == 1 || sp20 == 2 || sp20 == 3 || sp20 == 5) {
        func_800E3980(sp24.v);
        _cadbfunc_entrypoint_1(sp24.v);
        func_800E3A58(sp24.v);
        _cadbfunc_entrypoint_3(sp24.v);
    } else {
        _cadbfunc_entrypoint_1(sp24.v);
        _cadbfunc_entrypoint_3(sp24.v);
    }
    _cadbfunc_entrypoint_5(sp24.v);
    _cadbfunc_entrypoint_7(1.75f, 3.75f);
    _cadbfunc_entrypoint_9(2.75f, 12.0f);
    _cadbfunc_entrypoint_11(150.0f);
    _cadbfunc_entrypoint_13(40.0f);
    _cadbfunc_entrypoint_15(1.0f);
    _cadbfunc_entrypoint_17(-1);
    _cadbfunc_entrypoint_19(1000.0f);
    _cadbfunc_entrypoint_21(1000.0f);
    _cadbfunc_entrypoint_25(0);
    _cadbfunc_entrypoint_27(0);
    _cadbfunc_entrypoint_23(0);
    _cadbfunc_entrypoint_31(0);
    _cadbfunc_entrypoint_33(0.0f);
    _cadbfunc_entrypoint_35(0);
    switch (sp20) {
    case 4:
        _cadbfunc_entrypoint_27(0);
        _cadbfunc_entrypoint_23(10);
        break;
    case 1:
        _cadbfunc_entrypoint_28(2, 1);
        break;
    case 7:
        _cadbfunc_entrypoint_25(1);
        break;
    }
    return 1;
}

#else
#include "common.h"

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) cadbmgrDll_entrypoint_0(u8 **arg0, s32 arg1) {
    s32 func_800A56A4();
    void *heap_alloc(s32);
    s32 i;

    *arg0 = heap_alloc((arg1 * 2) + 0x40);
    for (i = 1; i < 9; i++) {
        ((s16 *)*arg0)[i + 15] = 0;
        ((s32 *)*arg0)[i - 1] = 0;
    }
    (*(s32 *)((s8 *)(*arg0) + (0x38))) = arg1;
    BT_NATIVE_ONLY(return) func_800A56A4();
}

/* extern */

void cadbmgrDll_entrypoint_1(s32 *arg0) {
    s32 func_800A56A4();
    s32 heap_free(s32);
    func_800A56A4();
    heap_free(*arg0);
    *arg0 = 0;
}

s32 func_808000F4_cadbmgrDll(s32 arg0) {
    s32 _cadbfunc_entrypoint_1(f32 *);
    s32 _cadbfunc_entrypoint_3(f32 *);
    s32 _cadbfunc_entrypoint_5(f32 *);
    s32 _cadbfunc_entrypoint_7(f32, f32);
    s32 _cadbfunc_entrypoint_9(f32, f32);
    s32 _cadbfunc_entrypoint_11(f32);
    s32 _cadbfunc_entrypoint_13(f32);
    s32 _cadbfunc_entrypoint_15(f32);
    s32 _cadbfunc_entrypoint_17(s16);
    s32 _cadbfunc_entrypoint_19(f32);
    s32 _cadbfunc_entrypoint_21(f32);
    s32 _cadbfunc_entrypoint_23(s32);
    s32 _cadbfunc_entrypoint_25(s32);
    s32 _cadbfunc_entrypoint_27(s32);
    s32 _cadbfunc_entrypoint_28(s32, s32);
    s32 _cadbfunc_entrypoint_31(s32);
    s32 _cadbfunc_entrypoint_33(f32);
    s32 _cadbfunc_entrypoint_35(s32);
    s32 func_800A5800(s32);
    s32 func_800A5854(s32);
    void func_800E3980(f32 *);
    void func_800E3A58(f32 *);
    struct CadbmgrVector { f32 v[3]; } sp24;
    extern struct CadbmgrVector D_80800630_cadbmgrDll;
    s32 sp20;

    sp24 = D_80800630_cadbmgrDll;
    sp20 = func_800A5854(arg0);
    func_800A5800(arg0);
    if (sp20 == 1 || sp20 == 2 || sp20 == 3 || sp20 == 5) {
        func_800E3980(sp24.v);
        _cadbfunc_entrypoint_1(sp24.v);
        func_800E3A58(sp24.v);
        _cadbfunc_entrypoint_3(sp24.v);
    } else {
        _cadbfunc_entrypoint_1(sp24.v);
        _cadbfunc_entrypoint_3(sp24.v);
    }
    _cadbfunc_entrypoint_5(sp24.v);
    _cadbfunc_entrypoint_7(1.75f, 3.75f);
    _cadbfunc_entrypoint_9(2.75f, 12.0f);
    _cadbfunc_entrypoint_11(150.0f);
    _cadbfunc_entrypoint_13(40.0f);
    _cadbfunc_entrypoint_15(1.0f);
    _cadbfunc_entrypoint_17(-1);
    _cadbfunc_entrypoint_19(1000.0f);
    _cadbfunc_entrypoint_21(1000.0f);
    _cadbfunc_entrypoint_25(0);
    _cadbfunc_entrypoint_27(0);
    _cadbfunc_entrypoint_23(0);
    _cadbfunc_entrypoint_31(0);
    _cadbfunc_entrypoint_33(0.0f);
    _cadbfunc_entrypoint_35(0);
    switch (sp20) {
    case 4:
        _cadbfunc_entrypoint_27(0);
        _cadbfunc_entrypoint_23(10);
        break;
    case 1:
        _cadbfunc_entrypoint_28(2, 1);
        break;
    case 7:
        _cadbfunc_entrypoint_25(1);
        break;
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

struct CadbmgrData;
s32 cadbmgrDll_entrypoint_2(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_808000F4_cadbmgrDll(s32);
    s32 func_808003D8_cadbmgrDll(struct CadbmgrData *, s32, s32);
    s32 func_808004C4_cadbmgrDll(s32 *, s32, s32);
    void func_80800528_cadbmgrDll(s32, s32, s32);
    s32 result;
    s32 index;

    if (((u8 *)arg0 + arg2 * 2)[0x3C] != 0) {
        return 0;
    }
    result = func_808004C4_cadbmgrDll(arg0, arg1, arg2);
    for (index = 0; index < arg0[14]; index++) {
        if (arg1 == ((u8 *)arg0)[index * 2 + 0x3C]) {
            if (((u8 *)arg0)[index * 2 + 0x3D] >= result) {
                ((u8 *)arg0)[index * 2 + 0x3D]++;
            }
        }
    }
    ((u8 *)arg0 + arg2 * 2)[0x3C] = arg1;
    ((u8 *)arg0 + arg2 * 2)[0x3D] = result;
    func_808003D8_cadbmgrDll((struct CadbmgrData *)arg0, arg1, ((s32 *)((u8 *)arg0 + arg1 * 4))[-1] + 1);
    if (result < ((s32 *)((u8 *)arg0 + arg1 * 4))[-1] - 1) {
        func_80800528_cadbmgrDll((s32)arg0, arg1, result);
    }
    func_808000F4_cadbmgrDll(arg2);
    return 1;
}

/* extern */

struct CadbmgrData {
    s32 counts[8];
    s16 handles[8];
    s32 invalid;
    s32 zero;
};

s32 func_808003D8_cadbmgrDll(struct CadbmgrData *arg0, s32 arg1, s32 arg2) {
    s16 func_8001B668(s32, s32);
    void *func_8001B710(s16, s32);
    void func_8001B754(s16);
    s32 func_800A57EC(s32);
    s16 handle;
    s16 *temp_v0;
    s16 *saved[2];

    if (arg2 != 0) {
        if (arg0->counts[arg1 - 1] != 0) {
            func_8001B710(arg0->handles[arg1 - 1], func_800A57EC(arg1) * arg2);
        } else {
            arg0->handles[arg1 - 1] = func_8001B668(0, func_800A57EC(arg1));
        }
    } else {
        temp_v0 = (s16 *)arg0 + arg1;
        if (arg0->counts[arg1 - 1] != 0) {
            handle = temp_v0[15];
            saved[1] = temp_v0;
            func_8001B754(handle);
            temp_v0 = saved[1];
            temp_v0[15] = 0;
        }
    }
    arg0->counts[arg1 - 1] = arg2;
    arg0->invalid = -1;
    arg0->zero = 0;
    return 1;
}

s32 func_808004C4_cadbmgrDll(s32 *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 var_v1;
    u8 temp_a0;
    u16 *var_a2;

    var_v0 = arg0[14] - 1;
    var_v1 = *(arg0 + arg1 - 1);
    if (var_v0 >= 0) {
        var_a2 = (u16 *)arg0 + var_v0;
        do {
            if ((arg1 == (*(u8 *)((s8 *)(var_a2) + (0x3C)))) && (arg2 < var_v0)) {
                temp_a0 = (*(u8 *)((s8 *)(var_a2) + (0x3D)));
                if (var_v1 >= (s32) temp_a0) {
                    var_v1 = (s32) temp_a0;
                }
            }
            var_v0 -= 1;
            var_a2 -= 1;
        } while (var_v0 >= 0);
    }
    return var_v1;
}

/* extern */

void func_80800528_cadbmgrDll(s32 arg0, s32 arg1, s32 arg2) {
    void func_808005AC_cadbmgrDll(s32, s32, s32, s32);
    s32 var_s0;

    for (var_s0 = *((s32 *)arg0 + arg1 - 1) - 1; arg2 < var_s0; var_s0--) {
        func_808005AC_cadbmgrDll(arg0, arg1, var_s0 - 1, var_s0);
    }
}

/* extern */

void func_808005AC_cadbmgrDll(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_8001B798(s16);
    s32 func_800A57EC(s32);
    void rare_memcpy(void *, void *, int);
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_800A57EC(arg1);
    temp_v0 = func_8001B798(*(s16 *)((s8 *)arg0 + (arg1 << 1) + 0x1E));
    rare_memcpy((void *)((s8 *)temp_v0 + arg3 * sp1C), (void *)((s8 *)temp_v0 + arg2 * sp1C), sp1C);
}

#endif

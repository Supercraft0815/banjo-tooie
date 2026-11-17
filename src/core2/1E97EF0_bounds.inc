#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "native_map.h"
void func_800BEC4C(s32 *lower,s32 *upper,s32 size) {
    func_800BECE0(lower,upper);
    if(size<=0)return;
    for(int i=0;i<3;++i) {
        lower[i]=lower[i]/size-(lower[i]<0)+native_map.config.padding[i];
        upper[i]=upper[i]/size-(upper[i]<0)+native_map.config.padding[i+3];
    }
}
f32 func_800BECCC(void) {return native_map.minimum[1];}
void func_800BECE0(s32 *lower,s32 *upper) {
    for(int i=0;i<3;++i){lower[i]=native_map.minimum[i];upper[i]=native_map.maximum[i];}
}
void func_800BED18(s32 *lower,s32 *upper) {
    for(int i=0;i<3;++i){lower[i]=native_map.combined_minimum[i];upper[i]=native_map.combined_maximum[i];}
}
#else
void func_800BECE0(s32 *arg0, s32 *arg1);
void func_800BEC4C(s32 *arg0, s32 *arg1, s32 arg2) { extern s8 D_801285B3; s8 *var_v0; s32 *var_v1; s32 *var_a0; s8 *end; func_800BECE0(arg0, arg1); func_800E37E8(arg0, arg1, arg2); end = &D_801285B3; var_v0 = (s8 *)&D_801285B0; var_v1 = arg0; var_a0 = arg1; do { *var_v1 += var_v0[0x5E]; var_v0++; var_v1++; *var_a0 += var_v0[0x60]; var_a0++; if (var_v0 == end) break; } while (1); }

f32 func_800BECCC(void) {
    extern s32 D_80128734;
    return (f32) D_80128734;
}

void func_800BECE0(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128730;
    extern s32 D_8012873C;
    func_800EE830(arg0, &D_80128730);
    func_800EE830(arg1, &D_8012873C);
}

void func_800BED18(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128748;
    extern s32 D_80128754;
    func_800EE830(arg0, &D_80128748);
    func_800EE830(arg1, &D_80128754);
}

#endif

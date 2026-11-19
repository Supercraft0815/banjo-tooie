#include <stdint.h>
#include <stddef.h>
#include "core2/taxi.h"

void func_800CB618(void);
s32 func_800CB3E0(s32);
s32 func_800CB698(s32, s32);
s32 func_800CB4D0(s32, TaxiProviderGetter, s32);
s16 func_800CB518(s32);
void func_800CB534(s32, f32 *, f32);
void func_800CB764(s32, f32 *, f32, s32, s32);
f32 func_800CB45C(s32, f32 *, s32 *, s32 *);
f32 func_800CB3FC(s32, f32 *, s32 *);
s32 func_800CB7C4(s32, f32 *, f32 *);

static int spawn_count, interaction_count, sound_count;
static s32 got_slot, got_flags;
static void copy3(f32 *dst, const f32 *src) { for (int i=0;i<3;i++) dst[i]=src[i]; }
static int equal3(const f32 *a, const f32 *b) { for (int i=0;i<3;i++) if (a[i]!=b[i]) return 0; return 1; }
static s32 got_yaw_bits;
static f32 got_position[3];
static s32 mock_interact(s32 slot, f32 *pos, f32 *out) {
    (void)pos; (void)out; interaction_count++; got_slot=slot; return 2;
}
static void mock_spawn(s32 slot, void *args, s32 yaw_bits, s32 flags) {
    f32 *pos=(f32 *)args;
    spawn_count++; got_slot=slot; got_yaw_bits=yaw_bits; got_flags=flags;
    copy3(got_position,pos);
}
static TaxiMethods methods={mock_interact,mock_spawn};
static OSThread *mock_get(void) { return (OSThread *)&methods; }
void func_800EE7F8(f32 *dst, f32 *src) { copy3(dst,src); }
void func_800EFD24(f32 *p) { p[0]=p[1]=p[2]=0.0f; }
void func_800FC63C(u32 a, u32 b) { if (a==0xE && b==0x7FFF) sound_count++; }

int main(void) {
    f32 pos[3], other[3]={1.0f,2.0f,3.0f}, out[3]={0};
    s32 map, flags;
    if (sizeof(void *) <= 4 || (uintptr_t)mock_get <= UINT32_MAX || (uintptr_t)&methods <= UINT32_MAX) return 1;
    func_800CB618();
    for (int i=0;i<16;i++) {
        if (D_8012AB70[i].index != i || func_800CB3E0(i) != 0 || D_8012AB70[i].provider) return 2;
        if (func_800CB4D0(i,mock_get,0x100+i)!=1) return 3;
        if (func_800CB3E0(i) != 1) return 11;
        func_800CB698(i, 4);
        if (func_800CB3E0(i) != 4 || D_8012AB70[i].index != i) return 12;
        if (func_800CB4D0(i,mock_get,0x200+i)!=0) return 4;
        func_800CB764(i,other,10.5f,0x120+i,0x30+i);
    }
    if (func_800CB518(15)!=0x10F) return 5;
    for (int i=0;i<16;i++) {
        if (func_800CB45C(i,pos,&map,&flags)!=10.5f || !equal3(pos,other) || map!=0x120+i || flags!=0x30+i) return 6;
        union { f32 value; s32 bits; } yaw; yaw.value=22.25f;
        func_800CB534(i,pos,yaw.value);
        if (got_slot!=i || got_yaw_bits!=yaw.bits || got_flags!=0x30+i || !equal3(got_position,pos)) return 7;
        if (func_800CB7C4(i,pos,out)!=2 || got_slot!=i) return 8;
    }
    if (spawn_count!=16 || interaction_count!=16 || sound_count!=16) return 9;
    func_800CB618();
    for (int i=0;i<16;i++) if (D_8012AB70[i].index!=i || func_800CB3E0(i)!=0 || D_8012AB70[i].provider) return 10;
    return 0;
}

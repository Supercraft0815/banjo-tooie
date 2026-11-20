#include "native_spawn_queue.h"
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"line %d: %s\n", __LINE__, #x); __builtin_trap(); } } while (0)

Actor *func_80800664_chbadshad(void *, void *, f32);
void func_8080000C_chbadshad(Actor *);
void func_808000E0_chbadshad(Actor *, BtIntPtr);
void func_8080082C_chbadshad(Actor *);
static Actor owner, shadow;
static Unk80132ED0 owner_marker, shadow_marker;
static int queue_count, released, found, render_state, translucent, scaled;
static NativeSpawn5 queued;
static uintptr_t words[5];
void _chbaddiesetup_entrypoint_5(NativeSpawn5 cb, uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e) {
    queued=cb; words[0]=a; words[1]=b; words[2]=c; words[3]=d; words[4]=e; ++queue_count;
}
Actor *func_80106790(Unk80132ED0 *marker) {
    CHECK(marker==&owner_marker || marker==&shadow_marker);
    ++found; return marker==&owner_marker ? &owner : &shadow;
}
Actor *func_801084B0(BtIntPtr id, Actor **parent) { CHECK(id==0x243 && *parent==&owner); return &shadow; }
void func_800FFAB0(Actor *actor) { CHECK(actor==&shadow); ++released; }
int func_8001211C(void) { return 43; }
void func_800EE7F8(f32 *dst, f32 *src) { __builtin_memcpy(dst,src,3*sizeof(f32)); }
void func_8010A800(Actor *actor, s32 value) { CHECK(actor==&shadow && value==5); }
s32 func_80102F74(void *actor, s32 mask) { CHECK(actor==&owner && (u32)mask==0x82000000); return translucent; }
s32 _subaddiefade_entrypoint_0(Actor *actor) { CHECK(actor==&owner); return 31; }
void func_800DF410(s32 fade) { CHECK(fade==31); }
void func_800DF470(s32 n) { CHECK(n==1); }
f32 func_800DF428(f32 distance) { CHECK(distance==4000); return 0; }
void func_800DF830(s32 state) { render_state=state; }
f32 func_800F10B4(f32 h, f32 a, f32 b, f32 c, f32 d) { CHECK(h==0 && a==0 && b==800); return .25f; }
f32 *func_80101918(f32 f) { CHECK(f==.5f); return shadow.rotation; }
u8 *func_801039E4(Unk80132ED0 *marker) { CHECK(marker==&shadow_marker); return (u8 *)&shadow; }
void *func_800DE448(f32 *pos, f32 *rot, f32 scale, f32 *transform, u8 *model) {
    CHECK(pos==shadow.position && rot==shadow.rotation && (void *)model==&shadow);
    CHECK(transform==(translucent ? NULL : shadow.rotation));
    CHECK(scale==(scaled ? 1.f : .5f)); return (void *)model;
}
int func_800DB9B0(void) { return 0; }
int func_80104544(BtIntPtr parent) { CHECK((Actor *)parent==&owner); return 0; }
void *func_80105494(Actor *actor) { CHECK(0); return NULL; }
s32 func_80104668(BtIntPtr actor,f32 *a,f32 *b,f32 *c,f32 *d){CHECK(0);return 0;}
s32 func_8010518C(BtIntPtr actor) {CHECK(0);return 0;}
void func_8010279C(void *a,void *b){CHECK(0);}
u32 func_8010A654(void ***a,s32 b){CHECK(0);return 0;}
void *func_800C6A7C(f32 *a,f32 *b,f32 *c,u32 d){CHECK(0);return NULL;}
f32 func_800F0E00(f32 a,f32 b){CHECK(0);return 0;}
int func_800F1988(f32 *a,f32 *b,f32 *c){CHECK(0);return 0;}
void func_801045AC(Actor *a,f32 *b,f32 *c,s32 d){CHECK(0);}
int main(void) {
    const f32 position[]={-11.25f,22.5f,83.f};
    CHECK((uintptr_t)&owner_marker>UINT32_MAX && (uintptr_t)&shadow_marker>UINT32_MAX);
    owner.unk0=&owner_marker; shadow.unk0=&shadow_marker;
    owner.unk3C=&owner_marker; shadow.unk3C=&shadow_marker;
    owner.rotation[0]=92.f; owner.unk14=0x11223344; owner.flags70=1u<<19;
    CHECK(func_80800664_chbadshad(&owner,(void *)position,2.f)==NULL);
    CHECK(queued && queue_count==1 && words[0]==(uintptr_t)&owner_marker);
    queued(words[0],words[1],words[2],words[3],words[4]);
    CHECK(owner.parent_marker==&shadow_marker && shadow.parent_marker==&owner_marker);
    CHECK(shadow.scale==2.f && !__builtin_memcmp(shadow.position,position,sizeof(position)));
    CHECK(shadow.unk14==owner.unk14 && shadow.actorData[0]==43);
    shadow.flags7A=0x1245;
    for(translucent=0;translucent<=1;++translucent) {
        scaled=translucent;
        owner.flags74=(u32)scaled<<26;
        func_8080000C_chbadshad(&shadow);
        CHECK(shadow.flags7A==(u16)(0x1245|((translucent+2)<<14)));
        func_808000E0_chbadshad(&shadow,0);
        CHECK(render_state==translucent+2 && shadow.unk7C_12);
    }
    CHECK(func_80800664_chbadshad(&owner,(void *)position,3.f)==&shadow && shadow.scale==3.f);
    owner.unk64_17=1;
    CHECK(func_80800664_chbadshad(&owner,(void *)position,3.f)==NULL);
    CHECK(owner.parent_marker==NULL && released==1 && owner.unk3C==&owner_marker && owner.rotation[0]==92.f);
    shadow.parent_marker=NULL; int lookups=found;
    func_8080082C_chbadshad(&shadow);
    CHECK(released==2 && lookups==found && shadow.unk3C==&shadow_marker);
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "gc/newoption_state.h"
#include "gc/newoption.h"

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "check failed at %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)

static uint64_t arena[4096];
static size_t arena_used;
static u8 *actor_data;
static OptionState *expected_option;
static int init_count;
static int finalize_count;
extern s32 _gcnewoption_entrypoint_35;

static void *high_map(size_t size) {
    size_t offset = (arena_used + 15u) & ~(size_t)15u;
    CHECK(offset + size <= sizeof(arena));
    void *p=(u8 *)arena + offset;
    arena_used=offset+size;
    for (size_t i=0;i<size;i++) ((u8 *)p)[i]=0;
    CHECK((uintptr_t)p>UINT32_MAX);
    return p;
}

void *func_80100094(Actor *actor, u32 offset) {
    CHECK((uintptr_t)actor>UINT32_MAX); CHECK(offset==0); return actor_data;
}
void func_8010A828(void **actor, s32 state) { CHECK(state==9); finalize_count++; }
s32 _gcnewoption_entrypoint_2(void) { return sizeof(OptionState); }
void _gcnewoption_entrypoint_5(void *state, BtIntPtr callback, BtIntPtr context, s32 size, Unk80132ED0 *parent) {
    CHECK(state==expected_option); CHECK((uintptr_t)state>UINT32_MAX);
    CHECK(callback==(BtIntPtr)&_gcnewoption_entrypoint_35); CHECK(context==0);
    CHECK(size==0x2468); CHECK(parent==(Unk80132ED0 *)(uintptr_t)0xBEEF);
    init_count++;
}
void _gcnewoption_entrypoint_8(s16 *state, s32 value) { CHECK((void *)state==expected_option); CHECK(value==3); }
void _gcnewoption_entrypoint_9(s16 *state, s32 value) { CHECK((void *)state==expected_option); CHECK(value==3); }
void _gcnewoption_entrypoint_10(void *state, s32 value) { CHECK(state==expected_option); CHECK(value==2); }
void _gcnewoption_entrypoint_14(void *state, s16 a, s16 b, s16 c, f32 d) { CHECK(state==expected_option); CHECK(a==0&&b==0&&c==0&&d==4.0f); }
int _gcnewoption_entrypoint_32(void *state, s16 value) { CHECK(state==expected_option); CHECK(value==0x22); return 0; }
void _gcnewoption_entrypoint_30(BtIntPtr state, s16 *texts) { CHECK((void *)state==expected_option); CHECK(texts[0]==157 && texts[1]==159 && texts[2]==-1 && texts[3]==0); }
void _gcnewoption_entrypoint_28(BtIntPtr state) { CHECK((void *)state==expected_option); }
void _gcnewoption_entrypoint_29(BtIntPtr state, s32 value) { CHECK((void *)state==expected_option); CHECK(value==1); }
void _gcnewoption_entrypoint_11(s16 *state) { CHECK((void *)state==expected_option); }
s32 _gcnewoption_entrypoint_35=0;

void func_80803224_chdiggerboss(Actor *actor);

int main(void) {
    Actor *actor=high_map(4096);
    actor_data=high_map(4096);
    actor->unk0=(Unk80132ED0 *)(uintptr_t)0xBEEF;
    *(u16 *)(actor_data+0x44)=0x2468;
    expected_option=(OptionState *)(actor_data+0x110);
    for (int i=0;i<(int)sizeof(*expected_option);i++) expected_option->data[i]=0xA5;
    actor_data[0x110+sizeof(*expected_option)]=0x5A;
    func_80803224_chdiggerboss(actor);
    CHECK(init_count==1 && finalize_count==1);
    for (int i=0;i<(int)sizeof(expected_option->data);i++) CHECK(expected_option->data[i]==0);
    CHECK(actor_data[0x110+sizeof(*expected_option)]==0x5A);
    CHECK(actor_data[0x40]==2 && actor_data[0x42]==1 && actor_data[0x48]==1);
    puts("Digger production option allocation path passed");
    return 0;
}

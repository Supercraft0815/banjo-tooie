#include "common.h"
#include "gameselect_roles.h"
#include <stdint.h>
#include <stdlib.h>

void func_8080000C_chgameselect(Actor *);
void func_80800440_chgameselect(void *);

static unsigned allocations, releases;
static void *allocated;
void *heap_alloc(s32 size) {
    if (size <= 0) abort();
    ++allocations;
    allocated = malloc(size);
    if (!allocated) abort();
    return allocated;
}
void heap_free(void *memory) {
    ++releases;
    free(memory);
}
void func_80016BDC(s32 mode) { (void)mode; }
void _gcfrontend_entrypoint_0(void) {}
void func_800AA00C(void) {}
u32 func_800AA0B8(void) { return 0; }
s32 func_800D395C(void) { return 0; }
void func_80108B04(Actor *actor, u32 id) { (void)actor; (void)id; }
void _glsavegame_entrypoint_0(void) {}
void _glsavegame_entrypoint_1(void) {}

void func_808021E4_chgameselect(void *);
void func_80802480_chgameselect(void *);
void func_808024D4_chgameselect(void *);
void func_80802588_chgameselect(void *);
void func_808025CC_chgameselect(Actor *, BtIntPtr);
void func_80806FAC_chgameselect(Actor *, BtIntPtr);
void func_80807030_chgameselect(Actor *);

static u8 boxes[4];
static u8 *drawn[4];
static unsigned draws, closed, released_strings;
static BtIntPtr render_context;
static GameSelectPanel panel;
static Actor *panel_owner;
u32 *func_80100074(Actor *actor, u32 slot, u32 size) {
    if (slot || size != sizeof(panel)) abort();
    panel_owner = actor;
    return (u32 *)&panel;
}
void *func_80100094(Actor *actor, u32 slot) {
    if (actor != panel_owner || slot) abort();
    return &panel;
}
void _gczoombox_entrypoint_0(void *box) {
    if (box != &boxes[closed % 4]) abort();
    ++closed;
}
void _gczoombox_entrypoint_2(u8 *box, BtIntPtr context) {
    if (draws >= 4 || context != render_context) abort();
    drawn[draws++] = box;
}
u8 *_gczoombox_entrypoint_5(s32 y, s32 id, s32 style, s32 open, BtIntPtr user) {
    if (style != 2 || user || (open ? id != 13 || y != 28 : id != 12 || y != 200)) abort();
    return &boxes[open];
}
void _gczoombox_entrypoint_9(void *box) { if (box != &boxes[1]) abort(); }
void _gczoombox_entrypoint_11(void *box) { if (box != &boxes[1]) abort(); }
void _gczoombox_entrypoint_19(void *box) { if (box != &boxes[0]) abort(); }
void _gldbstring_entrypoint_2(s32 id) { if (id != 7) abort(); ++released_strings; }

static int test_boxes(void) {
    Actor actors[2] = {0};
    u32 strings[] = {123};
    unsigned before = allocations;
    render_context = (BtIntPtr)&actors[1];
    if ((uintptr_t)&boxes[0] <= UINT32_MAX || (uintptr_t)render_context <= UINT32_MAX) return 1;
    func_808021E4_chgameselect(&actors[0]);
    func_808024D4_chgameselect(&actors[1]);
    if (actors[1].actorData[1] != (u32)-1) return 1;
    actors[0].game_select_box_data->first[63] = 'A';
    actors[0].game_select_box_data->second[63] = 'B';
    actors[1].actorData[0] = 7;
    actors[1].game_select_box_data->strings = strings;
    ActorData type = { .draw_actor = func_808025CC_chgameselect };
    type.draw_actor(&actors[0], render_context);
    type.draw_actor(&actors[1], render_context);
    if (draws != 2 || drawn[0] != &boxes[0] || drawn[1] != &boxes[1]) return 1;
    func_80802480_chgameselect(&actors[0]);
    func_80802588_chgameselect(&actors[1]);
    return released_strings != 1 || closed != 2 || allocations != before + 2 ||
           releases != allocations || actors[0].game_select_box_data || actors[1].game_select_box_data;
}
static int test_panel(void) {
    Actor actor = {0};
    GameSelectPanel *data = game_select_panel_init(&actor);
    if (data != &panel) return 1;
    draws = closed = 0;
    actor.unk6C_0 = 4;
    for (int i = 0; i < 4; ++i) {
        data->entries[i] = &boxes[i];
        data->texts[i] = heap_alloc(256);
    }
    data->buffer = heap_alloc(256);
    func_80806FAC_chgameselect(&actor, render_context);
    for (int i = 0; i < 4; ++i) if (drawn[i] != &boxes[i]) return 1;
    func_80807030_chgameselect(&actor);
    func_80807030_chgameselect(&actor);
    return draws != 4 || closed != 4 || data->buffer || allocations != releases;
}

int main(void) {
    Actor actors[2] = {0};
    Actor moved;
    Unk80132ED0 markers[2];
    for (int i = 0; i < 2; ++i) {
        actors[i].actorData[5] = 0x12345678;
        actors[i].unk50 = 12.5f;
        actors[i].unk54 = 19.25f;
        func_8080000C_chgameselect(&actors[i]);
        if (actors[i].game_select_root_data != allocated || game_select_root_child(&actors[i], 5))
            return 1;
        for (unsigned slot = 3; slot <= 7; ++slot)
            game_select_root_set_child(&actors[i], slot, &markers[i]);
    }
    if (allocations != 2 || releases) return 1;
    moved = actors[0];
    actors[0] = (Actor){0};
    if ((uintptr_t)&markers[0] <= UINT32_MAX || game_select_root_child(&moved, 5) != &markers[0] ||
        game_select_root_child(&actors[1], 5) != &markers[1] || moved.actorData[5] != 0x12345678 ||
        moved.unk50 != 12.5f || moved.unk54 != 19.25f) return 1;
    func_80800440_chgameselect(&moved);
    func_80800440_chgameselect(&actors[1]);
    func_80800440_chgameselect(&moved);
    if (test_boxes() || test_panel()) return 1;
    return moved.game_select_root_data || actors[1].game_select_root_data || allocations != releases;
}

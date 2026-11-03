#include "common.h"
struct ImageStruct;

/* extern */

s32 func_80800000_glsplineDll(u32 *arg0, s32 *arg1, u32 *arg2, u32 *arg3, u32 *arg4, u32 *arg5, s32 *arg6, void *arg7) {
    s32 _gspropctrl_entrypoint_6(void *);
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg7) + (4)));
    if (!(temp_v0 & 1) && (((u32) (temp_v0 << 0x19) >> 0x1A) == 0xB)) {
        *arg0 = (u32) ((*(s32 *)((s8 *)(arg7) + (8))) << 0x16) >> 0x1F;
        *arg1 = (*(u8 *)((s8 *)(arg7) + (0xA))) & 1;
        *arg2 = (u32) ((*(u32 *)((s8 *)(arg7) + (0xC))) << 0x12) >> 0x16;
        *arg3 = (u32) ((*(s32 *)((s8 *)(arg7) + (8))) << 0x12) >> 0x1F;
        *arg4 = (u32) (*(u32 *)((s8 *)(arg7) + (0xC))) >> 0x17;
        *arg5 = (u32) ((*(u32 *)((s8 *)(arg7) + (0xC))) << 9) >> 0x17;
        *arg6 = _gspropctrl_entrypoint_6(arg7);
        return 1;
    }
    return 0;
}

void glsplineDll_entrypoint_0(void *arg0) {
    typedef struct {
        s16 next;
        s16 pos[3];
        u16 hasPrev : 1;
        u16 visited : 1;
        u16 isEvent : 1;
        u16 value : 10;
        u16 flag2 : 1;
        u16 flag1 : 1;
        u16 flag0 : 1;
        s16 id;
        u16 type : 6;
        u16 value2 : 9;
        u16 unused0 : 1;
        u16 value3 : 9;
        u16 value4 : 5;
        u16 unused1 : 2;
    } Node;
    typedef struct {
        f32 time;
        u8 data[16];
    } Event;
    typedef struct {
        s32 count;
    } Events;
    typedef struct {
        s16 id;
        u8 count;
        u8 flags;
        u8 map;
        u8 pad[3];
        f32 value0;
        f32 value1;
        s16 ids;
        s16 pad12;
    } Spline;
    typedef struct {
        s8 active : 1;
        s8 unused : 7;
        u8 data[11];
    } Cache;
    typedef struct {
        u8 pad[0x184];
        s16 handle0;
        s16 handle1;
        s32 count;
        s32 pad18C;
        f32 value0;
        f32 value1;
        s32 asset;
        s32 *offsets;
        s32 unk1A0;
        Cache *cache;
        u8 map;
    } Context;
    u32 _gccubeDll_entrypoint_7(void);
    Prop *_gccubesearch_entrypoint_17(s32, s32 *);
    u32 _gccubesearch_entrypoint_18(s32, s32 *, u32 *, s32 *, s32 *, s32 *, Prop **);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    void func_800C84A4(s8 *, s32);
    struct ImageStruct *func_800D674C(s32);
    s32 func_800D7488(s16, s16);
    void *func_800D7520(s32);
    u8 *func_800D7570(s32);
    void func_800D87B0(void);
    u32 func_800E6A00(void);
    void func_800E9EE8(s32);
    s32 func_80800000_glsplineDll(u32 *, s32 *, u32 *, u32 *, u32 *, u32 *, s32 *, void *);
    void *heap_alloc(s32);
    void heap_free(void *);
    void rare_memcpy(void *, void *, s32);
    extern s32 D_80800FC0_glsplineDll[2];
    s32 count;
    s32 i;
    s32 scan;
    u8 *nodes;
    s32 pos[3];
    u32 next;
    s32 isEvent;
    s32 search0[3];
    s32 search1;
    Prop *search2;
    u32 setting6;
    s32 setting5;
    u32 setting4;
    u32 setting3;
    u32 setting2;
    u32 lowHigh;
    s32 lowLow;
    Node *node;
    s32 pointCount;
    s32 eventCount;
    s32 current;
    s32 remaining;
    s32 coordIndex;
    s32 size;
    Events *events;
    s32 *ids;
    s32 idIndex;
    s16 idsHandle;
    s16 splineHandle;
    s16 eventsHandle;
    f32 *coords;
    Spline *spline;
    Event *event;
    u32 end;
    Event *copyEvent;
    Event temp;
    Event *source;
    s32 unusedSwaps;
    u8 *asset;
    u8 *data;
    s32 *entry;
    s32 nodeId;
    Node *root;
    s32 coordCount;
    s32 unusedEventIndex;
    s32 stackPadding; /* Retain the original local stack layout. */

    ((Context *)arg0)->map = func_800E6A00();
    ((Context *)arg0)->handle0 = func_8001B668(0, 0);
    ((Context *)arg0)->handle1 = func_8001B668(0, 0);
    ((Context *)arg0)->count = 0;
    count = _gccubeDll_entrypoint_7() + 1;
    if (count >= 2) {
        nodes = heap_alloc(count * sizeof(Node));
        for (i = 0; i < count; i++) {
            ((Node *)(nodes + (i << 4)))->next = -1;
        }
        _gccubesearch_entrypoint_18(0, pos, &next, &isEvent, search0, &search1, &search2);
        do {
            nodeId = _gccubesearch_entrypoint_18(1, pos, &next, &isEvent, search0, &search1, &search2);
            if (nodeId >= 0) {
                node = ((Node *)nodes) + nodeId;
                node->id = nodeId;
                node->next = next;
                node->isEvent = isEvent;
                node->pos[0] = pos[0];
                node->pos[1] = pos[1];
                node->pos[2] = pos[2];
                if (func_80800000_glsplineDll(&setting6, &setting5, &setting4, &setting3, &setting2, &lowHigh, &lowLow, search2)) {
                    node->type = 11;
                    node->flag1 = setting6;
                    node->flag0 = setting5;
                    node->value = setting4;
                    node->flag2 = setting3;
                    node->value2 = setting2;
                    node->value3 = lowHigh;
                    node->value4 = lowLow;
                } else {
                    node->type = 0;
                }
            }
        } while (nodeId >= 0);
        for (i = 1; i < count; i++) {
            ((Node *)(nodes + (i << 4)))->hasPrev = 0;
            if (((Node *)(nodes + (i << 4)))->next >= count || ((Node *)(nodes + (i << 4)))->next == -1) {
                ((Node *)(nodes + (i << 4)))->next = 0;
            }
        }
        for (i = 1; i < count; i++) {
            if (((Node *)(nodes + (i << 4)))->next > 0) {
                ((Node *)(nodes + (((Node *)(nodes + (i << 4)))->next << 4)))->hasPrev = 1;
            }
        }
        for (i = 1; i < count; i++) {
            if (((Node *)(nodes + (i << 4)))->isEvent == 1) {
                if (((Node *)(nodes + (i << 4)))->hasPrev == 0 && ((Node *)(nodes + (i << 4)))->next > 0) {
                    continue;
                }
                if (((Node *)(nodes + (i << 4)))->hasPrev == 1 && ((Node *)(nodes + (i << 4)))->next > 0) {
                    continue;
                }
                if (((Node *)(nodes + (i << 4)))->hasPrev == 1 && ((Node *)(nodes + (i << 4)))->next == 0) {
                    continue;
                }
                func_800E9EE8(i);
                ((Node *)(nodes + (i << 4)))->next = -1;
                ((Node *)(nodes + (i << 4)))->isEvent = 0;
            }
        }
        for (i = 1; i < count; i++) {
            /* Empty tests preserve IDO's original temporary-register lifetimes. */
            if ((i << 3) != 0) {}
            root = (Node *)(nodes + (i << 4));
            if (root->next > 0 && root->hasPrev == 0 && root->isEvent == 0) {
                current = 1;
                for (; current < count; current++) {
                    /* The unused look-ahead address may be one past the node array. */
                    node = (Node*)(nodes + ((current + 1) << 4));
                    ((Node *)(nodes + (current << 4)))->visited = 0;
                }
                pointCount = 1;
                eventCount = 0;
                idIndex = 0;
                coordIndex = 5;
                /* Preserve the original IDO register allocation across the count pass. */
                if ((s32)nodes != 0) {}
                current = i;
                if (root->next != 0 && root->visited == 0) {
                    do {
                    /* Keep this count-pass temporary live for IDO. */
                    if ((i << 3) != current) {}
                    ((Node *)(nodes + (u32)(current << 4)))->visited = 1;
                    pointCount += ((Node *)(nodes + (u32)(current << 4)))->isEvent == 0 ? 1 : 0;
                    eventCount += ((Node *)(nodes + (u32)(current << 4)))->isEvent == 0 ? 0 : 1;
                    current = ((Node *)(nodes + (u32)(current << 4)))->next;
                    } while (((Node *)(nodes + (u32)(current << 4)))->next != 0 && ((Node *)(nodes + (u32)(current << 4)))->visited == 0);
                }
                /* IDO must encounter the coordinate-pointer range before the IDs range. */
                coords = 0;
                /* Both masks preserve IDO's original sign-extension/temporary sequence. */
                idsHandle = ((func_8001B668(0, pointCount * 4) & 0xffffU) & 0xffffU);
                ids = func_8001B798(idsHandle);
                coordCount = pointCount * 3;
                splineHandle = func_8001B668(0, coordCount * 4 + 20);
                coords = func_8001B798(splineHandle);
                spline = (Spline *)coords;
                spline->count = pointCount;
                spline->flags = 0;
                spline->value0 = 0.0f;
                spline->value1 = 0.0f;
                size = eventCount * 20 + 4;
                eventsHandle = func_8001B668(0, size);
                events = func_8001B798(eventsHandle);
                events->count = eventCount;
                copyEvent = ((Event *)(events + 1));
                scan = i;
                remaining = eventCount;
                if (size != 4) do {
                    if (((Node *)(nodes + (scan << 4)))->isEvent == 1) {
                        source = (Event *)_gccubesearch_entrypoint_17(scan, 0);
                        source->data[7] = ((Context *)arg0)->count;
                        rare_memcpy(copyEvent, source, 20);
                        copyEvent++;
                        remaining--;
                    }
                    scan = ((Node *)(nodes + (scan << 4)))->next;
                } while (remaining != 0);
                /* Zero events use an integer bound, not a pointer before the payload. */
                end = (u32)((events->count - 1) * (s32)sizeof(Event)) + (u32)(events + 1);
                do {
                    remaining = 0;
                    for (event = ((Event *)(events + 1)); (u32)event < end; event++) {
                        if (event[1].time < event[0].time) {
                            rare_memcpy(&temp, event, 20);
                            rare_memcpy(event, event + 1, 20);
                            rare_memcpy(event + 1, &temp, 20);
                            remaining++;
                        }
                    }
                } while (remaining != 0);
                spline->id = root->id;
                spline->map = ((Context *)arg0)->map;
                spline->ids = idsHandle;
                current = i;
                /* Use the allocation count for the first gate, then the remaining point count. */
                for (scan = pointCount; coordCount != 0; coordCount = scan) {
                    if (((Node *)(nodes + (u32)(current << 4)))->isEvent == 0) {
                        coords[coordIndex] = ((Node *)(nodes + (u32)(current << 4)))->pos[0];
                        coords[coordIndex + 1] = ((Node *)(nodes + (u32)(current << 4)))->pos[1];
                        coords[coordIndex + 2] = ((Node *)(nodes + (u32)(current << 4)))->pos[2];
                        coordIndex += 3;
                        scan--;
                        ids[idIndex++] = ((Node *)(nodes + (u32)(current << 4)))->id;
                    }
                    current = ((Node *)(nodes + (u32)(current << 4)))->next;
                }
                func_800D7488(splineHandle, eventsHandle);
            }
        }
        heap_free(nodes);
    }
    ((Context *)arg0)->asset = 0;
    ((Context *)arg0)->offsets = 0;
    ((Context *)arg0)->unk1A0 = 0;
    ((Context *)arg0)->value0 = 0.0;
    ((Context *)arg0)->value1 = 0.0;
    func_800D87B0();
    if (((Context *)arg0)->offsets != 0) {
        asset = (u8 *)func_800D674C(((Context *)arg0)->asset);
        for (i = 0; i < ((Context *)arg0)->count; i++) {
            data = func_800D7570(i);
            if (data != 0 && (*(u32 *)(data + 4) & 1) && (*(u32 *)(data + 12) & 1) && data[12] != 0) {
                size = data[12] - 1;
                entry = (s32 *)(asset + ((Context *)arg0)->offsets[size]);
                if (entry[1] == D_80800FC0_glsplineDll[0] && entry[2] == D_80800FC0_glsplineDll[1]) {
                    func_800C84A4(func_800D7520(i), 1);
                }
            }
        }
    }
    ((Context *)arg0)->cache = heap_alloc(7 * sizeof(Cache));
    for (i = 0; i < 7; i++) {
        ((Context *)arg0)->cache[i].active = 0;
    }
}

s16 func_80800C70_glsplineDll(void) {
    extern u8 D_8012762C;
    extern struct { s16 level; s16 result; } D_80800FC8_glsplineDll[];
    s32 i = 0;
    while (D_8012762C != D_80800FC8_glsplineDll[i].level && D_80800FC8_glsplineDll[i].level != -1) {
        i++;
    }
    return D_80800FC8_glsplineDll[i].result;
}

/* extern */

void glsplineDll_entrypoint_1(void *arg0) {
    void func_8001B754(s16);
    void *func_8001B798(s16);
    void heap_free(void *);
    s16 *temp_v0;
    s16 *sp28;
    s16 *var_s0;
    s16 *var_s2;
    s32 var_s1;

    sp28 = func_8001B798((*(s16 *)((s8 *)(arg0) + (0x184))));
    temp_v0 = func_8001B798((*(s16 *)((s8 *)(arg0) + (0x186))));
    var_s1 = 0;
    var_s0 = sp28;
    var_s2 = temp_v0;
    if ((*(s32 *)((s8 *)(arg0) + (0x188))) > 0) {
        do {
            func_8001B754((*(s16 *)((s8 *)(func_8001B798(*var_s0)) + (0x10))));
            func_8001B754(*var_s0);
            func_8001B754(*var_s2);
            var_s1 += 1;
            var_s0++;
            var_s2++;
        } while (var_s1 < (*(s32 *)((s8 *)(arg0) + (0x188))));
    }
    func_8001B754((*(s16 *)((s8 *)(arg0) + (0x184))));
    func_8001B754((*(s16 *)((s8 *)(arg0) + (0x186))));
    (*(s16 *)((s8 *)(arg0) + (0x184))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x186))) = 0;
    heap_free((*(void **)((s8 *)(arg0) + (0x1A4))));
    (*(s32 *)((s8 *)(arg0) + (0x188))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1A4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x198))) = 0;
    heap_free((*(void **)((s8 *)(arg0) + (0x19C))));
    (*(s32 *)((s8 *)(arg0) + (0x19C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1A0))) = 0;
}

void glsplineDll_entrypoint_2(u8 *arg0)
{
  struct ImageStruct *func_800D674C(s32);
  void *heap_alloc(s32);
  s16 func_80800C70_glsplineDll(void);
  s32 *q;
  s32 *start;
  s32 *p;
  s32 state;
  s32 offset;
  s32 count;
  s32 value;
  s32 asset;
  asset = func_80800C70_glsplineDll();
  if (asset != 0)
  {
    *((s32 *) (arg0 + 0x198)) = asset;
    start = (s32 *) func_800D674C(asset);
    *((s32 *) (arg0 + 0x1A0)) = 0;
    for (state = 0, q = start; state != 3; q++)
    {
      if (state == 2)
      {
        state = ((*q) == 3) ? (3) : (0);
      }
      asset = *q;
      if (state == 1)
      {
        state = (2 == (asset | 0)) ? (2) : (0);
      }
      if (state == 0)
      {
        state = (0 == (asset | 0)) ? (1) : (0);
      }
      if ((0x10005 == (asset | 0)) || (0x10006 == (asset | 0)))
      {
        (*((s32 *) (arg0 + 0x1A0)))++;
      }
    }

    *((s32 **) (arg0 + 0x19C)) = heap_alloc((*((s32 *) (arg0 + 0x1A0))) * 4);
    p = start;
    state = 4;
    count = 0;
    offset = 0;
    while (state != 3)
    {
if (!offset) {}
      if (!start)
      {
      }
      if (state == 2)
      {
        state = ((*p) == 3) ? (3) : ((((*p) == 0x10005) || ((*p) == 0x10006)) ? (4) : (0));
      }
      if (state == 1)
      {
        state = ((*p) == 2) ? (2) : (0);
      }
      if (state == 0)
      {
        state = ((*p) == 0) ? (1) : (0);
      }
      p++;
      if (state == 4)
      {
        state = 0;
        (*((s32 **) (arg0 + 0x19C)))[count++] = offset;
      }
      offset += 4;
    }

    while (((value = *p) ^ 0) != 4)
    {
      arg0[(value >> 16) & 0x7F] = (u8) (value & 0xFFUL);
      value = *(p++);
      arg0[((value >> 16) & 0x7F) + 0x80] = (u8) (value & 0xFFUL);
    }

  }
}

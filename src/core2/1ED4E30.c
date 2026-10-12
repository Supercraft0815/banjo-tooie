#include "core2/1ED4E30.h"

typedef struct {
    u8 unk0[0x28];
    s16 track_id;
    s16 unk2A;
    u8 unk2C[0xC];
    s32 freelist;
    s32 volume_indices[5];
} MusicTrack;

extern MusicTrack D_801357D0[6];
void func_800FB774(void *);
void func_800FCB00(s32, s32, s32, s32);


extern s32 D_80135960;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB540.s")

/* extern */

void func_800FB5BC(void *arg0) {
    s32 func_800FED90(s16, void *);
    if ((*(u8 *)((s8 *)(arg0) + (0x33))) != 0) {
        func_800FED90((*(s16 *)((s8 *)(arg0) + (0x28))), arg0);
        (*(u8 *)((s8 *)(arg0) + (0x33))) = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB650.s")

void func_800FB6C0(s32 *ptr, s32 volume) {
    void func_800FB650(s32 *, s32, s32);
    func_800FB650(ptr, volume, volume);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB808.s")

void func_800FB908(void) {
    void func_80017244(void);
    void func_80016E7C(void);
    void freelist_free(s32);
    extern u8 D_80123E40;
    MusicTrack *track;
    func_80017244();
    func_80016E7C();
    for (track = D_801357D0; track < &D_801357D0[6]; track++) {
        freelist_free(track->freelist);
        track->freelist = 0;
    }
    D_80123E40 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB968.s")

void func_800FBEC8(u8 *track, s32 *minimum_first, s32 *minimum_second) {
    s32 freelist_capacity(s32);
    s32 freelist_is_element_alive(s32, s32);
    void *freelist_at(s32, s32);
    int i;
    int count = freelist_capacity(*(s32 *)(track + 0x38));
    s32 first = 0x7FFF;
    s32 second = 0x40000000;
    s32 *entry;
    for (i = 1; i < count; i++) {
        if (freelist_is_element_alive(*(s32 *)(track + 0x38), i)) {
            entry = freelist_at(*(s32 *)(track + 0x38), i);
            if (entry[0] < first || (first == entry[0] && entry[1] < second)) {
                first = entry[0];
                second = entry[1];
            }
        }
    }
    *minimum_first = first;
    *minimum_second = second;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FBF9C.s")

void func_800FC124(u32 arg0)
{
  s32 func_800172D4(s32, u32);
  s32 func_80017764(u32);
  void func_800FB6C0(s32 *, s32);
  s32 func_800FB6E0(s32 *, s32, u32);
  extern f32 D_80135964;
  extern s32 D_80135980;
  extern s16 D_80135988;
  extern s16 D_8013598A;
  s32 temp_v0;
  if (arg0 != D_80135988)
  {
    func_800FB6E0(&D_80135960, 0, arg0);
    func_800172D4(5, arg0);
    D_80135988 = (s16) arg0;
    temp_v0 = func_80017764(arg0) ^ 0;
    D_80135980 = temp_v0;
    D_8013598A = 0;
    D_80135964 = 0.0f;
    func_800FB6C0(&D_80135960, temp_v0);
  }
}

void func_800FC1A8()
{
    func_800FB774(&D_80135960);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC508.s")

void func_800FC618(s32 arg0, s32 arg1) {
    func_800FC508(arg0, arg1, 0, (-1));
}

void func_800FC63C(u32 track_id, u32 volume) {
    func_800FC508(track_id, volume, 1, -1);
}

void func_800FC660(u32 track_id) {
    func_800FC508(track_id, -1, 1, -1);
}

void func_800FC688(u32 track_id, s32 volume) {
    func_800FC508(track_id, 1, 1, volume);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC6B0.s")

void func_800FC74C(u32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    if (ptr != NULL && *(s16 *)((u8 *)ptr + 0x28) >= 0) func_800FB774(ptr);
}

void func_800FC788(s32 track_id, s32 state) {
    typedef struct {
        u8 pad0[0x30];
        u8 state : 4;
        u8 flags : 4;
    } MusicFlags;
    void *func_800FB5F8(s32);
    MusicFlags *track = func_800FB5F8(track_id);
    if (track != NULL) track->state = state;
}

void func_800FC7C4(void) {
    MusicTrack *track;
    for (track = D_801357D0; track < &D_801357D0[6]; track++) {
        if (track->track_id >= 0) func_800FB774(track);
    }
}

void func_800FC81C(void) {
    s32 func_800FE7A8(s16);
    MusicTrack *track;
    for (track = D_801357D0; track < &D_801357D0[6]; track++) {
        s16 id = track->track_id;
        if (id >= 0 && func_800FE7A8(id) == 0) func_800FB774(track);
    }
}

void func_800FC884(void) {
    MusicTrack *track;
    for (track = D_801357D0; track < &D_801357D0[6]; track++) {
        if (track->track_id >= 0 && (*(u32 *)((u8 *)track + 0x30) >> 28) == 0) {
            func_800FB774(track);
        }
    }
}

/* extern */

void func_800FC8EC(void) {
    void *func_800FB5F8();
    void *temp_v0;

    temp_v0 = func_800FB5F8();
    if (temp_v0 != NULL) {
        (*(f32 *)((s8 *)(temp_v0) + (0xC))) = 1.0f;
        (*(f32 *)((s8 *)(temp_v0) + (0x14))) = 1.0f;
        (*(f32 *)((s8 *)(temp_v0) + (8))) = 0.0f;
        (*(f32 *)((s8 *)(temp_v0) + (0x10))) = 0.25f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC9B4.s")

void func_800FCA90(u32 track_id) {
    void *func_800FB5F8(s32);
    u8 *track;
    track = func_800FB5F8(track_id);
    if (track == NULL) return;
    track[0x31] = 1;
    if (*(s32 *)(track + 0x20) == 0 || track[0x34] != 0) func_800FB774(track);
}

void func_800FCAE0(u32 track_id, u32 volume, u32 duration) {
    void func_800FCB54(s32, s32, s32, f32);
    func_800FCB54(track_id, volume, duration, 0.0f);
}

void func_800FCB00(s32 track, s32 first, s32 second, s32 index) {
    void *func_800FB5F8(s32);
    void func_800FCB9C(s32, s32, s32, f32, void *);
    func_800FCB9C(track, first, second, 0.0f, (u8 *)func_800FB5F8(track) + 0x3C + index * 4);
}

void func_800FCB54(s32 track_id, s32 arg1, s32 arg2, f32 arg3) {
    void *func_800FB5F8(s32);
    void func_800FCB9C(s32, s32, s32, f32, void *);
    func_800FCB9C(track_id, arg1, arg2, 0.0f, (u8 *)func_800FB5F8(track_id) + 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB9C.s")

s32 func_800FCCD4(s32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    return (ptr == NULL || *(s16 *)((u8 *)ptr + 0x28) == -1) ? 0 : 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCD14.s")

void func_800FCD5C(void) {
    s32 freelist_defrag(s32);
    extern u8 D_80123E40;
    MusicTrack *track;
    if (D_80123E40 != 0) {
        for (track = D_801357D0; track < &D_801357D0[6]; track++) {
            track->freelist = freelist_defrag(track->freelist);
        }
    }
}

/* extern */

s32 func_800FCDB4(void) {
    void *func_800FB5F8();
    void *temp_v0;

    temp_v0 = func_800FB5F8();
    if (temp_v0 != NULL) {
        return (*(s32 *)((s8 *)(temp_v0) + (0x2C)));
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCED0.s")

s32 func_800FCF50(s32 arg0)
{
  s16 *new_var;
  s32 func_800DA298(s32);
  extern s16 D_80123DE0;
  s32 var_v0;
  s32 var_a1;
 var_v0 = 0; var_a1 = 0x30; do { new_var = &D_80123DE0;
    if (arg0 == (*(new_var + var_v0)))
    {
      return func_800DA298(var_v0 + 0x53E);
    }
    var_v0 += 1;
  }
  while (var_v0 != var_a1);
  return 1;
}

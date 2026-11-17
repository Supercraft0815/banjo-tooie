#include "core2/1ED4E30.h"

typedef struct {
    u8 unk0[8];
    f32 fade[2];
    u8 unk10[0x18];
    s16 track_id;
    s16 unk2A;
    u8 unk2C[0xC];
    struct FreeList *freelist;
    s32 volume_indices[5];
} MusicTrack;

extern MusicTrack D_801357D0[6];
void func_800FB774(void *);
void func_800FCB00(s32, s32, s32, s32);


extern s32 D_80135960;                                    typedef struct { u8 pad0[0x28]; s16 unk28; u8 pad2A[0x9]; u8 unk33; } Obj1ED4E30_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_800FB540(void *arg0) {
    void func_800DA544(GameFlag);
    s32 func_800FED70(s16, void *);
    extern s16 D_80123DE0;
    s16 *var_v1;
    s32 var_v0;

    if ((((Obj1ED4E30_arg0 *)arg0)->unk33) == 0) {
        func_800FED70((((Obj1ED4E30_arg0 *)arg0)->unk28), arg0);
        (((Obj1ED4E30_arg0 *)arg0)->unk33) = 1U;
        for (var_v1 = &D_80123DE0, var_v0 = 0; var_v0 < 0x30; var_v0++, var_v1++) {
            if ((((Obj1ED4E30_arg0 *)arg0)->unk28) == *var_v1) {
                func_800DA544(var_v0 + 0x53E);
                return;
            }
        }
    }
}

/* extern */

void func_800FB5BC(void *arg0) {
    s32 func_800FED90(s16, void *);
    if ((((Obj1ED4E30_arg0 *)arg0)->unk33) != 0) {
        func_800FED90((((Obj1ED4E30_arg0 *)arg0)->unk28), arg0);
        (((Obj1ED4E30_arg0 *)arg0)->unk33) = 0U;
    }
}

void *func_800FB5F8(s32 arg0) {
    MusicTrack *i_ptr, *first_free = NULL;

    for (i_ptr = D_801357D0; i_ptr < &D_801357D0[6]; i_ptr++) {
        if (i_ptr->track_id == arg0) {
            return i_ptr;
        }
        if ((first_free == NULL) && (i_ptr->track_id < 0)) {
            first_free = i_ptr;
        }
    }
    return first_free;
}

void func_800FB650(s32 *arg0, s32 arg1, s32 arg2) {
    void freelist_clear(void *);
    void *freelist_next(void **, s32 *);
    s32 sp24;
    s32 i;
    s32 *tmp;

    freelist_clear((void *)arg0[0x38 / 4]);
    for (i = 0; i < 5; i++) {
        arg0[0x3C / 4 + i] = 0;
    }
    tmp = freelist_next((void **)(arg0 + 0x38 / 4), &sp24);
    tmp[0] = arg1;
    tmp[1] = arg2;
}

void func_800FB6C0(s32 *ptr, s32 volume) {
    void func_800FB650(s32 *, s32, s32);
    func_800FB650(ptr, volume, volume);
}

void func_800FB6E0(s32 *arg0, s32 arg1) {
    extern f32 D_801359B4;
    extern f32 D_801359B8;
    ((f32 *)arg0)[0] = 0.0f;
    ((f32 *)arg0)[1] = 0.0f;
    ((f32 *)arg0)[2] = D_801359B4;
    ((f32 *)arg0)[3] = D_801359B8;
    ((f32 *)arg0)[6] = D_801359B4;
    ((f32 *)arg0)[7] = D_801359B8;
    ((f32 *)arg0)[4] = 0.0;
    ((f32 *)arg0)[5] = 1.0f;
    arg0[8] = 0;
    arg0[9] = 0;
    ((s16 *)arg0)[0x28 / 2] = -1;
    ((s16 *)arg0)[0x2A / 2] = 0;
    ((u32 *)arg0)[0x2C / 4] = 0xFFFFFFFF;
    ((u8 *)arg0)[0x30] = ((u8 *)arg0)[0x30] & 0xFFF0;
    ((s8 *)arg0)[0x31] = 0;
    ((s8 *)arg0)[0x32] = 0;
    ((s8 *)arg0)[0x34] = 0;
    if (arg1 == 0) {
        ((s8 *)arg0)[0x33] = 0;
    }
}

void func_800FB774(void *arg0) {
    void func_800172D4(u8, s32);
    void func_80017404(u8, s16);
    u32 func_80017764(s32);
    u32 index;

    index = func_80017764(((s16 *)arg0)[0x28 / 2]);
    func_800FB6C0(arg0, index);
    func_800FB5BC(arg0);
    ((s16 *)arg0)[0x28 / 2] = -1;
    ((u8 *)arg0)[0x30] &= 0xFF0F;
    index = (u8)((MusicTrack *)arg0 - D_801357D0);
    func_80017404(index, ((s16 *)arg0)[0x22 / 2]);
    func_800FB6E0(arg0, 0);
    func_800172D4(index, -1);
}

void func_800FB808(void) {
    struct FreeList *freelist_new(s32, s32);
    void func_800FB908(void);
    void func_800FE614(void);
    void func_80017864(void);
    extern u8 D_80123E40;
    extern u8 D_801359B0;
    extern f32 D_801359B4;
    extern f32 D_801359B8;
    MusicTrack *track;
    int i;

    if (D_80123E40 != 0) {
        func_800FB908();
    }
    D_80123E40 = 1;
    D_801359B4 = 0;
    D_801359B8 = 1.0f;
    for (track = D_801357D0; track < &D_801357D0[6]; track++) {
        track->track_id = -1;
        ((s32 *)track)[0x20 / 4] = 0;
        track->unk2A = 0;
        ((s32 *)track)[0x24 / 4] = 0;
        ((f32 *)track)[1] = 0.0f;
        track->unk2C[4] &= 0xFF0F;
        track->freelist = freelist_new(8, 4);
        func_800FB6E0((s32 *)track, 0);
        for (i = 0; i < 5; i++) {
            track->volume_indices[i] = 0;
        }
    }
    func_800FE614();
    func_80017864();
}

void func_800FB908(void) {
    void func_80017244(void);
    void func_80016E7C(void);
    void freelist_free(struct FreeList *);
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

void func_800FB968(void)
{
  s32 func_80017070(u8);
  s32 func_800170D4(u8);
  void func_80017404(u8, s16);
  void func_80017534(u8, f32, f32);
  void func_800175F0(void);
  s32 func_80017778(s32);
  int func_800177C4(BtIntPtr);
  void func_80017EC0(s32);
  s32 func_80090200(void);
  s32 func_800A5490(void);
  f32 func_800D8FF8(void);
  f32 func_800F13F0(f32, f32);
  void func_800FDC58(s32);
  extern f32 D_80126150;
  extern u8 D_801359B0;
  MusicTrack *track;
  s32 index;
  register f32 delta;
  s32 active;
  s32 mode;
  s32 mask;
  s32 stopped;
  s32 requested;
  f32 blend;
  u8 *mode_ptr;
  delta = func_800D8FF8(); mode_ptr = (u8 *) ((BtIntPtr) ((&D_801359B0) + 1)); mode = *mode_ptr;
  if (func_80090200()) {
    mode = func_800A5490();
    *mode_ptr = mode;
  }
  blend = D_80126150; track = D_801357D0; do {
    if (track->track_id >= 0) {
      ((f32 *) track)[1] = func_800F13F0(((f32 *) track)[1] + delta, 600.0f);
      if ((((f32 *) track)[1] > 1.0f) && func_80017778(track - D_801357D0)) {
        func_800FB774(track);
      } else if (mode) {
        if ((((f32 *) track)[6] != ((f32 *) track)[4]) || (((f32 *) track)[7] != ((f32 *) track)[5])) {
          ((f32 *) track)[6] += (((f32 *) track)[4] - ((f32 *) track)[6]) * blend;
          ((f32 *) track)[7] += (((f32 *) track)[5] - ((f32 *) track)[7]) * blend;
          func_80017534(track - D_801357D0, ((f32 *) track)[6], ((f32 *) track)[7]);
        }
      }
      else
        if ((((f32 *) track)[6] != ((f32 *) track)[2]) || (((f32 *) track)[7] != ((f32 *) track)[3]))
      {
        ((f32 *) track)[6] += (((f32 *) track)[2] - ((f32 *) track)[6]) * blend;
        ((f32 *) track)[7] += (((f32 *) track)[3] - ((f32 *) track)[7]) * blend;
        func_80017534(track - D_801357D0, ((f32 *) track)[6], ((f32 *) track)[7]);
      }
    }
    track++;
  }
  while (track < ((MusicTrack *) ((BtIntPtr) (&D_801359B0))));
  func_800175F0();
  func_800FDC58(mode);
  track = D_801357D0;
  do
  {
    if (track->track_id >= 0)
    {
      index = track - D_801357D0;
      func_80017EC0(index);
      active = func_800170D4(index);
      mask = func_80017070(index);
      stopped = func_800177C4(index);
      active &= mask;
      requested = ((s32 *) track)[11] & mask;
      if ((stopped && requested) || ((!stopped) && (!active)))
      {
        if (active || requested)
        {
          func_80017404(index, ((s32 *) track)[8]);
          track->unk2C[8] = 0;
        }
        else
        {
          func_80017404(index, 0);
          track->unk2C[8] = 1;
        }
      }
    }
    track++;
  }
  while (track < ((MusicTrack *) ((BtIntPtr) (&D_801359B0))));
  track = D_801357D0;
  if (D_801359B0)
  {
    D_801359B0 = 0;
    do
    {
      if ((track->track_id >= 0) && (track->unk2A != 0))
      {
        if (0.0f < ((f32 *) track)[0])
        {
          ((f32 *) track)[0] -= func_800D8FF8();
          D_801359B0 = 1;
        }
        else
          if (track->unk2A < 0)
        {
          ((s32 *) track)[8] += track->unk2A;
          if ((track->unk2C[5] && (((s32 *) track)[9] == 0)) && (((s32 *) track)[8] <= 0))
          {
            func_800FB774(track);
          }
          else
          {
            if (((s32 *) track)[9] >= ((s32 *) track)[8])
            {
              ((s32 *) track)[8] = ((s32 *) track)[9];
              track->unk2A = 0;
            }
            else
            {
              D_801359B0 = 1;
            }
            if (!track->unk2C[8])
            {
              func_80017404(track - D_801357D0, ((s32 *) track)[8]);
            }
          }
        }
        else
          if (((s32 *) track)[8] < ((s32 *) track)[9])
        {
          if (((s32 *) track)[8] == 0)
          {
            ((f32 *) track)[1] = 0.0f;
          }
          ((s32 *) track)[8] = track->unk2A + ((s32 *) track)[8];
          if (((s32 *) track)[8] >= ((s32 *) track)[9])
          {
            ((s32 *) track)[8] = ((s32 *) track)[9];
            track->unk2A = 0;
          }
          else
          {
            D_801359B0 = 1;
          }
          if (!track->unk2C[8])
          {
            func_80017404(track - D_801357D0, ((s32 *) track)[8]);
          }
        }
        else
        {
          track->unk2A = 0;
        }
      }
      track++;
    }
    while (track < ((MusicTrack *) ((BtIntPtr) (&D_801359B0))));
  }
}

void func_800FBEC8(u8 *track, s32 *minimum_first, s32 *minimum_second) {
    s16 freelist_capacity(void *list);
    s32 freelist_is_element_alive(void *list, s32 index);
    void * freelist_at(void *list, s32 index);
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

void func_800FBF9C(s32 *arg0, s32 *arg1, s32 *arg2, void *arg3) {
    void * freelist_at(void *list, s32 index);
    void freelist_erase(void *list, s32 index);
    s32 freelist_is_element_alive(void *list, s32 index);
    void *freelist_next(void **, s32 *);
    u32 func_80017764(s32);
    s32 *entry;
    f32 pad;
    s32 sp34;
    s32 volume;

    volume = *arg1;
    sp34 = *arg2;
    if ((*(s32 *)arg3 != 0) && !freelist_is_element_alive(arg0[14], *(s32 *)arg3)) {
        *(s32 *)arg3 = 0;
    }
    if (volume < 0) {
        entry = freelist_at(arg0[14], 1);
        if (entry[0] < (s32)func_80017764(((Obj1ED4E30_arg0 *)arg0)->unk28)) {
            volume = func_80017764(((Obj1ED4E30_arg0 *)arg0)->unk28);
        } else {
            volume = entry[0];
        }
        if (*(s32 *)arg3 != 0) {
            entry = freelist_at(arg0[14], *(s32 *)arg3);
            *arg2 = entry[1];
            freelist_erase(arg0[14], *(s32 *)arg3);
            *(s32 *)arg3 = 0;
            func_800FBEC8((u8 *)arg0, arg1, &sp34);
            return;
        }
    }
    if (*(s32 *)arg3 == 0) {
        entry = freelist_at(arg0[14], 1);
        if ((entry[0] < volume) || ((volume == entry[0]) && (sp34 >= entry[1]))) {
            func_800FB650(arg0, volume, sp34);
        } else {
            freelist_next((void **)(arg0 + 14), arg3);
        }
    }
    if (*(s32 *)arg3 != 0) {
        entry = freelist_at(arg0[14], *(s32 *)arg3);
        entry[0] = volume;
        entry[1] = sp34;
    }
    func_800FBEC8((u8 *)arg0, arg1, arg2);
}

void func_800FC124(u32 arg0)
{
  void func_800172D4(u8, s32);
  u32 func_80017764(s32);
  void func_800FB6C0(s32 *, s32);
  void func_800FB6E0();
  extern f32 D_80135964;
  extern s32 D_80135980;
  extern s16 D_80135988;
  extern s16 D_8013598A;
  s32 temp_v0;
  if (arg0 != D_80135988)
  {
#ifdef BT_NATIVE
    ((void (*)())func_800FB6E0)(&D_80135960, 0, arg0);
#else
    func_800FB6E0(&D_80135960, 0, arg0);
#endif
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

void func_800FC1CC(s32 arg0, s32 arg1)
{
  MusicTrack *track;
  s16 id;
 track = D_801357D0; do {
    id = track->track_id;
    if (id >= 0)
    {
      func_800FCB00(id, arg0, arg1, 1);
    }
    track++;
  }
  while (track != ((MusicTrack *) (&D_80135960)));
}

void func_800FC240(s32 arg0, s32 arg1) {
    s32 func_800FE7A8(s32);
    MusicTrack *track;
    s16 id;

    track = D_801357D0; do {
        id = track->track_id;
        if ((id >= 0) && (func_800FE7A8(id) == 0)) {
            func_800FCB00(track->track_id, arg0, arg1, 1);
        }
        track++;
    } while (track != ((MusicTrack *) (&D_80135960)));
}

void func_800FC2C4(s32 arg0, s32 arg1) {
    MusicTrack *track;
    s16 id;

    track = D_801357D0; do {
        id = track->track_id;
        if ((id >= 0) && ((*(u32 *)((u8 *)track + 0x30) >> 28) == 0)) {
            func_800FCB00(id, arg0, arg1, 1);
        }
        track++;
    } while (track != ((MusicTrack *) (&D_80135960)));
}

void func_800FC348(u32 arg0, u32 arg1, u32 arg2) {
    s32 func_800FE7A8(s32);
    MusicTrack *track;
    s16 id;

    track = D_801357D0; do {
        id = track->track_id;
        if ((id >= 0) && (func_800FE7A8(id) == 0)) {
            func_800FCB00(track->track_id, arg0, arg1, arg2);
        }
        track++;
    } while (track != ((MusicTrack *) (&D_80135960)));
}

s32 func_800FC3D8(s32 arg0, s32 arg1, s32 arg2, f32 duration) {
    u32 func_80017764(s32);
    s32 step;
    s32 result;

    if (duration == 0.0f) {
        return 0x7FFF;
    }
    if (arg2 == -1) {
        arg2 = func_80017764(arg0);
    }
    if (arg1 == arg2) {
        return 1;
    }
    if (duration == 0.0f) {
        result = arg1 - arg2;
    } else {
        step = (s32)(((f32)(arg1 - arg2) / (duration * 30.0f)) + 1.0f);
        result = step;
        if (step < 0) {
            result = -step;
        } else if (step == 0) {
            result = 1;
        }
    }
    return result;
}    typedef struct { u8 pad0[0x20]; s32 unk20; } Obj1ED4E30_func_800FC4B0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_800FC4B0(s32 arg0, s32 arg1, s32 arg2, f32 arg3) { void *func_800FB5F8(s32); s32 func_800FC3D8(s32, s32, s32, f32); void *temp_v0; if (arg1 == -1) { temp_v0 = func_800FB5F8(arg0); if (temp_v0 == NULL) return 0; arg1 = ((Obj1ED4E30_func_800FC4B0_temp_v0 *)temp_v0)->unk20; } return func_800FC3D8(arg0, arg1, arg2, arg3); }

void func_800FC508(s32 arg0, s32 arg1, s32 arg2, s32 arg3) { void func_800172D4(u8, s32); void func_80017404(u8, s16); u32 func_80017764(s32); s32 *track; if (arg1 == -1) { arg1 = func_80017764(arg0); } if (arg3 == -1) { arg3 = arg1; } track = func_800FB5F8(arg0); if (track != NULL) { if (((s16 *)track)[0x28 / 2] < 0 || arg2 != 0) { func_800FB6E0(track, arg2); ((s16 *)track)[0x28 / 2] = arg0; ((s8 *)track)[0x31] = 0; ((s16 *)track)[0x2A / 2] = 0; ((f32 *)track)[1] = 0.0f; func_800FB6C0(track, arg3); func_800172D4(((u8 *)track - (u8 *)D_801357D0) / 80, arg0); } if (((u8 *)track)[0x34] == 0) { func_80017404(((u8 *)track - (u8 *)D_801357D0) / 80, arg1); } track[0x20 / 4] = arg1; func_800FB540(track); } }

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

void func_800FC6B0(u32 track_id) {
    void func_800172D4(u8, s32);
    u32 func_80017764(s32);
    s32 *track;
    s32 volume;

    track = func_800FB5F8(track_id);
    if (track != NULL) {
        if (((s16 *)track)[0x28 / 2] < 0) {
            func_800FB6E0(track, 0);
            ((s16 *)track)[0x2A / 2] = 0;
            ((s16 *)track)[0x28 / 2] = track_id;
            ((f32 *)track)[1] = 0.0f;
            func_800172D4(((u8 *)track - (u8 *)D_801357D0) / 80, track_id);
            volume = func_80017764(track_id) ^ 0;
            track[0x20 / 4] = volume;
            func_800FB6C0(track, volume);
        }
        func_800FB540(track);
    }
}    typedef struct { u8 pad0[0x28]; s16 unk28; } Obj1ED4E30_func_800FC74C_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

void func_800FC74C(u32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    if (ptr != NULL && ((Obj1ED4E30_func_800FC74C_ptr *)ptr)->unk28 >= 0) func_800FB774(ptr);
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
    s32 func_800FE7A8(s32);
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
}    typedef struct { u8 pad0[0x8]; f32 unk8; f32 unkC; f32 unk10; f32 unk14; } Obj1ED4E30_func_800FC8EC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800FC8EC(BT_PARAM_OR_VOID(s32 bt_a0)) {
    void *func_800FB5F8(BT_NATIVE_ONLY(s32 bt_a0));
    void *temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_800FB5F8(BT_NATIVE_ONLY(bt_a0));
#else
    temp_v0 = func_800FB5F8();
#endif
    if (temp_v0 != NULL) {
        (((Obj1ED4E30_func_800FC8EC_temp_v0 *)temp_v0)->unkC) = 1.0f;
        (((Obj1ED4E30_func_800FC8EC_temp_v0 *)temp_v0)->unk14) = 1.0f;
        (((Obj1ED4E30_func_800FC8EC_temp_v0 *)temp_v0)->unk8) = 0.0f;
        (((Obj1ED4E30_func_800FC8EC_temp_v0 *)temp_v0)->unk10) = 0.25f;
    }
}    typedef struct { u8 pad0[0x8]; f32 unk8; f32 unkC; u8 pad10[0x20]; u8 unk30; } Obj1ED4E30_func_800FC934_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800FC934(s32 arg0, f32 arg1, f32 arg2) {
    void *func_800FB5F8(s32);
    void *temp_v0;

    temp_v0 = func_800FB5F8(arg0);
    if (temp_v0 != NULL) {
        (((Obj1ED4E30_func_800FC934_temp_v0 *)temp_v0)->unk8) = arg1;
        (((Obj1ED4E30_func_800FC934_temp_v0 *)temp_v0)->unkC) = arg2;
        (((Obj1ED4E30_func_800FC934_temp_v0 *)temp_v0)->unk30) = (u8) (((((Obj1ED4E30_func_800FC934_temp_v0 *)temp_v0)->unk30) & 0xFFF0) | 1);
    }
}    typedef struct { u8 pad0[0x10]; f32 unk10; f32 unk14; } Obj1ED4E30_func_800FC97C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800FC97C(s32 arg0, f32 arg1, f32 arg2) {
    void *func_800FB5F8(s32);
    u8 *temp_v0;

    temp_v0 = func_800FB5F8(arg0);
    if (temp_v0 != NULL) {
        (((Obj1ED4E30_func_800FC97C_temp_v0 *)temp_v0)->unk10) = arg1;
        (((Obj1ED4E30_func_800FC97C_temp_v0 *)temp_v0)->unk14) = arg2;
    }
}

void func_800FC9B4(s32 arg0, f32 arg1) {
    s32 func_800FE7A8(s32);
    extern f32 D_801359B4;
    extern f32 D_801359B8;
    s32 index;
    s16 temp_a0;

    if (arg0 != 0) {
        D_801359B4 = arg1;
        D_801359B8 = 1.0f;
    } else {
        D_801359B4 = 0.0f;
        D_801359B8 = 1.0f;
    }
    index = 0; do {
        temp_a0 = D_801357D0[index].track_id;
        if ((temp_a0 >= 0) && (func_800FE7A8(temp_a0) == 0) && !(D_801357D0[index].unk2C[4] & 0xF)) {
            D_801357D0[index].fade[0] = D_801359B4;
            D_801357D0[index].fade[1] = D_801359B8;
        }
        index++;
    } while (&D_80135960 != (void *)&D_801357D0[index]);
}

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

void func_800FCB9C(s32 track_id, s32 arg1, s32 arg2, f32 arg3, void *arg4) {
    void func_800172D4(u8, s32);
    void func_80017404(u8, s16);
    void func_800FBF9C(s32 *, s32 *, s32 *, void *);
    extern u8 D_801359B0;
    s32 *track;
    BtUIntPtr slot_index;

    track = func_800FB5F8(track_id);
    if (track == NULL)
        return;
    if (((s16 *)track)[0x28 / 2] < 0) {
        if (arg1 == 0)
            return;
        func_800FB6E0(track, 0);
        slot_index = ((BtIntPtr)track - (BtIntPtr)D_801357D0) / 80;
        func_800172D4(slot_index, track_id);
        ((s16 *)track)[0x28 / 2] = track_id;
        track[0x20 / 4] = 0;
        ((f32 *)track)[1] = 0.0f;
        func_800FB6C0(track, 0);
        if (((u8 *)track)[0x34] == 0)
            func_80017404(slot_index, 0);
    }
    func_800FBF9C(track, &arg1, &arg2, arg4);
    ((f32 *)track)[0] = arg3;
    ((s16 *)track)[0x2A / 2] = track[0x20 / 4] < arg1 ? arg2 : -arg2;
    track[0x24 / 4] = arg1;
    if (arg1 != 0)
        func_800FB540(track);
    else
        func_800FB5BC(track);
    D_801359B0 = 1;
}    typedef struct { u8 pad0[0x28]; s16 unk28; } Obj1ED4E30_func_800FCCD4_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

s32 func_800FCCD4(s32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    return (ptr == NULL || ((Obj1ED4E30_func_800FCCD4_ptr *)ptr)->unk28 == -1) ? 0 : 1;
}

void func_800FCD14(s32 arg0, s32 arg1) {
    void *ptr = func_800FB5F8(arg0);
    if (ptr != NULL) {
        func_800174C0(((BtIntPtr)ptr - (BtIntPtr)D_801357D0) / 80 & 0xFF, arg1);
    }
}

void func_800FCD5C(void) {
    BtIntPtr freelist_defrag(BtIntPtr);
    extern u8 D_80123E40;
    MusicTrack *track;
    if (D_80123E40 != 0) {
        for (track = D_801357D0; track < &D_801357D0[6]; track++) {
            track->freelist = freelist_defrag(track->freelist);
        }
    }
}    typedef struct { u8 pad0[0x2C]; s32 unk2C; } Obj1ED4E30_func_800FCDB4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_800FCDB4(BT_NATIVE_ONLY(s32 bt_a0)) {
    void *func_800FB5F8(BT_NATIVE_ONLY(s32 bt_a0));
    void *temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_800FB5F8(BT_NATIVE_ONLY(bt_a0));
#else
    temp_v0 = func_800FB5F8();
#endif
    if (temp_v0 != NULL) {
        return (((Obj1ED4E30_func_800FCDB4_temp_v0 *)temp_v0)->unk2C);
    }
    return 0;
}    typedef struct { u8 pad0[0x2C]; s32 unk2C; u8 pad30[0x2]; u8 unk32; } Obj1ED4E30_func_800FCDE0_track; /* offsets.py genstruct: fields from raw offsets on track; rename once understood */

s32 func_800FCDE0(s32 arg0, s32 arg1, f32 arg2) {
    s16 func_80017108(u8);
    s32 func_80017210(u8);
    int func_800177C4(BtIntPtr);
    s32 func_800178C4(BtIntPtr, s32, f32);
    BtIntPtr slot;
    void *track;

    track = func_800FB5F8(arg0);
    if (track == NULL) {
        return 0;
    }
    if (((Obj1ED4E30_func_800FCDE0_track *)track)->unk32 != 0 && arg1 == ((Obj1ED4E30_func_800FCDE0_track *)track)->unk2C) {
        return 1;
    }
    slot = ((BtIntPtr)track - (BtIntPtr)D_801357D0) / 80;
    if (func_80017108(slot) == arg0 &&
        (func_80017210(slot) == 1 || func_800177C4(slot) != 0) &&
        func_800178C4(slot, arg1, arg2) != 0) {
        ((Obj1ED4E30_func_800FCDE0_track *)track)->unk2C = arg1;
        ((Obj1ED4E30_func_800FCDE0_track *)track)->unk32 = 1;
        return 1;
    }
    ((Obj1ED4E30_func_800FCDE0_track *)track)->unk2C = arg1;
    ((Obj1ED4E30_func_800FCDE0_track *)track)->unk32 = 0;
    return 0;
}

s32 func_800FCED0(s32 arg0, s32 arg1, f32 arg2) {
    s16 func_80017108(u8);
    s32 func_80017D74(BtIntPtr, s32, f32);
    void *track;

    track = func_800FB5F8(arg0);
    if (track != NULL) {
        if (func_80017108(((BtIntPtr)track - (BtIntPtr)D_801357D0) / 80) != arg0) {
            return 0;
        }
        return func_80017D74(((BtIntPtr)track - (BtIntPtr)D_801357D0) / 80, arg1, arg2);
    }
    return 0;
}

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

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
MusicTrack D_801357D0 [ 6 ] BT_DATA(4, bss_core2bss2_2, 0x2930);
s32 D_80135960 BT_DATA(4, bss_core2bss2_2, 0x2AC0);
f32 D_80135964 BT_DATA(4, bss_core2bss2_2, 0x2AC4);
s32 D_80135980 BT_DATA(4, bss_core2bss2_2, 0x2AE0);
s16 D_80135988 BT_DATA(4, bss_core2bss2_2, 0x2AE8);
s16 D_8013598A BT_DATA(4, bss_core2bss2_2, 0x2AEA);
u8 D_801359B0 BT_DATA(4, bss_core2bss2_2, 0x2B10);
f32 D_801359B4 BT_DATA(4, bss_core2bss2_2, 0x2B14);
f32 D_801359B8 BT_DATA(4, bss_core2bss2_2, 0x2B18);
#endif

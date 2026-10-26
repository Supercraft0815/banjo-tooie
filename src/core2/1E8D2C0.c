#include "common.h"

s16 *func_800B39D0(u8 *arg0, s32 arg1) {
    struct Record {
        s16 stride;
        s16 pad;
        u8 data[1];
    } *record = (struct Record *) arg0;

    return (s16 *) (record->data + arg1 * record->stride);
}

/* extern */

void func_800B39E8(void *arg0) {
    s16 *temp_v0;
    s16 *var_v0 = (s16 *)((u8 *)arg0 + 4);

    *(s16 *)((u8 *)arg0 + 6) = 0;
    if (*(s16 *)((u8 *)arg0 + 2) != 0) {
        *var_v0 = 1;
        temp_v0 = func_800B39D0(arg0, *var_v0);
        temp_v0[0] = 0;
        temp_v0[1] = *(s16 *)((u8 *)arg0 + 2) - 1;
        return;
    }
    *var_v0 = 0;
}

void func_800B3A40(u8 *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    s16 *entry;
    s16 *next;

    entry = func_800B39D0(arg0, arg2);
    if (arg2 + arg3 == arg1[0]) {
        next = func_800B39D0(arg0, arg1[0]);
        entry[0] = next[0];
        entry[1] = next[1] + arg3;
    } else {
        entry[0] = arg1[0];
        entry[1] = arg3;
    }
    if (func_800B39D0(arg0, arg2 - arg1[1]) == arg1) {
        arg1[1] += entry[1];
        arg1[0] = entry[0];
    } else {
        arg1[0] = arg2;
    }
}

/* extern */

void func_800B3B08(u8 *arg0, s32 arg1, s32 arg2) {
    s16 *func_800B39D0(u8 *, s32);
    void func_800B3A40(u8 *, s16 *, s32, s32);
    s16 *temp_v0;
    s16 *var_s0;
    s16 temp_a1;

    var_s0 = arg0 + 4;
    if ((*(s16 *)((s8 *)(arg0) + (4))) != 0) {
loop_1:
        temp_a1 = *var_s0;
        if (temp_a1 < (arg1 + arg2)) {
            temp_v0 = func_800B39D0(arg0, temp_a1);
            var_s0 = temp_v0;
            if (*temp_v0 != 0) {
                goto loop_1;
            }
        }
    }
    func_800B3A40(arg0, var_s0, arg1, arg2);
}

void func_800B3B8C(u8 *arg0, s16 *arg1, s16 *arg2, s32 arg3) { s16 *temp_v0; *arg2 += arg3; temp_v0 = func_800B39D0(arg0, *arg2); temp_v0[0] = arg1[0]; temp_v0[1] = arg1[1] - arg3; }

/* extern */

s16 *func_800B3BDC(u8 *arg0, s16 *arg1) { s16 *temp_v0; temp_v0 = func_800B39D0(arg0, *arg1); if (temp_v0[1] == 1) { *arg1 = temp_v0[0]; } else { func_800B3B8C(arg0, temp_v0, arg1, 1); } return temp_v0; }

s16 *func_800B3C40(u8 **arg0, s32 arg1, s32 arg2) { u8 *data; s32 old_count; s32 new_count; s16 *entry; s16 *result; data = *arg0; old_count = *(s16 *)(data + 2); new_count = old_count + arg2; data = heap_realloc(data, *(s16 *)data * new_count + 4); *(s16 *)(data + 2) = new_count; *arg0 = data; result = func_800B39D0(data, arg1); *result = old_count; entry = func_800B39D0(data, *result); entry[0] = 0; entry[1] = arg2; return result; }

s16 *func_800B3CDC(u8 **arg0, void *arg1)
{
  void aligned4_memcpy(void *, void *, int);
  s32 padding[6];
  s32 old_start;
  s16 *dest;
  s16 *source;
  s16 *entry;
  s16 *result;
  s16 previous;
  s32 end;
  s32 count;
  u8 *data;
  data = *arg0;
  result = NULL;
  entry = (s16 *) (data + 4);
  if ((*((s16 *) (data + 4))) == 0)
  {
    entry = func_800B3C40(arg0, 0, 10);
    data = *arg0;
  }
  if ((*((s16 *) arg1)) == 0)
  {
    *((s16 *) arg1) = *entry;
    result = func_800B3BDC(data, entry);
  }
  else
  {
    end = ((s16 *) arg1)[1] + (*((s16 *) arg1));
    while ((*entry) != 0)
    {
      if (end == (*entry))
      {
        break;
      }
      entry = func_800B39D0(data, *entry);
    }

    if ((*entry) != 0)
    {
      result = func_800B3BDC(data, entry);
    }
    else
    {
      old_start = *((s16 *) arg1);
      count = ((s16 *) arg1)[1] + 1;
      previous = 0;
      entry = (s16 *) (data + 4);
      old_start = *((s16 *) arg1);
      while ((*entry) != 0)
      {
        result = func_800B39D0(data, *entry);
        if (result[1] >= count)
        {
          break;
        }
        previous = *entry;
        entry = result;
      }

      if ((result == NULL) || (result[1] < count))
      {
        entry = func_800B3C40(arg0, previous, count + 5);
        data = *arg0;
      }
      dest = func_800B39D0(data, *entry);
      source = func_800B39D0(data, *((s16 *) arg1));
      *((s16 *) arg1) = *entry;
      func_800B3B8C(data, dest, entry, ((s16 *) arg1)[1]);
      aligned4_memcpy(dest, source, (*((s16 *) data)) * ((s16 *) arg1)[1]);
      result = func_800B3BDC(data, entry);
      func_800B3B08(data, old_start, ((s16 *) arg1)[1]);
    }
  }
  ((s16 *) arg1)[1]++;
  return result;
}

/* extern */

void func_800B3EDC(u8 **arg0, s32 arg1) {
    s16 *next;
    s16 *entry;
    s16 *previous;
    s32 total;
    s32 next_index;
    s32 available;
    s32 value;
    u8 *data;
    u8 *resized;

    data = *arg0;
    value = 0;
    previous = NULL;
    entry = (s16 *)(data + 4);
    if (*(s16 *)(data + 4) != 0) {
        do {
            next_index = *entry;
            previous = entry;
            value = next_index;
            next = func_800B39D0(data, next_index);
            entry = next;
        } while (*next != 0);
    }
    available = entry[1];
    total = *(s16 *)(data + 2);
    if ((total == (available + value)) && (available >= arg1)) {
        value = total;
        value -= (arg1 > 0 ? arg1 : available);
        if ((arg1 == 0) || (arg1 == available)) {
            *previous = 0;
        } else {
            entry[1] = available - arg1;
        }
        resized = heap_realloc(data, (*(s16 *)data * value) + 4);
        *(s16 *)(resized + 2) = value;
        *arg0 = resized;
    }
}

void func_800B3FD0(u8 **arg0, void *arg1, s32 arg2) {
    void aligned4_memcpy(void *, void *, int);
    s32 handled[2];
    s16 *dest;
    s16 *next;
    s16 *entry;
    s16 first;
    s16 second;
    s32 index;
    s32 count;
    u8 *data;

    data = *arg0;
    handled[0] = 0;
    if (arg2 == 0) {
        entry = (s16 *)(data + 4);
        index = 0;
        if (*(s16 *)(data + 4) != 0) {
loop:
            first = (*(s16 *)((u8 *)arg1 + 0));
            if (first == entry[1] + index) {
                func_800B3B08(data, first, 1);
                (*(s16 *)((u8 *)arg1 + 0))++;
                handled[0] = 1;
            } else {
                second = entry[0];
                index = second;
                next = func_800B39D0(data, second);
                entry = next;
                if (next[0] != 0) {
                    goto loop;
                }
            }
        }
    }
    if (handled[0] == 0) {
        count = (*(s16 *)((u8 *)arg1 + 2));
        count -= arg2;
        count--;
        if (count > 0) {
            dest = func_800B39D0(data, (*(s16 *)((u8 *)arg1 + 0)) + arg2);
            aligned4_memcpy(dest, func_800B39D0(data, (*(s16 *)((u8 *)arg1 + 0)) + arg2 + 1), *(s16 *)data * count);
        }
        func_800B3B08(data, (*(s16 *)((u8 *)arg1 + 2)) + (*(s16 *)((u8 *)arg1 + 0)) - 1, 1);
    }
    func_800B3EDC(arg0, 0xA);
    (*(s16 *)((u8 *)arg1 + 2))--;
    if ((*(s16 *)((u8 *)arg1 + 2)) == 0) {
        (*(s16 *)((u8 *)arg1 + 0)) = 0;
    }
}

/* extern */

s32 func_800B4134(u8 **arg0, void *arg1) {
    void aligned4_memcpy(void *, void *, int);
    s32 sp34[5];
    s16 *temp_v0;
    s16 *var_s0;
    s16 *var_s4;
    s16 temp_a1;
    s32 var_s1;
    u8 *temp_s2;

    temp_s2 = *arg0;
    var_s4 = NULL;
    var_s1 = 0;
    var_s0 = temp_s2 + 4;
    if ((*(s16 *)((s8 *)(temp_s2) + (4))) != 0) {
loop_1:
        if ((*(s16 *)((s8 *)(arg1) + (0))) == ((*(s16 *)((s8 *)(var_s0) + (2))) + var_s1)) {
            *var_s4 = (*(s16 *)((s8 *)(var_s0) + (0)));
            sp34[0] = (s32) (*(s16 *)((s8 *)(var_s0) + (2)));
            aligned4_memcpy(var_s0, func_800B39D0(temp_s2, (*(s16 *)((s8 *)(arg1) + (0)))), (*(s16 *)((s8 *)(temp_s2) + (0))) * (*(s16 *)((s8 *)(arg1) + (2))));
            (*(s16 *)((s8 *)(arg1) + (0))) = var_s1;
            func_800B3B08(temp_s2, (*(s16 *)((s8 *)(arg1) + (2))) + (*(s16 *)((s8 *)(arg1) + (0))), sp34[0]);
            return 1;
        }
        temp_a1 = (*(s16 *)((s8 *)(var_s0) + (0)));
        var_s4 = var_s0;
        var_s1 = temp_a1;
        temp_v0 = func_800B39D0(temp_s2, temp_a1);
        var_s0 = temp_v0;
        if (*temp_v0 == 0) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return 0;
}

void func_800B422C(u8 **arg0, s16 *arg1) { u8 *data; s32 count; data = *arg0; count = arg1[0]; if (count != 0) { func_800B3B08(data, count, arg1[1]); func_800B3EDC(arg0, 0xA); arg1[1] = 0; arg1[0] = arg1[1]; } }

void func_800B4290(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (2))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0))) = (s16) (*(s16 *)((s8 *)(arg0) + (2)));
}

s32 func_800B42A0(u8 *arg0, s16 *arg1) {
    s32 value;
    s32 result;

    value = *arg1;
    if (value != 0) {
        result = (s32) func_800B39D0(arg0, value);
    } else {
        result = 0;
    }
    return result;
}

void func_800B42DC(void* arg0) 
{
    heap_free(arg0);
}
s16 *func_800B42FC(s32 size, s32 count) {
    void func_800B39E8(void *);
    s16 *ptr;
    count++;
    ptr = heap_alloc(size * count + 4);
    ptr[0] = size;
    ptr[1] = count;
    func_800B39E8(ptr);
    return ptr;
}

void func_800B4354(u8 **arg0)
{
    func_800B3EDC(arg0,0);
}

s32 func_800B4374(s16 *arg0)
{
    return arg0[2];
}

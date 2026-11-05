#include "common.h"

#ifdef BT_NATIVE
#include "native_vector_table.h"
#include "memory.h"
void func_800EE7F8(f32 *,f32 *),func_800EE904(s32 *,f32 *),func_800EF2A0(f32 *),func_800EFB24(void *,void *,void *);
void func_800DBEB0(void *data) {rare_memset(data,0,sizeof(NativeVectorTable));}
void func_800DBEFC(void *data,s32 index,f32 *out) {
    if(index>=0 && index<23)func_800EE7F8(out,((NativeVectorTable *)data)->vectors[index]);
}
void func_800DBF38(void *data,s32 index,s32 *out) {
    if(index>=0 && index<23)func_800EE904(out,((NativeVectorTable *)data)->vectors[index]);
}
void func_800DBF74(void *data,s32 first,s32 second,f32 *out) {
    NativeVectorTable *table=data;
    if(first<0 || first>=23 || second<0 || second>=23)return;
    func_800EFB24(out,table->vectors[second],table->vectors[first]);func_800EF2A0(out);
}
void func_800DBFD8(void *data) {heap_free(data);}
void *func_800DBFF8(void) {
    void *data=heap_alloc(sizeof(NativeVectorTable));func_800DBEB0(data);return data;
}
void func_800DC028(void *data,s32 index,f32 *value) {
    if(index>=0 && index<23)func_800EE7F8(((NativeVectorTable *)data)->vectors[index],value);
}
void *func_800DC060(void *data) {return defrag(data);}
#else
/* extern */

void func_800DBEB0(s32 arg0) {
    s32 func_800EFD24(u32);
    u32 temp_s1;
    u32 var_s0;

    var_s0 = arg0 + 4;
    temp_s1 = arg0 + 0x118;
    if (var_s0 < temp_s1) {
        do {
            func_800EFD24(var_s0);
            var_s0 += 0xC;
        } while (var_s0 < temp_s1);
    }
}

void func_800DBEFC(s32 *arg0, s32 arg1, f32 *arg2) {
    s32 func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg2, (f32 *)((u8 *)arg0 + (arg1 * 12) + 4));
}

void func_800DBF38(void *arg0, s32 arg1, s32 *arg2) {
    typedef struct { s32 header; f32 vectors[23][3]; } VectorTable;
    void func_800EE904(s32 *, f32 *);
    func_800EE904(arg2, ((VectorTable *)arg0)->vectors[arg1]);
}

/* extern */

void func_800DBF74(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EF2A0(f32[3]);
    void func_800EFB24(void *, void *, void *);
    func_800EFB24((void *)arg3, (u8 *)arg0 + (arg2 * 12) + 4, (u8 *)arg0 + (arg1 * 12) + 4);
    func_800EF2A0((f32 *)arg3);
}

void func_800DBFD8(void* arg0) 
{
    heap_free(arg0);
}
u8 *func_800DBFF8(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x118);
    sp1C = temp_v0;
    func_800DBEB0((s32) temp_v0);
    return sp1C;
}

/* extern */

void func_800DC028(s32 arg0, s32 arg1, f32 *arg2) {
    s32 func_800EE7F8(f32 *, f32 *);
    typedef struct { s32 pad; f32 position[2]; } Entry;
    func_800EE7F8(((Entry *)arg0)[arg1].position, arg2);
}

/* extern */
s32 func_800DC060(s32 arg0) {
    s32 defrag(s32);

    if (arg0 != 0) {
        arg0 = defrag(arg0);
    }
    return arg0;
}
#endif

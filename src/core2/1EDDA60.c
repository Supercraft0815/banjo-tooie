#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_actor_animation.h"
#include "freelist.h"
FreeList *D_80136E70;

void func_80104170(void) {D_80136E70=freelist_new(func_8008B4F4(),32);}
void func_801041A0(void) {freelist_free(D_80136E70);D_80136E70=NULL;}
void func_801041C8(void) {if(D_80136E70)D_80136E70=freelist_defrag(D_80136E70);}
AnimCtrl *func_80104200(s16 handle) {
    if(!D_80136E70 || handle<=0 || handle>=freelist_capacity(D_80136E70) || !freelist_is_element_alive(D_80136E70,handle))return NULL;
    return freelist_at(D_80136E70,handle);
}
AnimCtrl *func_80104248(void *data) {Actor *actor=data;return actor ? func_80104200(actor->animation_handle) : NULL;}
AnimCtrl *func_80104268(s16 *handle) {
    s32 index=0;AnimCtrl *control=freelist_next(&D_80136E70,&index);
    func_8008B518(control,0);*handle=index;return control;
}
AnimCtrl *func_801042B8(Actor *actor) {return func_80104268(&actor->animation_handle);}
void func_801042D8(s16 *handle) {
    AnimCtrl *control=func_80104200(*handle);
    if(control){func_8008B5E8(control);freelist_erase(D_80136E70,*handle);*handle=0;}
}
void func_80104328(Actor *actor) {func_801042D8(&actor->animation_handle);}
#else

void func_80104170(void) {
    s32 freelist_new(s32, s32);
    s32 func_8008B4F4();
    extern s32 D_80136E70;
    D_80136E70 = freelist_new(func_8008B4F4(), 0x20);
}

void func_801041A0(void) {
    s32 freelist_free(s32);
    extern s32 D_80136E70;
    freelist_free(D_80136E70);
    D_80136E70 = 0;
}

void func_801041C8(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136E70;
    if (D_80136E70 != 0) {
        D_80136E70 = freelist_defrag(D_80136E70);
    }
}

struct anctrl_s *func_80104200(s16 arg0) {
    BT_IDO_ONLY(void *freelist_at(s32, s16);) BT_NATIVE_ONLY(struct FreeList; void *freelist_at(struct FreeList *, s32);)
    extern s32 D_80136E70;
    struct anctrl_s *var_v1;

    if (arg0 != 0) {
        var_v1 = freelist_at(BT_NATIVE_ONLY((struct FreeList *)) D_80136E70, arg0);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

struct anctrl_s *func_80104248(void *arg0) {
    struct anctrl_s *func_80104200(s16);
    return func_80104200((*(s16 *)((s8 *)(arg0) + (0x8C))));
}

struct anctrl_s *func_80104268(u32 *arg0) {
    void *freelist_next(void *, s32 *);
    extern s32 D_80136E70;
    s32 sp1C;
    struct anctrl_s *sp18;
    sp1C = 0;
    sp18 = freelist_next(&D_80136E70, &sp1C);
    func_8008B518((void *)sp18, 0);
    *(s16 *)arg0 = (s16)sp1C;
    return sp18;
}

/* extern */

struct anctrl_s *func_801042B8(Actor *arg0) {
    return func_80104268(&arg0->pad8C);
}

s32 func_801042D8(void *arg0) {
    struct anctrl_s *func_80104200(s16);
    void func_8008B5E8(struct anctrl_s *);
    void freelist_erase(s32, s32);
    extern s32 D_80136E70;
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104200((*(s16 *)((s8 *)(arg0) + 0)));
    if (temp_v0 != 0) {
        func_8008B5E8(temp_v0);
        freelist_erase(D_80136E70, (*(s16 *)((s8 *)(arg0) + 0)));
        (*(s16 *)((s8 *)(arg0) + 0)) = 0;
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_80104328(Actor *arg0) {
    func_801042D8(&arg0->pad8C);
}
#endif

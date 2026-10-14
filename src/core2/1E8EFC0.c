#include "common.h"

typedef struct {
    f32 freeTime;
    void *emitter;
    u32 isActive : 1;
    u32 capacity : 10;
    u32 reserved : 21;
} EmitterData;

void func_800B58D4(u8);

void *func_800B56D0(u8 index) {
    extern EmitterData D_80127F28[];
    extern u8 D_80127F20;
    void *func_800B53A4(s32);
    void func_800B5534(void *);
    void func_800B5450(void *);
    void *func_800B5548(void *);

    if (D_80127F28[index].emitter == NULL) {
        D_80127F20 = index;
        D_80127F28[index].emitter = func_800B53A4(D_80127F28[index].capacity);
        func_800B5534(D_80127F28[index].emitter);
        D_80127F20 = 0;
    }

    D_80127F28[index].freeTime = 1.0f;

    return D_80127F28[index].emitter;
}

u8 func_800B5758(s32 count) {
    extern EmitterData D_80127F28[];
    int i;

    for (i = 1; i < 45; i++) {
        if (D_80127F28[i].isActive == 0) {
            D_80127F28[i].isActive++;
            D_80127F28[i].emitter = NULL;
            D_80127F28[i].capacity = count;
            return i;
        }
    }

    return 0;
}

void func_800B5824(void) {
    extern EmitterData D_80127F28[];
    extern u8 D_80127F20;
    void *func_800B53A4(s32);
    void func_800B5534(void *);
    void func_800B5450(void *);
    void *func_800B5548(void *);

    void func_800B58D4(u8 index);

    int i;

    for (i = 1; i < 45; i++) {
        if (D_80127F28[i].isActive != 0) {
            func_800B58D4(i);
        }
    }
}

void func_800B5884(void) {
    extern EmitterData D_80127F28[];
    int i;
    for (i = 1; i < 45; i++) {
        D_80127F28[i].isActive = 0;
    }
}

void func_800B58D4(u8 index) {
    extern EmitterData D_80127F28[];
    extern u8 D_80127F20;
    void *func_800B53A4(s32);
    void func_800B5534(void *);
    void func_800B5450(void *);
    void *func_800B5548(void *);

    void func_800B5450(void *this);

    if (D_80127F28[index].emitter) {
        func_800B5450(D_80127F28[index].emitter);
    }

    D_80127F28[index].isActive = 0;
}

void func_800B592C(void) {
    extern EmitterData D_80127F28[];
    f32 func_800D8FF8(void);
    int func_800BA28C(void *);
    void func_800B5450(void *);
    int i;
    f32 delta = func_800D8FF8();
    for (i = 1; i < 45; i++) {
        if (D_80127F28[i].isActive != 0 && D_80127F28[i].emitter != NULL && func_800BA28C(D_80127F28[i].emitter)) {
            D_80127F28[i].freeTime -= delta;
            if (D_80127F28[i].freeTime <= 0.0f) {
                func_800B5450(D_80127F28[i].emitter);
                D_80127F28[i].emitter = NULL;
            }
        }
    }
}

void func_800B59E0(void) {
    extern EmitterData D_80127F28[];
    extern u8 D_80127F20;
    void *func_800B53A4(s32);
    void func_800B5534(void *);
    void func_800B5450(void *);
    void *func_800B5548(void *);

    void func_800B5450(void *this);

    int i;

    for (i = 1; i < 45; i++) {
        if (D_80127F28[i].isActive != 0
            && D_80127F28[i].emitter != NULL
            && i != D_80127F20) {

            func_800B5450(D_80127F28[i].emitter);
            D_80127F28[i].emitter = NULL;
        }
    }
}

void func_800B5A6C(void) {
    extern EmitterData D_80127F28[];
    extern u8 D_80127F20;
    void *func_800B53A4(s32);
    void func_800B5534(void *);
    void func_800B5450(void *);
    void *func_800B5548(void *);

    void * func_800B5548(void *this);

    int i;

    for (i = 1; i < 45; i++) {
        if (D_80127F28[i].isActive != 0
            && D_80127F28[i].emitter != NULL) {

           D_80127F28[i].emitter = func_800B5548(D_80127F28[i].emitter);
        }
    }
}

/* extern */

void func_800B5AD4(void) {
    s32 _fxsparkle_entrypoint_2();
    s32 func_800B4428();
    s32 func_800B5B40();
    _fxsparkle_entrypoint_2();
    func_800B4428();
    func_800B5B40();
}

/* extern */

void func_800B5B04(void) {
    s32 func_800B5B88();
    s32 _fxsparkle_entrypoint_3();
    s32 func_800B43E0();
    func_800B5B88();
    _fxsparkle_entrypoint_3();
    func_800B43E0();
}

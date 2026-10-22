#include "common.h"

void func_80026DE0(ALVoice *arg0, u8 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0xc;
        update[3] = arg1;
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}

void func_80026E90(ALVoice *arg0, f32 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0x7;
        *(f32 *)(update + 3) = arg1;
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}

void func_80026F40(ALVoice *arg0, u8 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0x10;
        update[3] = arg1;
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}

void func_80026FF0(ALVoice *arg0) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0xF;
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}

void func_80027090(ALVoice *arg0) {
    s32 *func_80021794(void);
    void func_80021884(void *);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        if (*(s32 *)((u8 *)arg0->pvoice + 0x88) != 0) {
            update = func_80021794();
            if (update == NULL) {
                return;
            }
            update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
            *(s16 *)(update + 2) = 0;
            *(void **)(update + 3) = arg0->pvoice;
            func_8002B684(arg0->pvoice, 3, update);
        } else {
            func_80021884(arg0->pvoice);
        }
        arg0->pvoice = NULL;
    }
}

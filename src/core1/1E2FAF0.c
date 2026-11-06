#include "core2/1E2F380.h"
#ifdef BT_NATIVE
u8 func_80016800(s32);
#endif

typedef struct {
    s32 unk0;
    s32 active;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    OSPfs pfs;
} Motor;
OSMesgQueue D_8007AEF0;
OSMesg D_8007AF08;
OSMesgQueue *D_8007AF0C;
OSThread D_8007AF10;
u8 D_8007B0C0[0x210];
Motor D_8007B2D0[4];

void func_80017FC0(s32 arg0) {
    void func_80016934(s32);
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active != 0) {
        func_80016934(4);
        motor->active = __osMotorAccess(&motor->pfs, 1) == 0;
        func_80016934(0);
    }
}

void func_80018028(s32 arg0) {
    void func_80016934(s32);
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active != 0) {
        func_80016934(4);
        motor->active = __osMotorAccess(&motor->pfs, 0) == 0;
        func_80016934(0);
    }
}

void func_80018090(s32 arg0) {
    void func_80016934(s32);
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active == 0) {
        func_80016934(4);
        motor->active = osMotorInit(D_8007AF0C, &motor->pfs, arg0) == 0;
        func_80016934(0);
    }
}

void func_80018108(s32 arg0) { void func_80016934(s32); Motor *motor; if (func_80016800(arg0) != 0) { func_80016934(4); motor = &D_8007B2D0[arg0]; motor->unk0 = osMotorInit(D_8007AF0C, &motor->pfs, arg0) == 0; func_80016934(0); } }

void func_8001817C(void *arg0) {
    s32 func_800A9CAC(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    static s32 D_8007B4E0;
    s32 i;
    s32 previous;
    s32 period;
    s32 n;
    f32 value;
    f32 elapsed;
    f32 limit;
    f32 inverse;

    for (;;) {
        n = 4;
        osRecvMesg(&D_8007AEF0, NULL, 1);
        D_8007B4E0++;
        if (!(D_8007B4E0 & 0xF)) {
            func_80018108((D_8007B4E0 >> 4) & 3);
        }
        for (i = 0; i < n; i++) {
            if (D_8007B2D0[i].unk0 != 0) {
                if (D_8007B2D0[i].active == 0 && D_8007B4E0 % 60 == 0) {
                    func_80018090(i);
                }
                elapsed = D_8007B2D0[i].unk10;
                limit = D_8007B2D0[i].unkC;
                previous = D_8007B2D0[i].unk8;
                if (elapsed != limit) {
                    value = func_800F10B4(elapsed, 0.0f, limit, D_8007B2D0[i].unk14, D_8007B2D0[i].unk18);
                    inverse = 1.0f - value;
                    period = (s32)(inverse * 8.0f + 1);
                    if (period < 2) {
                        D_8007B2D0[i].unk8 = period != 0 || value > 0.0f;
                    } else {
                        D_8007B2D0[i].unk8 = D_8007B4E0 % period == 0;
                    }
                } else {
                    D_8007B2D0[i].unk8 = 0;
                }
                if (previous != D_8007B2D0[i].unk8 && func_800A9CAC() == 0) {
                    if (D_8007B2D0[i].unk8 != 0) {
                        func_80017FC0(i);
                    } else {
                        func_80018028(i);
                    }
                }
            }
        }
    }
}

/* extern */

void func_800183D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800187B4(s32, f32, f32, f32);
    func_800187B4(arg0, (f32) arg1 / 524288.0f, (f32) arg2 / 524288.0f, (f32) arg3 / 524288.0f);
}

void func_80018444(void) { f32 func_800D8FF8(void); Motor *motor; Motor *end; f32 delta; f32 limit; f32 elapsed; delta = func_800D8FF8(); end = D_8007B2D0 + 4; motor = D_8007B2D0; loop: if (motor->unk0 != 0) { limit = motor->unkC; elapsed = motor->unk10 + delta; if (limit < elapsed) { motor->unk10 = limit; } else { motor->unk10 = elapsed; } } if (motor[1].unk0 != 0) { limit = motor[1].unkC; elapsed = motor[1].unk10 + delta; if (limit < elapsed) { motor[1].unk10 = limit; } else { motor[1].unk10 = elapsed; } } motor += 2; if (motor != end) { goto loop; } }

void func_800184E8(void) {
    void func_80014F64(OSMesgQueue *, OSMesg);
    OSMesgQueue *func_80016928(void);
    void func_80016934(s32);
    void func_8001DCB0(OSThread *, __OSThreadOddFpStorage *, s32, void (*)(void *), void *, void *, OSPri);
    void func_8001817C(void *);
    extern OSPfs D_8007B2EC;
    Motor *motor;
    OSPfs *pfs;
    s32 i;
    s32 result;

    func_80016934(4);
    D_8007AF0C = func_80016928();
    motor = D_8007B2D0; pfs = &D_8007B2EC;
    for (i = 0; i != 4; i++, motor++, pfs = (OSPfs *)((u8 *)pfs + sizeof(Motor))) {
        result = osPfsInit(D_8007AF0C, pfs, i);
        if (result == 10 || result == 11) {
            result = osMotorInit(D_8007AF0C, pfs, i);
        }
        motor->unk0 = result == 0;
        motor->active = result == 0;
    }
    func_80016934(0);
    osCreateMesgQueue(&D_8007AEF0, &D_8007AF08, 1);
    func_8001DCB0(&D_8007AF10, (__OSThreadOddFpStorage *)&D_8007B0C0, 8, func_8001817C, 0, D_8007B2D0, 25);
    osStartThread(&D_8007AF10);
    func_80014F64(&D_8007AEF0, 0);
}

void func_8001862C(void) {
}

void func_80018634(void)
{
  OSMesgQueue *queue;
  int mode;
  void func_80016934(s32);
 
  OSPfs *pfs;
  s32 attempt;
  s32 port;
  for (port = 0; port != 4; port++)
  {
    pfs = &D_8007B2D0[port].pfs;
    mode = 4;
    if (D_8007B2D0[port].active != 0)
    {
      func_80016934(mode);
      queue = D_8007AF0C;
      D_8007B2D0[port].active = !osMotorInit(queue, pfs, port);
      for (attempt = 0; (attempt < 3) && (D_8007B2D0[port].active != 0); attempt++)
      {
        D_8007B2D0[port].active = !__osMotorAccess(pfs, 0);
      }

      func_80016934(0);
    }
  }

}

void func_80018704(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    extern f32 D_80041730;
    Motor *motor;

    if (arg3 != 0.0f) {
        motor = &D_8007B2D0[arg0];
        if (motor->unk0 != 0 && (arg4 != 0 || !(D_80041730 < motor->unkC - motor->unk10) || !(arg1 + arg2 < motor->unk18 + motor->unk14))) {
            motor->unkC = arg3;
            motor->unk14 = arg1;
            motor->unk10 = 0;
            motor->unk18 = arg2;
        }
    }
}

void func_800187B4(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_80018704(s32, f32, f32, f32, s32);
    func_80018704(arg0, arg1, arg2, arg3, 0);
}

void func_800187E8(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_80018704(s32, f32, f32, f32, s32);
    func_80018704(arg0, arg1, arg2, arg3, 1);
}

void func_80018820(s32 arg0, f32 arg1, f32 arg2) { func_800187B4(arg0, arg1, arg1, arg2); }

void func_80018854(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    void func_800C9EAC(f32, void *, s32, s32, s32, s32);

    if (D_8007B2D0[arg0].unk0 != 0) {
        func_800C9EAC(0.0f, func_800183D4, arg0, 0, (s32)(arg1 * 524288.0f), (s32)(arg3 * 524288.0f));
        func_800C9EAC(arg3, func_800183D4, arg0, (s32)(arg1 * 524288.0f), (s32)(arg2 * 524288.0f), (s32)(arg4 * 524288.0f));
        func_800C9EAC(arg3 + arg4, func_800183D4, arg0, (s32)(arg2 * 524288.0f), (s32)(arg2 * 524288.0f), (s32)(arg5 * 524288.0f));
        func_800C9EAC(arg3 + arg4 + arg5, func_800183D4, arg0, (s32)(arg2 * 524288.0f), 0, (s32)(arg6 * 524288.0f));
    }
}

void func_800189A8(s32 arg0, f32 arg1[][2], s16 arg2, f32 arg3, f32 arg4) {
    void func_800C9EAC(f32, void *, s32, s32, s32, s32);
    f32 temp_f12;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f14;
    s32 var_s1;

    if (D_8007B2D0[arg0].unk0 != 0) {
        for (var_s1 = 0; var_s1 < arg2 - 1; var_s1++) {
                temp_f12 = arg1[var_s1][0] * arg3;
                temp_f0 = arg1[var_s1 + 1][0] * arg3;
                temp_f2 = arg1[var_s1][1] * arg4;
                temp_f14 = arg1[var_s1 + 1][1] * arg4;
                func_800C9EAC(temp_f12, func_800183D4, arg0, (s32) (temp_f2 * 524288.0f), (s32) (temp_f14 * 524288.0f), (s32) ((temp_f0 - temp_f12) * 524288.0f));
        }
    }
}

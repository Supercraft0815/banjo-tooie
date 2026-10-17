#include "common.h"

void func_800E6A10(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }

    while (*src) {
        *dest++ = *src++;
    }

    *dest = '\0';
}

void func_800E6A58(char *dest, char src) {
    while (*dest) {
        dest++;
    }

    *dest++ = src;
    *dest = '\0';
}

void func_800E6A90(char *arg0, u8 *arg1) {
    void func_800E6AFC(char *, u8);
    extern s32 D_80125DC0;
    u8 var_a2;
    var_a2 = *arg1;
    if (var_a2 != 0) {
        do {
            func_800E6AFC(arg0, *arg1++);
            func_800E6A10(arg0, (const char *) &D_80125DC0);
            var_a2 = *arg1;
        } while (var_a2 != 0);
    }
}

void func_800E6AFC(char *arg0, u8 arg1) {
    s32 var_a2;
    s32 temp_v1;

    while (*arg0 != 0) {
        arg0++;
    }
    arg0[0] = 0x30;
    arg0[1] = 0x78;
    arg0 += 2;
    temp_v1 = arg1;
    for (var_a2 = 4; var_a2 >= 0; var_a2 -= 4) {
        temp_v1 = (temp_v1 >> var_a2) & 0xF;
        if ((temp_v1 < 0xA) & 0xFF) {
            *arg0 = temp_v1 + 0x30;
        } else {
            *arg0 = temp_v1 + 0x57;
        }
        arg0 += 1;
        temp_v1 = arg1;
    }
    *arg0 = 0;
}

s32 func_800E6B7C(char **arg0, f32 arg1) {
    return (arg1 < 0.0f) ? -1 : 1;
}

void func_800E6BAC(char *dest, f32 val) {
    extern char D_80125DC4[];
    extern char D_80125DC8[];
    extern char D_80125DCC[];
    void func_800E6DB4(char *, s32);
    s32 decimal;
    char *str;

    switch (func_800E6B7C(&str, val)) {
    case 0:
        func_800E6A10(dest, str);
        break;
    case -1:
        func_800E6A10(dest, D_80125DC4);
        val = -val;
    case 1:
        func_800E6DB4(dest, (s32)val);
        func_800E6A10(dest, D_80125DC8);
        decimal = (s32)((val - (f32)(s32)val) * 100.0f);
        if (decimal < 10) {
            func_800E6A10(dest, D_80125DCC);
        }
        func_800E6DB4(dest, decimal);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6CA8.s")

void func_800E6DB4(char *str, s32 num) {
    void func_800E6DD8(char *, s32, s32, s32);
    func_800E6DD8(str, num, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6DD8.s")

void func_800E6F7C(u8 *arg0, u32 arg1) {
    s32 var_v1;
    s32 temp_t0;
    while (*arg0 != 0) {
        arg0++;
    }
    arg0[0] = 0x30;
    arg0[1] = 0x78;
    arg0 += 2;
    temp_t0 = arg1;
    for (var_v1 = 0x1C; var_v1 >= 0; var_v1 -= 4) {
        temp_t0 = ((u32)temp_t0 >> var_v1) & 0xF;
        if ((temp_t0 < 0xA) & 0xFF) {
            *arg0 = temp_t0 + 0x30;
        } else {
            *arg0 = temp_t0 + 0x57;
        }
        arg0 += 1;
        temp_t0 = arg1;
    }
    *arg0 = 0;
}

void func_800E6FEC(u8 *arg0, u32 arg1) {
    s32 var_v1;
    s32 temp_t0;
    while (*arg0 != 0) {
        arg0++;
    }
    arg0[0] = 0x30;
    arg0[1] = 0x2E;
    arg0 += 2;
    temp_t0 = arg1;
    for (var_v1 = 0x1C; var_v1 >= 0; var_v1 -= 4) {
        temp_t0 = ((u32)temp_t0 >> var_v1) & 0xF;
        if ((temp_t0 < 0xA) & 0xFF) {
            *arg0 = temp_t0 + 0x30;
        } else {
            *arg0 = temp_t0 + 0x37;
        }
        arg0 += 1;
        temp_t0 = arg1;
    }
    *arg0 = 0;
}

void func_800E705C(char *arg0, u8 arg1) {
    s32 var_a2;
    s32 temp_v1;

    while (*arg0 != 0) {
        arg0++;
    }
    arg0[0] = 0x30;
    arg0[1] = 0x78;
    arg0 += 2;
    temp_v1 = arg1;
    for (var_a2 = 4; var_a2 >= 0; var_a2 -= 4) {
        temp_v1 = (temp_v1 >> var_a2) & 0xF;
        if ((temp_v1 < 0xA) & 0xFF) {
            *arg0 = temp_v1 + 0x30;
        } else {
            *arg0 = temp_v1 + 0x37;
        }
        arg0 += 1;
        temp_v1 = arg1;
    }
    *arg0 = 0;
}

int func_800E70DC(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    if (*lhs == *rhs) {
        return 0;
    } else if ((*lhs == '\0') || (*lhs < *rhs)) {
        return -1;
    } else {
        return 1;
    }
}

void func_800E715C(u8 *arg0, u8 *arg1) {
    u8 var_v0;

    var_v0 = *arg1;
    if (var_v0 != 0) {
        do {
            *arg0 = var_v0;
            var_v0 = arg1[1];
            arg0++;
            arg1++;
        } while (var_v0 != 0);
    }
    *arg0 = 0;
}

s32 func_800E7188(u8 *arg0) {
    u8 temp_v0;
    s32 var_v1 = 0;

    temp_v0 = *arg0++;
    if (temp_v0 != 0) {
        do {
            temp_v0 = *arg0;
            var_v1++;
            arg0++;
        } while (temp_v0 != 0);
    }
    return var_v1;
}

/* extern */

s32 func_800E71B8(s32 arg0) {
    s32 _gldialog_entrypoint_1();
    if (_gldialog_entrypoint_1() != 0) {
        return arg0 += 2;
    }
    return arg0;
}

int func_800E71EC(char *str1, char *str2, char *str3) {
    while (*str2 == *str3) {
        str2++;
        str3++;
        if (((*str2 == '\0') || (*str2 == *str1)) && ((*str3 == '\0') || (*str3 == *str1))) {
            return 1;
        }
    }
    return 0;
}

char *func_800E7254(char *str, const char *delim) {
    while (*delim && *delim != *str ) {
        delim++;
    }

    if (*delim == *str) {
        delim++;
    }

    return (char *) delim;
}

void func_800E729C(char *str1, char *str2, char *str3){
    while ((*str3 != '\0') && (*str3 != *str1)){
        *str2 = *str3;
        str3++;
        str2++;
    }
    *str2 = '\0';
}

void func_800E72E0(u8 *arg0) {
    u8 *ptr;

    ptr = arg0;
    while (*ptr != 0) {
        if (*ptr >= 0x61 && *ptr < 0x7B) {
            *ptr -= 0x20;
        }
        ptr++;
    }
}

void func_800E7324(char *str) {
    char *ch = str;

    while (*ch) {
        if ((*ch >= 'A') && (*ch <= 'Z')) {
            *ch += 'a' - 'A';
        }

        ch++;
    }
}

/* extern */

void func_800E7368(s32 arg0, s32 arg1) {
    void func_800E6A58(char *, char);
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0x1F;
    do {
        if ((1 << var_s0) & arg1) {
            var_v0 = 0x31;
        } else {
            var_v0 = 0x30;
        }
        func_800E6A58(arg0, var_v0);
        var_s0 -= 1;
    } while (var_s0 >= 0);
}

void func_800E73D4(s8 *arg0) {
    arg0[0] = 0;
}

void func_800E73DC(s8 *arg0, s32 arg1, ...) {
    s32 func_800E7480(s8 *, s32, s32);
    u32 args;
    func_800E73D4(arg0);
    args = (u32)&arg1 + sizeof(arg1);
    func_800E7480(arg0, arg1, (args + 3) & ~3);
}

void func_800E7428(s8 *arg0, s32 arg1, ...) {
    s32 func_800E7480(s8 *, s32, s32);
    u32 args;
    if ((u8)arg0[0] != 0) {
        do {
            arg0 += 1;
        } while ((u8)arg0[0] != 0);
    }
    args = (u32)&arg1 + sizeof(arg1);
    func_800E7480(arg0, arg1, (args + 3) & ~3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7480.s")

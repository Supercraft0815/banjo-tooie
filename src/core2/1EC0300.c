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
    u8 var_a2;
    var_a2 = *arg1;
    if (var_a2 != 0) {
        do {
            func_800E6AFC(arg0, *arg1++);
            func_800E6A10(arg0, " ");
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
    void func_800E6DB4(char *, s32);
    s32 decimal;
    char *str;

    switch (func_800E6B7C(&str, val)) {
    case 0:
        func_800E6A10(dest, str);
        break;
    case -1:
        func_800E6A10(dest, "-");
        val = -val;
    case 1:
        func_800E6DB4(dest, (s32)val);
        func_800E6A10(dest, ".");
        decimal = (s32)((val - (f32)(s32)val) * 100.0f);
        if (decimal < 10) {
            func_800E6A10(dest, "0");
        }
        func_800E6DB4(dest, decimal);
        break;
    }
}

void func_800E6CA8(char *dest, f32 val, s32 decPlaces) {
    void func_800E6DB4(char *, s32);
    char *str;
    u32 i;
    switch (func_800E6B7C(&str, val)) {
    case 0:
        func_800E6A10(dest, str);
        break;
    case -1:
        func_800E6A10(dest, "-");
        val = -val;
    case 1:
        func_800E6DB4(dest, (s32)val);
        if (decPlaces != 0) {
            func_800E6A10(dest, ".");
            for (i = decPlaces--; i > 0; i = decPlaces--) {
                val -= (s32)val;
                val *= 10;
                func_800E6DB4(dest, (s32)val);
            }
        }
        break;
    }
}

void func_800E6DB4(char *str, s32 num) {
    void func_800E6DD8(char *, s32, u8, s32);
    func_800E6DD8(str, num, 0, 0);
}

void func_800E6DD8(char *str, s32 num, u8 prefix, s32 arg3) {
    s32 i;



    while (*str != 0) {
        str++;
    }
    if (num < 0) {
        *str = '-';
        str++;
        num = -num;
    } else if (prefix != 0) {
        *str = prefix;
        str++;
    }
    for (i = 1000000000; num < i; i /= 10) {}
    if (i == 0) {
        *str = '0';
        str++;
    } else {
        while (i > 0) {
            if (arg3 != 0) {
                *str++ = 0x10 + (num / i);
            } else {
                *str++ = '0' + (num / i);
            }
            num %= i;
            i /= 10;
        }
    }
    *str = 0;
}

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

BtIntPtr func_800E71B8(BtIntPtr arg0) {
#if defined(BT_NATIVE) && defined(BT_ILP32)
    s32 _gldialog_entrypoint_1(const u8 *);
    if (_gldialog_entrypoint_1((const u8 *)arg0) != 0) {
#else
    s32 _gldialog_entrypoint_1();
    if (_gldialog_entrypoint_1() != 0) {
#endif
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

void func_800E7368(BtIntPtr arg0, s32 arg1) {
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
        func_800E6A58(BT_NATIVE_ONLY((char *))arg0, var_v0);
        var_s0 -= 1;
    } while (var_s0 >= 0);
}

void func_800E73D4(s8 *arg0) {
    arg0[0] = 0;
}

void func_800E73DC(s8 *arg0, s32 arg1, ...) {
    void func_800E7480(s8 *, BtIntPtr, u8 *);
    BtUIntPtr args;
    func_800E73D4(arg0);
    args = (BtUIntPtr)&arg1 + sizeof(arg1);
    func_800E7480(arg0, arg1, (u8 *)((args + 3) & ~3));
}

void func_800E7428(s8 *arg0, s32 arg1, ...) {
    void func_800E7480(s8 *, BtIntPtr, u8 *);
    BtUIntPtr args;
    if ((u8)arg0[0] != 0) {
        do {
            arg0 += 1;
        } while ((u8)arg0[0] != 0);
    }
    args = (BtUIntPtr)&arg1 + sizeof(arg1);
    func_800E7480(arg0, arg1, (u8 *)((args + 3) & ~3));
}

void func_800E7480(s8 *arg0, BtIntPtr arg1, u8 *arg2) {
    u8 *format = (u8 *)arg1;
    f64 value;

    for (; *format; format++) {
        if (*format != '%') {
            if (*format >= 0x20) {
                func_800E6A58((char *)arg0, *format);
            }
            continue;
        }
        format++;
        switch (*format) {
            case 'b':
                func_800E7368((BtIntPtr)arg0, *(s32 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 4));
                break;
            case 'c':
                func_800E6A58((char *)arg0, *(u8 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 1));
                break;
            case 'd':
                func_800E6DB4((char *)arg0, *(s32 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 4));
                break;
            case 'f':
                value = *(f64 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 15) & ~7)) - 8);
                func_800E6BAC((char *)arg0, value);
                break;
            case 'p':
                func_800E6F7C((u8 *)arg0, *(u32 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 4));
                break;
            case 's':
                func_800E6A10((char *)arg0, *(char **)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 4));
                break;
            case 'x':
                func_800E6F7C((u8 *)arg0, *(u32 *)((arg2 = (u8 *)(((BtUIntPtr)arg2 + 7) & ~3)) - 4));
                break;
            default:
                func_800E6A58((char *)arg0, *format);
                break;
        }
    }
}

/* The retail formatter retains these special-value strings alongside its finite-value code. */
struct {
    char nan[4], signaling_nan[8], infinity[4], negative_infinity[8];
    char padding[8];
} D_801232F0 BT_DATA(4, number_format_strings, 0) = {"NaN", "sNaN", "INF", "-INF", {0}};

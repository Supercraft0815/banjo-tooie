// Included by PR/ultratypes.h (both copies), so every game file has these macros.
#ifndef BT_NATIVE_H
#define BT_NATIVE_H
// Code only the native build runs, written onto an existing line (a src file must not gain lines:
// IDO's as1 schedules by line number). One argument: no top-level commas inside.
// BT_PASS2: a K&R call that passes on the caller's a0/a1 (`f()` where f takes two); natively the
// arguments are written out, IDO keeps the empty list. BT_PARAM_OR_VOID names, natively, the
// register parameter a `(void)` function passes on that way. BT_IDO_ONLY: N64-only code, such as a
// local prototype that a native header already declares with another type.
// Paired declarations keep the N64 field order and IDO source line numbers.
#ifdef BT_ILP32
#define BT_BITFIELD_ORDER(n64, guest) guest
#define BT_ILP32_ONLY(code) code
#else
#define BT_BITFIELD_ORDER(n64, guest) n64
#define BT_ILP32_ONLY(code)
#endif
#ifdef BT_NATIVE
#define BT_NATIVE_ONLY(code) code
#define BT_PASS2(a, b) a, b
#define BT_PARAM_OR_VOID(decl) decl
#define BT_IDO_ONLY(code)
#else
#define BT_NATIVE_ONLY(code)
#define BT_PASS2(a, b)
#define BT_PARAM_OR_VOID(decl) void
#define BT_IDO_ONLY(code) code
#endif
#endif

#ifndef BT_GUEST_ASSERT_H
#define BT_GUEST_ASSERT_H
_Noreturn void bt_assert_fail(const char *expr, const char *file, int line);
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#define assert(e) ((e) ? (void)0 : bt_assert_fail(#e, __FILE__, __LINE__))
#endif
#endif

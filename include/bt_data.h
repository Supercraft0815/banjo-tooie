#ifndef BT_DATA_H
#define BT_DATA_H
// BT_DATA for files that do not include common.h (same definition; see there)
#ifndef BT_DATA
#ifdef BT_ILP32
#define BT_DATA(n, m, o) __attribute__((aligned(n), section(".btgroup." #m "." #o)))
#else
#define BT_DATA(n, m, o)
#endif
#endif
#endif

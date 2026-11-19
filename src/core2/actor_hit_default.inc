#include "marker_hit_callbacks.h"
void func_80108F08(void *, void *, s32);

/* A generic actor reacts to impacts; its optional collision and filter callbacks are empty. */
struct {
    MarkerHitMethods hit;
    void (*reserved[3])(void);
} D_80124580 BT_DATA(4, actor_hit_default, 0) = {
    {{NULL, NULL, NULL}, func_80108F08, NULL}, {NULL, NULL, NULL}
};

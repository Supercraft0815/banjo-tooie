#include "core2/actor_animation_entry.h"

struct AthleteCurve6 {
    f32 points[6][2];
};
struct AthleteCurve5 {
    f32 points[5][2];
};

typedef union {
    f32 prefix[9];
#ifdef BT_NATIVE
    struct AthleteCurve5 curve;
#endif
} AthleteCurveTail;

#include "core2/1E8DC70.h"

#ifdef BT_NATIVE
extern Vector *D_80127EF0, *D_80127EF4, *D_80127EF8;
#else
extern s32 D_80127EF0[3];
#endif


void func_800B4380(void)
{
    s32 index;
#ifdef BT_NATIVE
    Vector **slots[] = {&D_80127EF0, &D_80127EF4, &D_80127EF8};
    Vector *temp_a0;
#else
    BtIntPtr temp_a0;
#endif

    for (index = 0; index < 3; index++)
    {
        temp_a0 = BT_DATA_FIELD(*slots[index], D_80127EF0[index]);
        if (temp_a0 != 0)
        {
            BT_DATA_FIELD(*slots[index], D_80127EF0[index]) = vector_defrag(temp_a0);
        }
    }
}

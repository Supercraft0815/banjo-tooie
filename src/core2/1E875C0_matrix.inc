#ifdef BT_NATIVE
#include "native_skinning.h"
MtxF *func_800ADE2C(NativeBoneMatrices *list,s32 index) {
    if(!list || index < -1 || index>=list->count)return NULL;
    return index==-1 ? &list->base : &list->matrices[index];
}
#else
s32 func_800ADE2C(s32 arg0, s32 arg1) {
    if (arg1 == -1) {
        return arg0 + 0x10;
    }
    return (arg0 + 0x50) + (arg1 << 6);
}
#endif

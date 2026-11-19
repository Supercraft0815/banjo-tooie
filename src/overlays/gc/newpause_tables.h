/* The same ten signed distances are summed at setup and applied one at a time when paging. */
typedef union {
    struct {
        s8 first[2];
        MemorySetupStruct groups[2];
        s8 padding[2];
    } setup;
    s8 offsets[10];
} PausePageOffsets;

BT_IDO_ONLY(extern s8 D_80802125_gcnewpause;)
BT_IDO_ONLY(extern MemorySetupStruct D_80802126_gcnewpause[];)
BT_IDO_ONLY(extern s8 D_8080212E_gcnewpause;)

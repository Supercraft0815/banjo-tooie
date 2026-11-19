typedef struct {
    s32 map, parkedFlag, dialog, travelFlag, prerequisite;
} TimetableEntry;

typedef union {
    struct {
        TimetableEntry stations[7];
        f32 camera[4];
        ActorData actor;
    } objects;
    TimetableEntry scan[11];
} TimetableData;

extern TimetableData D_80800730_chtimetable;

/* Both original loops probe eleven records. The last four cover the camera
 * and actor fields after the seven train stations. Project those same words
 * when the host's native pointers change the descriptor layout. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
static s32 timetable_float_word(f32 value) {
    union {
        f32 floating;
        s32 word;
    } bits;
    bits.floating = value;
    return bits.word;
}
static s32 timetable_map_word(const TimetableEntry *row) {
    const TimetableData *data = &D_80800730_chtimetable;
    const ActorData *actor = &data->objects.actor;
    BtIntPtr index = row - data->scan;
    switch (index) {
    case 7:
        return timetable_float_word(data->objects.camera[0]);
    case 8:
        return ((u32)(u16)actor->unk4 << 16) | (u16)actor->unk6;
    case 9:
        return actor->unk18;
    case 10:
        return (s32)actor->unk2C;
    default:
        return data->objects.stations[index].map;
    }
}
static s32 timetable_flag_word(const TimetableEntry *row) {
    const TimetableData *data = &D_80800730_chtimetable;
    const ActorData *actor = &data->objects.actor;
    BtIntPtr index = row - data->scan;
    switch (index) {
    case 7:
        return timetable_float_word(data->objects.camera[1]);
    case 8:
        return (s32)(BtIntPtr)actor->unk8;
    case 9:
        return actor->unk1C;
    case 10:
        return ((u32)(u16)actor->unk30 << 16) | (u16)actor->unk32;
    default:
        return data->objects.stations[index].parkedFlag;
    }
}
static s32 timetable_dialog_word(s32 index) {
    const TimetableData *data = &D_80800730_chtimetable;
    const ActorData *actor = &data->objects.actor;
    if (index >= 0 && index < 7) return data->objects.stations[index].dialog;
    switch (index) {
        case 7: return timetable_float_word(data->objects.camera[2]);
        case 8: return (s32)(BtUIntPtr)actor->unkC_func;
        case 9: return ((u32)(u16)actor->unk20 << 16) | (u16)actor->unk22;
        case 10: return (s32)(BtUIntPtr)actor->unk34_func;
        default: return -1;
    }
}
#else
#define timetable_dialog_word(index) (D_80800730_chtimetable.scan[index].dialog)
#define timetable_map_word(row) ((row)->map)
#define timetable_flag_word(row) ((row)->parkedFlag)
#endif

BT_IDO_ONLY(extern s32 D_80800744_chtimetable;)
BT_IDO_ONLY(extern s32 D_80800758_chtimetable;)
BT_IDO_ONLY(extern TimetableEntry D_8080076C_chtimetable;)
BT_IDO_ONLY(extern TimetableEntry D_8080080C_chtimetable;)

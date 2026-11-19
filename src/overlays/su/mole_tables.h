typedef struct {
    f32 camera[4];
    s32 effects[3];
} MoleCameraEffects;
typedef struct {
    s32 dialog, event, parameter;
} MoleTutorialEffect;
typedef struct {
    s32 dialog, event;
} MoleTutorialEvent;
typedef union {
    struct {
        MoleTutorialEffect effects[6];
        MoleTutorialEvent learned[5];
        s32 padding;
    } tables;
    /* The original 3-word loop also examines three entries from learned. */
    s32 effectWords[27];
} MoleTutorialTables;

/* Row four handles dialog zero; all later keys in the old native image
 * are also zero. Stop at the known row rather than reading the next section. */
#define MOLE_LEARNED_COUNT BT_DATA_FIELD(5, 8)

#define MOLE_LEARNED_EVENTS BT_DATA_FIELD(D_8080256C_sumole.tables.learned, D_808025B4_sumole)

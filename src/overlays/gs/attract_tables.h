typedef struct {
    s16 map;
    s8 exit;
    u8 flags;
    u8 setup;
    u8 pad5;
} DemoScene;

typedef struct {
    s16 map;
    u8 exit;
    u8 sceneCount;
    DemoScene *scenes;
    u8 flags;
    u8 padding[3];
} DemoSequence;

extern DemoSequence D_80800490_gsattract[2];

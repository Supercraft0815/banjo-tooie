typedef struct {
    f32 rotation[3];
    f32 translation[3];
    f32 scale[3];
} JointTransform;

typedef struct {
    u8 bone;
    u8 flags;
    JointTransform *transforms;
} JointPart;

typedef struct {
    JointPart *parts;
    u8 (*values)[4];
    s16 id;
    u8 defaultValue;
    u8 partCount;
    u8 count;
    u8 padD[3];
} JointInfo;

extern JointInfo D_80801818_suexpressjoint[22];

BT_IDO_ONLY(extern s16 D_80801820_suexpressjoint;)
BT_IDO_ONLY(extern s16 D_80801830_suexpressjoint;)
BT_IDO_ONLY(extern JointInfo D_80801838_suexpressjoint[];)

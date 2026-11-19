/* The duration lookup is one-based and only reads positive state IDs. */
typedef struct {
    ActorData actor;
    f32 stateDuration[7];
} MasterJiggyConfig;

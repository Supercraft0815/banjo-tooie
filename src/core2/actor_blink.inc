/* The original NULL callback at index zero shares the origin vector's third word. */
typedef void (*ActorBlinkCallback)(Actor *);
void func_80101A50(Actor *actor);
void func_80101BA0(Actor *actor);

f32 D_801243E0[3] BT_DATA(4, actor_blink, 0) = {0.0f, -4.0f, 0.0f};
ActorBlinkCallback actorBlinkCallbacks[2] BT_DATA(4, actor_blink, 12) = {
    func_80101A50, func_80101BA0,
};

#ifdef BT_NATIVE
#define BLINK_CALLBACK(index) actorBlinkCallbacks[(index) - 1]
#else
extern ActorBlinkCallback D_801243E8[];
#define BLINK_CALLBACK(index) D_801243E8[index]
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define BLINK_NATIVE(native, retail) native
typedef struct { unsigned state : 2, frame : 3; } BlinkState;
#define LOAD_ACTOR_BLINK(actor) BlinkState blink = {((actor)->flags7A >> 12) & 3u, ((actor)->flags7A >> 9) & 7u};
#define STORE_ACTOR_BLINK(actor) (actor)->flags7A = ((actor)->flags7A & ~0x3E00u) | (blink.state << 12) | (blink.frame << 9);
#else
#define BLINK_NATIVE(native, retail) retail
#define LOAD_ACTOR_BLINK(actor)
#define STORE_ACTOR_BLINK(actor)
#endif

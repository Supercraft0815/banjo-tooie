typedef struct {
    f32 edgeAB[3],edgeAC[3],normal[3];
    void *triangle;
    f32 point[3][3];
} NativeProcessedTriangle;
typedef struct NativeCollisionBlock {
    struct NativeCollisionBlock *previous,*next;
    s32 frame,capacity;
    NativeProcessedTriangle triangles[];
} NativeCollisionBlock;
#define COLL_BLOCK_HEADER offsetof(NativeCollisionBlock,triangles)
void *D_8012798C;

void func_800AB9D0(void) {
    NativeCollisionBlock *block=D_8012798C;
    while(block){NativeCollisionBlock *next=block->next;heap_free(block);block=next;}
    D_8012798C=NULL;
}
void func_800AB980(void) {
    func_800AB9D0();
    NativeCollisionBlock *block=heap_alloc(COLL_BLOCK_HEADER+15*sizeof(NativeProcessedTriangle));
    *block=(NativeCollisionBlock){.frame=0x40000000,.capacity=15};D_8012798C=block;
}
void func_800ABA20(void) { /* Native heap allocations do not move. */ }
void func_800ABA9C(void) {
    s32 func_8001211C(void);
    NativeCollisionBlock *block=D_8012798C;if(!block)return;
    s32 cutoff=func_8001211C()-40;block=block->next;
    while(block && cutoff<block->frame)block=block->next;
    if(block)block->previous->next=NULL;
    while(block){NativeCollisionBlock *next=block->next;heap_free(block);block=next;}
}
void func_800ABB34(void *cursor_arg,void **block_arg) {
    s32 func_8001211C(void);
    void **cursor=cursor_arg;NativeCollisionBlock *block=*block_arg;
    *cursor=(u8 *)*cursor+sizeof(NativeProcessedTriangle);
    if((u8 *)*cursor==(u8 *)(block->triangles+block->capacity)) {
        if(!block->next) {
            block->next=heap_alloc(COLL_BLOCK_HEADER+50*sizeof(NativeProcessedTriangle));
            *block->next=(NativeCollisionBlock){.previous=block,.capacity=50};
        }
        block=block->next;block->frame=func_8001211C();*block_arg=block;*cursor=block->triangles;
    }
}
void func_800ABC0C(u8 **cursor,u8 **block_arg) {
    NativeCollisionBlock *block=(void *)*block_arg;*cursor+=sizeof(NativeProcessedTriangle);
    if(*cursor==(u8 *)(block->triangles+block->capacity)) {
        block=block->next;*block_arg=(void *)block;*cursor=(u8 *)block->triangles;
    }
}

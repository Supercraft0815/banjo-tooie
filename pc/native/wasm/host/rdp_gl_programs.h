// The renderer owns the material table. The compiler thread owns its shared GL
// context and publishes a fully linked immutable program with a release store.
typedef struct {
    u32 key[6];
    unsigned uses;
    _Atomic int linked;
    DrawProgram program;
} MaterialProgram;

enum { PROGRAM_SLOTS=128, PROGRAM_LIMIT=48, PROGRAM_HOT_DRAWS=32 };
static struct {
    SDL_GLContext context;
    DrawProgram generic;
    MaterialProgram material[PROGRAM_SLOTS], *last, *queue[PROGRAM_LIMIT];
    pthread_mutex_t lock;
    pthread_cond_t pending;
    unsigned submitted,next,draws;
    _Atomic unsigned ready;
} programs = {.lock=PTHREAD_MUTEX_INITIALIZER,.pending=PTHREAD_COND_INITIALIZER};

static DrawProgram draw_program(GLuint name) {
    glUseProgram(name);
    glUniform1i(glGetUniformLocation(name,"atlas"),0);
    glUniform1i(glGetUniformLocation(name,"mats"),1);
    glUniform1i(glGetUniformLocation(name,"dst"),4);
    glUniform1i(glGetUniformLocation(name,"silhouette"),6);
    return (DrawProgram){name,glGetUniformLocation(name,"scale"),glGetUniformLocation(name,"frame"),
        glGetUniformLocation(name,"color16"),glGetUniformLocation(name,"rmw"),glGetUniformLocation(name,"soften")};
}

static void *compile_draw_programs(void *unused) {
    (void)unused;
    if (!SDL_GL_MakeCurrent(gpu_window,programs.context)) return NULL;
    for (;;) {
        pthread_mutex_lock(&programs.lock);
        while (programs.next==programs.submitted) pthread_cond_wait(&programs.pending,&programs.lock);
        MaterialProgram *m=programs.queue[programs.next++];
        pthread_mutex_unlock(&programs.lock);
        char text[sizeof gpu_fragment_shader+256];
        const u32 *k=m->key;
        const char *body=strchr(gpu_fragment_shader,'\n')+1;
        snprintf(text,sizeof text,"#version 330\n#define BT_MATERIAL\n#define BT_H0 uvec4(%uu,%uu,%uu,%uu)\n"
                 "#define BT_H1 uvec2(%uu,%uu)\n%s",k[0],k[1],k[2],k[3],k[4],k[5],body);
        GLuint name=gpu_build_program(gpu_vertex_shader,text,1);
        if (name) {
            m->program=draw_program(name);
            glFinish(); // only the compiler context waits, including its initial sampler bindings
            atomic_store(&m->linked,1);
            atomic_fetch_add(&programs.ready,1);
        }
    }
    return NULL;
}

static const DrawProgram *select_draw_program(const u32 *key) {
    if (!programs.context) return &programs.generic;
    MaterialProgram *m=programs.last;
    if (!m || memcmp(m->key,key,sizeof m->key)) {
        u32 hash=2166136261u;
        for (int i=0;i<6;i++) hash=(hash^key[i])*16777619u;
        for (int i=0;i<PROGRAM_SLOTS;i++) {
            m=&programs.material[(hash+(u32)i)%PROGRAM_SLOTS];
            if (!m->uses) { memcpy(m->key,key,sizeof m->key); break; }
            if (!memcmp(m->key,key,sizeof m->key)) break;
            if (i==PROGRAM_SLOTS-1) return &programs.generic;
        }
        programs.last=m;
    }
    if (atomic_load(&m->linked)) { programs.draws++; return &m->program; }
    if (m->uses<PROGRAM_HOT_DRAWS && ++m->uses==PROGRAM_HOT_DRAWS) {
        pthread_mutex_lock(&programs.lock);
        if (programs.submitted<PROGRAM_LIMIT) {
            programs.queue[programs.submitted++]=m;
            pthread_cond_signal(&programs.pending);
        }
        pthread_mutex_unlock(&programs.lock);
    }
    return &programs.generic;
}

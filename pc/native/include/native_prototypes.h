/* Force-included in every native compile (see CMakeLists.txt).
 * Functions whose host signature differs from the N64 one, mostly because they
 * return or take pointers that the N64 code passes as s32. A caller that still
 * declares the old signature then fails to compile instead of truncating a pointer.
 * Only basic C types here: this header precedes all game headers. */
#if !defined(NATIVE_PROTOTYPES_H) && !defined(__ASSEMBLER__)
#define NATIVE_PROTOTYPES_H

/* core1/1E2C940.c framebuffers */
void *func_80014E10(int index, int size);
void *func_80014ED4(void);
void *func_80014F00(void);
void *func_8001575C(void);

/* core1/1E31B40.c depth buffer and task records */
void *func_8001A018(int size);
void *func_8001A0A8(void);

#endif

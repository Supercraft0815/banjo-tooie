#ifndef _OS_LIBC_H_
#define _OS_LIBC_H_
#ifndef BT_NATIVE
#error "The host libc adapter is only for native builds"
#endif
#include <stdio.h>
#include <PR/os_pfs.h>
#include <PR/ultratypes.h>
#ifdef __cplusplus
extern "C" {
#endif
/* Game byte routines retain their original signed-length interface. */
void bcopy(const void *,void *,int);
int bcmp(const void *,const void *,int);
void bzero(void *,int);
void osSyncPrintf(const char *,...);
#ifdef __cplusplus
}
#endif
#endif

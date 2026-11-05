#ifndef NATIVE_OS_H
#define NATIVE_OS_H

#include <ultra64.h>

// Delivers a message from a host thread (event source), dropping it when the queue is full.
void bt_os_post(OSMesgQueue *mq, OSMesg msg);
// Sends the message registered with osSetEventMesg for e.
void bt_os_event(OSEvent e);
void bt_vi_init(void);
int bt_vi_is_black(void);

#endif

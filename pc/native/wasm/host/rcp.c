// RCP tasks from the guest scheduler.
#include <stdlib.h>
#include "guest.h"

#define M_GFXTASK 1
#define OS_EVENT_SP 4
#define OS_EVENT_DP 9

// Graphics tasks run at once (gsp.c, rdp.c). shortcut: audio tasks complete without
// producing samples, until the audio microcode is ported. OSTask: type at 0, data_ptr at 48.
// Event numbers as in PR/os_message.h.
void w2c_env_rcp_task(struct w2c_env *env, u32 task) {
    u32 type = gr32(task);
    (void)env;
    if (type == M_GFXTASK && !getenv("BT_NO_GFX")) gsp_run(gr32(task + 48));
    bt_os_event(OS_EVENT_SP);
    if (type == M_GFXTASK) bt_os_event(OS_EVENT_DP);
}

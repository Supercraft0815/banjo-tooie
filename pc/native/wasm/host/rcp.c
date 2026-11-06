// RCP tasks from the guest scheduler.
#include <stdlib.h>
#include "guest.h"

#define M_GFXTASK 1
#define M_AUDTASK 2
#define OS_EVENT_SP 4
#define OS_EVENT_DP 9

// Tasks run at once: graphics in gsp.c and rdp.c, audio on the RSP interpreter (rsp.c).
// OSTask: type at 0, data_ptr at 48.
// Event numbers as in PR/os_message.h.
void w2c_env_rcp_task(struct w2c_env *env, u32 task) {
    u32 type = gr32(task);
    (void)env;
    if (type == M_GFXTASK && !getenv("BT_NO_GFX")) gsp_run(gr32(task + 48));
    if (type == M_AUDTASK && !getenv("BT_MUTE")) bt_rsp_audio(task);
    bt_os_event(OS_EVENT_SP);
    if (type == M_GFXTASK) bt_os_event(OS_EVENT_DP);
}

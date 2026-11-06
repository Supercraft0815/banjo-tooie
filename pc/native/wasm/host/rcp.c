// RCP tasks from the guest scheduler.
#include "guest.h"

#define M_GFXTASK 1
#define OS_EVENT_SP 4
#define OS_EVENT_DP 5

// shortcut: tasks complete without running; the F3DEX2 renderer and the audio
// microcode come next (task type at OSTask offset 0).
void w2c_env_rcp_task(struct w2c_env *env, u32 task) {
    u32 type = GW(task);
    (void)env;
    bt_os_event(OS_EVENT_SP);
    if (type == M_GFXTASK) bt_os_event(OS_EVENT_DP);
}

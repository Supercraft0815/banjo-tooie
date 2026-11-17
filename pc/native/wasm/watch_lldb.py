# lldb script: logs every write to a guest address with a short backtrace (finds who corrupts a
# variable or heap header in a deterministic BT_VCLOCK run). Guest addresses: build/ilp32/game.map.
#   WATCH=0x80d29160 WSIZE=2 [WLAST=12] BT_VCLOCK=1 BT_HEADLESS=1 ... \
#     lldb -b -o "command script import pc/native/wasm/watch_lldb.py" -- build/ilp32/bt_game baserom.us.z64
# Prints the last WLAST writes (value read big-endian) and the fault, if the run ends in one.
import lldb, os

def __lldb_init_module(dbg, _):
    dbg.SetAsync(False)
    target = dbg.GetSelectedTarget()
    target.BreakpointCreateByName('bt_trace_init')
    process = target.LaunchSimple(None, None, os.getcwd())
    frame = process.GetSelectedThread().GetFrameAtIndex(0)
    mem = frame.EvaluateExpression('(unsigned long long)bt_mem').GetValueAsUnsigned()
    addr = mem + int(os.environ['WATCH'], 16)
    size = int(os.environ.get('WSIZE', '2'))
    err = lldb.SBError()
    target.WatchAddress(addr, size, False, True, err)
    target.DeleteAllBreakpoints()
    last = int(os.environ.get('WLAST', '12'))
    log = []
    while True:
        process.Continue()
        if process.GetState() != lldb.eStateStopped:
            break
        th = next((t for t in process if t.GetStopReason() not in (lldb.eStopReasonNone, lldb.eStopReasonInvalid)), None)
        if th is None:
            break
        val = process.ReadUnsignedFromMemory(addr, size, err)
        val = int.from_bytes(val.to_bytes(size, 'little'), 'big')
        names = [f.GetFunctionName() or '?' for f in list(th)[:8]]
        names = [n.replace('w2c_bt_', '') for n in names if 'load' not in n and 'store' not in n]
        log.append('%s value=0x%x %s' % (th.GetStopDescription(60)[:22], val, ' < '.join(names[:6])))
        if th.GetStopReason() != lldb.eStopReasonWatchpoint:
            break
    print('\n'.join(log[-last:]))
    process.Kill()

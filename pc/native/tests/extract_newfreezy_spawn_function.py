from pathlib import Path
import sys

source = Path(sys.argv[1]).resolve()
out = Path(sys.argv[2]).resolve()
text = source.read_text()
needle = "Actor *chnewfreezy_entrypoint_0(Unk80132ED0 *marker, s32 x, s32 y, s32 z) {"
assert text.count(needle) == 1, source
start = text.index(needle)
open_brace = text.index("{", start)
depth = 0
state = "code"
i = open_brace
while i < len(text):
    ch = text[i]
    nxt = text[i + 1] if i + 1 < len(text) else ""
    if state == "code":
        if ch == "/" and nxt == "*": state = "comment"; i += 1
        elif ch == "/" and nxt == "/": state = "line_comment"; i += 1
        elif ch == '"': state = "string"
        elif ch == "'": state = "char"
        elif ch == "{": depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0: break
    elif state == "comment" and ch == "*" and nxt == "/": state = "code"; i += 1
    elif state == "line_comment" and ch == "\n": state = "code"
    elif state in ("string", "char"):
        if ch == "\\": i += 1
        elif (state == "string" and ch == '"') or (state == "char" and ch == "'"): state = "code"
    i += 1
assert depth == 0, source
body = text[start:i + 1]
line = text.count("\n", 0, start) + 1
preamble = '''#include "common.h"
Actor *func_80106790(Unk80132ED0 *);
void *func_80101080(void);
Actor *func_801084B0(BtIntPtr, Actor **);
u8 *func_800B27E0(u8 *);
struct anctrl_s;
void func_80103DFC(Actor *, f32 *);
u32 *func_80100074(Actor *, u32, u32);
void func_800DF41C(void *);
void *func_8008B4D4(void *);
void func_808011A8_chnewfreezy(f32, f32);
void func_80800974_chnewfreezy(Actor *, u8 *);
void func_80800AA4_chnewfreezy(Actor *, u8 *);
void func_80800BFC_chnewfreezy(Actor *, u8 *);
void func_80800D28_chnewfreezy(Actor *, BtIntPtr);
void func_80800E74_chnewfreezy(Actor *, u8 *, void *, s32);
f32 func_808012F8_chnewfreezy(Actor *);
'''
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text(preamble + f'#line {line} "src/overlays/ch/newfreezy.c"\n' + body + "\n")

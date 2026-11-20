from pathlib import Path
import sys

source = Path(sys.argv[1]).resolve()
out = Path(sys.argv[2]).resolve()
text = source.read_text()
needle = "void func_808016B4_chnewfreezy(Actor *arg0, s32 arg1) {"
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
        if ch == "/" and nxt == "*":
            state = "comment"
            i += 1
        elif ch == "/" and nxt == "/":
            state = "line_comment"
            i += 1
        elif ch == '"':
            state = "string"
        elif ch == "'":
            state = "char"
        elif ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                break
    elif state == "comment" and ch == "*" and nxt == "/":
        state = "code"
        i += 1
    elif state == "line_comment" and ch == "\n":
        state = "code"
    elif state in ("string", "char"):
        if ch == "\\":
            i += 1
        elif (state == "string" and ch == '"') or (state == "char" and ch == "'"):
            state = "code"
    i += 1
assert depth == 0, source
body = text[start:i + 1]
line = text.count("\n", 0, start) + 1
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text(f'#include "common.h"\n#line {line} "src/overlays/ch/newfreezy.c"\n' + body + "\n")

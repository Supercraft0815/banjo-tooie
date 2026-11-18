"""Add the renderer's guest memory observer to wasm2c scalar and bulk operations."""

def instrument(text):
    # Preserve the continuation of the generated multiline C macros.
    continuation = " " + chr(92) + "\n"
    anchors = (
        ('#define DEFINE_LOAD(name, t1', '#include "image_memory.h"\n#define DEFINE_LOAD(name, t1'),
        ('    t1 result; ', '    bt_image_scalar(addr, sizeof(t1));' + continuation + '    t1 result; '),
        ('    t1 wrapped = (t1)value; ', '    bt_image_scalar(addr, sizeof(t1));' + continuation + '    t1 wrapped = (t1)value; '),
        ('  memset(MEM_ADDR(mem, d, n), val, n);', '  bt_image_range(d, n);\n  memset(MEM_ADDR(mem, d, n), val, n);'),
        ('  memmove(MEM_ADDR(dest, dest_addr, n),', '  bt_image_range(src_addr, n);\n  bt_image_range(dest_addr, n);\n  memmove(MEM_ADDR(dest, dest_addr, n),'),
        ('  LOAD_DATA((*dest), dest_addr, src + src_addr, n);', '  bt_image_range(dest_addr, n);\n  LOAD_DATA((*dest), dest_addr, src + src_addr, n);'),
    )
    for before, after in anchors:
        if text.count(before) != 1:
            raise ValueError('unsupported wasm2c image-memory accessor: ' + before)
        text = text.replace(before, after)
    return text

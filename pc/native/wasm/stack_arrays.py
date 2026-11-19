#!/usr/bin/env python3
"""List adjacent same-type local arrays when only one is passed to a callee.

Review the callee's reads before joining arrays. Source order on its own does
not establish that the original N64 frame uses the arrays as one object.
"""
from collections import defaultdict
from multiprocessing import Pool
import sys

from offsets import ARGS, K, T, ci, game_files


def arrays_in_block(block):
    group = []
    shape = None
    for statement in block.get_children():
        declarations = list(statement.get_children()) if statement.kind == K.DECL_STMT else []
        for decl in declarations or [statement]:
            ty = decl.type.get_canonical()
            array = (decl.kind == K.VAR_DECL and ty.kind == T.CONSTANTARRAY and
                     decl.storage_class not in (ci.StorageClass.STATIC, ci.StorageClass.EXTERN))
            if not array or ty.spelling != shape:
                if len(group) > 1:
                    yield group
                group = []
            if array:
                shape = ty.spelling
                group.append(decl)
    if len(group) > 1:
        yield group


def passed_arrays(expr):
    if expr.kind == K.DECL_REF_EXPR:
        decl = expr.referenced
        if decl and decl.kind == K.VAR_DECL and decl.type.get_canonical().kind == T.CONSTANTARRAY:
            yield decl.hash
    elif expr.kind != K.CALL_EXPR:
        children = list(expr.get_children())
        # For &array[index], only the array operand supplies the address.
        for child in children[:1] if expr.kind == K.ARRAY_SUBSCRIPT_EXPR else children:
            yield from passed_arrays(child)


def address_operand(arg):
    # The N64 sources also pass addresses through integer parameters.
    while arg.type.get_canonical().kind not in (T.POINTER, T.CONSTANTARRAY):
        if arg.kind not in (K.CSTYLE_CAST_EXPR, K.UNEXPOSED_EXPR, K.PAREN_EXPR):
            return None
        children = [child for child in arg.get_children() if child.kind.is_expression()]
        if len(children) != 1:
            return None
        arg = children[0]
    return arg


def scan(path):
    unit = ci.Index.create().parse(path, ARGS)
    rows = []
    for fn in unit.cursor.get_children():
        if fn.kind != K.FUNCTION_DECL or not fn.is_definition() or str(fn.location.file) != path:
            continue
        groups = []
        calls = defaultdict(set)
        for node in fn.walk_preorder():
            if node.kind == K.COMPOUND_STMT:
                groups.extend(arrays_in_block(node))
            elif node.kind == K.CALL_EXPR:
                for arg in node.get_arguments():
                    address = address_operand(arg)
                    if address is not None:
                        for array in passed_arrays(address):
                            calls[array].add(node.spelling or '(indirect)')
        for group in groups:
            used = [decl for decl in group if decl.hash in calls]
            if len(used) == 1:
                rows.append((path, fn.spelling, str(group[0].location.line),
                             ','.join(decl.spelling for decl in group), used[0].spelling,
                             ','.join(sorted(calls[used[0].hash]))))
    return rows


if __name__ == '__main__':
    print('file\tfunction\tline\tadjacent_arrays\tpassed\tcallees')
    files = game_files(sys.argv[1:])
    with Pool() as pool:
        for rows in pool.imap(scan, files):
            for row in rows:
                print('\t'.join(row))

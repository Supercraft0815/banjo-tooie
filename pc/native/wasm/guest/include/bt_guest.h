// Guest (wasm32) side of the ILP32 port: functions the host executable provides.
#ifndef BT_GUEST_H
#define BT_GUEST_H
// Declares host_NAME, imported from the host as env.NAME.
#define BT_HOST(name) __attribute__((import_module("env"), import_name(#name))) host_##name
#endif

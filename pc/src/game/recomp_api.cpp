#include <cassert>

#include "recomp.h"
#include "librecomp/addresses.hpp"
#include "librecomp/game.hpp"

extern "C" void osPiReadIo_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t physical_addr = recomp::rom_base | ((uint32_t)ctx->r4 & 0x1FFFFFFF);
    assert(physical_addr > recomp::rom_base && "SRAM ReadIo unimplemented");
    recomp::do_rom_pio(rdram, ctx->r5, physical_addr);
    ctx->r2 = 0;
}

extern "C" void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 11; // PFS_ERR_DEVICE
}

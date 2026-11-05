#ifndef __TOOIE_GAME_H__
#define __TOOIE_GAME_H__

#include <cstdint>
#include <string>
#include "recomp.h"

namespace tooie {
    inline const std::u8string program_id = u8"BanjoTooieRecompiled";
    inline const std::string program_name = "Banjo-Tooie: Recompiled";

    void on_init(uint8_t* rdram, recomp_context* ctx);
    void init_config();
    void register_overlays();
}

#endif

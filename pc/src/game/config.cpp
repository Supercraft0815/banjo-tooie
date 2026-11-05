#include <filesystem>

#include "SDL2/SDL.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "util/file.h"
#include "tooie_game.h"

static void set_control_defaults() {
    using namespace recompinput;

    set_default_mapping_for_controller(GameInput::C_DOWN, {
        InputField::controller_analog(SDL_CONTROLLER_AXIS_RIGHTY, true),
        InputField::controller_digital(SDL_CONTROLLER_BUTTON_LEFTSHOULDER),
    });
    set_default_mapping_for_controller(GameInput::C_UP, {
        InputField::controller_analog(SDL_CONTROLLER_AXIS_RIGHTY, false),
        InputField::controller_digital(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER),
    });
    set_default_mapping_for_controller(GameInput::C_LEFT, {
        InputField::controller_analog(SDL_CONTROLLER_AXIS_RIGHTX, false),
        InputField::controller_digital(SDL_CONTROLLER_BUTTON_NORTH),
    });
    set_default_mapping_for_controller(GameInput::C_RIGHT, {
        InputField::controller_analog(SDL_CONTROLLER_AXIS_RIGHTX, true),
        InputField::controller_digital(SDL_CONTROLLER_BUTTON_EAST),
    });
    set_default_mapping_for_controller(GameInput::L, { InputField::controller_digital(SDL_CONTROLLER_BUTTON_RIGHTSTICK) });
}

void tooie::init_config() {
    std::filesystem::path recomp_dir = recompui::file::get_app_folder_path();
    if (!recomp_dir.empty()) {
        std::filesystem::create_directories(recomp_dir);
    }

    recompui::config::GeneralTabOptions general_options{};
    general_options.has_rumble_strength = true;
    general_options.has_gyro_sensitivity = false;
    general_options.has_mouse_sensitivity = false;
    recompui::config::create_general_tab(general_options);

    recompui::config::create_graphics_tab();

    set_control_defaults();
    recompui::config::create_controls_tab();

    recompui::config::create_sound_tab();
    recompui::config::create_mods_tab();
    recompui::config::finalize();
}

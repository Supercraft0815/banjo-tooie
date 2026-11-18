// Window-thread UI. Both game renderers present using this SDL OpenGL context.
#include "menu.h"
#include "glad/gl.h"
#include "imgui.h"
#include "imgui_internal.h" // FocusItem moves the gamepad cursor without activating a slider.
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl3.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <initializer_list>

static SDL_Window *window;
static SDL_GLContext context;
static bool opened, focus_content, focus_pages, on_pages = true;
static SDL_ThreadID owner;
static int page, port, capture = -1;
static const char *const pages[] = {"Grafik", "Audio", "Steuerung", "Verbesserungen", "Debug"};

static void mode_key(const SDL_DisplayMode *mode, char *key, size_t n) {
    // Stable across SDL enumeration order and display IDs. Keep logical and backing sizes distinct.
    std::snprintf(key, n, "%dx%d@%.3f/%.3f/%u", mode->w, mode->h,
                  mode->refresh_rate, mode->pixel_density, (unsigned)mode->format);
}

void bt_menu_display_changed() {
    const SDL_DisplayMode *selection = nullptr;
    int count = 0;
    auto **modes = SDL_GetFullscreenDisplayModes(SDL_GetDisplayForWindow(window), &count);
    for (int i = 0; i < count; i++) {
        char key[80]; mode_key(modes[i], key, sizeof key);
        if (!std::strcmp(key, bt_fullscreen_mode())) { selection = modes[i]; break; }
    }
    if (!SDL_SetWindowFullscreenMode(window, selection)) SDL_Log("Vollbildmodus: %s", SDL_GetError());
    SDL_free(modes);
}

static void mode_label(const SDL_DisplayMode *mode, char *text, size_t n) {
    if (!mode) { std::snprintf(text, n, "Desktop"); return; }
    std::snprintf(text, n, "%.0f × %.0f · %.2f Hz · %.1fx",
                  mode->w * mode->pixel_density, mode->h * mode->pixel_density,
                  mode->refresh_rate, mode->pixel_density);
}

static void fullscreen_modes() {
    char label[100];
    const auto *current = SDL_GetWindowFullscreenMode(window);
    mode_label(current, label, sizeof label);
    ImGui::TextUnformatted("Vollbildmodus");
    ImGui::SetNextItemWidth(-1);
    if (!ImGui::BeginCombo("##fullscreen_mode", label)) return;
    if (ImGui::Selectable("Desktop", !current) && SDL_SetWindowFullscreenMode(window, nullptr))
        bt_fullscreen_mode_set("");
    int count = 0;
    auto **modes = SDL_GetFullscreenDisplayModes(SDL_GetDisplayForWindow(window), &count);
    for (int i = 0; i < count; i++) {
        char key[80]; mode_key(modes[i], key, sizeof key);
        mode_label(modes[i], label, sizeof label);
        ImGui::PushID(i);
        if (ImGui::Selectable(label, !std::strcmp(key, bt_fullscreen_mode())) && SDL_SetWindowFullscreenMode(window, modes[i]))
            bt_fullscreen_mode_set(key);
        ImGui::PopID();
    }
    SDL_free(modes);
    ImGui::EndCombo();
}

int bt_menu_init(SDL_Window *win, SDL_GLContext gl) {
    window = win;
    context = gl;
    if (window && *bt_fullscreen_mode()) bt_menu_display_changed();
    return window && context;
}

static void shutdown() {
    if (SDL_GetCurrentThreadID() != owner || SDL_GL_GetCurrentContext() != context) return;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

static bool start() {
    if (ImGui::GetCurrentContext()) return true;
    owner = SDL_GetCurrentThreadID();
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    auto &io = ImGui::GetIO();
    io.IniFilename = nullptr; // settings.ini owns persistence; the overlay has no movable windows.
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
    if (!ImGui_ImplSDL3_InitForOpenGL(window, context)) { ImGui::DestroyContext(); return false; }
    if (!ImGui_ImplOpenGL3_Init("#version 330 core")) {
        ImGui_ImplSDL3_Shutdown(); ImGui::DestroyContext(); return false;
    }
    ImGui_ImplSDL3_SetGamepadMode(ImGui_ImplSDL3_GamepadMode_AutoAll);
    auto &style = ImGui::GetStyle();
    style.FontSizeBase = 17;
    style.WindowRounding = 10;
    style.FrameRounding = 4;
    style.WindowPadding = ImVec2(20, 18);
    style.FramePadding = ImVec2(9, 6);
    style.ItemSpacing = ImVec2(10, 7);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(.065f, .085f, .11f, .98f);
    style.Colors[ImGuiCol_Header] = ImVec4(.16f, .33f, .36f, 1);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(.22f, .43f, .46f, 1);
    style.Colors[ImGuiCol_HeaderActive] = style.Colors[ImGuiCol_HeaderHovered];
    style.Colors[ImGuiCol_NavCursor] = ImVec4(.98f, .77f, .30f, 1);
    atexit(shutdown);
    return true;
}

int bt_menu_open() { return opened; }

static void close_menu() {
    capture = -1;
    opened = false;
    ImGui::GetIO().AddFocusEvent(false);
    bt_input_capture(0);
}

int bt_menu_event(const SDL_Event *e) {
    if (!window) return 0;
    const bool key = e->type == SDL_EVENT_KEY_DOWN && !e->key.repeat;
    const bool pad = e->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN;
    if ((key && e->key.key == SDLK_F2) || (pad && e->gbutton.button == SDL_GAMEPAD_BUTTON_BACK)) {
        if (opened) close_menu();
        else if (start()) {
            bt_input_capture(1);
            ImGui::GetIO().AddFocusEvent(true);
            opened = true;
            focus_pages = true; on_pages = true;
        } else SDL_Log("Dear ImGui: %s", SDL_GetError());
        return 1;
    }
    if (!opened) return 0;
    const bool cancel = key && e->key.key == SDLK_ESCAPE;
    if (on_pages && ((key && e->key.key == SDLK_RIGHT) || (pad && e->gbutton.button == SDL_GAMEPAD_BUTTON_DPAD_RIGHT)))
        focus_content = true;
    if (!on_pages && pad && e->gbutton.button == SDL_GAMEPAD_BUTTON_EAST && capture < 0 &&
        !ImGui::IsPopupOpen(nullptr, ImGuiPopupFlags_AnyPopup)) focus_pages = true;
    if (capture >= 0 && (key || pad)) {
        if (!cancel) {
            char field[48], value[128];
            const char *name = bt_input_button(capture);
            if (key && port == 0) std::snprintf(field, sizeof field, "key.%s", name);
            else std::snprintf(field, sizeof field, "pad%d.%s", port + 1, name);
            if (key) std::snprintf(value, sizeof value, "%s%s", port ? "key:" : "", SDL_GetScancodeName(e->key.scancode));
            else std::snprintf(value, sizeof value, "%s", SDL_GetGamepadStringForButton((SDL_GamepadButton)e->gbutton.button));
            bt_settings_option(field, value);
        }
        capture = -1;
        return 1;
    }
    if (cancel) { close_menu(); return 1; }
    ImGui_ImplSDL3_ProcessEvent(e);
    // Keep device hotplug, focus and window events flowing to their owners.
    return (e->type >= SDL_EVENT_KEY_DOWN && e->type <= SDL_EVENT_KEYBOARD_REMOVED) ||
           (e->type >= SDL_EVENT_MOUSE_MOTION && e->type <= SDL_EVENT_MOUSE_WHEEL) ||
           (e->type >= SDL_EVENT_GAMEPAD_AXIS_MOTION && e->type <= SDL_EVENT_GAMEPAD_BUTTON_UP);
}

static void focus_first_item() {
    if (!focus_content) return;
    ImGui::SetWindowFocus();
    ImGui::FocusItem();
    ImGui::SetScrollY(0);
    focus_content = false; on_pages = false;
}

static void option(int id) {
    const auto *s = bt_setting_info(id);
    int v = bt_setting(id);
    ImGui::TextUnformatted(s->label);
    ImGui::PushID(id);
    ImGui::SetNextItemWidth(-1);
    if (s->names[0]) {
        int index = v - s->min, count = s->max - s->min + 1;
        if (id == BT_SET_MSAA) {
            GLint samples = 0; glGetIntegerv(GL_MAX_SAMPLES, &samples);
            while (count > 1 && (1 << (count - 1)) > samples) count--;
            if (index >= count) index = count - 1;
        }
        if (ImGui::Combo("##value", &index, s->names, count))
            bt_setting_set(id, index + s->min);
    } else if (ImGui::SliderInt("##value", &v, s->min, s->max, "%d / 10"))
        bt_setting_set(id, v);
    focus_first_item();
    ImGui::PopID();
}

static void controls() {
    static const char *const ports[] = {"Port 1", "Port 2", "Port 3", "Port 4"};
    ImGui::SetNextItemWidth(150);
    ImGui::Combo("Controller", &port, ports, BT_PORTS);
    focus_first_item();
    for (int i = 0; i < 2; i++) {
        int v = bt_input_stick_option(port, i);
        if (ImGui::SliderInt(i ? "Empfindlichkeit" : "Totzone", &v, i ? 25 : 0, i ? 200 : 90, "%d %%")) {
            char field[48], value[16];
            std::snprintf(field, sizeof field, "pad%d.%s", port + 1, i ? "sensitivity" : "deadzone");
            std::snprintf(value, sizeof value, "%d", v);
            bt_settings_option(field, value);
        }
    }
    ImGui::SeparatorText("N64-Belegung");
    if (capture >= 0) ImGui::TextWrapped("Taste oder Gamepad-Knopf für %s drücken. Esc bricht ab.", bt_input_button(capture));
    if (ImGui::BeginTable("bindings", 2, ImGuiTableFlags_SizingStretchProp)) {
        for (int i = 0; i < BT_BUTTONS; i++) {
            ImGui::TableNextColumn();
            ImGui::AlignTextToFramePadding();
            ImGui::TextUnformatted(bt_input_button(i));
            ImGui::TableNextColumn();
            char value[160];
            bt_input_binding_text(port, i, value, sizeof value);
            ImGui::PushID(i);
            char label[192];
            std::snprintf(label, sizeof label, "%s###binding", capture == i ? "Eingabe erwartet" : value);
            if (ImGui::Button(label, ImVec2(-1,0))) capture = i;
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
    option(BT_SET_RUMBLE);
}

void bt_menu_draw(const char *fps, unsigned repeated, unsigned skipped) {
    if (!opened) return;
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    const ImVec2 screen = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowSize(ImVec2(screen.x > 814 ? 790 : screen.x - 16, screen.y > 650 ? 626 : screen.y - 16));
    ImGui::SetNextWindowPos(ImVec2(screen.x * .5f, screen.y * .5f), ImGuiCond_Always, ImVec2(.5f, .5f));
    ImGui::Begin("Einstellungen", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
    ImGui::BeginChild("pages", ImVec2(158,0), ImGuiChildFlags_NavFlattened);
    for (int i = 0; i < 5; i++) {
        if (ImGui::Selectable(pages[i], page == i, 0, ImVec2(0, 28))) { page = i; capture = -1; on_pages = true; }
        if (page == i) {
            ImGui::SetItemDefaultFocus();
            if (focus_pages) { ImGui::SetWindowFocus(); ImGui::FocusItem(); focus_pages = false; on_pages = true; }
        }
    }
    ImGui::Spacing();
    if (ImGui::Button("Schließen")) close_menu();
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::BeginChild("content", ImVec2(0,0), ImGuiChildFlags_Borders | ImGuiChildFlags_NavFlattened);
    if (ImGui::IsWindowFocused()) on_pages = false;
    ImGui::PushID(page);
    ImGui::SeparatorText(pages[page]);
    switch (page) {
        case 0:
            for (int id : {BT_SET_RENDERER, BT_SET_GPU_WINDOW, BT_SET_SCALE, BT_SET_MSAA, BT_SET_WIDESCREEN, BT_SET_WINDOW_RES, BT_SET_BORDERLESS, BT_SET_FULLSCREEN, BT_SET_FILTER,
                           BT_SET_INTERP, BT_SET_SMOOTH, BT_SET_VSYNC}) option(id);
            fullscreen_modes();
            break;
        case 1: option(BT_SET_VOLUME); option(BT_SET_AUDIO_LATENCY); break;
        case 2: controls(); break;
        case 3:
            for (int id : {BT_SET_FPS, BT_SET_CAMERA, BT_SET_CAM_INVERT, BT_SET_LANGUAGE}) option(id);
            break;
        case 4: {
            option(BT_SET_SHOW_FPS); option(BT_SET_RENDER_STATS);
            if (bt_setting(BT_SET_RENDER_STATS)) ImGui::TextWrapped("%s · Wiederholungen %u · Ausgelassene Retraces %u",
                                                                    fps, repeated, skipped);
            ImGui::SeparatorText("Karten-Warp");
            static int map = 0xaf, exit_id = 1;
            ImGui::SliderInt("Karte (hex)", &map, 1, 0x1ff, "%03X", ImGuiSliderFlags_AlwaysClamp);
            ImGui::SliderInt("Ausgang", &exit_id, 0, 255, "%d", ImGuiSliderFlags_AlwaysClamp);
            if (ImGui::Button("Karte laden")) bt_input_warp(map, exit_id);
            break;
        }
    }
    ImGui::PopID();
    ImGui::EndChild();
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

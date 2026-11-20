get_filename_component(BT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)

find_package(Python3 3.11 REQUIRED COMPONENTS Interpreter)
find_package(ZLIB REQUIRED)
set(BT_OVERLAY_ALIASES "${CMAKE_CURRENT_BINARY_DIR}/generated/overlay_aliases.h")
add_custom_command(OUTPUT "${BT_OVERLAY_ALIASES}"
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/generate_overlay_aliases.py"
        "${BT_ROOT}/overlays.us.toml" "${BT_OVERLAY_ALIASES}"
    DEPENDS "${BT_ROOT}/overlays.us.toml" generate_overlay_aliases.py
    VERBATIM)
add_custom_target(bt_native_overlay_aliases DEPENDS "${BT_OVERLAY_ALIASES}")

add_library(bt_native_options INTERFACE)
add_dependencies(bt_native_options bt_native_overlay_aliases)
target_compile_features(bt_native_options INTERFACE c_std_11)
target_compile_definitions(bt_native_options INTERFACE
    BT_NATIVE=1 _LANGUAGE_C BUILD_VERSION=VERSION_J _FINALROM F3DEX_GBI_2)
if(CMAKE_C_BYTE_ORDER STREQUAL "LITTLE_ENDIAN")
    target_compile_definitions(bt_native_options INTERFACE BT_NATIVE_LITTLE_ENDIAN=1)
endif()
target_include_directories(bt_native_options INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include" "${BT_ROOT}/include"
    "${BT_ROOT}/lib/ultralib/include" "${BT_ROOT}/src")
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_options INTERFACE
        "SHELL:-include \"${BT_OVERLAY_ALIASES}\""
        "SHELL:-include \"${CMAKE_CURRENT_SOURCE_DIR}/include/native_prototypes.h\""
        -fno-builtin -fno-strict-aliasing -fwrapv
        -Werror=implicit-function-declaration -Werror=pointer-to-int-cast
        -Werror=int-to-pointer-cast -Werror=int-conversion
        -Werror=incompatible-pointer-types)
endif()
if(MSVC)
    target_compile_options(bt_native_options INTERFACE "/FI${BT_OVERLAY_ALIASES}"
        "/FI${CMAKE_CURRENT_SOURCE_DIR}/include/native_prototypes.h")
endif()
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    target_compile_options(bt_native_options INTERFACE -Wno-deprecated-non-prototype)
endif()

# The point-light tests also build the light section independently.
set_source_files_properties("${BT_ROOT}/src/core2/1EA1DA0_lights.inc" PROPERTIES LANGUAGE C)
set_source_files_properties("${BT_ROOT}/src/core2/1E8A670_vertices.inc" PROPERTIES LANGUAGE C)

# Only exercised source modules belong in the runnable native core.
set_source_files_properties("${BT_ROOT}/src/core2/1EC3810_collision.inc" PROPERTIES LANGUAGE C)
set_source_files_properties("${BT_ROOT}/src/core2/1EC3810_prop_hooks.inc" PROPERTIES LANGUAGE C)
set_source_files_properties("${BT_ROOT}/src/core2/1E8DFA0_reflection_height.inc" "${BT_ROOT}/src/core2/1EC1380_culling.inc" PROPERTIES LANGUAGE C)
set_source_files_properties("${BT_ROOT}/src/core2/1ED8C80_metadata.inc" PROPERTIES LANGUAGE C)
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    set_source_files_properties(matrix.c skinning.c skeleton.c quaternion.c "${BT_ROOT}/src/core2/1E95F80.c" "${BT_ROOT}/src/core2/1EAC200.c" "${BT_ROOT}/src/core1/1E2B7B0.c" "${BT_ROOT}/src/core2/1ECBCC0.c" "${BT_ROOT}/src/core2/1EB5E70_geometry.inc" "${BT_ROOT}/src/core2/1EA3AA0.c" "${BT_ROOT}/src/core2/1EBCFC0.c" "${BT_ROOT}/src/core2/1EE8860.c" "${BT_ROOT}/src/core2/1E875C0.c" "${BT_ROOT}/src/core2/1E8CC00.c" "${BT_ROOT}/src/core2/1EE7960.c" "${BT_ROOT}/src/core2/1EE8100.c" "${BT_ROOT}/src/core2/1EE8B70.c" "${BT_ROOT}/src/overlays/tr/angler.c" PROPERTIES COMPILE_OPTIONS "-ffp-contract=off")
elseif(MSVC)
    set_source_files_properties(matrix.c skinning.c skeleton.c quaternion.c "${BT_ROOT}/src/core2/1E95F80.c" "${BT_ROOT}/src/core2/1EAC200.c" "${BT_ROOT}/src/core1/1E2B7B0.c" "${BT_ROOT}/src/core2/1ECBCC0.c" "${BT_ROOT}/src/core2/1EB5E70_geometry.inc" "${BT_ROOT}/src/core2/1EA3AA0.c" "${BT_ROOT}/src/core2/1EBCFC0.c" "${BT_ROOT}/src/core2/1EE8860.c" "${BT_ROOT}/src/core2/1E875C0.c" "${BT_ROOT}/src/core2/1E8CC00.c" "${BT_ROOT}/src/core2/1EE7960.c" "${BT_ROOT}/src/core2/1EE8100.c" "${BT_ROOT}/src/core2/1EE8B70.c" "${BT_ROOT}/src/overlays/tr/angler.c" PROPERTIES COMPILE_OPTIONS "/fp:strict")
endif()
set_source_files_properties("${BT_ROOT}/src/core2/1EB5E70_reset.inc" "${BT_ROOT}/src/core2/1EB5E70_state.inc" PROPERTIES LANGUAGE C)
set_source_files_properties("${BT_ROOT}/src/core2/1EB5E70_geometry.inc" "${BT_ROOT}/src/core2/1EA3AA0.c" PROPERTIES LANGUAGE C)
add_library(bt_native_core STATIC
    "${BT_ROOT}/src/core2/inflate_rodata.c"
    "${BT_ROOT}/src/core2/model_materials.c"
    "${BT_ROOT}/src/core2/player_form_data.c"
    "${BT_ROOT}/src/core2/actor_item_types.c"
    "${BT_ROOT}/src/core2/1EFC920.c"
    "${BT_ROOT}/src/core2/dialog_render_data.c"
    "${BT_ROOT}/src/core2/player_motion_data.c"
    "${BT_ROOT}/src/core2/face_culling_data.c"
    "${BT_ROOT}/src/core2/particle_draw_data.c"
    "${BT_ROOT}/src/core1/trig_constants.c"
    "${BT_ROOT}/src/core1/trig_tables.c"
    "${BT_ROOT}/src/core2/1EB5E70_geometry.inc"
    "${BT_ROOT}/src/core2/1EA3AA0.c"
    "${BT_ROOT}/src/core2/1EBCFC0.c"
    "${BT_ROOT}/src/core2/1EAC200.c"
    "${BT_ROOT}/src/core2/1E95F80.c"
    "${BT_ROOT}/src/core2/1E8DFA0_reflection_height.inc"
    "${BT_ROOT}/src/core2/1EC1380_culling.inc"
    "${BT_ROOT}/src/core2/1EE8860.c"
    "${BT_ROOT}/src/core2/1EB5E70_reset.inc"
    "${BT_ROOT}/src/core2/1EB5E70_state.inc"
    "${BT_ROOT}/src/core2/1E8CC00.c"
    "${BT_ROOT}/src/core2/1EE7960.c"
    "${BT_ROOT}/src/core2/1EE8100.c"
    "${BT_ROOT}/src/core2/1EE8B70.c"
    "${BT_ROOT}/src/overlays/tr/angler.c"
    "${BT_ROOT}/src/overlays/db/tex.c"
    textures.c
    skinning.c fixed_matrix.c geometry_data.c graphics_memory.c model_modes.c
    skeleton.c
    "${BT_ROOT}/src/core2/1E875C0.c"
    "${BT_ROOT}/src/core2/1EBA250.c"
    "${BT_ROOT}/src/core2/1ECBCC0.c"
    "${BT_ROOT}/src/core1/1E2B7B0.c"
    "${BT_ROOT}/src/overlays/db/anim.c"
    "${BT_ROOT}/src/core2/1EDA900.c"
    "${BT_ROOT}/src/core2/1ED8C80_metadata.inc"
    "${BT_ROOT}/src/core2/1ED8C80.c"
    "${BT_ROOT}/src/core2/1EDDA60.c"
    "${BT_ROOT}/src/core2/1EDB4D0.c"
    "${BT_ROOT}/src/core2/1ED9D70.c"
    "${BT_ROOT}/src/core2/1EDCA30.c"
    "${BT_ROOT}/src/overlays/gl/packvtx.c"
    "${BT_ROOT}/src/core2/1EA6B20.c"
    "${BT_ROOT}/src/core2/1EA5130.c"
    "${BT_ROOT}/src/core2/1EC3810_collision.inc"
    "${BT_ROOT}/src/core2/1EC3810_prop_hooks.inc"
    "${BT_ROOT}/src/overlays/gs/proplookup.c"
    "${BT_ROOT}/src/overlays/su/baddie/customhits.c"
    "${BT_ROOT}/src/core1/memory.c"
    "${BT_ROOT}/src/core2/vector.c"
    "${BT_ROOT}/src/core2/freelist.c"
    "${BT_ROOT}/src/core2/baflag.c"
    "${BT_ROOT}/src/core2/1E965B0.c"
    "${BT_ROOT}/src/core2/1E8BFE0.c"
    "${BT_ROOT}/src/core2/1EB57A0.c"
    "${BT_ROOT}/src/core2/1E97EF0.c"
    "${BT_ROOT}/src/core2/1E83B90.c"
    "${BT_ROOT}/src/core1/mlmtx.c"
    matrix.c
    "${BT_ROOT}/src/overlays/gc/mapDll.c"
    "${BT_ROOT}/src/overlays/gc/mapsects.c"
    "${BT_ROOT}/src/overlays/gc/mapsects/_lagoontop.c"
    "${BT_ROOT}/src/overlays/gc/mapsects/_lagoonmid.c"
    "${BT_ROOT}/src/overlays/gc/mapsects/_lagoonbot.c"
    "${BT_ROOT}/src/core2/1EC9740.c"
    "${BT_ROOT}/src/core2/1EA0210.c"
    "${BT_ROOT}/src/overlays/gl/zone.c"
    "${BT_ROOT}/src/overlays/db/zone.c"
    "${BT_ROOT}/src/core2/1E8A670_vertices.inc"
    "${BT_ROOT}/src/overlays/db/palette.c"
    "${BT_ROOT}/src/core2/bakey.c"
    "${BT_ROOT}/src/core2/1EC8070.c"
    "${BT_ROOT}/src/core2/1ECA640.c"
    "${BT_ROOT}/src/core2/anctrl.c"
    "${BT_ROOT}/src/core2/1E64F00.c"
    "${BT_ROOT}/src/core2/1EB93C0.c"
    "${BT_ROOT}/src/core2/1EB9940.c"
    "${BT_ROOT}/src/core2/1EAED30.c"
    "${BT_ROOT}/src/core2/1EAF950.c"
    "${BT_ROOT}/src/core2/1EA1270.c"
    "${BT_ROOT}/src/core2/1ECB0F0.c"
    "${BT_ROOT}/src/overlays/ml/spline.c"
    "${BT_ROOT}/src/overlays/gl/spline/Dll.c"
    "${BT_ROOT}/src/overlays/gl/spline/find.c"
    "${BT_ROOT}/src/overlays/gl/spline/node.c"
    "${BT_ROOT}/src/overlays/gl/spline/funcs.c"
    "${BT_ROOT}/src/overlays/gl/spline/cs.c"
    "${BT_ROOT}/src/core2/1EB52C0.c"
    "${BT_ROOT}/src/core2/1EB2EF0.c"
    "${BT_ROOT}/src/core2/1EDED00.c"
    "${BT_ROOT}/src/core2/1EDFED0.c"
    "${BT_ROOT}/src/core2/1EDC7B0.c"
    "${BT_ROOT}/src/core2/1EE1510.c"
    "${BT_ROOT}/src/core2/1EC4CC0.c"
    "${BT_ROOT}/src/core2/1E8D2C0.c"
    "${BT_ROOT}/src/core2/1EA5180.c"
    "${BT_ROOT}/src/overlays/gc/boundDll.c"
    "${BT_ROOT}/src/core2/1EC2FD0.c"
    "${BT_ROOT}/src/core2/1E96E60.c"
    "${BT_ROOT}/src/core2/1E7F4D0.c"
    "${BT_ROOT}/src/overlays/ch/bad/dieDll.c"
    "${BT_ROOT}/src/overlays/ch/bad/diesetup.c"
    "${BT_ROOT}/src/overlays/ba/drone.c"
    "${BT_ROOT}/src/overlays/gl/dbDll.c"
    "${BT_ROOT}/src/overlays/bs/drone.c"
    "${BT_ROOT}/src/overlays/bs/drone/bubbled.c"
    "${BT_ROOT}/src/core2/1EA1DA0_lights.inc"
    "${BT_ROOT}/src/overlays/gc/lightsDll.c"
    "${BT_ROOT}/src/overlays/gs/worldDll.c"
    "${BT_ROOT}/src/core2/1E7EE40.c"
    "${BT_ROOT}/src/overlays/ca/dbmgrDll.c"
    "${BT_ROOT}/src/overlays/ca/dbfunc.c"
    "${BT_ROOT}/src/overlays/ca/dbio.c"
    "${BT_ROOT}/src/overlays/gc/cubeDll.c"
    "${BT_ROOT}/src/overlays/gs/propsDll.c"
    "${BT_ROOT}/src/overlays/gs/propmarker.c"
    "${BT_ROOT}/src/overlays/gs/maker.c"
    platform/rdram.c platform/trig.c memory.c input.c quaternion.c animation_resource.c assets.c wasm/host/mod_assets.c cic.c spline.c model.c)
target_link_libraries(bt_native_core PUBLIC bt_native_options ZLIB::ZLIB)
if(UNIX AND NOT APPLE)
    target_link_libraries(bt_native_core PUBLIC m)
endif()
target_compile_options(bt_native_core PRIVATE -ffunction-sections -fdata-sections)

add_executable(bt_native_core_test tests/core.c)
target_link_libraries(bt_native_core_test PRIVATE bt_native_core)
add_test(NAME native_core COMMAND bt_native_core_test)

add_executable(bt_native_sfx_owner_test tests/sfx_owner.c
    "${BT_ROOT}/src/core2/1E9A960.c" "${BT_ROOT}/src/core2/1EB5C70.c"
    "${BT_ROOT}/src/core1/1E36640.c" "${BT_ROOT}/src/core1/1E38100.c"
    "${BT_ROOT}/src/core1/1E38970.c" "${BT_ROOT}/src/core1/1E3DEF0.c")
target_link_libraries(bt_native_sfx_owner_test PRIVATE bt_native_options)
set_source_files_properties("${BT_ROOT}/src/core2/1E9A960.c" PROPERTIES COMPILE_OPTIONS "-Wno-error=int-conversion;-Wno-error=incompatible-pointer-types;-Wno-error=implicit-function-declaration")
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_sfx_owner_test PRIVATE -ffunction-sections -fdata-sections -Wno-error=int-conversion -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration)
    if(APPLE)
        target_link_options(bt_native_sfx_owner_test PRIVATE -Wl,-dead_strip)
    else()
        target_link_options(bt_native_sfx_owner_test PRIVATE -Wl,--gc-sections)
    endif()
elseif(MSVC)
    target_link_options(bt_native_sfx_owner_test PRIVATE /OPT:REF)
endif()
add_test(NAME native_sfx_owner COMMAND bt_native_sfx_owner_test)

add_test(NAME native_overlay_aliases
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tests/overlay_aliases.py"
        "${CMAKE_C_COMPILER}" "${BT_OVERLAY_ALIASES}")

add_executable(bt_native_level_test tests/level.c "${BT_ROOT}/src/overlays/gc/level.c" "${BT_ROOT}/src/core2/1E78170.c")
target_link_libraries(bt_native_level_test PRIVATE bt_native_options)
# Keep this unit test limited to the level query; the full game target must resolve everything.
target_compile_options(bt_native_level_test PRIVATE -ffunction-sections -fdata-sections)
if(APPLE)
    target_link_options(bt_native_level_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_level_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_level_query COMMAND bt_native_level_test)

add_executable(bt_native_player_death_test tests/player_death.c "${BT_ROOT}/src/core2/1E6B700.c")
target_link_libraries(bt_native_player_death_test PRIVATE bt_native_options)
add_test(NAME native_player_death COMMAND bt_native_player_death_test)

add_executable(bt_native_taxi_test tests/taxi.c "${BT_ROOT}/src/core2/1EA4CD0.c")
target_link_libraries(bt_native_taxi_test PRIVATE bt_native_options)
add_test(NAME native_taxi_owner COMMAND bt_native_taxi_test)

add_executable(bt_native_input_test tests/input.c)
target_link_libraries(bt_native_input_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_input_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_input_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_input COMMAND bt_native_input_test)

add_executable(bt_native_optionstate_lp64_test tests/optionstate_lp64.c tests/digger_option_layout.c)
target_link_libraries(bt_native_optionstate_lp64_test PRIVATE bt_native_options)
target_include_directories(bt_native_optionstate_lp64_test PRIVATE "${BT_ROOT}" "${BT_ROOT}/lib/ultralib/include")
target_compile_options(bt_native_optionstate_lp64_test PRIVATE -ffunction-sections -fdata-sections)
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_optionstate_lp64_test PRIVATE "SHELL:-include \"${CMAKE_CURRENT_SOURCE_DIR}/include/PR/ultratypes.h\"")
endif()
if(APPLE)
    target_link_options(bt_native_optionstate_lp64_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_optionstate_lp64_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_optionstate_lp64 COMMAND bt_native_optionstate_lp64_test)

add_executable(bt_native_digger_option_runtime_test tests/digger_option_runtime.c "${BT_ROOT}/src/overlays/ch/digger/boss.c")
add_dependencies(bt_native_digger_option_runtime_test bt_native_overlay_aliases)
target_compile_features(bt_native_digger_option_runtime_test PRIVATE c_std_11)
target_compile_definitions(bt_native_digger_option_runtime_test PRIVATE BT_NATIVE=1 BT_NATIVE_LITTLE_ENDIAN=1 _LANGUAGE_C BUILD_VERSION=VERSION_J _FINALROM F3DEX_GBI_2)
target_include_directories(bt_native_digger_option_runtime_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include" "${BT_ROOT}/include"
    "${BT_ROOT}/lib/ultralib/include" "${BT_ROOT}/src")
target_compile_options(bt_native_digger_option_runtime_test PRIVATE
    -ffunction-sections -fdata-sections -fno-builtin -fno-strict-aliasing -fwrapv
    "SHELL:-include \"${BT_OVERLAY_ALIASES}\""
    "SHELL:-include \"${CMAKE_CURRENT_SOURCE_DIR}/include/PR/ultratypes.h\""
    "SHELL:-include \"${CMAKE_CURRENT_SOURCE_DIR}/include/native_prototypes.h\""
    -Wno-implicit-function-declaration -Wno-deprecated-non-prototype -Wno-int-conversion -Wno-incompatible-pointer-types)
if(APPLE)
    target_link_options(bt_native_digger_option_runtime_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_digger_option_runtime_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_digger_option_runtime COMMAND bt_native_digger_option_runtime_test)

set(BT_DRONE_FIXTURE "${CMAKE_CURRENT_BINARY_DIR}/generated/drone_fixture.c")
add_custom_command(OUTPUT "${BT_DRONE_FIXTURE}"
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tests/drone_fixture.py"
        "${BT_ROOT}/decompressed.us.z64" "${BT_ROOT}/syscall_symbol_addrs.us.txt" "${BT_DRONE_FIXTURE}"
    DEPENDS tests/drone_fixture.py "${BT_ROOT}/decompressed.us.z64" "${BT_ROOT}/syscall_symbol_addrs.us.txt"
    VERBATIM)
add_executable(bt_native_drone_test "${BT_DRONE_FIXTURE}")
target_link_libraries(bt_native_drone_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_drone_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_drone_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_drone_dispatch COMMAND bt_native_drone_test)

add_executable(bt_native_drone_component_test tests/drone.c)
target_link_libraries(bt_native_drone_component_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_drone_component_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_drone_component_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_drone_component COMMAND bt_native_drone_component_test)

add_executable(bt_native_bubbled_test tests/bubbled.c)
target_link_libraries(bt_native_bubbled_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_bubbled_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_bubbled_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_bubbled_states COMMAND bt_native_bubbled_test)

add_executable(bt_native_anctrl_test tests/anctrl.c)
target_link_libraries(bt_native_anctrl_test PRIVATE bt_native_core)
add_test(NAME native_animation_controller COMMAND bt_native_anctrl_test)

add_executable(bt_native_bones_test tests/bones.c)
target_link_libraries(bt_native_bones_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_bones_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_bones_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_bone_poses COMMAND bt_native_bones_test)

add_executable(bt_native_animation_test tests/animation.c)
target_link_libraries(bt_native_animation_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_animation_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_animation_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_animation_pipeline COMMAND bt_native_animation_test)

add_executable(bt_native_animation_resource_test tests/animation_resource.c)
target_link_libraries(bt_native_animation_resource_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_animation_resource_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_animation_resource_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_animation_resources COMMAND bt_native_animation_resource_test)

add_executable(bt_native_assets_test tests/assets.c)
target_link_libraries(bt_native_assets_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_assets_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_assets_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_assets COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/assets_fixture.py" "$<TARGET_FILE:bt_native_assets_test>")

add_executable(bt_native_drill_field_test tests/drill_field.c
    "${BT_ROOT}/src/overlays/ch/fantasy/drillfield.c")
target_link_libraries(bt_native_drill_field_test PRIVATE bt_native_options)
target_compile_options(bt_native_drill_field_test PRIVATE -ffunction-sections -fdata-sections)
if(APPLE)
    target_link_options(bt_native_drill_field_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_drill_field_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_drill_field COMMAND bt_native_drill_field_test)

add_executable(bt_native_asset_decoder_test tests/asset_decoder.c memory.c platform/rdram.c
    "${BT_ROOT}/src/core2/1EBE020.c")
target_link_libraries(bt_native_asset_decoder_test PRIVATE bt_native_options)
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_asset_decoder_test PRIVATE -ffunction-sections -fdata-sections)
endif()
if(APPLE)
    target_link_options(bt_native_asset_decoder_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_asset_decoder_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_asset_decoder COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/asset_decoder_fixture.py" "$<TARGET_FILE:bt_native_asset_decoder_test>")

add_executable(bt_native_database_test tests/database.c)
target_link_libraries(bt_native_database_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_database_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_database_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_database COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/database_fixture.py" "$<TARGET_FILE:bt_native_database_test>")

add_executable(bt_native_asset_cache_test tests/asset_cache.c)
target_link_libraries(bt_native_asset_cache_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_asset_cache_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_asset_cache_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_asset_cache COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/asset_cache_fixture.py" "$<TARGET_FILE:bt_native_asset_cache_test>")

add_executable(bt_native_spline_test tests/spline.c)
target_link_libraries(bt_native_spline_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_spline_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_spline_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_spline COMMAND bt_native_spline_test)

add_executable(bt_native_path_test tests/path.c tests/marker_world.c)
target_link_libraries(bt_native_path_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_path_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_path_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_path COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/path_fixture.py" "$<TARGET_FILE:bt_native_path_test>")

add_executable(bt_native_path_motion_test tests/path_motion.c tests/marker_world.c)
target_link_libraries(bt_native_path_motion_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_path_motion_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_path_motion_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_path_motion COMMAND bt_native_path_motion_test)

add_executable(bt_native_actor_items_test tests/actor_items.c)
target_link_libraries(bt_native_actor_items_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_actor_items_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actor_items_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actor_items COMMAND bt_native_actor_items_test)

add_executable(bt_native_ballcontroller_markers_test
    tests/ballcontroller_markers.c
    ${CMAKE_SOURCE_DIR}/../src/overlays/ch/collballcontrol.c
    ${CMAKE_SOURCE_DIR}/../src/overlays/ch/stoneballcontrol.c)
target_link_libraries(bt_native_ballcontroller_markers_test PRIVATE bt_native_core)
target_compile_options(bt_native_ballcontroller_markers_test PRIVATE
    -Wno-error=incompatible-pointer-types
    -Wno-error=int-conversion
    -Wno-error=pointer-to-int-cast
    -Wno-error=int-to-pointer-cast)
if(APPLE)
    target_link_options(bt_native_ballcontroller_markers_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_ballcontroller_markers_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_ballcontroller_markers COMMAND bt_native_ballcontroller_markers_test)
set_source_files_properties(
    ${CMAKE_SOURCE_DIR}/../src/overlays/ch/collballcontrol.c
    ${CMAKE_SOURCE_DIR}/../src/overlays/ch/stoneballcontrol.c
    PROPERTIES COMPILE_OPTIONS "-Wno-error;-Wno-incompatible-pointer-types;-Wno-int-conversion;-Wno-pointer-to-int-cast;-Wno-int-to-pointer-cast;-Wno-implicit-function-declaration")

add_executable(bt_native_actors_test tests/actors.c)
target_link_libraries(bt_native_actors_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_actors_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actors_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actors COMMAND bt_native_actors_test)

add_executable(bt_native_actor_factory_test tests/actor_factory.c tests/marker_world.c)
target_link_libraries(bt_native_actor_factory_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_actor_factory_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actor_factory_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actor_factory COMMAND bt_native_actor_factory_test)

add_executable(bt_native_spawn_queue_test tests/spawn_queue.c tests/marker_world.c)
target_link_libraries(bt_native_spawn_queue_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_spawn_queue_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_spawn_queue_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_spawn_queue COMMAND bt_native_spawn_queue_test)

add_executable(bt_native_markers_test tests/markers.c tests/marker_world.c)
target_link_libraries(bt_native_markers_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_markers_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_markers_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_markers COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/asset_cache_fixture.py" "$<TARGET_FILE:bt_native_markers_test>")

add_executable(bt_native_block_pool_test tests/block_pool.c)
target_link_libraries(bt_native_block_pool_test PRIVATE bt_native_core)
add_test(NAME native_block_pool COMMAND bt_native_block_pool_test)

add_executable(bt_native_bounds_test tests/bounds.c)
target_link_libraries(bt_native_bounds_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_bounds_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_bounds_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_bounds COMMAND bt_native_bounds_test)

add_executable(bt_native_inventory_counters_test tests/inventory_counters.c "${BT_ROOT}/src/core2/1EAAD80.c")
target_compile_options(bt_native_inventory_counters_test PRIVATE -ffunction-sections -fdata-sections)
target_link_libraries(bt_native_inventory_counters_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_inventory_counters_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_inventory_counters_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_inventory_counters COMMAND bt_native_inventory_counters_test)

add_executable(bt_native_particle_registry_test tests/particle_registry.c
    "${BT_ROOT}/src/core2/1E8DFA0.c" "${BT_ROOT}/src/core2/1E93440.c")
add_executable(bt_native_transition_registry_test tests/transition_registry.c "${BT_ROOT}/src/core2/1EA1DA0.c")
add_executable(bt_native_core1_sound_data_test tests/core1_sound_data.c
    "${BT_ROOT}/src/core1/1E389F0.c" "${BT_ROOT}/src/core1/1E38970.c"
    "${BT_ROOT}/src/core1/1E3DEF0.c")
target_compile_options(bt_native_core1_sound_data_test PRIVATE -ffunction-sections -fdata-sections)
target_link_libraries(bt_native_core1_sound_data_test PRIVATE bt_native_options)
if(APPLE)
    target_link_options(bt_native_core1_sound_data_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_core1_sound_data_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_core1_sound_data COMMAND bt_native_core1_sound_data_test)

add_executable(bt_native_timer_queue_test tests/timer_queue.c "${BT_ROOT}/src/core2/1EA1DA0.c")
target_link_libraries(bt_native_particle_registry_test PRIVATE bt_native_options)
target_link_libraries(bt_native_transition_registry_test PRIVATE bt_native_options)
target_link_libraries(bt_native_timer_queue_test PRIVATE bt_native_core)
add_executable(bt_native_gameselect_roles_test tests/gameselect_role_layout.c
    "${BT_ROOT}/src/overlays/ch/gameselect.c")
target_include_directories(bt_native_gameselect_roles_test PRIVATE "${BT_ROOT}/src/overlays/ch")
target_link_libraries(bt_native_gameselect_roles_test PRIVATE bt_native_options)
set_source_files_properties("${BT_ROOT}/src/core2/player_contact_vectors.inc" PROPERTIES LANGUAGE C)
add_executable(bt_native_player_vectors_test tests/player_vectors.c "${BT_ROOT}/src/core2/player_contact_vectors.inc" "${BT_ROOT}/src/core2/1E75920.c")
target_link_libraries(bt_native_player_vectors_test PRIVATE bt_native_core)
set_source_files_properties("${BT_ROOT}/src/overlays/ch/honeyb_hud.inc" PROPERTIES LANGUAGE C)
add_executable(bt_native_hud_draw_test tests/hud_draw.c
    "${BT_ROOT}/src/overlays/sc/infobar.c" "${BT_ROOT}/src/overlays/sc/custom.c"
    "${BT_ROOT}/src/overlays/sc/custom_big.c" "${BT_ROOT}/src/overlays/sc/custom_banjo.c"
    "${BT_ROOT}/src/overlays/ch/honeyb_hud.inc" "${BT_ROOT}/src/core2/1EC0300.c"
    "${BT_ROOT}/src/core2/1EB45C0.c")
target_link_libraries(bt_native_hud_draw_test PRIVATE bt_native_options)
add_executable(bt_native_fxstep_test tests/fxstep.c
    "${BT_ROOT}/src/core2/1E7BFA0.c" "${BT_ROOT}/src/overlays/fx/step.c")
target_link_libraries(bt_native_fxstep_test PRIVATE bt_native_options)
add_executable(bt_native_dialog_state_test tests/dialog_state.c
    "${BT_ROOT}/src/overlays/gc/dialog/Dll.c" "${BT_ROOT}/src/core2/1E99980.c")
target_link_libraries(bt_native_dialog_state_test PRIVATE bt_native_options)
add_executable(bt_native_dialog_open_test tests/dialog_open.c
    "${BT_ROOT}/src/overlays/gc/dialog/Dll.c" "${BT_ROOT}/src/overlays/gc/dialog/exec.c")
target_link_libraries(bt_native_dialog_open_test PRIVATE bt_native_options)
add_executable(bt_native_deflect_test tests/deflect.c "${BT_ROOT}/src/overlays/su/deflect.c")
target_link_libraries(bt_native_deflect_test PRIVATE bt_native_options)
foreach(registry_test IN ITEMS particle_registry transition_registry timer_queue gameselect_roles player_vectors hud_draw fxstep dialog_state dialog_open deflect)
    if(MSVC)
        target_compile_options(bt_native_${registry_test}_test PRIVATE /Gy /Gw)
        target_link_options(bt_native_${registry_test}_test PRIVATE /OPT:REF)
    elseif(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(bt_native_${registry_test}_test PRIVATE -ffunction-sections -fdata-sections)
    endif()
    if(APPLE)
        target_link_options(bt_native_${registry_test}_test PRIVATE -Wl,-dead_strip)
    elseif(NOT MSVC AND CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        target_link_options(bt_native_${registry_test}_test PRIVATE -Wl,--gc-sections)
    endif()
    add_test(NAME native_${registry_test} COMMAND bt_native_${registry_test}_test)
endforeach()

if(CMAKE_C_COMPILER_ID MATCHES "Clang" AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_test(NAME native_player_component_slots COMMAND "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/player_slots_n3.py"
        --cc "${CMAKE_C_COMPILER}" --aliases "${BT_OVERLAY_ALIASES}"
        $<$<BOOL:${BT_NATIVE_SANITIZERS}>:--sanitize>
        COMMAND_EXPAND_LISTS)
endif()

add_executable(bt_native_save_slots_test tests/save_slots.c "${BT_ROOT}/src/overlays/gl/savegame.c")
target_link_libraries(bt_native_save_slots_test PRIVATE bt_native_core)
add_test(NAME native_save_slots COMMAND bt_native_save_slots_test)

add_executable(bt_native_gamestore_test tests/gamestore.c "${BT_ROOT}/src/overlays/gl/gamestore.c")
target_link_libraries(bt_native_gamestore_test PRIVATE bt_native_options)
add_test(NAME native_gamestore COMMAND bt_native_gamestore_test)

add_executable(bt_native_world_props_test tests/world_props.c tests/marker_world.c)
target_link_libraries(bt_native_world_props_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_world_props_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_world_props_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_world_props COMMAND bt_native_world_props_test)

add_executable(bt_native_world_grid_test tests/world_grid.c)
target_link_libraries(bt_native_world_grid_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_world_grid_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_world_grid_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_world_grid COMMAND bt_native_world_grid_test)

option(BT_NATIVE_SANITIZERS "Check native memory access and undefined behavior" OFF)
if(BT_NATIVE_SANITIZERS)
    if(NOT CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        message(FATAL_ERROR "BT_NATIVE_SANITIZERS requires Clang or GCC")
    endif()
    target_compile_options(bt_native_options INTERFACE
        -fsanitize=address,undefined -fno-sanitize-recover=undefined -fno-omit-frame-pointer)
    target_link_options(bt_native_options INTERFACE -fsanitize=address,undefined)
endif()

# This target deliberately fails on unported code; it never drops failed files.
file(GLOB_RECURSE BT_GAME_C CONFIGURE_DEPENDS "${BT_ROOT}/src/*.c")
add_library(bt_native_all_sources OBJECT EXCLUDE_FROM_ALL ${BT_GAME_C})
target_link_libraries(bt_native_all_sources PRIVATE bt_native_options)
message(STATUS "Native source port: core tests available; full game is not yet linked")

add_executable(bt_native_gsfile_test tests/gsfile.c)
target_link_libraries(bt_native_gsfile_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_gsfile_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_gsfile_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_gsfile COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/gsfile_fixture.py" "$<TARGET_FILE:bt_native_gsfile_test>")

add_executable(bt_native_cube_test tests/cube.c tests/map_dependencies.c)
target_link_libraries(bt_native_cube_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_cube_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_cube_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_cube COMMAND bt_native_cube_test)

add_executable(bt_native_camera_db_test tests/camera_db.c)
target_link_libraries(bt_native_camera_db_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_camera_db_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_camera_db_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_camera_db COMMAND bt_native_camera_db_test)

add_executable(bt_native_lights_test tests/lights.c)
target_link_libraries(bt_native_lights_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_lights_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_lights_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_lights COMMAND bt_native_lights_test)

add_test(NAME native_world_load COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/world_fixture.py" "$<TARGET_FILE:bt_native_cube_test>")

add_executable(bt_native_model_test tests/model.c)
target_link_libraries(bt_native_model_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_model_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_model_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_model COMMAND bt_native_model_test)

add_executable(bt_native_map_test tests/map.c tests/map_dependencies.c)
target_link_libraries(bt_native_map_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_map_test PRIVATE -Wl,-dead_strip)
elseif(UNIX)
    target_link_options(bt_native_map_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_map COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/map_fixture.py" "$<TARGET_FILE:bt_native_map_test>")

add_executable(bt_native_map_sections_test tests/map_sections.c tests/map_dependencies.c)
target_link_libraries(bt_native_map_sections_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_map_sections_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_map_sections_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_map_sections COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/map_fixture.py" "$<TARGET_FILE:bt_native_map_sections_test>")

add_executable(bt_native_collision_dispatch_test tests/collision_dispatch.c)
target_link_libraries(bt_native_collision_dispatch_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_collision_dispatch_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_collision_dispatch_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_collision_dispatch COMMAND bt_native_collision_dispatch_test)

add_executable(bt_native_collision_geometry_test tests/collision_geometry.c tests/map_dependencies.c)
target_link_libraries(bt_native_collision_geometry_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_collision_geometry_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_collision_geometry_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_collision_geometry COMMAND bt_native_collision_geometry_test)

add_executable(bt_native_world_collision_test tests/world_collision.c tests/marker_world.c tests/actor_model_dependencies.c)
target_link_libraries(bt_native_world_collision_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_world_collision_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_world_collision_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_world_collision COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/world_collision_fixture.py" "$<TARGET_FILE:bt_native_world_collision_test>")

add_executable(bt_native_actor_model_test tests/actor_model.c tests/actor_model_dependencies.c tests/marker_world.c)
target_link_libraries(bt_native_actor_model_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_actor_model_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actor_model_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actor_model COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/world_collision_fixture.py" "$<TARGET_FILE:bt_native_actor_model_test>")

add_executable(bt_native_actor_events_test tests/actor_events.c tests/marker_world.c)
target_link_libraries(bt_native_actor_events_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_actor_events_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actor_events_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actor_events COMMAND bt_native_actor_events_test)

add_executable(bt_native_actor_lifecycle_test tests/actor_lifecycle.c tests/marker_world.c tests/actor_model_dependencies.c)
target_link_libraries(bt_native_actor_lifecycle_test PRIVATE bt_native_core)
target_compile_definitions(bt_native_actor_lifecycle_test PRIVATE BT_TEST_REAL_ITEMS=1 BT_TEST_REAL_ACTOR_ANIMATION=1 BT_TEST_REAL_SKELETON=1 BT_TEST_REAL_RENDER_STATE=1)
if(APPLE)
    target_link_options(bt_native_actor_lifecycle_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_actor_lifecycle_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_actor_lifecycle COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/world_collision_fixture.py" "$<TARGET_FILE:bt_native_actor_lifecycle_test>")

add_executable(bt_native_skinning_test tests/skinning.c)
target_link_libraries(bt_native_skinning_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_skinning_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_skinning_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_skinning COMMAND bt_native_skinning_test)

add_executable(bt_native_skeleton_test tests/skeleton.c)
target_link_libraries(bt_native_skeleton_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_skeleton_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_skeleton_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_skeleton COMMAND bt_native_skeleton_test)

add_executable(bt_native_render_state_test tests/render_state.c)
target_link_libraries(bt_native_render_state_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_render_state_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_render_state_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_render_state COMMAND bt_native_render_state_test)

add_executable(bt_native_firstperson_camera_state_test tests/firstperson_camera_state.c "${BT_ROOT}/src/core2/1E7D460.c")
add_dependencies(bt_native_firstperson_camera_state_test bt_native_overlay_aliases)
target_compile_definitions(bt_native_firstperson_camera_state_test PRIVATE
    BT_NATIVE=1 BT_NATIVE_LITTLE_ENDIAN=1 _LANGUAGE_C BUILD_VERSION=VERSION_J _FINALROM F3DEX_GBI_2)
target_include_directories(bt_native_firstperson_camera_state_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include" "${BT_ROOT}/include"
    "${BT_ROOT}/lib/ultralib/include" "${BT_ROOT}/src")
target_compile_options(bt_native_firstperson_camera_state_test PRIVATE -std=gnu89 -ffunction-sections -fdata-sections
    "SHELL:-include \"${BT_OVERLAY_ALIASES}\""
    "SHELL:-include \"${CMAKE_CURRENT_SOURCE_DIR}/include/native_prototypes.h\""
    -fno-builtin -fno-strict-aliasing -fwrapv -Wno-deprecated-non-prototype
    -Wno-error=implicit-function-declaration -Wno-error=int-conversion
    -Wno-error=incompatible-pointer-types -Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast)
if(APPLE)
    target_link_options(bt_native_firstperson_camera_state_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_firstperson_camera_state_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_firstperson_camera_state COMMAND bt_native_firstperson_camera_state_test)

add_executable(bt_native_shadow_links_test tests/shadow_links.c "${BT_ROOT}/src/overlays/ch/bad/shad.c")
target_link_libraries(bt_native_shadow_links_test PRIVATE bt_native_options)
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_shadow_links_test PRIVATE -ffunction-sections -fdata-sections)
endif()
if(APPLE)
    target_link_options(bt_native_shadow_links_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_shadow_links_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_shadow_links COMMAND bt_native_shadow_links_test)

add_executable(bt_native_graphics_abi_test tests/graphics_abi.c)
target_link_libraries(bt_native_graphics_abi_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_graphics_abi_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_graphics_abi_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_graphics_abi COMMAND bt_native_graphics_abi_test)

add_executable(bt_native_geometry_data_test tests/geometry_data.c)
target_link_libraries(bt_native_geometry_data_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_geometry_data_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_geometry_data_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_geometry_data COMMAND bt_native_geometry_data_test)

add_executable(bt_native_sky_state_test tests/sky_state.c
    "${BT_ROOT}/src/core2/1E995C0.c" "${BT_ROOT}/src/core2/1EC7E20.c")
target_link_libraries(bt_native_sky_state_test PRIVATE bt_native_core)
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(bt_native_sky_state_test PRIVATE -ffunction-sections -fdata-sections)
endif()
if(APPLE)
    target_link_options(bt_native_sky_state_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_sky_state_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_sky_state COMMAND bt_native_sky_state_test)

add_executable(bt_native_graphics_memory_test tests/graphics_memory.c
    "${BT_ROOT}/src/core2/1E88E90.c")
target_link_libraries(bt_native_graphics_memory_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_graphics_memory_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_graphics_memory_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_graphics_memory COMMAND bt_native_graphics_memory_test)

add_executable(bt_native_geometry_test tests/geometry.c)
target_link_libraries(bt_native_geometry_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_geometry_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_geometry_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_geometry COMMAND bt_native_geometry_test)

add_executable(bt_native_camera_test tests/camera.c)
target_link_libraries(bt_native_camera_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_camera_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_camera_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_camera COMMAND bt_native_camera_test)

add_executable(bt_native_camera_frame_test tests/camera_frame.c)
target_link_libraries(bt_native_camera_frame_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_camera_frame_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_camera_frame_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_camera_frame COMMAND bt_native_camera_frame_test)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_executable(bt_native_player_viewports_test tests/player_viewports.c
        "${BT_ROOT}/src/core2/1EA3AA0.c" "${BT_ROOT}/src/core2/1EE92B0.c")
    target_compile_definitions(bt_native_player_viewports_test PRIVATE
        heap_alloc=viewport_test_alloc heap_free=viewport_test_free defrag=viewport_test_defrag)
    target_link_libraries(bt_native_player_viewports_test PRIVATE bt_native_core)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(bt_native_player_viewports_test PRIVATE -ffunction-sections -fdata-sections)
        if(APPLE)
            target_link_options(bt_native_player_viewports_test PRIVATE -Wl,-dead_strip)
        else()
            target_link_options(bt_native_player_viewports_test PRIVATE -Wl,--gc-sections)
        endif()
    endif()
    add_test(NAME native_player_viewports COMMAND bt_native_player_viewports_test)
endif()

add_executable(bt_native_textures_test tests/textures.c)
target_link_libraries(bt_native_textures_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_textures_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_textures_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_textures COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/map_fixture.py" "$<TARGET_FILE:bt_native_textures_test>")

add_executable(bt_native_point_lighting_test tests/point_lighting.c)
target_link_libraries(bt_native_point_lighting_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_point_lighting_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_point_lighting_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_point_lighting COMMAND bt_native_point_lighting_test)

add_executable(bt_native_trig_tables_test tests/trig_tables.c)
target_link_libraries(bt_native_trig_tables_test PRIVATE bt_native_core)
add_test(NAME native_trig_tables COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/sine_fixture.py" "$<TARGET_FILE:bt_native_trig_tables_test>"
    "${BT_ROOT}/decompressed.us.z64")

add_executable(bt_native_model_modes_test tests/model_modes.c)
target_link_libraries(bt_native_model_modes_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_model_modes_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_model_modes_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_model_modes COMMAND "${Python3_EXECUTABLE}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/model_modes.py" "$<TARGET_FILE:bt_native_model_modes_test>"
    "${BT_ROOT}/decompressed.us.z64")

add_executable(bt_native_fog_test tests/fog.c)
target_link_libraries(bt_native_fog_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_fog_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_fog_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_fog COMMAND bt_native_fog_test)

add_executable(bt_native_reflection_test tests/reflection.c)
target_link_libraries(bt_native_reflection_test PRIVATE bt_native_core)
if(APPLE)
    target_link_options(bt_native_reflection_test PRIVATE -Wl,-dead_strip)
else()
    target_link_options(bt_native_reflection_test PRIVATE -Wl,--gc-sections)
endif()
add_test(NAME native_reflection COMMAND bt_native_reflection_test)

# The game executable: everything that compiles natively, plus generated traps for
# what is still missing (pc/native/link_game.py builds it and writes the traps).
file(STRINGS game_sources.txt BT_GAME_PORTED)
list(TRANSFORM BT_GAME_PORTED PREPEND "${BT_ROOT}/")
set(BT_GAME_TRAPS "${CMAKE_CURRENT_BINARY_DIR}/generated/unported.c")
set(BT_GAME_TRAP_DATA "${CMAKE_CURRENT_BINARY_DIR}/generated/unported.s")
foreach(f "${BT_GAME_TRAPS}" "${BT_GAME_TRAP_DATA}")
    if(NOT EXISTS "${f}")
        file(WRITE "${f}" "")
    endif()
endforeach()
add_executable(bt_native_game EXCLUDE_FROM_ALL platform/main.c platform/traps.c
    platform/ultra_os.c platform/ultra_vi.c platform/ultra_pi.c platform/ultra_si.c platform/handwritten.c ${BT_GAME_PORTED}
    "${BT_GAME_TRAPS}" "${BT_GAME_TRAP_DATA}")
target_link_libraries(bt_native_game PRIVATE bt_native_core)

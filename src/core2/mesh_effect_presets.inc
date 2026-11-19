typedef struct {
    s16 map, mesh, scale, offset;
} MeshEffectPreset;

/* The map-zero row supplies the default scale and offset. */
MeshEffectPreset D_80123580[2] BT_DATA(2, mesh_effect_presets, 0) = {
    {0xB0, 1300, 400, 16},
    {0, 0, 800, 8},
};

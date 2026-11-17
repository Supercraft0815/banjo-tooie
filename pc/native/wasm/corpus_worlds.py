"""Q2 world entrance and interior cases, separate from the Phase-0 corpus."""

from save_editor import START_ABILITIES
from sweep import press


SCENES = (
    ('mt', 'Mayahem Temple', 0xB8, 'Temple', 0xC5),
    ('ggm', 'Glitter Gulch Mine', 0xC7, 'Gloomy Caverns', 0xD2),
    ('ww', 'Witchyworld', 0xD6, 'Haunted Cavern', 0xEB),
    ('jrl', "Jolly Roger's Lagoon", 0x1A7, 'Temple of Fishes', 0xFA),
    ('gi', 'Grunty Industries', 0x100, 'Factory interior', 0x101),
    ('tdl', 'Terrydactyland', 0x112, 'Inside Mountain', 0x116),
    ('hp', 'Hailfire Peaks, Lava Side', 0x127, 'Inside Volcano', 0x133),
    ('ccl', 'Cloud Cuckooland', 0x136, 'Central Cavern', 0x13A),
    ('ioh', "Isle o' Hags, Wooded Hollow", 0x14F, 'Jiggywiggy Temple', 0x151),
    ('ck', 'Cauldron Keep', 0x15D, 'Gatehouse', 0x15E),
)

FLAGS = tuple(range(0x392, 0x39B)) + tuple(START_ABILITIES)
START_PRESS = press(34, 0)


CASES = {
    f'{slug}-{part}': {
        'region': region,
        'scene': scene,
        'expected_map': map_id,
        'warp': f'34:{map_id:X}:1',
        'press': START_PRESS,
        'seconds': 44,
        'dump_every': 1318,  # second frame is ten seconds past the warp
        'flags': FLAGS,
    }
    for slug, region, entrance, interior_name, interior in SCENES
    for part, scene, map_id in (
        ('entrance', f'{region} entrance', entrance),
        ('interior', interior_name, interior),
    )
}

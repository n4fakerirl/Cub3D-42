#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# liste des maps
FILES=(
valid/01.cub
valid/02.cub
valid/03.cub
valid/04.cub
valid/05.cub
valid/default.cub
valid/weird_map01.cub
valid/weird_map02.cub
valid/weird_map03.cub
valid/weird_map04.cub
valid/weird_map05.cub
good/cheese_maze.cub
good/creepy.cub
good/dungeon.cub
good/library.cub
good/matrix.cub
good/sad_face.cub
good/square_map.cub
good/subject_map.cub
good/test_map_hole.cub
good/test_map.cub
good/test_pos_bottom.cub
good/test_pos_left.cub
good/test_pos_right.cub
good/test_pos_top.cub
good/test_textures.cub
good/test_whitespace.cub
good/works.cub
perso/basrelief.cub
perso/empty.cub
perso/subject_map.cub
perso/test.cub
perso/tonton.cub
old/big_map.cub
old/crash.cub
old/map.cub
old/open.cub
old/parsing.cub
old/simple.cub
old/very_big_map.cub
old/very_simple.cub
bad/color_invalid_rgb.cub
bad/color_missing_ceiling_rgb.cub
bad/color_missing_floor_rgb.cub
bad/color_missing.cub
bad/color_none.cub
bad/empty.cub
bad/file_letter_end.cub
bad/filetype_missing
bad/filetype_wrong.buc
bad/map_first.cub
bad/map_middle.cub
bad/map_missing.cub
bad/map_only.cub
bad/map_too_small.cub
bad/player_multiple.cub
bad/player_none.cub
bad/player_on_edge.cub
bad/textures_dir.cub
bad/textures_duplicates.cub
bad/textures_invalid.cub
bad/textures_missing.cub
bad/textures_none.cub
bad/textures_not_xpm.cub
bad/wall_hole_east.cub
bad/wall_hole_north.cub
bad/wall_hole_south.cub
bad/wall_hole_west.cub
bad/wall_none.cub
invalid/error_color_newline.cub
invalid/error_color1.cub
invalid/error_color2.cub
invalid/error_color3.cub
invalid/error_color4.cub
invalid/error_color5.cub
invalid/map_prank.cub
invalid/map_prank2.cub
invalid/no_border_down.cub
invalid/no_border_left.cub
invalid/no_border_right.cub
invalid/no_border_up.cub
invalid/no_color1.cub
invalid/no_color2.cub
invalid/no_position.cub
invalid/no_texture1.cub
invalid/no_texture2.cub
invalid/no_texture3.cub
invalid/no_texture4.cub
invalid/too_many_start_1.cub
invalid/too_many_start_2.cub
invalid/too_many_start_3.cub
invalid/trash_in_map1.cub
invalid/trash_in_map2.cub
invalid/trash_in_map3.cub
invalid/trash_in_map4.cub
invalid/trash_in_map5.cub
invalid/trash_in_map6.cub
invalid/trash_in_map7.cub
invalid/trash_in_map8.cub
invalid/trash_in_map9.cub
invalid/trash_in_map10.cub
)

# boucle test
for file in "${FILES[@]}"; do
    echo "Testing $file -> $out"
    funcheck ./cub3d "maps/$file"

done

echo "Funcheck done."
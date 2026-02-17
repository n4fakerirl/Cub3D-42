#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/invalid"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
error_color_newline.cub
error_color1.cub
error_color2.cub
error_color3.cub
error_color4.cub
error_color5.cub
map_prank.cub
map_prank2.cub
no_border_down.cub
no_border_left.cub
no_border_right.cub
no_border_up.cub
no_color1.cub
no_color2.cub
no_position.cub
no_texture1.cub
no_texture2.cub
no_texture3.cub
no_texture4.cub
too_many_start_1.cub
too_many_start_2.cub
too_many_start_3.cub
trash_in_map1.cub
trash_in_map2.cub
trash_in_map3.cub
trash_in_map4.cub
trash_in_map5.cub
trash_in_map6.cub
trash_in_map7.cub
trash_in_map8.cub
trash_in_map9.cub
trash_in_map10.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/invalid/$file" > "$out" 2>&1
done

echo "Invalid map done."
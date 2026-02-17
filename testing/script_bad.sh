#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/bad"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
color_invalid_rgb.cub
color_missing_ceiling_rgb.cub
color_missing.cub
color_missing_floor_rgb.cub
color_none.cub
empty.cub
file_letter_end.cub
filetype_missing
filetype_wrong.buc
map_first.cub
map_middle.cub
map_missing.cub
map_only.cub
map_too_small.cub
player_multiple.cub
player_none.cub
player_on_edge.cub
textures_dir.cub
textures_duplicates.cub
textures_invalid.cub
textures_missing.cub
textures_none.cub
textures_not_xpm.cub
wall_hole_east.cub
wall_hole_north.cub
wall_hole_south.cub
wall_hole_west.cub
wall_none.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/bad/$file" > "$out" 2>&1
done

echo "Bad map done."
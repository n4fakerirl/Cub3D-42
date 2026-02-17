#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/good"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
cheese_maze.cub
creepy.cub
dungeon.cub
library.cub
matrix.cub
sad_face.cub
square_map.cub
subject_map.cub
test_map.cub
test_map_hole.cub
test_pos_bottom.cub
test_pos_left.cub
test_pos_right.cub
test_pos_top.cub
test_textures.cub
test_whitespace.cub
works.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/good/$file" > "$out" 2>&1
done

echo "Good map done."
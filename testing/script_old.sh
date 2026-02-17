#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/old"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
big_map.cub
crash.cub
map.cub
open.cub
parsing.cub
simple.cub
very_big_map.cub
very_simple.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/old/$file" > "$out" 2>&1
done

echo "Bad map done."
#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/valid"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
01.cub
02.cub
03.cub
04.cub
05.cub
default.cub
weird_map01.cub
weird_map02.cub
weird_map03.cub
weird_map04.cub
weird_map05.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/valid/$file" > "$out" 2>&1
done

echo "Valid map done."
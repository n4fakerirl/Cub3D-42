#!/bin/bash

# build
make || { echo "Compilation failed"; exit 1; }

# dossier de sortie
OUT_DIR="sortie/perso"
mkdir -p "$OUT_DIR"

# liste des maps
FILES=(
basrelief.cub
empty.cub
subject_map.cub
test.cub
tonton.cub
)

# boucle test
for file in "${FILES[@]}"; do
    name=$(basename "$file")
    out="$OUT_DIR/${name%.cub}.txt"

    echo "Testing $file -> $out"
    valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes ./cub3d "maps/perso/$file" > "$out" 2>&1
done

echo "perso map done."
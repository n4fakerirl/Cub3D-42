# Cub3D (with @gamabuntoo)

## 📚 Description

`cub3D` est un projet graphique de l'école 42 inspiré du jeu Wolfenstein 3D.
Le but est de créer un moteur de rendu en raycasting permettant d’afficher une vue pseudo-3D à partir d’une carte 2D, en utilisant la bibliothèque MiniLibX.
Le projet inclut la gestion des textures, des collisions, des déplacements du joueur, ainsi que l’analyse et la validation d’un fichier de configuration .cub.

---

## 📦 Objectifs

- Implémenter un moteur de rendu 3D simple (raycasting)
- Lire et valider un fichier de configuration .cub
- Afficher des murs texturés selon l’orientation
- Gérer les déplacements et rotations du joueur
- Gérer les collisions avec les murs

---

## 📄 Fichier .cub

Le fichier .cub contient :

# 🎨 Textures

```bash
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm
```

# 🌈 Couleurs

```bash
F 220,100,0   # Sol
C 225,30,0    # Plafond
```

# 🗺️ Carte

```bash
111111
100001
10N0C1
100001
111111
```

---

## 🔁 Symboles de la carte

| Symbole | Signification         |
| ------- | --------------------- |
| `1`     | Mur                   |
| `0`     | Sol                   |
| `N`     | Joueur orienté Nord   |
| `S`     | Joueur orienté Sud    |
| `W`     | Joueur orienté Ouest  |
| `E`     | Joueur orienté Est    |
| ` `     | Espace vide à gerer selon l'emplacement |

La carte doit être fermée, valide et contenir une seule position de départ.

---

## ⌨️ Contrôles

| Touche | Action         |
| ------ | -------------- |
| `W`  | Haut           |
| `S`  | Bas            |
| `A`  | Gauche         |
| `D`  | Droite         |
| `← et →`  | Rotation de la caméra 
| `ESC ou croix`  | Quitter le jeu |

---

## ⚙️ Compilation

| Commande      | Description                                 |
| ------------- | ------------------------------------------- |
| `make`        | Compile `cub3d`                         |
| `make clean`  | Supprime les fichiers objets (`.o`)         |
| `make fclean` | Supprime les fichiers objets et exécutables |
| `make re`     | Nettoie puis recompile entièrement          |

---

## 🚀 Exemple d'exécution

```bash
./cub3D maps/map.cub
```

---

## 🖼️ Note du projet

---

## 🫐 Auteurs

- Guillaume (gule-bat) && Océane (ocviller)
- Projet réalisé à 42 Paris, 2026

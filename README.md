# cub3d - 42 (with @gamabuntoo) | [FRENCH VERSION] english below

## 📚 Description

`cub3D` est un projet graphique de l'école 42 inspiré du jeu **Wolfenstein 3D**.
Le but est de créer un moteur de rendu 3D en utilisant la technique du **raycasting** avec la bibliothèque **MiniLibX**.

Le joueur évolue dans un environnement en vue à la première personne, peut se déplacer dans la carte, tourner la caméra et interagir avec un monde généré à partir d'une carte au format `.cub`.

---

## 📦 Objectifs

* Parser et vérifier une carte au format `.cub`
* Implémenter un moteur de rendu 3D avec le raycasting
* Gérer les déplacements et la rotation de la caméra
* Appliquer les textures sur les murs
* Gérer les collisions avec les murs

---

## 🔁 Symboles de la carte

| Symbole | Signification              |
| ------- | -------------------------- |
| `1`     | Mur                        |
| `0`     | Sol                        |
| `N`     | Position de départ (Nord)  |
| `S`     | Position de départ (Sud)   |
| `E`     | Position de départ (Est)   |
| `W`     | Position de départ (Ouest) |

---

## ⌨️ Contrôles

| Touche | Action                     |
| ------ | -------------------------- |
| `W`    | Avancer                    |
| `S`    | Reculer                    |
| `A`    | Déplacement vers la gauche |
| `D`    | Déplacement vers la droite |
| `←`    | Tourner la caméra à gauche |
| `→`    | Tourner la caméra à droite |
| `ESC`  | Quitter le jeu             |

---

## ⚙️ Compilation

| Commande      | Description                                  |
| ------------- | -------------------------------------------- |
| `make`        | Compile `cub3D`                              |
| `make clean`  | Supprime les fichiers objets (`.o`)          |
| `make fclean` | Supprime les fichiers objets et l'exécutable |
| `make re`     | Nettoie puis recompile entièrement           |

---

## 🚀 Exemple d'exécution

```bash
./cub3D maps/map.cub
```

<p align="center">
 <img width="2528" height="1410" alt="image" src="https://github.com/user-attachments/assets/4dbe0fec-4b2d-4205-9fbb-ba9c124c5f08" />
</p>

---

## 🖼️ Project Grade

<p align="center">
  <img width="199" height="169" alt="image" src="https://github.com/user-attachments/assets/3cb12a00-dc57-4f96-a6b9-66bbfe7cd7b8" />
</p>

---

## 🫐 Auteur

* Guillaume (gule-bat) & Océane (ocviller)
* Piscine de septembre 2024 (Guillaume) & Piscine de mars 2025 (Océane)
* Projet réalisé à 42 Paris en 2026

---

# cub3d - 42 (with @gamabuntoo) | [FRENCH VERSION] english below

## 📚 Description

`cub3D` is a graphical project from the 42 curriculum inspired by **Wolfenstein 3D**.
The goal is to build a 3D rendering engine using the **raycasting** technique with the **MiniLibX** library.

The player explores a first-person environment, can move around the map, rotate the camera, and navigate through a world generated from a `.cub` map file.

---

## 📦 Objectives

* Parse and validate a `.cub` map
* Implement a 3D rendering engine using raycasting
* Handle player movement and camera rotation
* Apply textures to walls
* Detect and prevent wall collisions

---

## 🔁 Map Symbols

| Symbol | Meaning                          |
| ------ | -------------------------------- |
| `1`    | Wall                             |
| `0`    | Floor                            |
| `N`    | Player starting position (North) |
| `S`    | Player starting position (South) |
| `E`    | Player starting position (East)  |
| `W`    | Player starting position (West)  |

---

## ⌨️ Controls

| Key   | Action              |
| ----- | ------------------- |
| `W`   | Move Forward        |
| `S`   | Move Backward       |
| `A`   | Strafe Left         |
| `D`   | Strafe Right        |
| `←`   | Rotate Camera Left  |
| `→`   | Rotate Camera Right |
| `ESC` | Quit the game       |

---

## ⚙️ Compilation

| Command       | Description                             |
| ------------- | --------------------------------------- |
| `make`        | Compiles `cub3D`                        |
| `make clean`  | Removes object files (`.o`)             |
| `make fclean` | Removes object files and the executable |
| `make re`     | Cleans and recompiles the project       |

---

## 🚀 Example

```bash
./cub3D maps/map.cub
```

<p align="center">
 <img width="2528" height="1410" alt="image" src="https://github.com/user-attachments/assets/4dbe0fec-4b2d-4205-9fbb-ba9c124c5f08" />
</p>

---

## 🖼️ Project Grade

<p align="center">
  <img width="199" height="169" alt="image" src="https://github.com/user-attachments/assets/3cb12a00-dc57-4f96-a6b9-66bbfe7cd7b8" />
</p>

---

## 🫐 Author

* Guillaume (gule-bat) & Océane (ocviller)
* September 2024 Piscine (Guillaume) & March 2025 Piscine (Océane)
* Project completed at 42 Paris in 2026


*This project has been created as part of the 42 curriculum by ocviller, gule-bat*

# Description

Cub3d is *a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the ray-casting principles mentioned earlier.*

# Instructions

To compile and run the game:
	- Mandatory:
		-make all-
		-./cub3d "mapfilepath.cub"-
	- Bonus:	
		-make all-
		-make bonus-
		-./cub3d_bonus "mapfilepath.cub"-

Controls:

	  w         
	q s d  and  ←  →

	esc or cross to close

Maps:
		NO ./textures/N.xpm      Path to texture.
		SO ./textures/S.xpm
		EA ./textures/E.xpm
		WE ./textures/W.xpm
	
		C 35,19,73		Ceiling color:	R,G,B channels;
		F 15,6,40		Floor color:	R,G,B channels;
	
		111111111111111		1 = Wall;
		111111000111111		0 = Empty space;
		111110000011111
		1111000N0001111		The map must be closed so that the
		111000000000111		player cannot go out of its bounds.
		110000000000011		The player must be able to move through
		100001111100001		the map.
		110000111000011
		111000010000111
		111100000001111
		111110000011111
		111111000111111
		111111111111111

# Ressources

*https://www.youtube.com/watch?v=gYRrGTC7GtA*
*https://www.youtube.com/watch?v=NbSee-XM7WA*
*https://lodev.org/cgtutor/raycasting.html*
*https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/*

*Ai was used to understand and vulgarize some mathematical concepts such as some used in the dda.*



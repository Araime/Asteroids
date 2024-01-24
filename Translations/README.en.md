[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

# Asteroids SFML
A space game where a ship destroys asteroids. The ship is destroyed upon collision with asteroids.

<kbd>[<img title="English (United States)" alt="English (United States)" src="https://cdn.statically.io/gh/hjnilsson/country-flags/master/svg/us.svg" width="22">](Translations/README.en.md)</kbd>
<kbd>[<img title="Russian language" alt="Russian language" src="https://cdn.statically.io/gh/hjnilsson/country-flags/master/svg/ru.svg" width="22">](Translations/README.ru.md)</kbd>

https://github.com/Araime/Asteroids/assets/19285919/5b868eb9-550c-4540-a31c-d10c9e01307b

=======================

https://github.com/Araime/Asteroids/assets/82653875/d6041447-6f65-42df-abe9-74a24cb894ba

# COMPLETED:
~~different weapon/weapon change,~~

~~fully implement a unified game font,~~

======

~~WASD Keyboard support~~

~~+ = Increase Volume~~

~~- = Decrease Volume~~

~~Numpad8 = Mute/Unmute~~

~~Player speed boost via Shift Key and "Tokyo Drift" ability~~

~~ALARM signal if ship hull below 50%~~

~~Screen flashes red on/off to simulate red alert~~

~~Timer showing how long the player has survived~~

~~Asteroid collisions with one another for a more dynamic environment~~

~~POWERUP suggestions added in ship.cpp~~

## TO DO:

PowerUp drops,

possibly level upgrades (unlikely).

======
MAIN MENU on the start page of the game, including PLAY, CREDITS, GITHUB, EXIT

- IMGUI cheat: provides the player a GUI option to adjust game settings in-game
        * infinite HP
        * option to speed up or slow down their attack
        * Use boosts
        * etc.
  
Upon player's death, their score will be displayed, based on how many asteroids they have destroyed & how long they have survived, with a combined Total

Add Controller support

======

## Installation

### Download Source Code

VisualStudio should already be installed.

[Download - Original](https://github.com/Araime/Asteroids/archive/master.zip) this repository to your computer. 
The repository includes all necessary resources, as well as the SFML library.

[Download - Forked](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) this is the forked version: download it to your computer. 
The repository includes all necessary resources, as well as the SFML library.

### Download Debug Build
[Download - Forked](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) this contains the debug build that you can just play out of the box. Folder & Project name is called 0_DEBUG_BUILD/Asteroids.exe

### Launch

Open the `Asteroids.sln` file in the repository folder and launch it.

## Credits
- Music:  
	- `menu` cynicmusic - Enchanted Tiki 86.mp3
	- `level` maxstack - through space.ogg  
	- `end of game` Alexandr Zhelanov - space.mp3  

- Sounds:
  
    - `Player Critical Warning` 
		- @Mknai225 - Advanced Digital/Samples/Loops/Bass 160 BPM 2 -> Player_critical sound/Player_critical_damage_warning/Player_critical.wav
   		- https://twitter.com/Mknai225 
  
    - `Laser` 
		- Kenney - 63 Digital sound effects/laser1.wav  
		- Kenney - 63 Digital sound effects/laser2.wav  
		- Kenney - 63 Digital sound effects/laser3.wav

	- `Rocket`
 		- dklon - Rocket Launch Pack/rocket_launch1.wav  
		- dklon - Rocket Launch Pack/rocket_launch2.wav  
		- dklon - Rocket Launch Pack/rocket_launch3.wav  
		- dklon - Rocket Launch Pack/rocket_launch4.wav  

	- `Weapon change`
		- Tim Mortimer - 4 sci-fi menu sounds/Flashpoint001a.flac  

	- `Countdown`
		- legoluft - Krank_sounds/magnet_start.wav  

	- `Explosions`
		- dklon - Boom Pack 1/boom2.wav  
		- dklon - Boom Pack 1/boom9.wav
    
 -  Language Translations:
     -

 `ChatGPT/Google`
       		- English/Russian
-  Code Educator/On Site 24/7 Review:
     - `ChatGPT/C++ Primer Plus (5th Edition)/SFML-Game-Developme-By-Example.pdf`
       	
       
-  Repo Contrib:
     - `Current Repo`
       		- [Araime](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master)
       		- [AstroRoost](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) 

## Project Goal

Creating a game in C++ using the SFML library.

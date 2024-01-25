# Version_Info Ariame/Asteroids

----------------------------    ----------------------------   ------------------------- ------------------------------

- Forked latest version: https://github.com/Araime/Asteroids/commit/bae34ee773da48e42a746455ce251f19ae7e4be8

- Updated forked: https://github.com/AstroRoost/Contrib_Asteroids_Araime
=======
# VERSION INFO UPDATE
=======

  # Updated Game/ files
            - .h goes to /header
            - .cpp goes to /src
            - Input.h & Input.ccp has been added
            - Game icon has been added ../Resources/Icon/ico
            - Compress file usage and added to PCH.h for most common used
            

            - Updated ../Resources/Sounds
                *.wav & .ogg format has been placed in their respective folders
                *As of now only Flashpoint001a.wav & magnet_start is left in the default folder Sounds
                -Added ../Sounds/Player_critical_damage_warning folder with credits to sound author used for ALARM

                - Sound Folder names:
                 * Background_music
                 * Explosion    
                 * Main_menu_theme
                 * Player_critical_damage_warning 
                 * Projectiles
                 * Timer

            - Added Ref_Img Folder ->  ../Resources/Ref_Img
                * player_icon_indicator_out_of_bounds.pdn
                * Semi_Transparent_004A7F_Ship_Shielded.PNG
                * Shield_Outline_Ship_Shielded_00FFFF.PNG
                * spaceship_shielded.pdn

                -.pdn format created in Paint.net

                -Possible player boost spaceship_shield
                -Added player_icon_indicator_out_of_bounds.pdn in case you would like to add an indicator on where the player is if they go outside of bounds


                - spaceship_shielded.png has been added to ../Resources/Images
                - player_icon_indicator_out_of_bounds.png has been added to ../Resources/Images
    
   # Gameplay Additions

    - Added WASD Keyboard support
    -  Gave the player the ability to mute,unmute, increase volume or decrease volume of the background music during gameplay
        * + = Increase Volume
        * - = Decrease Volume
        * Numpad8 = Mute/Unmute
        * Information can be seen on Input.cpp for more info
    
    - Player speed boost via : Shift Key && can "Tokyo Drift"

    - Ship will make an "ALARM" if ship hull below 50%
    - Screen will Flash red/in&out to simulate red alert

    - Pilot will be "injected" with adrenaline to keep going, player will be able to shoot faster for both laser & rockets
    - Until HP is above 50% or if the player dies

    - Added // POWERUP IDEA: on Ship.cpp, will let you decide if you wish to implement that or add in your own additions to it

    - Added Timer, tell the player how long they have survived for

    - Provided asteroids with their own collision to one another
        * If they hit each other they will destroy & spawn in small asteroids to "simulate a semi dynamic environment/random/choatic"

    - Added in comments on the code additions as a reference point/ on the spot info

    - Will eventually add in additional comments based on any new updates that will occur


   # In Progress

        - Depending on what you add, will update the MAIN MENU of the start page for the game, to include PLAY, CREDITS, GITHUB, EXIT        
        - IMGUI cheat : provides the player an GUI option to play around with the game setting in-game
            * infinite HP
            * option to speed up or slow down their attack
            * Use boosts
            * etc
        - Upon death the player score will show, based on how many asteroids they have destroyed & how long they have survived for with a combined Total
        - Will add Controller support
        -- AS OF NOW: Updating Language on https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master
            * For both English and Russian using https://github.com/CyborgVillager/edu-first-contributions as a reference point
            - Updating Credits 


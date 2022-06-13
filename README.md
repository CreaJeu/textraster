Minimalist C library to calculate text visualization of graphical content. Intended to be used by ascii/console game engines.

Provides only theorical calculations for rasterization, letting any display dependency like ncurses to your game engine. Suggested design:

- your game
    - ... game logic, assets...
    - your game engine
        - ...
        - textraster
        - ncurses or any display tech

The goal of this lib is to show that low-tech is great (and shouldn't even have a specific name like "low-tech"). It runs on much much less powerful devices, really meets real real needs, and is the real real way to real real sustainable tech progress. Yes, ascii display is exaggerated, but this exaggeration is a choice to demonstrate all this :)

Hence, only minimalist features will ever be added into this lib.

BUILD :
Only usual C here. Just compile it your favourite way. No dependency. Code::Blocks project included (textraster.cbp), for those who like it, providing just straightforward compilation as static lib.

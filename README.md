Minimalist C library to calculate text visualization of graphical content. Intended to be used by ascii/console game engines.

Provides only theorical calculations for rasterization, letting any display dependency like ncurses to your game engine. Suggested design:

- your game
    - ... game logic, assets...
    - your game engine
        - ...
        - textraster
        - ncurses or any display tech

BUILD :
Only usual C here. Just compile it your favourite way. No dependency. Code::Blocks project included (textraster.cbp), for those who like it, providing just straightforward compilation as static lib.

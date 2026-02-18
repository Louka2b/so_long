*This project has been created as part of the 42 curriculum by ldeplace*

# SO_LONG

## Description:
so_long is a small 2D game where the goal is to collect all items present on a map and then escape through the exit using the fewest movements possible. This project involves window management, events (keyboard), and textures using the MiniLibX graphic library.

## Instruction:
compilation:
This project includes a Makefile to automate the compilation process. To compile the program run the following command in your terminal:

```make```

### Usage:
To run the program provide a map file with the .ber extension as an argument. The map must follow specific rules (closed walls, at least one collectible, one player, and one exit).

### example:
```./so_long maps/map1.ber```

### Controls:
W / A / S / D (or arrow keys): Move the character.
ESC: Close the game and exit cleanly.

## Project Features:
XPM texture management.
Rigorous map parsing (validation of walls and required elements).
Movement counter displayed in the terminal or on the window.
Clean memory management (no leaks upon closing).

## Resources:
MiniLibX:
https://harm-smits.github.io/42docs/libs/minilibx
https://gontjarow.github.io/MiniLibX/

## Algorithmic:
https://en.wikipedia.org/wiki/Flood_fill

## IA USAGE:
I used AI to help me structure this README file.
# So_Long

## Summary  
So_Long is a small 2D game project written in C using the MiniLibX graphical library. The objective is to parse a map file (with a `.ber` extension), render the map as tiles, allow the player to navigate using keyboard input, collect all collectibles, and then reach the exit. The game enforces map validation rules—such as a rectangular layout, surrounding walls, at least one exit (`E`), at least one collectible (`C`), and exactly one player start (`P`)—and displays a move counter as the player moves. :contentReference[oaicite:0]{index=0}

## Repository Structure  
- **`.vscode/`**: Configuration files for Visual Studio Code (e.g., `settings.json`, `launch.json`).  
- **`includes/`**: Header files for this project, including `so_long.h` which defines map characters, error messages, and function prototypes. :contentReference[oaicite:1]{index=1}  
- **`libft/`**: A custom Libft library containing reimplementations of common C standard library functions, used for string operations and memory management. :contentReference[oaicite:2]{index=2}  
- **`maps/`**: Example `.ber` map files that demonstrate valid layouts. Each map is a text file with characters `1` (wall), `0` (floor), `C` (collectible), `E` (exit), and `P` (player start). :contentReference[oaicite:3]{index=3}  
- **`minilibx-linux/`**: A Git submodule or clone of the MiniLibX library for Linux, providing functions like `mlx_init()`, `mlx_new_window()`, and `mlx_put_image_to_window()` to create and manipulate a graphical window. :contentReference[oaicite:4]{index=4}  
- **`srcs/`**: All C source files implementing the game:
  - **`main.c`**: Entry point that checks arguments, initializes data structures, calls the map parser, and enters the game loop.  
  - **`map_parser.c`**, **`map_checker.c`**: Validate file extension, ensure the map is non-empty, rectangular, surrounded by walls, and contains the required components; perform a flood‐fill or BFS to verify there is a valid path from the player to every collectible and the exit.  
  - **`render.c`**, **`textures.c`**: Load XPM or PNG textures from `textures/`, convert them into `mlx_image_t*`, and draw each tile (wall, floor, collectible, exit, player) based on the current map state.  
  - **`input_handler.c`**: Process key events (`W`/`A`/`S`/`D` or arrow keys), calculate the player’s next position, check collisions (walls), update collectible count when stepping on `C`, and increment the move counter.  
  - **`game_utils.c`**, **`error.c`**: Utility functions for printing error messages (e.g., wrong number of parameters, invalid extension, non-rectangular map, missing walls, etc.), freeing allocated memory, and gracefully exiting the game.  
  - **`hooks.c`**, **`exit_handler.c`**: Set up MiniLibX hooks for key presses and window close events, and handle the end‐game conditions (all collectibles gathered + reaching `E` or pressing `ESC`). :contentReference[oaicite:5]{index=5}  
- **`textures/`**: Image assets used by the game (e.g., `wall.xpm`, `floor.xpm`, `player.xpm`, `collectible.xpm`, `exit.xpm`).  
- **`.gitignore`**: Specifies files to ignore (e.g., object files, `.o`, temporary editor files).  
- **`Makefile`**: Build instructions:
  - **`all`**: Compiles `libft`, then compiles all `.c` files in `srcs/` (including linking with `libft` and MiniLibX) into an executable named `so_long`.  
  - **`clean` / `fclean` / `re`**: Remove compiled objects, libraries, and rebuild from scratch. :contentReference[oaicite:6]{index=6}

## Languages and Tools  
- **C (96.6%)**: Core language used for all game logic, map parsing, rendering, and event handling. :contentReference[oaicite:7]{index=7}  
- **Makefile (3.4%)**: Automates compilation of Libft, MiniLibX, and So_Long source files into a single executable. :contentReference[oaicite:8]{index=8}  
- **MiniLibX (vendor: `minilibx-linux/`)**: A lightweight graphical library provided by 42 to create windows, load textures, and handle keyboard/mouse events. :contentReference[oaicite:9]{index=9}

## How to Use This Repository  

1. **Clone the repository**:  
   ```bash
   git clone https://github.com/yuhi-ootani/So_Long.git
   cd So_Long
   ``` :contentReference[oaicite:10]{index=10}

2. **Compile with Make**:  
   ```bash
   make

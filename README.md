# cub3D with bonus

## Project Description

`cub3D` is a simplified 3D game engine built with **raycasting** techniques, inspired by classics like *Wolfenstein 3D*. The project uses a 2D map to render a pseudo-3D environment from a first-person perspective.

It is designed to introduce students to the fundamentals of **graphics programming**, **raycasting algorithms**, **game loops**, **input handling**, and **performance constraints** using **C** and the **MiniLibX** graphics library.

This version includes the **mandatory features** and **bonus features** (such as mouse support, minimap, and more).

---

## 🛠️ Mandatory Features

- Parse a `.cub` configuration file:
  - Textures (walls), colors (floor/ceiling).
  - Map with correct walls, player starting position, and closed structure.
- Raycasting engine:
  - Render a 3D environment using walls from a 2D map.
  - Texturing on walls.
- Player movement:
  - Move forward/backward.
  - Strafe left/right.
  - Rotate view left/right.
- Error handling and protection against invalid inputs.
- Frame rendering using MiniLibX.

---

## ⭐ Bonus Features

The following additional features were implemented:

- **Wall Collisions**:
   - Unable to move into a wall/closed door
   - Sliding along the wall

- **Minimap**:
  - Top-down view of the map
  - Dynamic player position and direction
  - Position of doors (red = closed, green = open)

- **Mouse Support**:
  - Smooth view rotation using the mouse

- **Doors**:
  - Doors rendered in the environment
  - Open on keypress (`E`)
  - Closing automatically after a few seconds of being outside of the doors radius

- **Sprinting**:
  - Temporarily increase player speed on keypress (`Q`)

- **Support for multiple keys being pressed at the same time**

---

## Configuration File (.cub)

The `.cub` file describes the map and textures. Example format:

```
NO ./assets/textures/wall_north.xpm
SO ./assets/textures/wall_south.xpm
WE ./assets/textures/wall_west.xpm
EA ./assets/textures/wall_east.xpm
DO ./assets/textures/door.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
10D0000001
10000N0001
1111111111
```

- `NO`, `SO`, `WE`, `EA`: wall textures
- `DO`: door texture (in bonus)
- `F` and `C`: floor and ceiling colors
- `1`: wall
- `0`: empty space
- `D`: door (in bonus)
- `N`, `S`, `E`, `W`: player's starting position+direction

---

## Controls

| Key            | Action                  |
|----------------|--------------------------|
| `W`            | Move forward             |
| `S`            | Move backward            |
| `A`            | Strafe left              |
| `D`            | Strafe right             |
| `←` / `→`      | Rotate view left/right   |
| `Q`            | Sprint (bonus)           |
| `E`            | Open door (bonus)        |
| `MOUSE`        | Look around (bonus)      |
| `ESC`          | Exit program             |

---

## How to Run

Clone this repository and move into it.

Now for the **mandatory** version run:

```
make
./cub3d assets/maps/valid/<xyz>.cub
```

Or for the *(mandatory +)* **bonus** version run:

```
make bonus
./cub3d_bonus assets/maps/bonus/<xyz>.cub
```

---

## Dependencies

**MiniLibX**

If the program is not run on a 42 school computer:

Download the MiniLibX library and add it to the cub3d directory.

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation

Now a part of the Makefile needs to be changed:

from:
```
#make:
$(CC) $(OFILES) ./lib/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)
#bonus:
$(CC) $(BONUSOFILES) ./lib/libft.a -lmlx -lXext -lX11 -lm -o $(BONUS_NAME)
```

[only for linux] to:
```
#make:
$(CC) $(OFILES) ./lib/libft.a ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -o $(NAME)
#bonus:
$(CC) $(BONUSOFILES) ./lib/libft.a ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -o $(BONUS_NAME)
```

---

## Contributors

Lilly (https://github.com/waterlillly) and Monika (https://github.com/LaDeMonika)

This project was completed as part of the 42Vienna curriculum with a score of 120%.

## Author

Lilly

## cub3D

### 🗺️ Project Description

The `cub3D` project takes you on a journey through raycasting visualizer 3D graphics.
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. 🎮

### 🌟 Key Features

- Read and analyse map files.
- Render 3D environments visualisation from map files.
- Render textures from xpm files.
- 3D Rotations for enhanced exploration.
- Translation controls for moving up, down, left, and right.
- Wall collisions.
- Minimap or Map visuals
- Opening/Closing doors (ability to go through them)

### 🎮 Controls

- `W`, `A`, `S`, `D`: Translate player.
- `Left key` and `Right Key` / `Mouse`: Rotate point of view.
- `M`: Switch into Map mode.
- `Esc`: Shutdown the program.

With these additional features, your exploration becomes even more exciting and user-friendly. Enjoy the enhanced experience! 🌟🎨🕹️

### 🚀 Usage

#### 1. Clone the repository

```shell
git clone --recursive git@github.com:romann-broque/CUB3d.git
```

#### 2. Install the dependencies

```shell
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

#### 3. Compile the `cub3D` program

```shell
# without bonuses
make
# or for bonuses
make bonus
```

#### 4. Execute with a map file as parameter

```shell
./cub3D maps/42.cub
```

![](assets/gameplay.gif)

### 🔎 Help

If you are in lack of inspiration, you can take a look at some map file examples [here](assets/maps/).
You can use `-h` or `--help` to get more information about writing a good map.

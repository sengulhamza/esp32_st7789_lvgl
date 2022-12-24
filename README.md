# DEMO

![](https://github.com/sengulhamza/esp32_st7789_lvgl/blob/master/readme_assets/demo.gif)


# IDF Version: Release 5.0

```
cd esp/esp-idf
git checkout release/v5.0
git submodule update --init --recursive
git branch
```
git branch output
```
  master
* release/v5.0
(END)
```


# How to build

```
git clone https://github.com/sengulhamza/esp32_st7789_lvgl.git
cd esp32_st7789_lvgl
#idf.py -DCMAKE_BUILD_TYPE=Debug reconfigure or
idf.py -DCMAKE_BUILD_TYPE=Release reconfigure
idf.py build
idf.py flash -p <port>
```
---
# How to open terminal screen
```
idf.py monitor -p <port>
idf.py flash monitor  -p <port> # load and open terminal
```
---
## Source hierarchy

- `src` is the main application source directory.
- `src/app` for application related code files. ie: main, led, web server
- `src/core` system files related to ESP32
- `src/ui` LVGL UI files. It may be SquareLine Studio's exported files.

`tree src/`

```
src
├── CMakeLists.txt
├── app
├── common
└── core
└── ui
```
---
## Branch workflow
- Before create a new branch follow the below flow
```
git checkout master
git pull
git checkout -b feature/branch-name
```
- If your commit fixing a bug branch name will be like `bugfix/branch-name`
- Before push your commit, write a clear and concise explanation with -m option
---

## License

[GPL-V3](https://github.com/sengulhamza/esp32_st7789_lvgl/blob/master/LICENSE)

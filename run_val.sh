#!/bin/bash

# Run the make command
make re; make clean; clear; valgrind --leak-check=full -s ./cub3d assets/maps/valid/valid.cub
# for file in $(ls src/assets/maps/valid/*); do valgrind ./so_long "$file"; done 
# for file in $(ls src/assets/maps/invalid/*); do funcheck -a ./so_long "$file"; done
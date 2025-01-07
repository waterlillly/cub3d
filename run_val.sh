#!/bin/bash

# Run the make command
make clean

# Check if make was successful
if [ $? -eq 0 ]; then
    # Execute the program with the map
    # clear
    echo "Running the cub3d program..."
    echo ""
    valgrind --leak-check=full ./cub3d assets/maps/valid/valid.cub
else
    echo "Make command failed."
fi
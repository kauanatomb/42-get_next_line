#!/bin/bash

# Var for bonus version
if [ "$BONUS" == "1" ]; then
    echo "=== Test BONUS ==="
    SOURCE_FILES="../get_next_line_bonus.c ../get_next_line_utils_bonus.c test_gnlb.c"
else
    echo "=== Test MANDATORY ==="
    SOURCE_FILES="../get_next_line.c ../get_next_line_utils.c test_gnl.c"
fi

# Loop to test different buffer sizes
for bs in 1 2 4 8 16 32 64 128 1024
do
    echo "=== BUFFER_SIZE=$bs ==="
    
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$bs $SOURCE_FILES -o test
    
    leaks --atExit -- ./test

    echo
done



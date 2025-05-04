#!/bin/bash
for bs in 1 2 4 8 16 32 64 128 1024
do
    echo "=== BUFFER_SIZE=$bs ==="
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$bs ../get_next_line.c ../get_next_line_utils.c test_gnl.c -o test
    leaks --atExit -- ./test
    echo
done


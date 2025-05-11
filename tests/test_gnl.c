#include "../get_next_line.h"
#include <stdio.h> // printf

void test_empty(void)
{
    int     fd;
    char    *line;

    printf("=== Test: empty.txt ===\n");
    fd = open("empty.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    line = get_next_line(fd);
    if (!line)
        printf("[empty] -> NULL (OK)\n");
    else
    {
        printf("[empty] -> '%s' (FAIL)\n", line);
        free(line);
    }
    close(fd);
}

void test_one_line(void)
{
    int     fd;
    char    *line;

    printf("=== Test: one_line.txt ===\n");
    fd = open("one_line.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    line = get_next_line(fd);
    while (line)
    {
        printf("[one_line] -> '%s'\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

void test_big_line(void)
{
    int     fd;
    char    *line;

    printf("=== Test: big_line.txt ===\n");
    fd = open("big_line.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    line = get_next_line(fd);
    while (line)
    {
        printf("[big_line] -> '%s'\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

void test_just_break_lines(void)
{
    int     fd;
    char    *line;

    printf("=== Test: just_break_lines.txt ===\n");
    fd = open("just_break_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    line = get_next_line(fd);
    while (line)
    {
        printf("[breaks] -> '%s'\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

void test_mixed_lines(void)
{
    int     fd;
    char    *line;

    printf("=== Test: mixed_lines.txt ===\n");
    fd = open("mixed_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    line = get_next_line(fd);
    while (line)
    {
        printf("[mixed] -> '%s'\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

int main(void)
{
	test_empty();
	test_one_line();
	test_big_line();
	test_just_break_lines();
	test_mixed_lines();
	return (0);
}


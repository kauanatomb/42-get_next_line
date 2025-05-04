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

void test_multiple_fds(void)
{
    int     fd1 = open("mixed_lines.txt", O_RDONLY);
    int     fd2 = open("just_break_lines.txt", O_RDONLY);
    char    *line1;
    char    *line2;

    printf("=== Test: multiple FDs ===\n");
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return;
    }
    int i = 0;
    while (i < 3)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        printf("[fd1] -> %s", line1 ? line1 : "NULL\n");
        printf("[fd2] -> %s", line2 ? line2 : "NULL\n");
	i++;
        free(line1);
        free(line2);
    }
    close(fd1);
    close(fd2);
}

void test_memory_growth(void)
{
    int     fd = open("big_line.txt", O_RDONLY);
    char    *lines[100];
    int     i = 0;

    printf("=== Test: memory growth check ===\n");
    if (fd < 0)
    {
        perror("open");
        return;
    }
    while ((lines[i] = get_next_line(fd)) && i < 100)
    {
        printf("[line %d] -> %.20s...\n", i + 1, lines[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
        free(lines[j]);
    close(fd);
}

int main(void)
{
	test_empty();
	test_one_line();
	test_big_line();
	test_just_break_lines();
	test_mixed_lines();
	test_multiple_fds();
	test_memory_growth();
	return (0);
}


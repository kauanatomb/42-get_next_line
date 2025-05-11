#include "../get_next_line_bonus.h"
#include <stdio.h> // printf

void test_multiple_fds(void)
{
    int     fd1 = open("mixed_lines.txt", O_RDONLY);
    int     fd2 = open("just_break_lines.txt", O_RDONLY);
    char    *line1;
    char    *line2;

    printf("=== Test: multiple_fds ===\n");
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return;
    }
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    while (line1 || line2)
    {
        if (line1)
        {
            printf("[fd1] -> '%s'\n", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2)
        {
            printf("[fd2] -> '%s'\n", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
    }
    close(fd1);
    close(fd2);
}

void test_check_stash_persistence_for_multiple_fds(void)
{
    int     fd1 = open("just_break_lines.txt", O_RDONLY);
    int     fd2 = open("mixed_lines.txt", O_RDONLY);
    char    *line1;
    char    *line2;

    printf("=== Test: check_stash_persistence_for_multiple_fds ===\n");
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return;
    }

    while ((line1 = get_next_line(fd1)) != NULL)
    {
        printf("[fd1] -> '%s'\n", line1);
        free(line1);
    }

    while ((line2 = get_next_line(fd2)) != NULL)
    {
        printf("[fd2] -> '%s'\n", line2);
        free(line2);
    }

    // Verify if fd1 is at the end
    line1 = get_next_line(fd1);  // It should return NULL
    if (line1)
    {
        printf("[fd1] -> '%s'\n", line1);
        free(line1);
    }
    else
    {
        printf("[fd1] -> NULL (Confirmed that arrived to the end)\n");
    }

    close(fd1);
    close(fd2);
}

int main(void)
{
    test_multiple_fds();
    test_check_stash_persistence_for_multiple_fds();
    return (0);
}
#include "2048.h"

int load_score(char buffer[256])
{
    int     fd;
    ssize_t n;

    fd = open(SAVE_FILE, O_RDONLY);
    if (fd == -1)
        return (1);
    n = read(fd, buffer, 255);
    if (n >= 0)
        buffer[n] = '\0';
    close(fd);
    return (0);
}

int write_score(int score)
{
    int fd;
    
    fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
        return (1);

    ft_putnbr_fd(score, fd);
    write(fd, "\n", 1);
    close(fd);
    return (0);
}

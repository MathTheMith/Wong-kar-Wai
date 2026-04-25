#include "2048.h"

int load_score(char buffer[256])
{
    int fd;

    fd = open(SAVE_FILE, O_RDONLY);
    if (fd == -1)
        return (1);
    
    read(fd, buffer, 256);
    close(fd);
    return (0);
}

int write_score(int score)
{
    int fd;
    
    fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (1);

    ft_putnbr_fd(score, fd);
    return (0);
}
#include "2048.h"
#include <string.h>

char *get_ascii(int nb)
{
    switch (nb)
    {
    case 0:
        return "0000\n00  00\n00  00\n00  00\n 0000";
    case 1:
        return "1111\n  11\n  11\n  11\n111111";
    case 2:
        return " 2222\n22  22\n   22\n  22\n222222";
    case 3:
        return " 3333\n33  33\n   333\n33  33\n 3333";
    case 4:
        return "44  44\n44  44\n444444\n    44\n    44";
    case 5:
        return "555555\n55\n55555\n    55\n55555";
    case 6:
        return " 6666\n66\n66666\n66  66\n 6666";
    case 7:
        return "777777\n   77\n  77\n 77\n77";
    case 8:
        return " 8888\n88  88\n 8888\n88  88\n 8888";
    case 9:
        return " 9999\n99  99\n 99999\n    99\n 9999";
    default:
        break;
    }
    return "";
}

int get_ascii_width(int nb)
{
    char *s = get_ascii(nb);
    int w = 0;

    while (s[w] && s[w] != '\n')
        w++;
    return w;
}

int get_ascii_height(int nb)
{
    char *s = get_ascii(nb);
    int h = 1;

    while (*s)
        if (*s++ == '\n')
            h++;
    return h;
}

void draw_ascii(int y, int x, int nb)
{
    (void)nb;
    char *str = strdup(get_ascii(nb));
    if (!str)
        return;
    char *line = strtok(str, "\n");
    int row = 0;

    while (line)
    {
        mvprintw(y + row, x, "%s", line);
        row++;
        line = strtok(NULL, "\n");
    }
    free(str);
}

static int get_digits(int nb, int digits[10])
{
    int tmp[10];
    int count = 0;

    if (nb == 0)
    {
        digits[0] = 0;
        return 1;
    }
    while (nb > 0)
    {
        tmp[count++] = nb % 10;
        nb /= 10;
    }
    for (int i = 0; i < count; i++)
        digits[i] = tmp[count - 1 - i];
    return count;
}

int get_ascii_number_width(int nb)
{
    int digits[10];
    int count = get_digits(nb, digits);
    int total = 0;

    for (int i = 0; i < count; i++)
    {
        total += get_ascii_width(digits[i]);
        if (i < count - 1)
            total += 1;
    }
    return total;
}

void draw_ascii_number(int y, int x, int nb)
{
    int digits[10];
    int count = get_digits(nb, digits);
    int cur_x = x;

    for (int i = 0; i < count; i++)
    {
        draw_ascii(y, cur_x, digits[i]);
        cur_x += get_ascii_width(digits[i]) + 1;
    }
}

/*
** EPITECH PROJECT, 2020
** rush1-2
** File description:
** 
*/
#include <unistd.h>

int my_putchar(char c);

void make_border_up(int x, int y)
{
    if (x == 1)
    {
        my_putchar('*');
        return;
    }
    if (x == 2)
    {
        my_putchar('*');
        my_putchar('*');
    }
    int i = x - 2;
    if (y == 1)
    {
        while((i > 0?i:(i+2)) > 0)
        {
            my_putchar('*');
            i = i - 1;
        }
        return;
    }
    if (x > 2)
        my_putchar('/');
    while( i > 0)
    {
        my_putchar('*');
        i = i - 1;
    }
    my_putchar('\\');
    my_putchar(10);
}

void make_border_side2(int x, int y)
{
    int i = y - 2;
    int j = x - 2;
    while (i > 0)
    {
        my_putchar('*');
        while (j > 0)
        {
            my_putchar(32);
            j = j - 1;
        }
        j = x - 2;
        my_putchar('*');
        my_putchar(10);
        i = i - 1;
    }

}

void make_border_up2(int x)
{
    if (x == 1)
        my_putchar('*');
    if (x == 2)
    {
        my_putchar('*');
        my_putchar('*');
    }
    if (x > 2)
    {
        int i = x - 2;
        my_putchar('\\');
        while( i > 0)
        {
            my_putchar('*');
            i = i - 1;
        }
        my_putchar('/');
        my_putchar(10);
    }
}

    
void make_border_side(int x, int y)
{
    if (x == 1 && y > 2)
    {	
        my_putchar(10);
        int i = y - 2;
        while (i > 0)
        {
            my_putchar('*');
            my_putchar(10);
            i = i - 1;
        }
    }
    else if (x >= 2 && y > 2)
    {
        make_border_side2(x, y);
    }
}

void rush(int x, int y)
{
    if ( x <= 0 || y <= 0)
    {
        write(1, "Invalid size", 12);
        return;
    }
    if (y == 1)
    {
        make_border_up(x, y);
        return;
    }
    if(y == 2)
    {
        make_border_up(x, y);
        make_border_up2(x);
        return;
    }
    else {
        make_border_up(x, y);
        make_border_side(x, y);
        make_border_up2(x);
    }
}

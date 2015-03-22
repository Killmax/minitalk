/*
** my_put.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/server
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb 23 15:50:25 2015 bruguet Maxime
** Last update Sun Mar 22 12:46:18 2015 bruguet Maxime
*/

#include <unistd.h>
#include "minitalk.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putnbr(int nb)
{
  int		neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb++;
        }
      nb *= -1;
    }
  if (nb >= 10)
    my_putnbr(nb / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}

/*
** calc.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Mar  9 15:06:39 2015 bruguet Maxime
** Last update Mon Mar  9 15:22:48 2015 bruguet Maxime
*/

#include <signal.h>
#include <unistd.h>
#include <minitalk.h>

void		my_write_int(int to_put)
{
  static int	c = 0;
  static int	i = 0;

  c += (to_put << i++);
  if (i > 31)
    {
      if (c == 0)
	{
	  my_putchar('\n');
	  is_pid_rec = TRUE;
	}
      else
	my_putnbr(c);
      i = 0;
      c = 0;
    }
}

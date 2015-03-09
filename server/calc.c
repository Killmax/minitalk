/*
** calc.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Mar  9 15:06:39 2015 bruguet Maxime
** Last update Mon Mar  9 17:42:25 2015 bruguet Maxime
*/

#include <signal.h>
#include <unistd.h>
#include <minitalk.h>

int		my_write_int(int to_put)
{
  static int	c = 0;
  static int	i = 0;
  int		tmp;

  c += (to_put << i++);
  if (i > 31)
    {
      if (c == 0)
	my_putchar('\n');
      else
	{
	  my_putstr("PID DU CLIENT : ");
	  my_putnbr(c);
	  kill(SIGUSR2, c);
	  tmp = c;
	}
      i = 0;
      c = 0;
    }
}

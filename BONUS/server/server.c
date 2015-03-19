/*
** server.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/server
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb 23 15:36:43 2015 bruguet Maxime
** Last update Thu Mar 19 17:42:19 2015 bruguet Maxime
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "minitalk.h"

void		put_serv(void)
{
  my_putstr("PID : ");
  my_putnbr(getpid());
  my_putchar('\n');
}

void		my_write(int to_put)
{
  static unsigned char	c = 0;
  static int	i = 0;

  c |= (to_put << i++);
  if (i > 7)
    {
      if (c == '\0')
	{
	  my_putchar('\n');
	  my_putchar(c);
	  my_putstr("---------------------------\n");
	}
      else
	my_putchar(c);
      i = 0;
      c = 0;
    }
}

void		sig(int sign)
{
  if (sign == SIGUSR1)
    my_write(0);
  else if (sign == SIGUSR2)
    my_write(1);
}
void		get_sig(void)
{
  if (signal(SIGUSR1, sig) == SIG_ERR)
    my_error("SIGUSR1 ERROR\n");
  if (signal(SIGUSR2, sig) == SIG_ERR)
    my_error("SIGUSR2 ERROR\n");
}

int		main(int ac, char **av)
{
  if (ac != 1)
    my_error("No parameters needed\n");
  put_serv();
  get_sig();
  signal(SIGWINCH, SIG_IGN);
  while (42)
    pause();
  (void)av;
  return (0);
}

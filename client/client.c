/*
** client.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/client
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 11:59:21 2015 bruguet Maxime
** Last update Wed Feb 25 16:54:59 2015 bruguet Maxime
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "minitalk.h"

void		send_sign(int pid, int nb)
{
  if (nb == 0)
    {
      if (kill(pid, SIGUSR1) == -1)
	my_error("ERROR : cannot send SIGUSR1\n");
    }
  if (nb == 1)
    {
      if (kill(pid, SIGUSR2) == -1)
	my_error("ERROR : cannot send SIGUSR2\n");
    }
}

void		trad_sign(int pid, char to_send)
{
  char		c;
  int		nb;

  c = 0;
  while (c < 8)
    {
      usleep(130);
      nb = (to_send >> c++) & 1;
      send_sign(pid, nb);
    }
}

void		init(int pid, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      trad_sign(pid, str[i]);
      i++;
    }
  trad_sign(pid, 0);
}

int		main(int ac, char **av)
{
  int		pid;

  if (ac != 3)
    my_error("USAGE : ./client PID str_to_send\n");
  if (my_str_isnum(av[1]) == 0)
    pid = my_getnbr(av[1]);
  else
    my_error("ERROR : First arg must be a number\n");
  init(pid, av[2]);
  return (0);
}

/*
** client.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/client
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 11:59:21 2015 bruguet Maxime
** Last update Wed Mar 18 15:39:37 2015 bruguet Maxime
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "minitalk.h"

void		send_sign(int pid, int nb)
{
  if (nb == 0)
    if (kill(pid, SIGUSR1) == -1)
      my_error("ERROR : cannot send SIGUSR1\n");
  if (nb == 1)
    if (kill(pid, SIGUSR2) == -1)
      my_error("ERROR : cannot send SIGUSR2\n");
}

void		trad_sign(int pid, char to_send)
{
  char		c;
  int		nb;

  c = 0;
  while (c < 8)
    {
      nb = (to_send >> c++) & 1;
      usleep(800);
      send_sign(pid, nb);
    }
}

void		treat_char(int pid, char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    trad_sign(pid, str[i]);
  trad_sign(pid, 0);
}

void		treat_pid(int pid_cli)
{
  my_putstr("PID : ");
  my_putnbr(pid_cli);
  my_putchar('\n');
}

int		main(int ac, char **av)
{
  pid_t		pid_serv;

  if (ac != 3)
    my_error("USAGE : ./client PID str_to_send\n");
  if (my_str_isnum(av[1]) == 0 )
    pid_serv = my_getnbr(av[1]);
  else
    my_error("ERROR : First arg must be a number\n");
  if (pid_serv <= 1)
    my_error("Bad PID\n");
  treat_char(pid_serv, av[2]);
  return (0);
}

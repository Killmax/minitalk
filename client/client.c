/*
** client.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/client
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 11:59:21 2015 bruguet Maxime
** Last update Mon Mar  9 15:26:24 2015 bruguet Maxime
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
      usleep(300);
      nb = (to_send >> c++) & 1;
      send_sign(pid, nb);
    }
}

void		treat_char(int pid)
{
  static int	i = 0;

  if (to_send[i])
    trad_sign(pid, to_send[i]);
  else
    trad_sign(pid, 0);
}

void		treat_pid(int pid_cli, int pid_serv)
{
  my_putstr("PID : ");
  my_putnbr(pid_cli);
  my_putchar('\n');
  send_pid(pid_cli, pid_serv);
}

int		main(int ac, char **av)
{
  if (ac != 3)
    my_error("USAGE : ./client PID str_to_send\n");
  if (my_str_isnum(av[1]) == 0)
    pid_serv = my_getnbr(av[1]);
  else
    my_error("ERROR : First arg must be a number\n");
  to_send = av[2];
  treat_pid(getpid(), pid_serv);
  get_sig();
  return (0);
}

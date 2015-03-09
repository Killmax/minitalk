/*
** convert.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Mar  9 13:11:12 2015 bruguet Maxime
** Last update Mon Mar  9 14:51:50 2015 bruguet Maxime
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "minitalk.h"

void		send_pid(int pid_cli, int pid_serv)
{
  int           i;

  i = 0;
  while (i < 32)
    {
      send_sign(pid_serv, pid_cli % 2);
      pid_cli /= 2;
      i++;
      usleep(300);
    }
}

void		sig_h(int sig)
{
  if (sig == SIGUSR2 && is_pid_sent == FALSE)
    {
      is_pid_sent = TRUE;
      treat_char(pid_serv);
    }
  if (sig == SIGUSR2 && is_pid_sent == TRUE)
    //end_trans();
  if (sig == SIGUSR1)
    treat_char(pid_serv);
}

void		get_sig(void)
{
  if (signal(SIGUSR1, sig_h) == SIG_ERR)
    my_error("ERROR : SIGUSR1 problem\n");
  if (signal(SIGUSR2, sig_h) == SIG_ERR)
    my_error("ERROR : SIGUSR2 problem\n");
}

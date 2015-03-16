/*
** convert.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Mar  9 13:11:12 2015 bruguet Maxime
** Last update Mon Mar 16 16:13:51 2015 bruguet Maxime
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "minitalk.h"

void		my_sleep(void)
{
  int		i;

  i = -1;
  while (++i < 10000);
}

void		send_pid(int pid_cli, int pid_serv)
{
  int           i;

  i = 0;
  while (i < 32)
    {
      usleep(130);
      send_sign(pid_serv, pid_cli % 2);
      pid_cli /= 2;
      i++;
    }
}

/* void		sig_h(int sig) */
/* { */
/*   //if (sig == SIGUSR2 && is_pid_sent == FALSE) */
/*   //{ */
/*   //  is_pid_sent = TRUE; */
/*   //  treat_char(pid_serv); */
/*   //} */
/*   //if (sig == SIGUSR2 && is_pid_sent == TRUE) */
/*   //;//end_trans(); */
/*   //  if (sig == SIGUSR1) */
/*   //treat_char(pid_serv); */
/*   if (sig == SIGUSR2) */
/*     { */
/*       printf("finish\n"); */
/*       exit(0); */
/*     } */
/* } */

/* void		get_sig(void) */
/* { */
/*   if (signal(SIGUSR1, sig_h) == SIG_ERR) */
/*     my_error("ERROR : SIGUSR1 problem\n"); */
/*   if (signal(SIGUSR2, sig_h) == SIG_ERR) */
/*     my_error("ERROR : SIGUSR2 problem\n"); */
/* } */

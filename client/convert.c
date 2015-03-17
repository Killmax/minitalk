/*
** convert.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Mar  9 13:11:12 2015 bruguet Maxime
** Last update Tue Mar 17 14:31:11 2015 bruguet Maxime
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
      usleep(130);
      send_sign(pid_serv, pid_cli % 2);
      pid_cli /= 2;
      i++;
    }
}

/*
** my_put.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/client
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 14:51:15 2015 bruguet Maxime
** Last update Wed Feb 25 16:55:39 2015 bruguet Maxime
*/

#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}

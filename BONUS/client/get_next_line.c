/*
** get_next_line.c for bsq in /home/brugue_m/rendu/CPE_2014_bsq
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Jan 14 11:44:07 2015 bruguet Maxime
** Last update Sun Mar 22 12:56:41 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

static int	my_len(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

static char	*my_realloc(char *old, int size)
{
  int		i;
  char		*new;

  i = 0;
  new = NULL;
  if ((new = malloc(sizeof(*new) * (my_len(old) + size))) == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

char		*get_next_line(const int fd)
{
  static int	last = 1;
  static int	rd = 0;
  static int	i = 0;
  static char	*res = NULL;
  static char	buf[BUFF_SIZE];

  if (buf[my_strlen(buf) - rd] == '\0')
    {
      if ((rd = read(fd, buf, BUFF_SIZE)) <= 0)
        return (res = (last-- && buf[my_len(buf) - rd - 1] != 10) ? res : NULL);
      buf[rd] = '\0';
    }
  if ((res = (i == 0) ? malloc(sizeof(*res) * BUFF_SIZE + 1) :
       my_realloc(res, sizeof(*res) * BUFF_SIZE + 1)) == NULL)
    return (NULL);
  while (buf[my_len(buf) - rd] && buf[my_len(buf) - rd] != '\n')
    res[i++] = buf[my_len(buf) - rd--];
  res[i] = 0;
  if (buf[my_len(buf) - rd] == '\n')
    {
      i = 0;
      rd--;
      return (res);
    }
  return (get_next_line(fd));
}

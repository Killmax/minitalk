/*
** my_str_isnum.c for 104 in /home/brugue_m/rendu/104intersection
** 
** Made by Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Dec 25 14:13:30 2014 Maxime
** Last update Thu Dec 25 14:16:23 2014 Maxime
*/

int		my_str_isnum(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '-')
    i++;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (1);
    }
  return (0);
}

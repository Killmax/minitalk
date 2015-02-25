/*
** my_getnbr.c for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/client
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 13:36:36 2015 bruguet Maxime
** Last update Wed Feb 25 13:38:23 2015 bruguet Maxime
*/

int		my_getnbr(char *str)
{
  int		res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str)
    {
      res *= 10;
      res += *str - '0';
      str += 1;
    }
  return (res);
}

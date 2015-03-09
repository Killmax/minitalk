/*
** minitalk.h for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/include
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 16:38:41 2015 bruguet Maxime
** Last update Mon Mar  9 15:20:29 2015 bruguet Maxime
*/

#ifndef MINITALK_H_
# define MINITALK_H_

# define TRUE 1
# define FALSE 0

/*
** Global variable
*/

int		pid_serv;
char		is_pid_sent;
char		is_pid_rec;
char		*to_send;

/*
** Prototypes for client binary
*/

void		my_error(char *);
int		my_str_isnum(char *);
int		my_getnbr(char *);
void		my_putstr(char *);
void		my_putnbr(int);
void		sig(int nb);
void		my_putchar(char);

#endif /* MINITALK_H */

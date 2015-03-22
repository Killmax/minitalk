/*
** minitalk.h for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk/include
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 25 16:38:41 2015 bruguet Maxime
** Last update Sun Mar 22 13:01:37 2015 bruguet Maxime
*/

#ifndef MINITALK_H_
# define MINITALK_H_

# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 32000

/*
** Prototypes for both binaries
*/

void		my_error(char *);
int		my_strlen(char *);
char		*get_next_line(const int fd);
int		my_str_isnum(char *);
int		my_getnbr(char *);
void		my_putstr(char *);
void		my_putnbr(int);
void		sig(int nb);
void		my_sleep(void);
void		send_pid(int, int);
void		send_sign(int, int);
void		my_putchar(char);

#endif /* MINITALK_H */

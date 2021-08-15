#ifndef FT_H
# define FT_H
# include "ft_flags.h"

void ft_putstr(char *str);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_unsigned_putnbr(unsigned int n);
char *ft_strcpy(char *dst, const char *src);
int ft_strlen(const char *s);
long display(long nb, char *str, char *result, int index);
long get_number_length(long number, char *base);
long get_nb(char c, char *base);
long ft_atoi_base(char *str, char *base);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int	ft_atoi(char *str);
char *ft_itoa(long n);
char *ft_strjoin(char const *s1, char const *s2);
int	count(char *str);
int	word_length(char *str, int i);
char **ft_split(char *str);
int detect_nbr(char *str);
int ft_is_flag(char to_find, char *str);
struct s_flags *ft_param_to_tab(char** str);

#endif

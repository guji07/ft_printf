/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:48:38 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 12:39:27 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
#define MINUS form.flag[0]
#define PLUS form.flag[1]
#define ZERO form.flag[2]
#define HASHTAG form.flag[3]
#define SPACE form.flag[4]
#define h 1
#define hh 2
#define l 3
#define ll 4

typedef  struct				s_format
{
	int			*flag;
	int 		width;
	int 		precision;
}							t_format;

int kolvo;

/*
 * part1 functions from libft subject ecole 42
 */
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *string, int symbol);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
int					ft_strequ(char const *s1, char const *s2);
void				ft_putnbrpos(long long int nb);
void				ft_putunsignednbrpos(unsigned long long nb);
void				ft_putchar(char c);
void				ft_putstr(char const *s);

long double			ft_pow(long double num, int power);
void 				ft_write(char *s, int len);
void 				ft_putnstr(char *str, size_t n);
int					ft_module(int a);
void 				ft_memswap(char *s1,char *s2);
int 				ft_max(int a, int b);
char				*ft_itoabase(long long num, char* str, int base);
char				*ft_itoabaseunsigned(unsigned long long num, char* str, int base);
void 				reverse(char str[], int length);
void				ft_putupstr(char *s);

/*
 * printf function
 */

int					ft_printf(char* format, ...);
int					ft_format(char *ss, va_list ap);
/*
 * parsers for format-string: width, precision, flags, conversion and type
 */

int 				ft_len_to_type(char *s);
int 				ft_parse_name(char *s);
int					*ft_parse_flag(int num, char *ss);
int 				ft_parse_width(char *ss);
int 				ft_parse_precision(char *ss);
int 				ft_parse_size(char *ss);
int 				ft_checkzero(char *ss);
/*
 * int handlers
 */

void				ft_int(char *ss, va_list ap);
void				ft_flagint(long long num, char *ss);
int					ft_intlen(long long int num);
void				ft_intleft(long long num, t_format form);
void				ft_intright(long long num, t_format form);

/*
 * str handlers
 */

void 				ft_flagstr(char *str, char *ss);
void 				ft_flagpercent(char *ss);
void				ft_flagchar(char *ss, char c);

/*
 * unsigned int handlers(u)
 */

void				ft_unsignedint(char *ss, va_list ap);
void				ft_flagunsignedint(unsigned long long num, char *ss);
void				ft_unsignedintright(unsigned long long num, t_format form);
void				ft_unsignedintleft(unsigned long long num, t_format form);
int					ft_unsignedintlen(unsigned long long int num);

/*
 * octet handlers(O)
 */

void				ft_octet(char *ss, va_list ap);
void				ft_flagoctet(unsigned long long num, char *ss);
/*
 * base 16 ints handlers(xX)
 */
void				ft_xtet(char *ss, va_list ap, int mode);
/*
 * floats handlers
 */

void				ft_float(char *ss, va_list ap);
int 				ft_doublelen(double num);

/*
 * pointers
 */
void				ft_ptet(char *ss, va_list ap);
#endif

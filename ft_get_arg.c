/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/30 11:55:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	get_int_flagged(va_list va, char c, char d)
{
	long long int	out;

	if (c == 'H')
		out = (signed char)va_arg(va, int);//auto promoted
	else if (c == 'l' || ('A' <= d && d <= 'Z'))
		out = va_arg(va, long);
	else if (c == 'h')
		out = (short)va_arg(va, int);
	else if (c == 'L')
		out = va_arg(va, long long);
	else if (c == 'j')
		out = va_arg(va, intmax_t);
	else // (c == 'z')
		out = va_arg(va, ssize_t);//+-= signed size_t
	return (out);
}

long long int	get_uint_flagged(va_list va, char c, char d)
{
	long long int	out;

	out = 0;
	if (c == 'H')
		out = (unsigned char)va_arg(va, unsigned int);
	else if (c == 'l' || ('A' <= d && d <= 'Z'))
		out = va_arg(va, unsigned long);
	else if (c == 'h')
		out = (unsigned short)va_arg(va, unsigned int);
	else if (c == 'L')
		out = va_arg(va, unsigned long long);
	else if (c == 'j')
		out = va_arg(va, uintmax_t);
	else // (c == 'z')
		out = va_arg(va, size_t);
	return ((unsigned long long)out);
}

long long int	get_arg_nb(va_list va, char c, char *flag)
{
	long long int	out;

	if (flag[3] || ft_get_char("DIOU", flag[4]) != -1)
	{
		if (ft_get_char("ouxOUX", c) != -1)
			out = get_uint_flagged(va, flag[3], flag[4]);
		else //(ft_get_char("DIdi", c) != -1)
			out = get_int_flagged(va, flag[3], flag[4]);
	}
	else
	{
		if (ft_get_char("di", c) != -1)
			out = va_arg(va, int);
		else if (ft_get_char("ouxX", c) != -1)
			out = va_arg(va, unsigned int);
		else //(c == 'p')
			out = va_arg(va, long long);//puis printf hexa prefixe de 0x
	}
	//printf("out vaut ca = %lli\n", out);
	return (out);
}

void			get_arg(va_list va, char *flag, int *tab, t_data s)
{
	long long int	lli;

	lli = 0;
	if (flag[4] == '%')
		lli = 1;
	else if (flag[4] == 'C' || (flag[3] == 'l' && flag[4] == 'c'))
		s.c_spe = va_arg(va, wchar_t);
	else if (flag[4] == 's' && flag[3] != 'l')
		s.s = va_arg(va, const char *);
	else if (flag[4] == 'S' || (flag[3] == 'l' && flag[4] == 's'))
		s.s_spe = va_arg(va, wchar_t *);
	else if (flag[4] == 'c')
		s.c = va_arg(va, int);
	else //(ft_get_char("pdiouxDIOUX", flag[4]) != -1)
		lli = get_arg_nb(va, flag[4], flag);
	if (lli < 0)
	{
		flag[2] = '-';
		lli = -lli;
	}
	if (ft_get_char("pdiouxDIOUX%", flag[4]) != -1)
		do_nb(flag, tab, lli);
	else
		do_wrd(flag, tab, s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/21 09:54:40 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	get_int_flagged(va_list va, char c, char d)
{
	long long int	out;

	if (c == 'H')
		out = va_arg(va, signed char);//auto promoted
	else if (c == 'h')
		out = va_arg(va, short);
	else if (c == 'l' || ('A' <= d && d <= 'Z'))
		out = va_arg(va, long);
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

	if (c == 'H')
		out = va_arg(va, unsigned char);
	else if (c == 'h')
		out = va_arg(va, unsigned short);
	else if (c == 'l' || ('A' <= d && d <= 'Z'))
		out = va_arg(va, unsigned long);
	else if (c == 'L')
		out = va_arg(va, unsigned long long);
	else if (c == 'j')
		out = va_arg(va, uintmax_t);
	else // (c == 'z')
		out = va_arg(va, size_t);
	return (out);
}

long long int	get_arg_nb(va_list va, char c, char *flag)
{
	long long int	out;

	if (flag[3] || ft_get_char("DIOUX", flag[4]) != -1)
	{
		if (ft_get_char("ouxOUX", c) != -1)
			out = get_uint_flagged(va, flag[3], flag[4]);
		else if (ft_get_char("DIdi", c) != -1)
			out = get_int_flagged(va, flag[3], flag[4]);
	}
	else
	{
		if (ft_get_char("diouX", c) != -1)
			out = va_arg(va, int);
		if (c == 'p')
			out = va_arg(va, long long);//puis printf hexa prefixe de 0x10
		else if (c == 'c' && flag[3] != 'l')
			out = va_arg(ca, char);
	}
	return (out);
}

void			get_arg(va_list va, char *flag, int *tab)
{
	long long int	lli;
	struct			s_data;

	if (flag[4] == 'C' || (flag[3] == 'l' && flag[4] == 'c'))
		c_spe = va_arg(va, wint_t);
	else if (flag[4] == 's' && flag[3] != 'l')
		s = va_arg(va, const char *);
	else if (flag[4] == 'S' || (flag[3] == 'l' && flag[4] == 's'))
		s_spe = va_arg(va, wchar_t *);
	else if (ft_get_char("pcdiouxDIOUX", flag[4]) != -1)
		lli = get_arg_nb(va, flag[4], flag);
	if (lli < 0)
	{
		flag[2] == '-';
		lli = -lli;
	}//code utile pr print beg
	//gerer ensuite appel de fonction en fonction du flag;
	if (lli && flag[4] != 'c')
		write_nb(lli, flag, );//pb passer flag + tab d'int => struct ?
	else
		write_wrd();
}

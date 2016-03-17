/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/17 17:55:56 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	get_type(va_list va, char c, char *flag)
{
	long long int	big_fat;

	if (c == 'H' || c == 'h')
		big_fat = va_arg(va, int);//auto-promoted
	if (c == 'l' && flag[4] != 's' && flag[4] != 'c')
		big_fat = va_arg(va, long int);
	if (c == 'L')//pas sur cette ligne
		big_fat = va_arg(va, long long int);
	if (c == 'j')
		big_fat = va_arg(va, intmax_t);
	else (c == 'z')
		big_fat = va_arg(va, size_t);
	return (big_fat);
}

int		get_arg(va_list va, char **str, char *flag)
{
	long long int	big_fat;
	const char		*new_str;
	wint_t			g;
	wchar_t			*new_big_str;

	if (get_char("ipcdouxDOUX", flag[4]))//plus la meme condition
		big_fat = get_type(va, flag[3], flag);
	else
	{
		if (flag[4] == 's' && flag[3] != l)//p-e segfault si !flag[3] normalement ok car flag[3] == '\0'
			new_str = va_arg(va, const char *);
		if (flag[4] == 'S' || (flag[3] == 'l' && flag[4] == 's'))
			new_big_str = va_arg(va, wchar_t *);
		if (flag[4] == 'C' || (flag[3] == 'l' && flag[4] == 'c'))
			g = va_arg(va, wint_t);
	}
}

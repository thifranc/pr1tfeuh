/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:30:55 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/25 10:05:16 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *str)
{
	char	*out;

	if (!(out = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	ft_strcpy(out, str);
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <savas11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:21 by savas11           #+#    #+#             */
/*   Updated: 2022/09/08 22:26:22 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	end;

	i = 0;
	if (!s || ((start + 1) == 0) || (len + 1) == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*s) * (len) + 1)))
		return (NULL);
	end = start + len;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return ((char *)str);
}

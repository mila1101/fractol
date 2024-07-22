/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:42:45 by msoklova          #+#    #+#             */
/*   Updated: 2024/03/18 16:16:50 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	j;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = dstlen;
	i = 0;
	if (j < dstsize)
	{
		while (j < dstsize - 1 && src[i] != '\0')
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	else
		return (srclen + dstlen);
}

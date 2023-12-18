/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:33:49 by razaccar          #+#    #+#             */
/*   Updated: 2023/11/02 01:23:43 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	i = dst_len;
	while (src[dst_len - i] && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[dst_len - i];
		dst_len++;
	}
	if (i < dstsize)
		dst[dst_len] = 0;
	return (i + ft_strlen(src));
}

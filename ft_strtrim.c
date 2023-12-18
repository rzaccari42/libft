/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:58:31 by razaccar          #+#    #+#             */
/*   Updated: 2023/11/02 01:23:21 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	while (ft_inset(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_inset(s1[i], set))
		i--;
	len = i - start + 1;
	return (ft_substr(s1, start, len));
}

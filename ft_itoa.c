/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:01:20 by razaccar          #+#    #+#             */
/*   Updated: 2023/11/02 01:25:29 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= -10;
		len = 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	nbr = malloc((ft_nbrlen(n) + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	i = ft_nbrlen(n);
	nbr[i] = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		nbr[--i] = -(n % 10) + 48;
		if (n < -9)
			n /= -10;
	}
	if (n == 0)
		nbr[--i] = (n % 10) + 48;
	while (n > 0)
	{
		nbr[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (nbr);
}

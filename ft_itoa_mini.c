/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:08:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:08:32 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long int n)
{
	if (n < 0)
		return (1 + count(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + count(n / 10));
}

static void	base(long int n, char *number, long int i)
{
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		base((n / 10), number, (i - 1));
	}
	number[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*num_char;
	long int	len;

	len = count(n);
	num_char = (char *)malloc((len + 1) * sizeof(char));
	if (!num_char)
		return (NULL);
	num_char[len] = '\0';
	base(n, num_char, --len);
	return (num_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:10:13 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:10:14 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convertions_fd(int fd, const char *str, int i, va_list arg)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar_fd(va_arg(arg, int), fd);
	else if (str[i] == 's')
		count += ft_putstr_fd(va_arg(arg, char *), fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	t_arg;
	int		str_len;
	int		count;
	int		i;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	str_len = ft_strlen((char *)str);
	va_start(t_arg, str);
	while (++i < str_len)
	{
		if (str[i] == '%')
		{
			i += 1;
			count += convertions_fd(fd, str, i, t_arg);
		}
		else
			count += ft_putchar_fd(str[i], fd);
	}
	va_end(t_arg);
	return (count);
}

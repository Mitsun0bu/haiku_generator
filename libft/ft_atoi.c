/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:52:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 22:30:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:05:03 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/15 13:50:39 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32)
		return (1);
	return (0);
}

static int	ft_checkoverflow(long int nbr, long int sign)
{
	if (nbr > 2147483647 && sign == 1)
		return (-1);
	if (nbr > 2147483648 && sign == -1)
		return (-1);
	return ((int)nbr * sign);
}

int	ft_atoi(const char *str)
{
	long int	nbr;
	int			i;
	long int	sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i ++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (ft_checkoverflow(nbr, sign));
}
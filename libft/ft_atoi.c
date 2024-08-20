/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 04:02:27 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 18:05:54 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int num)
{
	if (num == '\t' || num == '\n' || num == '\r'
		|| num == '\f' || num == '\v' || num == ' ')
		return (1);
	else
		return (0);
}

void	ft_sign(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' && str[(*i) + 1] != '-')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
}

int	checklast(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	ft_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 255 && sign == 1)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && !checklast((char *)&str[i]))
		return (-1);
	return (sign * res);
}

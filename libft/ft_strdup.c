/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:16:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 18:06:28 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *) s1;
	cpy = malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (i < len)
	{
		cpy[i] = *str;
		i++;
		str++;
	}
	cpy[len] = '\0';
	return (cpy);
}

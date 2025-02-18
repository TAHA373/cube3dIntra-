/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:10:14 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 18:06:52 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		dlen = dstsize;
	if (dlen == dstsize)
		return (slen + dstsize);
	if (slen < dstsize - dlen)
		ft_memcpy(&dst[dlen], src, slen + 1);
	else
	{
		ft_memcpy(&dst[dlen], src, dstsize - dlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dlen + slen);
}

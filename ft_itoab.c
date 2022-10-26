/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:48 by samartin          #+#    #+#             */
/*   Updated: 2022/10/20 16:09:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Add if long_min case is solved:
// #include <limits.h>
// Add when integrate:
// #include "libft.h"
#include <stdlib.h>

// Remove when integrated:
static char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = -1;
	while (src[++pos] != 0)
		dest[pos] = src[pos];
	dest[pos] = src[pos];
	return (dest);
}

static int	drop_d(char *str, long n, unsigned int base, int sign)
{
	unsigned long	dig;
	char			base_symbols[33];

	dig = 0;
	ft_strcpy (base_symbols, "0123456789ABCDEFGHIJKLMNOPQRSTUV");
/* I have to see this case in depth, is a very rare but cruel exception.
   Solution was only for decimal.

	if (n == LONG_MIN)
	{
		str[0] = '9';
		n = n / 10;
		dig++;
	}
*/
	while ((n * sign) >= base)
	{
		str[dig] = base_symbols[(n % base) * sign];
		n = n / base;
		dig++;
	}
	str[dig] = base_symbols[n * sign];
	if (sign == -1)
	{
		dig++;
		str[dig] = '-';
	}
	str[dig + 1] = '\0';
	return (dig + 1);
}

static void	rev_str(char *str_dst, char *str_org, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		str_dst[i] = str_org[len - i - 1];
		i++;
	}
	str_dst[i] = '\0';
}

char	*ft_itoab(long n, unsigned int base)
{
	char			strswp[66];
	char			*nb_as_str;
	unsigned long	dig;
	int				sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dig = drop_d (strswp, n, base, sign);
	nb_as_str = malloc ((dig + 1) * (sizeof(char)));
	if (!nb_as_str)
		return (0);
	rev_str(nb_as_str, strswp, dig);
	return (nb_as_str);
}

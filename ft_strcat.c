/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:45:40 by samartin          #+#    #+#             */
/*   Updated: 2022/10/21 11:46:01 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strcat(char *dest, char *src)
{
	int	pos1;
	int	pos2;

	if (!dest)
		return (0);
	pos1 = 0;
	pos2 = 0;
	while (dest[pos1])
		pos1++;
	while (src && src[pos2])
	{
		dest[pos1] = src[pos2];
		pos1++;
		pos2++;
	}
	dest[pos1] = 0;
	return (dest);
}

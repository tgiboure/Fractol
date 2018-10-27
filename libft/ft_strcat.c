/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: togibour <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:15:42 by togibour     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:20:57 by togibour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i1;
	unsigned int	i2;

	i1 = ft_strlen(s1);
	i2 = 0;
	while (s2[i2])
	{
		s1[i1] = s2[i2];
		i1++;
		i2++;
	}
	s1[i1] = 0;
	return (s1);
}

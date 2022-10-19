/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:34:09 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/19 15:13:32 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main()
{
	char	a[] = "mm";
	char	b[]= "aa";
	int		c;
	int		d;

	c = strncmp(a, b, 0);
	d = ft_strncmp(a, b, 0);
	printf("%d\n", c);
	printf("%d\n", d);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:49:33 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:41:08 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && str[i + j] == to_find[j]
				&& (size_t)(i + j) < len)
				j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

/*int	main()
{
	char	a[] = "coronavirus, pour se proteger, il faut";
	char	b[] = "ona";
	char	*c;

	printf("%s\n", a);
	c = ft_strnstr(a, b, 30);
	printf("%s\n", c);
	return (0);
}*/

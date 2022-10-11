/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:10:58 by emiinatch         #+#    #+#             */
/*   Updated: 2022/10/11 20:40:13 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (a == b || n == 0)
		return (0);
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		if (n)
		{
			a++;
			b++;
		}	
	}
	return (0);
}

/*int	main()
{
	char	a[] = "ab";
	char	b[] = "a";
	int	comp;
	int	fonction;

	printf("%s\n", a);
	printf("%s\n", b);
	comp = ft_memcmp(a, b, 1);
	fonction = memcmp(a, b, 1);
	printf("%d\n", comp);
	printf("%d\n", fonction);
	return (0);
}*/

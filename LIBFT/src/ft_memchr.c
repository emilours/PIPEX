/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:57:48 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:10 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while (str && n--)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (0);
}

/*int	main()
{
	char	a[] = "Je suis devant la tele";
	char	*b;

	printf("%s\n", a);
	b = ft_memchr(a, 't', 17);
	printf("%s\n", b);
	return (0);

	//J'ai cree la variable *b car incompatibilite const void et printf//
	//pas possible de modifier une const, ni me deplacer dedans.//
}*/

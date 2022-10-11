/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:13:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:41:11 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = 0;
	while (*s)
	{
		if (*s == (char)c)
			str = (char *)s;
		++s;
	}
	if (str)
		return (str);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/*int		main()
{
	char	s[]= "je suis . devant le tele . ok";
	char	*a;
	char	*b;

	printf("%s\n", s);
	a = ft_strrchr(s, '.');
	b = strrchr(s, '.');
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}*/

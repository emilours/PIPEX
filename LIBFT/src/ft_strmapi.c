/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:32:33 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:58 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*s2;

	len = ft_strlen(s);
	i = 0;
	s2 = malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*static char	f(unsigned int i, char a)
{
	return (a + i);
}

int	main()
{
	char	s[] = "hello";
	char	*s2;

	s2 = ft_strmapi(s, f);
	printf("%s\n", s2);
	return (0);
}*/

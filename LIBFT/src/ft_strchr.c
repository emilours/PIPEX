/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:37:33 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:38 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (0);
		str++;
	}
	return (str);
}

/*int	main()
{
	char	s[] = "Je suis devant la tele de ma tante";
	char	*u;
	
	printf("%s\n", s);
	u = ft_strchr(s,'d');
	printf("%s\n", u);
	return (0);
}*/

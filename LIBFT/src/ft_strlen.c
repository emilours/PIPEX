/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:27:26 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/13 14:43:55 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\0')
		len++;
	return (len);
}

/* int	main()
{
	char	str1[] = "Hello la Terre";
	char	*str2 = NULL;

	printf("%ld\n", ft_strlen(str1));
	printf("%ld\n", ft_strlen(str2));
	printf("%ld\n", strlen(str2));
	return (0);
} */
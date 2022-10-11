/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:39:23 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:08 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	find_len(int n, int *flag)
{
	size_t	len;

	*flag = 0;
	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		*flag = 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_bis(int len)
{
	char	*s;

	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*s;
	int		flag;

	len = find_len(n, &flag);
	s = ft_itoa_bis(len);
	i = 0;
	while (len-- > i)
	{
		if (flag == 1)
			s[0] = '-';
		if (n < 0)
		{
			s[len] = '0' + n % 10 * (-1);
			n = n / 10;
		}
		else if (flag == 0)
		{
			s[len] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (s);
}

/* int	main()
{
	char *s;

	s = ft_itoa(0);
	printf("%s\n", s);
	printf("%d\n", itoa(0));
	free(s);
	return (0);
} */

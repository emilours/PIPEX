/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:48:55 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:03 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int i)
{
	if (!(i >= '0' && i <= '9'))
		return (0);
	return (1);
}

/*int	main()
{
	char	a = 'g';
	char	b = '?';
	char	c = '9';
	int	d = 9;

	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(d));
	return (0);
}*/

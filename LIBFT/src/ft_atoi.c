/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:59:01 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:39:43 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		signe;
	int		resultat;

	s = (char *)str;
	i = 0;
	signe = 1;
	resultat = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		resultat = resultat * 10 + s[i] - '0';
		i++;
	}
	return (resultat * signe);
}

/*int main()
{
    char    s[] = "    -128aa2-";
    int    p;
    int    q;

    printf("%s\n", s);
    p = ft_atoi(s);
    q = atoi(s);
    printf("%d\n", p);
    printf("%d\n", q);
    return (0);
}*/

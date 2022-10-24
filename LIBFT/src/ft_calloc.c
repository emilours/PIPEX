/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:42:20 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/24 15:12:30 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*res;

	res = malloc(nb * size);
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	ft_bzero(res, nb * size);
	return (res);
}
/*Cette fonction alloue un bloc de mémoire en initialisant 
tous ces octets à la valeur 0. Diff avec malloc :
> initialisation: C met tous les octets du bloc à la valeur 0
alors que M ne modifie pas la zone de mémoire.
> paramètresi: C prend deux paramètres (nb d'éléments à allouer
+  la taille d'un élément) 
/ M > la taille du bloc à allouer.
4294967295 * 2545 / 4294967295 != 2545*/

/*#include <stdio.h>

int	main()
{
	char	**tab;
	int	i = 0;
	char	*t;

	tab = malloc(sizeof(char *) * 5); //prevoir taille totale
	tab[0] = ft_strdup("salut");
	tab[1] = ft_strdup(" 42");
	tab[2] = ft_strdup(" ca va?");
	tab[3] = 0; //securiser tableau de tableau de char, pas our int
	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	t = ft_calloc(2, sizeof(tab));
	printf("%s\n", t);
	return (0);
}*/
//int main()
// {
// 	char *str;
// 	char *str2;

// 	str = calloc(0, 0);
// 	free (str);
// 	str2 = ft_calloc(0, 0);
// 	free (str2);
// }

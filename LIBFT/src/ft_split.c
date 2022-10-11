/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:31:45 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:35 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_split(char **a)
{
	size_t	i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
	return (NULL);
}

static char	**ft_split_bis(const char *s, char c, size_t *words)
{
	char	**tab;

	*words = count(s, c);
	tab = malloc(sizeof(char *) * (*words + 1));
	if (!tab)
		return (NULL);
	if (s == 0)
		return (ft_free_split(tab));
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	word;
	size_t	words;

	word = 0;
	i = 0;
	tab = ft_split_bis(s, c, &words);
	while (word < words)
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tab[word] = malloc((sizeof(char) * j) + 1);
		if (!tab[word])
			return (ft_free_split(tab));
		ft_strlcpy(tab[word], s + i, j + 1);
		i = i + j;
		word++;
	}
	tab[word] = NULL;
	return (tab);
}

// int    main(void)
// {
//     int        i;
//     char    charset = ' ';
//     char    *tab = "  tripouille  42   blabla   ";
//     char    **result;

//     i = 0;
//     result = ft_split(tab, charset);
//     while (result[i])
//     {
//         printf("%s\n", result[i]);
//         i++;
//     }
//     for (size_t j = 0; result[j]; j++)
//     {
//         free(result[j]);
//     }
//     free(result);
//     return (0);
// }
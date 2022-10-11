/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:31:29 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:18 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cpy_dest;
	const unsigned char	*cpy_src;
	size_t				i;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	i = 0;
	if (cpy_dest > cpy_src)
	{
		while (n > 0)
		{
			cpy_dest[n - 1] = cpy_src[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			cpy_dest[i] = cpy_src[i];
			i++;
		}
	}
	return (dest);
}

/*int main()
{
    char    dest[] = "coucou";
    char    src[] = ".......";

    printf("%s\n", dest);
    ft_memmove(src, dest, 2);
    printf("%s\n", src);
    return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:31:16 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:15 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cpy_dest;
	const unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	while (n > 0)
	{
		*cpy_dest = *cpy_src;
		cpy_src++;
		cpy_dest++;
		n--;
	}
	return (dest);
}

/*int main()
{
    char    one[] = "myrtille";
    char    two[50] = "";

    printf("%s\n", one);
    ft_memcpy(two, one, 4);
    printf("%s\n", two);
    return (0);
}*/

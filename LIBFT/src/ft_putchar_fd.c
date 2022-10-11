/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:12:15 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:24 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*Sur Unix, lorsqu'un processus manipule un fichier, 
il utilise le concept de DS
Un DS a une valeur entière non négative.
Si un fichier est ouvert alors qu'un processus est en cours d'exécution, 
le noyau alloue le plus petit nombre inutilisé de DS pour le processus. 
Ensuite, lorsque le processus accède au fichier ouvert
 à l'aide d'un appel système, 
le fichier peut être référencé à l'aide de la valeur du DS (FD).
destructeur defichier, assigné par défaut
- 0 : entrée standard
- 1 : Sortie Standard
- 2 : erreur type*/

// #include <fcntl.h>

// int main()
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDWR);
// 	if (fd == -1)
// 		printf("Error Open");
// 	ft_putchar_fd('c', fd);
// 	ft_putchar_fd('d', fd);
// 	if (close(fd) == -1)
// 		printf("Error close");
// }
// https://www.emi.ac.ma/~ntounsi/COURS/C/CC/C-IO.html
// On peut utiliser les constantes standards symboliques
//(dites drapeau ou flag) macro-définies dans <fcntl.h>
// O_RDONLY pour 0 donc lecture seule (ReaDONLY),
// O_WRONLY pour 1 donc écriture seule (WRiteONLY) et
// O_RDWR pour 2 donc lecture et écriture (ReaDWRite).
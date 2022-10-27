/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:03:07 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/27 20:10:50 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:28:28 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/26 20:44:17 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//donner valeurs erreur en initiaisant pour voir si changement par
//la suite dans fonction
void	ft_init_cmd(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->exit_code = 0;
	pipex->status = 0;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->parts = NULL;
	pipex->path_from_envp = NULL;
	pipex->my_paths = NULL;
	pipex->path = NULL;
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	dot_or_slash_case(char *cmd)
{
	if (cmd == NULL )
		return (1);
	if (cmd[0] == '.' && cmd[1] != '/')
		return (1);
	if (cmd[0] == '.' && cmd[1] == '/')
		return (2);
	if (cmd[0] == '/' && access(cmd, X_OK) != 0)
		return (2);
	return (0);
}

int	space(char *argv)
{
	int	len;

	len = ft_strlen(argv) - 1;
	if (argv[0] == ' ' || argv[len] == ' ')
		return (1);
	return (0);
}

void	ft_err(char *ft, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(ft, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:03:07 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/01 16:42:32 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* init structure's values */
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

/* frees the memory space pointed to by **str */
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

/* cmd is not executable if '/' or '.' */
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

/* cmd is not executable if space before or at the end of cmd */
int	space(char *argv)
{
	int	len;

	len = ft_strlen(argv) - 1;
	if (argv[0] == ' ' || argv[len] == ' ')
		return (1);
	return (0);
}

/* allows writting of error msg */
void	ft_err(char *ft, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(ft, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
}

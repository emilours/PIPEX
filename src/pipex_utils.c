/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:56:51 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/02 20:09:58 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* find PATH in envp variable */
char	*find_path(char *cmd, char **envp, t_pipex *pipex)
{
	int		i;

	i = 0;
	if (dot_or_slash_case(cmd) != 0)
		return (NULL);
	if (access(cmd, F_OK || X_OK) == 0)
		return (cmd);
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	pipex->my_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (pipex->my_paths && pipex->my_paths[i])
	{
		pipex->parts = ft_strjoin(pipex->my_paths[i], "/");
		pipex->path_from_envp = ft_strjoin(pipex->parts, cmd);
		free(pipex->parts);
		if ((access(pipex->path_from_envp, F_OK | X_OK)) == 0)
			return (pipex->path_from_envp);
		free(pipex->path_from_envp);
		i++;
	}
	ft_free(pipex->my_paths);
	return (NULL);
}

/* access checks whether the calling process can access 
the file pathname. Execve executes the program referred
to by pathname.*/
void	check_path(char **envp, t_pipex *pipex, char **cmd)
{
	if (pipex->path == NULL)
	{
		if (dot_or_slash_case(*cmd) == 2 && access(*cmd, X_OK))
		{
			ft_err(*cmd, strerror(errno));
			write(2, "\n", 1);
		}
		else
			ft_err(*cmd, "command not found\n");
		ft_free(cmd);
		exit(127);
	}
	else if (access(pipex->path, X_OK) == 0)
	{
		if (execve(pipex->path, cmd, envp) == -1)
		{
			free(pipex->path);
			ft_free(cmd);
			exit(127);
		}
	}
}

void	cmd_process(char *argv, char **envp, t_pipex *pipex)
{
	char	**cmd;

	if (space(argv) == 1)
	{
		ft_err(argv, "command not found\n");
		exit(127);
	}
	cmd = ft_split(argv, ' ');
	if (*envp != NULL)
		pipex->path = find_path(cmd[0], envp, pipex);
	check_path(envp, pipex, cmd);
}

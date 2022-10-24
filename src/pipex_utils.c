/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/24 19:52:14 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, < >)
{
	char	**my_paths;
	char	*path_from_envp;
	int		i;
	char	*parts;

	i = 0;
	if (cmd == NULL )
		return (NULL);
	if (cmd[i] == '.' && cmd[i + 1] != '/')
	{
		ft_err(cmd, "command not found\n");
		return (NULL);
	}
	if (cmd[i] == '.' && cmd[i + 1] == '/')
	{	
		ft_err(cmd, "No such file or directory");
		write(2, "\n", 1);
		return (NULL);
	}
	if (access(cmd, F_OK || X_OK) == 0)
		return (cmd);
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
			i++;
	my_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (my_paths[++i])
	{
		parts = ft_strjoin(my_paths[i], "/");
		path_from_envp = ft_strjoin(parts, cmd);
		free(parts);
		if ((access(path_from_envp, F_OK | X_OK)) == 0)
			return (path_from_envp);
		free(path_from_envp);
	}
	i = -1;
	while (my_paths[++i])
		free(my_paths[i]);
	free(my_paths);
	return (NULL);
}

int	space(char *argv, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[0] == ' ')
			return (1);
		if (argv && argv[0] != ' ')
		{
			while (argv[i] != '\0' && argv[i] != ' ')
				i++;
			while (argv[i] == ' ')
			{
				pipex->count_space++;
				i++;
			}
			if (pipex->count_space == 1)
				return (1);
			if (pipex->count_space > 1)
				return (0);
		}
		if (argv[pipex->len] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_err(char *ft, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(ft, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
}

void	my_cmd(char *argv, char **envp, t_pipex *pipex)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	if (space(argv, pipex) == 1)
	{
		ft_err(argv, "command not found\n");
		exit(127);
	}
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		if (cmd[0] == NULL)
			ft_err(*cmd, "command not found\n");
		ft_free(cmd);
		exit(127);
	}
	else if (execve(path, cmd, envp) == -1)
	{
		ft_free(cmd);
		exit(127);
	}
}

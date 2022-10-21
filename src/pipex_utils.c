/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/21 18:23:04 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
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
		ft_err(cmd, "command not found");
		write(2, "\n", 1);
		exit(127);
	}
	if (cmd[i] == '.' && cmd[i + 1] == '/')
	{	
		ft_err(cmd, "No such file or directory");
		write(2, "\n", 1);
		exit(127);
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

int	space(char *argv)
{
	int	len;
	int	i;
	int	count_space;

	len = ft_strlen(argv) - 1;
	i = 0;
	count_space = 0;
	if (argv[i] == ' ')
		return (1);
	while (argv[i])
	{
		if (argv[0] == ' ')
			return (1);
		if (argv && argv[0] != ' ')
		{
			while (argv && argv[i] != ' ')
				i++;
			while (argv[i] == ' ')
			{
				count_space++;
				i++;
			}
			if (count_space == 1)
				return (0);
			if (count_space > 1)
				return (1);
		}
		if (argv[len] == ' ')
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

void	my_cmd(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	if (space(argv) == 1)
	{
		ft_err(argv, "command not found\n");
		exit(127);
	}
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_err(*cmd, "command not found\n");
		free(cmd);
		exit(127);
	}
	else if (execve(path, cmd, envp) == -1)
	{
		// perror("pipex1:");
		exit(127);
	}
}

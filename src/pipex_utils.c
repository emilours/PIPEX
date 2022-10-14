/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/14 18:28:45 by eminatch         ###   ########.fr       */
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
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	my_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (my_paths[i])
	{
		parts = ft_strjoin(my_paths[i], "/");
		path_from_envp = ft_strjoin(parts, cmd);
		free(parts);
		if ((access(path_from_envp, F_OK | X_OK)) == 0)
			return (path_from_envp);
		free(path_from_envp);
		i++;
	}
	i = -1;
	while (my_paths[++i])
		free(my_paths[i]);
	free(my_paths);
	return (0);
}

void	my_cmd(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
	}
	if (execve(path, cmd, envp) == -1)
		perror("bad execution of execve");
}

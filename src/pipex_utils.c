/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/20 22:30:02 by eminatch         ###   ########.fr       */
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
	if (cmd[i] == '.' && cmd[i + 1] == '/')
	{	
		write(2, "pipex: ", 8);
		write(2, &cmd[i++], ft_strlen(cmd));
		write(2, ": No such file or directory\n", 29);
		exit(127);
		// return (NULL);
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
	
	len = ft_strlen(argv) - 1;
	i = 0;
	 if (argv[i] == ' ')
	 		return (1);
	while (argv[i])
	{
		if (argv[0] == ' ')
			return (1);
		if (argv[len] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	my_cmd(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;
	
	i = -1;
	if (space(argv) == 1)
		exit(127);
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		free(cmd);
		perror("pipex:");
		//write(2, "pipex3: : command not found\n", 28);
		exit(127);
	}
	else if (execve(path, cmd, envp) == -1)
	{
		perror("pipex:");
		exit(127);
	}
}

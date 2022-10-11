/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/11 20:44:10 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		perror("bad file descriptor");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	my_cmd(argv[2], envp);
}

void	cmd2(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY);
	if (fileout == -1)
		perror("bad file descriptor");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	my_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	while (argc)
	{
		if (pipe(fd) == -1)
			perror("bad file descriptor");
		pid = fork();
		if (!pid)
			perror("bad process execution");
		if (pid == 0)
			cmd1(argv, envp, fd);
		waitpid(pid, NULL, 0); // null pour status
		cmd2(argv, envp, fd);
	}
	return (0);
}

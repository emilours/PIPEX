/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/14 17:34:22 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(char **argv, char **envp, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		perror("No such a file or directory");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	my_cmd(argv[2], envp);
}

void	cmd2(char **argv, char **envp, int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		perror("outfile descriptor");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	my_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid0;
	int	pid1;

	if (argc <= 5)
	{
		if (pipe(pipefd) == -1)
			perror("pipefd error");
		pid0 = fork();
		if (pid0 == -1)
			return (perror("PID"), 1);
		if (pid0 == 0)
			cmd1(argv, envp, pipefd);
		pid1 = fork();
		if (pid1 == -1)
			return (perror("PID"), 1);
		if (pid1 == 0)
			cmd2(argv, envp, pipefd);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid0, NULL, 0);
		waitpid(pid1, NULL, 0);
	}
	return (0);
}

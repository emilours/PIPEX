/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/18 21:53:59 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(char **argv, char **envp, int *fd, int i, int infile, int outfile)
{
	if (i == 0)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(errno);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	if (i == 1)
	{
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(1);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	close(fd[1]);
	close(fd[0]);
	my_cmd(argv[i + 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid0;
	int	exit_code = 0;
	int i = -1;
	int j = -1;
	int infile = 0;
	int outfile = 0;
	int	status = 0;

	if (argc <= 5)
	{
		while (++i < 2)
		{
			if (pipe(pipefd) == -1)
				write(2, ": No such file or directory\n", 28);
			pid0 = fork();
			if (pid0 == -1)
				write(2, ": No such file or directory\n", 28);
			if (pid0 == 0)
				cmd1(argv, envp, pipefd, i, infile, outfile);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		while (++j < 2)
		{
			wait(&status);
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
	}
	exit(exit_code);
	return (0);
}

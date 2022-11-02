/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:57:06 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/02 15:22:58 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Open creates a new open file description, with flags.
 Dup allocates a new fd that refers to the same open fd as the oldfd.
 What is written is kept until reading. */
void	infile_process(char **argv, int i, t_pipex *pipex)
{
	if (i == 0)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
		{
			ft_err(argv[1], strerror(errno));
			write(2, "\n", 1);
			exit(errno);
		}
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->pipefd[1]);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
}

void	outfile_process(char **argv, int i, t_pipex *pipex)
{
	if (i == 1)
	{
		pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile == -1)
		{
			ft_err(argv[4], strerror(errno));
			write(2, "\n", 1);
			exit(1);
		}
		dup2(pipex->pipefd[0], STDIN_FILENO);
		close(pipex->pipefd[0]);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
}

void	child_process(char **argv, char **envp, int i, t_pipex *pipex)
{
	if (i == 0)
		infile_process(argv, i, pipex);
	if (i == 1)
		outfile_process(argv, i, pipex);
	close(pipex->pipefd[1]);
	close(pipex->pipefd[0]);
	cmd_process(argv[i + 2], envp, pipex);
}

/* The wait call suspends execution of the calling process 
until one of its children terminates. Wifexited returns true 
if the child terminated normally and allow wifexitstatus, 
the exit status of the child */
void	close_and_wait(t_pipex *pipex)
{
	int	j;

	j = -1;
	close(pipex->pipefd[1]);
	close(pipex->pipefd[0]);
	while (++j < 2)
	{
		waitpid(pipex->pid[j], &pipex->status, 0);
		if (WIFEXITED(pipex->status))
			pipex->exit_code = WEXITSTATUS(pipex->status);
	}
}

/* pipe creates unidirectional data channel that can be
used for interprocess communication. fork creates a new 
process by duplicating the calling process. The new process
is referred to as the child process and calling
process is referred to as the parent process. */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	i = -1;
	ft_init_cmd(&pipex);
	if (argc == 5)
	{
		if (pipe(pipex.pipefd) == -1)
		{
			perror("pipex:");
			return (0);
		}
		while (++i < 2)
		{
			pipex.pid[i] = fork();
			if (pipex.pid[i] == -1)
				perror("pipex: ");
			if (pipex.pid[i] == 0)
				child_process(argv, envp, i, &pipex);
		}
		close_and_wait(&pipex);
	}
	exit(pipex.exit_code);
	return (0);
}

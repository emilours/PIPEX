/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/19 19:35:33 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(char **str)
{	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}


//donner valeurs erreur en initiaisant pour voir si changement par
//la suite dans fonction
void	ft_init_cmd(t_pipex *pipex)
{
    pipex->infile = -1;
	pipex->outfile = -1;
	pipex->exit_code = 0;
	pipex->status = 0;
	pipex->pid = 0;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
}

// je recois un pointeur en parametre > struc = ->
// si R, alors declare struc en variable > .
void	cmd1(char **argv, char **envp, int i, t_pipex *pipex)
{
	if (i == 0)
	
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(errno);
		}
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->pipefd[1]);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	if (i == 1)
	{
		pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(1);
		}
		dup2(pipex->pipefd[0], STDIN_FILENO);
		close(pipex->pipefd[0]);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	close(pipex->pipefd[1]);
	close(pipex->pipefd[0]);
	my_cmd(argv[i + 2], envp);
}

// &pipex: valeur modifiee / pipex: valeur lue //
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int i = -1;
	int	j = -1;
	
	ft_init_cmd(&pipex);
	if (argc <= 5)
	{
		if (pipe(pipex.pipefd) == -1)
			write(2, strerror(errno), ft_strlen(strerror(errno)));;
		while (++i < 2)
		{
			pipex.pid = fork();
			if (pipex.pid == -1)
				write(2, strerror(errno), ft_strlen(strerror(errno)));;
			if (pipex.pid == 0)
				cmd1(argv, envp, i, &pipex);
		}
		close(pipex.pipefd[1]);
		close(pipex.pipefd[0]);
		while (++j < 2)
		{
			wait(&pipex.status);
			if (WIFEXITED(pipex.status))
				pipex.exit_code = WEXITSTATUS(pipex.status);
		}
	}
	exit(pipex.exit_code);
	return (0);
}


/*

						VERSION SANS STRUCTURE 18/10/2022

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
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/20 22:42:53 by eminatch         ###   ########.fr       */
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
			write(2, "pipex: ", 8);
			write(2, &argv[1][i++], ft_strlen(argv[1]));
			perror(" ");
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
			perror("pipex: out");
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
		{
			perror("pipex:");
			return (0);
		}
		while (++i < 2)
		{
			pipex.pid = fork();
			if (pipex.pid == -1)
				perror("pipex:");
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
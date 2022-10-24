/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/24 19:05:40 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

//donner valeurs erreur en initialisant pour voir si changement par
//la suite dans fonction
void	ft_init_cmd(t_pipex *pipex, char **argv)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->exit_code = 0;
	pipex->status = 0;
	pipex->pid = 0;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->count_space = ft_strlen(*argv) - 1;
	pipex->len = 0;
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
			ft_err(argv[1], strerror(errno));
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
			if (argv[4][0] == '.' && argv[4][1] == '/')
			{
				ft_err(argv[4], "Is a directory");
				write(2, "\n", 1);
				exit(1);
			}
			ft_err(argv[4], strerror(errno));
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
	my_cmd(argv[i + 2], envp, pipex);
	if (argv == NULL)
		ft_free(argv);
}

// &pipex: valeur modifiee / pipex: valeur lue //
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_init_cmd(&pipex, argv);
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
				perror("pipex: ");
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
	if (argv == NULL)
		ft_free(argv);
	exit(pipex.exit_code);
	return (0);
}

/*
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (!envp)
		printf("Envp ok\n");
	if (!*envp)
		printf("*Envp ok\n");
	if (!envp[0])
		printf("Envp[0] ok\n");
	return (0);
}
*/
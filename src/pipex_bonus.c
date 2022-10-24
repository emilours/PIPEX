/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:01:43 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/24 14:47:10 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_init_cmd(&pipex);
	if (argc <= 5)
	{
		if (pipe(pipex.files) == -1)
		{
			perror("pipex:");
			return (0);
		}
		while (++i < 3)
		{
			pipex.pid = fork();
			if (pipex.pid == -1)
				perror("pipex:");
			if (pipex.pid == 0)
				cmd1(argv, envp, i, &pipex);
		}
		close(pipex.files[3]);
		close(pipex.files[2]);
		close(pipex.files[1]);
		while (++j < 3)
		{
			wait(&pipex.status);
			if (WIFEXITED(pipex.status))
				pipex.exit_code = WEXITSTATUS(pipex.status);
		}
	}
	exit(pipex.exit_code);
	return (0);
}

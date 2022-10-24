/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:48:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/24 15:00:44 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define PIPEX_H

# include "../LIBFT/includes/libft.h" 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_pipex
{
	int	exit_code;
	int	infile;
	int	outfile;
	int	pipefd[2];
	int	pid;
	int	status;
	int files[3];
	int	count_space;
	int	len;

}		t_pipex;

void	cmd1(char **argv, char **envp, int i, t_pipex *pipex);
int		main(int argc, char **argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	my_cmd(char *argv, char **envp, t_pipex *pipex);
void	error_msg(void);
void	ft_init_cmd(t_pipex *pipex, char **argv);
char	**ft_free(char **str);
void	ft_err(char *ft, char *err);
int		space(char *argv, t_pipex *pipex);

#endif
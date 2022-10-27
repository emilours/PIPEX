/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:48:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/27 20:15:36 by eminatch         ###   ########.fr       */
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
	int		exit_code;
	int		infile;
	int		outfile;
	int		pipefd[2];
	int		pid[2];
	int		status;
	int		files[3];
	char	*parts;
	char	*path_from_envp;
	char	**my_paths;
	char	*path;
}			t_pipex;

void	child_process(char **argv, char **envp, int i, t_pipex *pipex);
int		main(int argc, char **argv, char **envp);
char	*find_path(char *cmd, char **envp, t_pipex *pipex);
void	cmd_process(char *argv, char **envp, t_pipex *pipex);
void	error_msg(void);
void	ft_init_cmd(t_pipex *pipex);
char	**ft_free(char **str);
void	ft_err(char *ft, char *err);
int		space(char *argv);
int		dot_or_slash_case(char *cmd);

void	infile_process(char **argv, int i, t_pipex *pipex);
void	outfile_process(char **argv, int i, t_pipex *pipex);
void	close_and_wait(t_pipex *pipex);

#endif
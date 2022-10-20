/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:48:38 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/20 18:12:50 by eminatch         ###   ########.fr       */
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

typedef struct	s_pipex
{
        int     exit_code;
        int     infile;
	int     outfile;
       	int	pipefd[2];
	int	pid;
        int	status;
        
}		t_pipex;

enum e_error
{
        err_infile = 100,
        err_outfile = 101,
        err_badfork = 102,
        err_badpath = 103,
        err_badcmd = 104
};

void	cmd1(char **argv, char **envp, int i, t_pipex *pipex);
// void cmd1(char **argv, char **envp, int *fd, int i, int infile, int outfile);
int	main(int argc, char **argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	my_cmd(char *argv, char **envp);
void	error_msg(void);
void	ft_init_cmd(t_pipex *pipex);
void	ft_free(char **str);
int	space(char *argv);

#endif
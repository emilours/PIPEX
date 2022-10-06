/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:12 by eminatch          #+#    #+#             */
/*   Updated: 2022/10/06 16:47:15 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    pipex()
{
    int fd[2];
    pid_t   parent;
    
    pipe(fd);
    parent = fork();
    if (parent < 0)
        return (perror("Fork: error"));
    if (!parent)
        child_process(f1, cmd1);
    else
        parent_proess(f2, cmd2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 14:53:37 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/15 14:55:12 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_pipe
{
	int			fd[2];
	int			pi[2];
	pid_t		id;
	char		**cmd[2];
}				t_pipe;

char			*search(char *filename);
int				main(int argc, char **argv, char **env);

#endif

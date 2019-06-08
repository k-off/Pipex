/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <pacovali@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 11:12:22 by pacovali       #+#    #+#                */
/*   Updated: 2019/03/17 11:19:45 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_message(char *s, int i)
{
	if (i == 0)
		ft_putstr("usage: ./pipex file1 cmd1 cmd2 file2");
	if (i == 1)
		ft_putstr("error: wrong number of arguments");
	if (i == 2)
		ft_putstr("error: couldn't open input file: ");
	if (i == 3)
		ft_putstr("error: couldn't open output file: ");
	if (i == 4)
		ft_putstr("error: command not found: ");
	if (i == 5)
		ft_putstr("error: pipe fail");
	if (i == 6)
		ft_putstr("error: fork fail");
	if (i == 7)
		ft_putstr("error: dup2 fail");
	ft_putstr(s);
	ft_putstr("\n");
	exit(i);
}

static int	check_file(char *path, int rd_wr)
{
	int		fd;

	fd = -1;
	if (rd_wr == 2)
	{
		fd = open(path, O_RDONLY);
		if (fd < 2)
		{
			print_message(path, 2);
			exit(2);
		}
	}
	else if (rd_wr == 3)
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 2)
		{
			print_message(path, 3);
			exit(3);
		}
	}
	return (fd);
}

static void	check_input(int argc)
{
	if (argc == 1)
	{
		print_message("", 0);
		exit(0);
	}
	if (argc != 5)
	{
		print_message("", 1);
		exit(1);
	}
}

static void	pipex(t_pipe *pi, char **env, char *cmd, int num)
{
	char *tmp;

	pi->id = fork();
	if (num == 1)
		wait(NULL);
	pi->cmd[num] = ft_strsplit(cmd, ' ');
	tmp = pi->cmd[num][0];
	if (pi->cmd[num][0][0] != '/')
		pi->cmd[num][0] = search(pi->cmd[num][0]);
	free(tmp);
	if (pi->cmd[num][0] == NULL)
		print_message(cmd, 4);
	if (pi->id == -1)
		print_message("", 6);
	else if (pi->id == 0)
	{
		if (dup2(pi->fd[num], num) == -1)
			print_message("", 7);
		if (dup2(pi->pi[1 - num], 1 - num) == -1)
			print_message("", 7);
		close(pi->fd[num]);
		close(pi->pi[0]);
		close(pi->pi[1]);
		execve(pi->cmd[num][0], pi->cmd[num], env);
	}
}

int			main(int argc, char **argv, char **env)
{
	t_pipe	pi;

	check_input(argc);
	if (pipe(pi.pi) == -1)
		print_message("", 5);
	pi.fd[0] = check_file(argv[1], 2);
	pi.fd[1] = check_file(argv[4], 3);
	pipex(&pi, env, argv[2], 0);
	pipex(&pi, env, argv[3], 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 11:23:26 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/15 19:57:30 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <dirent.h>

static void	freeit(char **array)
{
	char	**final;

	final = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(final);
}

static char	**get_paths(void)
{
	extern char		**environ;

	while (*environ)
	{
		if (ft_strnequ("PATH=", *environ, 5))
			return (ft_strsplit(*environ + 5, ':'));
		environ++;
	}
	return (NULL);
}

static char	*prep_ret(char *s1, char *s2, char **tofree, DIR *d)
{
	char *ret;

	ret = ft_memalloc(ft_strlen(s1) + 1 + ft_strlen(s2) + 1);
	ret = ft_strcat(ret, s1);
	ret = ft_strcat(ret, "/");
	ret = ft_strcat(ret, s2);
	freeit(tofree);
	closedir(d);
	return (ret);
}

char		*search(char *filename)
{
	DIR				*d;
	struct dirent	*dir;
	char			**paths;
	char			*ret;
	char			**tofree;

	paths = get_paths();
	tofree = paths;
	while (paths && *paths)
	{
		d = opendir(*paths);
		dir = readdir(d);
		while (dir)
		{
			if (ft_strequ(filename, dir->d_name))
			{
				ret = prep_ret(*paths, filename, tofree, d);
				return (ret);
			}
			dir = readdir(d);
		}
		closedir(d);
		paths++;
	}
	return (NULL);
}

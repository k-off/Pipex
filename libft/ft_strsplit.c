/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:42:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/15 13:27:49 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*ft_strtrim_char(char const *s, char rem)
{
	char *str;
	char *rev;

	if (s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		while (*str != '\0' && *str == rem)
			str++;
		rev = ft_strrev(str);
		free(str);
		while (*rev != '\0' && *rev == rem)
			rev++;
		str = ft_strrev(rev);
		free(rev);
		return (str);
	}
	else
	{
		return (NULL);
	}
}

static int		ft_word_count(char *str, char delim)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str != delim && *str)
			str++;
		i++;
		while (*str == delim && *str)
			str++;
	}
	return (i);
}

static int		ft_word_len_delim(char *str, char delim)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != delim)
	{
		i++;
	}
	return (i);
}

static char		**ft_create_array(char **array, char *str, char delim)
{
	int words;
	int c;

	words = ft_word_count(str, delim);
	c = 0;
	while (c < words && *str)
	{
		while (*str == delim && *str)
			str++;
		array[c] = ft_strnew(ft_word_len_delim(str, delim));
		array[c] = ft_strncpy(array[c], str, ft_word_len_delim(str, delim));
		while (*str != delim && *str)
			str++;
		c++;
	}
	array[c] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*s1;
	int		words;

	if (s)
	{
		s1 = ft_strtrim_char(s, c);
		if (s1 == NULL)
			return (NULL);
		words = ft_word_count(s1, c);
		str = (char**)malloc(sizeof(char*) * (words + 1));
		if (str == NULL)
			return (NULL);
		str = ft_create_array(str, s1, c);
		if (str == NULL)
			return (NULL);
		free(s1);
		return (str);
	}
	return (NULL);
}

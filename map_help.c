/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:48:36 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:48:52 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_check(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	ft_calcule(cube);
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			map_check_help(cube, &i, &j);
		}
	}
}

void	check_ft(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (strchr(cube->wanted, (toupperv2(cube->map[i][j]))) == 0)
			{
				problem("Error\nin alpha\n");
			}
		}
	}
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	char	*tben;
	char	*lbra;

	a = 0;
	tben = (char *)haystack;
	lbra = (char *)needle;
	if (!haystack && len == 0)
		return (0);
	if (needle[a] == '\0')
		return (tben);
	while (a < len && tben[a])
	{
		b = 0;
		while (tben[a + b] == lbra[b] && (int)b < strlen(needle))
		{
			b++;
			if ((int)b == strlen(needle) && a + b <= len)
				return (tben + a);
		}
		a++;
	}
	return (0);
}

static size_t	bidaya(const char *phrase, const char *set)
{
	int		found;
	int		start;
	int		finish;
	size_t	j;

	start = 0;
	finish = strlen(phrase) - 1;
	while (start < finish)
	{
		found = 0;
		j = 0;
		while ((int)j < strlen(set))
		{
			if (phrase[start] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			break ;
		start++;
	}
	return (start);
}

static size_t	nihaya(const char *phrase, const char *set)
{
	int		found;
	int		finish;
	size_t	j;

	finish = strlen(phrase) - 1;
	while (0 < finish)
	{
		found = 0;
		j = 0;
		while ((int)j < strlen(set))
		{
			if (phrase[finish] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			break ;
		finish--;
	}
	return (finish);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		lowel;
	int		lekher;
	int		b;
	char	*natija;

	if (!set || !s1)
		return (0);
	b = 0;
	lowel = bidaya(s1, set);
	lekher = nihaya(s1, set);
	if (lekher < lowel)
		return ((char *)calloc(sizeof(char), 1));
	natija = malloc((lekher - lowel) * sizeof(char) + 2);
	if (!natija)
		return (0);
	while (lowel <= lekher)
	{
		natija[b++] = s1[lowel++];
	}
	natija[b] = '\0';
	return (natija);
}


static int	kalimat(char const *s, char c)

{
	int	i;
	int	ch7al;

	i = 0;
	ch7al = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			ch7al++;
		}
		i++;
	}
	return (ch7al);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			b;
	char			*subs;
	unsigned int	test;

	if (!s)
	{
		return (0);
	}
	if ((int)len > strlen(s))
		len = strlen(s);
	b = 0;
	test = strlen(s);
	subs = malloc(len * sizeof(char) + 1);
	if (!subs)
		return (0);
	while (b < len && test >= start)
	{
		subs[b] = s[start];
		b++;
		start++;
	}
	subs[b] = '\0';
	return (subs);
}


char	**ft_split(char const *s, char c)

{
	int		i;
	int		fin;
	int		debut;
	char	**new;
	int		j;

	j = 0;
	i = -1;
	if (!s)
		return (0);
	new = (char **)malloc((kalimat(s, c) + 1) * sizeof(char *));
	if (!new)
		return (0);
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			debut = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			fin = i;
			new[j++] = ft_substr(s, debut, fin - debut + 1);
		}
	}
	new[j] = NULL;
	return (new);
}

char	*ft_strjoingnle(char *s1, char *s2)
{
	char	*tkhlita;
	int		a;
	int		d;
	int		ls1;
	int		ls2;

	ls1 = ft_strlengnle(s1);
	ls2 = ft_strlengnle(s2);
	a = 0;
	tkhlita = (char *)calloc((ls1 + ls2) + 1, 1);
	if (!tkhlita)
		return (0);
	while (a < ls1)
	{
		tkhlita[a] = s1[a];
		a++;
	}
	d = 0;
	while (d < ls2)
	{
		tkhlita[a++] = s2[d++];
	}
	free(s1);
	return (tkhlita);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			b;
	int				c;
	unsigned char	*compare1;
	unsigned char	*compare2;

	b = 0;
	c = 0;
	compare1 = (unsigned char *)s1;
	compare2 = (unsigned char *)s2;
	while ((compare2[b] || compare1[b]) && (b < n))
	{
		if (compare1[b] != compare2[b])
		{
			c = (compare1[b] - compare2[b]);
			return (c);
		}
		b++;
	}
	return (0);
}

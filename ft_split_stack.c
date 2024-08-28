/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 13:45:18 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 13:45:18 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_ile(char const *s, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

int	ft_ileword(char const *s, int *a, int *i, char c)
{
	while (s[*i] == c || s[*i] == '\0')
	{
		(*i)++;
		(*a)++;
	}
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	return (*i - *a + 1);
}

static char	*allocate_word(const char *s, int *a, int *b, int i)
{
	char		*word;
	int			d;

	d = 0;
	word = (char *)malloc((i) * sizeof(char));
	if (!word)
		return (NULL);
	while (*b < *a)
		word[d++] = s[(*b)++];
	word[d] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		b;
	int		a;

	i = 0;
	b = 0;
	a = 0;
	array = NULL;
	array = (char **)malloc((ft_ile(s, c) + 2) * sizeof(char *));
	if (!s || !array)
		return (0);
	array[a] = (char *)malloc((1) * sizeof(char));
	if (!array[a])
		return (ft_free_table(array), NULL);
	a++;
	while (s[b] != '\0')
	{
		array[a] = allocate_word(s, &i, &b, ft_ileword(s, &b, &i, c));
		if (!array[a])
			return (ft_free_table(array), NULL);
		a++;
	}
	array[a] = NULL;
	return (array);
}

/*int main (int argc, char **argv)
{
	int i;

	i = 0;
	if(argc == 1 || (argc == 2 && !argv[1][0])) //one value or 2 but empty
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	printf("%i", argc);
	while (argv[i] != NULL)
	{
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}
	return(0);
}*/
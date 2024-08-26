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

static int	word_count(const char *s, char c)
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

static char	*malloc_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc((word_count(s, c) + 2) * sizeof(char *));
	if (!s || !array)
        return (0);
	array[i++] = NULL;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			array[i] = malloc_word(s, c);
			if (!array[i])
				return (ft_free_table(array), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	array[i] = NULL;
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
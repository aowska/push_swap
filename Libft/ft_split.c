/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:37:43 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 20:09:14 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

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
	int b;
	
	b = 0;
    while (s[*i] == c || s[*i] == '\0')
    {
        (*i)++;
        (*a)++;
    }
    while (s[*i] != c && s[*i] != '\0')
        (*i)++;
    b = ((*i) - (*a)) + 1;
    return (b);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		b;
	int		a;
	int		d;
	int		w;

	i = 0;
	b = 0;
	a = 0;
	d = 0;
	w = 0;
	w = ft_ile(s, c); 
	array = (char **)malloc((w + 1) * sizeof(char *));
	if (!s || !array)
		return (0);
	while (a < w)
	{
		array[a] = (char *)malloc((ft_ileword(s, &b, &i, c)) * sizeof(char));
        while (b < i)
            array[a][d++] = s[b++];
        array[a][d] = '\0';
        a++;
        i = b;
        d = 0;
	}
	array[a] = NULL;
	return (array);
}

/*int main()
{
    // Stała zdefiniowana w main
    char const *input_string = "To jest przykładowy ciąg znaków do podziału na słowa";

    char **result_array = ft_split(input_string, ' ');

    if (result_array == NULL) {
        printf("Błąd alokacji pamięci lub brak danych wejściowych.\n");
        return 1;
    }

    printf("Podzielony ciąg:\n");
    for (int i = 0; result_array[i] != NULL; i++) {
        printf("[%d]: \"%s\"\n", i, result_array[i]);
        free(result_array[i]); // Zwolnij pamięć zaalokowaną dla poszczególnych napisów
    }
    free(result_array); // Zwolnij pamięć zaalokowaną dla tablicy wskaźników

    return 0;
}*/
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

int ft_ile(char const *s, char c) {
    int a;
    int j;

    a = 1;
    j = 0;
    if (!*s)
        return (0);
    while (s[a] != '\0') {
        if (s[a] == c && s[a - 1] != c)
            j++;
        a++;
    }
    if (s[a - 1] != c)
        j++;
    return (j);
}

int ft_ileword(char const *s, char c, int *i) {
    int count = 0;
    while (s[*i] == c)
        (*i)++;
    while (s[*i] != c && s[*i] != '\0') {
        count++;
        (*i)++;
    }
    return count;
}

char **ft_split(char const *s, char c) {
    char **array;
    int a;
    int i;
    int w;

    a = 0;
    i = 0;
    w = ft_ile(s, c);
    array = (char **)malloc((w + 1) * sizeof(char *));
    if (!s || !array)
        return (0);
    while (a < w) {
        int word_len = ft_ileword(s, c, &i);
        array[a] = (char *)malloc((word_len + 1) * sizeof(char));
        int j = 0;
        while (word_len-- > 0)
            array[a][j++] = s[i - word_len - 1];
        array[a][j] = '\0';
        a++;
    }
    array[a] = NULL;

    return array;
}

/*
int main() 
{
    char const *test_string = "Test string for splitting";
    char **result = ft_split(test_string, ' ');

    // Printing result
    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // Free each individual string
    }

    free(result); // Free the array itself
    return 0;
} */

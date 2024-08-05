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

int    ft_ileword(char const *s, int *a, int *i, char c)
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

char    **ft_split(char const *s, char c)
{
    char    **array;
    int        i;
    int        b;
    int        a;
    int        d;

    i = 0;
    b = 0;
    a = 0;
    d = 0;
	array = NULL;
    array = (char **)malloc((ft_ile(s, c) + 2) * sizeof(char *));
    if (!s || !array)
        return (0);
    while (s[b] != '\0')
    {
		if (a == 0)
		{
			array[a] = (char *)malloc((1) * sizeof(char));
			if(!array[a])
				return (NULL);
			array[a++][0] = '\0';
		}
        array[a] = (char *)malloc((ft_ileword(s, &b, &i, c)) * sizeof(char));
		if(!array[a])
				return (NULL);
        while (b < i)
            array[a][d++] = s[b++];
        array[a][d] = '\0';
        a++;
        d = 0;
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

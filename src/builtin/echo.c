#include "../include/minishell.h"
#include "../libft/libft.h"

int ft_detect_dollar(char* s1)
{
    int i = 0;
    while (s1[i])
    { 
        if (s1[i] == '$')
        return 1;
        i++;
    }
    return 0;

}

int closed_quote(char *line)
{
	int i = 0;
	if (line[i] == '"')
	{
		while (line[i] != '\0')
		{
			if (line[i] == '"')
				{ return 1;
				break;}
			i++;
		}
	}
	return 0;
}

char *remove_real(char *s1)
{
    int i = 0;
    if (s1[i] == '"' && s1[strlen(s1) - 1] == '"' && !ft_detect_dollar(s1)) 
    {
        s1[strlen(s1) - 1] = '\0';
        return s1 + 1;
    }
    else if (s1[0] == '\'' && s1[strlen(s1) - 1] == '\'')
    {
        s1[strlen(s1) - 1] = '\0';
        return s1 + 1;
    }
    return s1;
}



int	echo(int argc, char **argv)
{
	int	i;
	int	flag;

	if (argc < 2)
		return (1);
	i = 1;
	flag = 0;
	if (argv[i] && strncmp(argv[i], "-n", 2) == 0)
	{
		flag = 1;
		i++;
	}
	while (argv[i])
	{
		//if (closed_quote(argv[i]))
		//	argv[i] = remove_real(argv[i]);
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
#include "../include/minishell.h"

t_mini	*init_mini(void)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	mini->tokens = 0;
	mini->cmd = 1;
	mini->pipe_read = -1;
	mini->pipe_write = -1;
	mini->input = -1;
	mini->output = -1;
	mini->stdin = dup(STDIN_FILENO);
	mini->stdout = dup(STDOUT_FILENO);
	mini->execute_code = 0;
	mini->env = NULL;
	return (mini);
}

//just to get rid of unused parameter error when compiling
void	init_main(int argc, char **argv)
{
	if (argc > 1 || argv[1])
	{
		printf("one argc ./minishell ");
		exit(1);
	}
}

int ft_whitespace(char *av)
{
	int i = 0;
	while (av[i])
	{
		if (av[i] == ' ' && av[i+1] == '\0')
			{printf("nope");
			free(av);
			return 1;}
		else if (av[i] == ' ')
			i++;		
		else 
			return 0;
	}
	return 0;
}	

char * display_readline(char *input)
{
	input = readline("@minishell> ");
	return (input);
}

static void read_input(t_mini *mini, char *input)
{

	input = display_readline(input);
	//input = readline("@minishell> ");
	//disable_veof();
	
	parse(mini, input);
	add_history(input);	
	dup2(mini->stdin, STDIN_FILENO);
	dup2(mini->stdout, STDOUT_FILENO);
	free(input);
}

int	main(int argc, char *argv[])
{
	t_mini	*mini;
	char	*buff;

	define_signal();
	init_main(argc, argv);
	mini = init_mini();
	head_ref = ft_link_env();
	while (1)
	{
		buff = NULL;
		read_input(mini, buff);
	}
	return (mini->execute_code);
}
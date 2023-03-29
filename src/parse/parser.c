#include "../include/minishell.h"
#include "../libft/libft.h"

void	parse(t_mini *mini, char *buff)
{
	char	**split = NULL;
	int		i;
	t_token	*head;
	char *cpy;

	while (*buff == ' ' || *buff == '\t')
		buff++;
	if (*buff == '\0')
			mini_exit(); // change to redisplay
	cpy = ft_strdup(buff);
	ft_linked_list(cpy);
	split = ft_split(buff, ' ');
	head = new_token(mini, *split);
	mini->tokens = head;
	i = 0;
	while (split[++i])
		token_addend(split[i], mini);
	execute(mini);
	mini->cmd = 1;
	token_free(mini->tokens);
	agrv_free(split);
}
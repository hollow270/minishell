/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:16:24 by yhajbi            #+#    #+#             */
/*   Updated: 2025/04/09 13:39:23 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int main(int arc, char **argv, char **env)
{
	char	*input;

	(void)arc;
	(void)argv;
	while (1)
	{
		input = readline(PROMPT);
		if (strcmp("exit", input) == 0)
			break ;
		add_history(input);
		ft_putstr(input);
		ft_putchar('\n');
		free(input);
	}
	free(input);
	rl_clear_history();
	return (1);
}
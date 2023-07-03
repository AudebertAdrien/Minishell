/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus & aaudeber <mcreus@student.42per    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 15:07:35 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	pid_t	process;
	pid_t	wait();
	char	*t = getenv("PWD");

	av[2] = "-la";
	printf("%s\n", t);	
	while (1)
	{
		static char	*s = (char *)NULL; 
		if (s)
		{
			free(s);
			s = (char *)NULL;
		}
		s = readline("");
		add_history(s);
		process = fork();
		printf("=> %d\n", process);
		if (s)
		{
			if (process > 0)
				wait();
			if (process == 0)
			{
				if (!strcmp(s, "ls"))
					execve("/bin/ls", av, NULL);
				if (!strcmp(s, "pwd"))
					execve("/bin/pwd", av, NULL);
				if (!strcmp(s, "unset"))
				{
					ft_printf("unset!\n");
					execve("/bin/unset PWD", av, NULL);
				}
			
			}
		}
	}
	return (0);
}


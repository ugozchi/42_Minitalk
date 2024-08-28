/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:09 by uzanchi           #+#    #+#             */
/*   Updated: 2024/07/03 11:38:45 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

/*Checks that the arguments of the program are valid:
• Two arguments to the 'client' program
• First argument is numeric (PID of the 'server')
• First argument is not a protected process (PID < 1050)
• Second argument is a not empty string*/

t_bool	argument_is_valid(int argc, char **argv)
{
	const char	*error_msg = NULL;

	if (argc != 3)
		error_msg = ERR_ARG_NR;
/*	else if (!ft_isnumeric(argv[1]))
		error_msg = ERR_NON_NUM_PID;*/
	else if (ft_atoi(argv[1]) <= 1050)
		error_msg = PROTECTED_PID;
	else if (!ft_strlen(argv[2]))
		error_msg = ERR_EMPT_STR;
	if (error_msg)
	{
		ft_printf(error_msg);
		return (FALSE);
	}
	return (TRUE);
}

/*Sends a bit encoded message to the server whose PID is 'pid' with SIGUSR1 to
represent 0 and SIGUSR2 to represent 1*/

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/*Checks that the program arguments are valids and sends message to the server.*/

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (!argument_is_valid(ac,av))
		return (-1);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_atob(pid, av[2][i]);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:06 by uzanchi           #+#    #+#             */
/*   Updated: 2024/09/25 12:25:07 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Sends the signal 'signu;' to the process whith ID 'PID' and prints the errno
and exits the process in case of failure of kill() function*/
void	send_signal(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		ft_printf_colour(RED_BOLD, KILL_FAIL, errno);
		exit (EXIT_FAILURE);
	}
}

int	free_resources(char	**message)
{
	if (*message)
	{
		free(*message);
		*message = NULL;
	}
	return (0);
}
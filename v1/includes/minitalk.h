/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:41 by uzanchi           #+#    #+#             */
/*   Updated: 2024/07/03 11:04:41 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"

/*Errors*/
# define ERR_ARG_NR "Wrong number of arguments\n"
# define ERR_EMPT_STR "Empty string to send to server\n"
# define ERR_NON_NUM_PID "Process ID argument is not numeric\n"
# define PROTECTED_PID "Process ID is protected and should be above 1050\n"

/*data_model*/
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:14:31 by youngmch          #+#    #+#             */
/*   Updated: 2022/10/14 20:13:59 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct	s_map
{
	int
}				t_map;


int	main(int argc, char **argv);
int	**read_map(int fd);


#endif

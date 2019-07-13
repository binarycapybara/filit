/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:27:22 by drafe             #+#    #+#             */
/*   Updated: 2019/07/13 17:34:48 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	(1)int	ft_y_c(char *s, int i)
**	Function generate offset from previous point for y
** **************************************************************************
*/

int					ft_x_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	res = res % 5;
	if ((res < 5) && (res > 1))
		res = res - 5;
	return (res);
}

/*
** **************************************************************************
**	(2)int	ft_y_c(char *s, int i)
** 	Function generate offset from previous point for y
** **************************************************************************
*/

int					ft_y_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	if (res < 3)
		res = 0;
	else
		res = 1;
	return (res);
}

/*
** **************************************************************************
**	(3)int	ft_save_shape(char *s, t_crds *all_sh)
**
**	t_crds *all_sh - 26 empty shapes structures;
**
**	char *s - buff string readed from input file;
**
**	p_nb - shape point_number, every shape has from 0 to 3 point_numbers;
**
**	sh_nb - shape_number(0..26) in t_crds	all_shapes[26];
**
**	nl_nb - new_line_number(0..4) help us count sh_nb;
** ------------------------------------------------------------------------
**	----Code for print coordinates----
**	sh_nb = 0;
** 	while (sh_nb < 19)
**	{
**		i = 0;
**		printf("\n***vvv***%d***vvv***", sh_nb);
**		while (i < 4)
**		{
**			printf("\nt[%d].x[%d]=%d  y[%d]=%d", sh_nb,\
**			i, all_sh[sh_nb].x[i], i, all_sh[sh_nb].y[i]);
**			i++;
**		}
**		sh_nb++;
**	}
** **************************************************************************
*/

int					ft_save_shape(char *s, t_crds *all_sh)
{
	int				p_nb;
	int				nl_nb;
	int				sh_nb;
	int				i;

	i = 0;
	sh_nb = 0;
	nl_nb = 0;
	p_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (p_nb != 0)
			{
				all_sh[sh_nb].x[p_nb] = all_sh[sh_nb].x[p_nb - 1] + ft_x_c(s, i);
				all_sh[sh_nb].y[p_nb] = all_sh[sh_nb].y[p_nb - 1] + ft_y_c(s, i);
			}
			p_nb++;
		}
		if (s[i] == '\n')
		{
			nl_nb++;
			if ((nl_nb % 5 == 0) && (nl_nb != 0))
			{
				sh_nb++;
				nl_nb = 0;
				p_nb = 0;
			}
		}
		i++;
	}
	return (sh_nb + 1);
}

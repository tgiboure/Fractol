/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hook.func.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: togibour <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/07 17:42:37 by togibour     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 19:12:17 by togibour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fractol.h"
#include "../minilibx_macos/mlx.h"

void	ft_move(int arrow, t_indication *id)
{
	if (arrow == 123)
		id->x1 += 5 / id->zoom;
	if (arrow == 126)
		id->y1 += 5 / id->zoom;
	if (arrow == 124)
		id->x1 -= 5 / id->zoom;
	if (arrow == 125)
		id->y1 -= 5 / id->zoom;
	set_image(id);
}

void	ft_iter(int keycode, t_indication *id)
{
	if (keycode == 78 && id->iter > 5)
		id->iter = id->iter - 5;
	if (keycode == 69)
		id->iter = id->iter + 5;
	set_image(id);
}

int		ft_key_func(int keycode, t_indication *id)
{
	if (keycode == 83 || keycode == 84 | keycode == 85)
	{
		id->colour = keycode;
		set_image(id);
	}
	if (keycode == 89 || keycode == 91 || keycode == 92)
		ft_chan(keycode);
	if (keycode == 49)
		id->pause++;
	if (id->pause == 2)
		id->pause = 0;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_move(keycode, id);
	if (keycode == 69 || keycode == 78)
		ft_iter(keycode, id);
	if (keycode == 53)
		exit(1);
	return (1);
}

int		mouse_zoom(int key, int x, int y, t_indication *id)
{
	if (key == 5 && id->zoom > 50)
	{
		id->x1 = (x / id->zoom + id->x1) - ((id->zoom * 0.95) / 2);
		id->x1 += ((id->zoom * 0.95) / 2) - (x / (id->zoom * 0.95));
		id->y1 = (y / id->zoom + id->y1) - ((id->zoom * 0.95) / 2);
		id->y1 += ((id->zoom * 0.95) / 2) - (y / (id->zoom * 0.95));
		id->zoom *= 0.95;
		if (id->i-- % 15 == 0)
			ft_iter(78, id);
	}
	if (key == 4)
	{
		id->x1 = (x / id->zoom + id->x1) - ((id->zoom * 1.05) / 2);
		id->x1 += ((id->zoom * 1.05) / 2) - (x / (id->zoom * 1.05));
		id->y1 = (y / id->zoom + id->y1) - ((id->zoom * 1.05) / 2);
		id->y1 += ((id->zoom * 1.05) / 2) - (y / (id->zoom * 1.05));
		id->zoom *= 1.05;
		if (id->i++ % 15 == 0)
			ft_iter(69, id);
	}
	set_image(id);
	return (1);
}

int		ft_fractolize(int x, int y, t_indication *id)
{
	if (id->pause)
	{
		id->julx = (double)x / (double)(id->zoom / 2) - 4;
		id->july = (double)y / (double)(id->zoom / 2) - 4;
		set_image(id);
	}
	return (1);
}

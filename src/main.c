/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: togibour <togibour@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 05:14:28 by togibour     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 04:36:14 by togibour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fractol.h"
#include "../minilibx_macos/mlx.h"

void	ft_chan(int keycode)
{
	if (keycode == 89)
		ft_fractol(1);
	if (keycode == 91)
		ft_fractol(2);
	if (keycode == 92)
		ft_fractol(3);
}

void	ft_err(void)
{
	ft_putstr("1/ Ecrire : Mandelbrot");
	ft_putstr("\n2/ Ecrire : Julia");
	ft_putstr("\n3/ Ecrire : Ship\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
			ft_fractol(1);
		if (!ft_strcmp(av[1], "Julia"))
			ft_fractol(2);
		if (!strcmp(av[1], "Ship"))
			ft_fractol(3);
		ft_err();
	}
	else
		ft_err();
	return (0);
}

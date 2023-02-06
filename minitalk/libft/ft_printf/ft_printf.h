/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:30:14 by maricard          #+#    #+#             */
/*   Updated: 2022/11/30 12:58:09 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//C libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Function Prototypes
int		ft_printf(const char *str, ...);
int		ft_char(int c);
int		ft_string(char *str);
int		ft_pointer(unsigned long long k);
void	ft_putchar(int c);
void	ft_unsigned(unsigned int x, int *len);
void	ft_number(int x, int *len);
void	ft_hexadecimal(unsigned long n, int *len);
void	ft_hexadecimal_x(unsigned long n, int *len);

#endif

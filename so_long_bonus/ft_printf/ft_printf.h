/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:15:55 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 09:36:27 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_putstr(char *str, int i);
int	put_digit(long long int number, char *base, int bsize);
int	ft_formats(va_list args, const char formats);
int	put_digit_pointer(void *point, char *base, int bsize);
int	ft_printf(const char *format, ...);
#endif
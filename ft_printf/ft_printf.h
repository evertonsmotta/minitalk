/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:24:12 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/21 13:45:23 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define    FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <inttypes.h>

int		ft_printf(const char *fstarg, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_pointer(unsigned long long address);
int		ft_iputstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbase(unsigned long nbr, const char *base, int fd);
int		ft_printfhexa(size_t num, const char format);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_uputnbr_fd(size_t n, int fd);

#endif

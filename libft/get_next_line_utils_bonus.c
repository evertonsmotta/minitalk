/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:55 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/12/20 19:17:16 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		s++;
	if (c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

/* ft_calloc(qnt_p_alocar, tam_em_byte_a_ser_alocada) */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	dst = malloc(size * nmemb);
	if (!dst)
		return (NULL);
	else
		ft_memset(dst, 0, (size * nmemb));
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

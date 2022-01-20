/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:17:40 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 20:12:01 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	buf_init(char **buf, size_t *buf_size)
{
	*buf_size = BUF_SIZE;
	*buf = (char *)malloc(sizeof(char) * (*buf_size));
	if (*buf == NULL)
		return (0);
	ft_memset(*buf, '\0', *buf_size);
	return (1);
}

char	*buf_resize(char *buf, size_t buf_size)
{
	char	*ret_buf;
	size_t	resize;

	if (SIZE_MAX - buf_size <= buf_size)
	{
		free(buf);
		return (NULL);
	}
	resize = buf_size * 2;
	ret_buf = (char *)malloc(sizeof(char) * resize);
	if (ret_buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	ft_memset(ret_buf, '\0', resize);
	ft_memcpy(ret_buf, buf, buf_size);
	free(buf);
	return (ret_buf);
}

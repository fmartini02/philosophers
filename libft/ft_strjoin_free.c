/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:18:05 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/19 16:52:11 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *str, char *buff)
{
	char	*temporaneo;

	if (!buff)
		return (str);
	temporaneo = ft_strjoin(str, buff);
	free(str);
	return (temporaneo);
}

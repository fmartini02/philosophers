/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:45 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 10:41:48 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*memb;

	memb = malloc(sizeof(t_list));
	if (!memb)
		return (NULL);
	memb->content = content;
	memb->next = NULL;
	memb->chunk = 0;
	memb->pos = 0;
	return (memb);
}

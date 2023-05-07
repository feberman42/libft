/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:31:40 by feberman          #+#    #+#             */
/*   Updated: 2023/05/07 19:56:26 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_del(void *content)
{
	printf("%s deleted\n", (char *)content);
}

void	testbonus(void)
{
	t_list	*lst = ft_lstnew("Hello");
	printf("\nLSTNEW\nCreate new node with Hello: %s\n",
		(char *)lst -> content);
	ft_lstadd_front(&lst, ft_lstnew("World"));
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	printf("\nLSTADD_FRONT\nHello world?: %s %s\n",
		(char *)(lst)->content, (char *)(lst)->next->content);
	printf("\nLSTSIZE\nList length (3): %i\n", ft_lstsize(lst));
	printf("\nLSTLAST\nThe last node is (Hello): %s\n",
		(char *)ft_lstlast(lst)->content);
	ft_lstadd_back(&lst, ft_lstnew("World2"));
	printf("\nLSTADD_BACK\nHello World x2?: %s %s %s %s\n",
		(char *)lst->content, (char *)lst->next->content, 
		(char *)lst->next->next->content, (char *)lst->next->next->next->content);
	ft_lstdelone(ft_lstlast(lst), ft_del);
}

int	main(void)
{
	testbonus();
}

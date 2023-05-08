/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:31:40 by feberman          #+#    #+#             */
/*   Updated: 2023/05/08 13:31:25 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_del(void *content)
{
	printf("%s deleted\n", (char *)content);
}

void	ft_f(void *content)
{
	char	*str = (char *)content;
	int		i = 0;

	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
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
	printf("\nLSTDELONE\nTest yourself!\n");
	printf("\nLSTCLEAR\nDelete whole list:\n");
	ft_lstclear(&lst, ft_del);
	char	hello[] = "Hello";
	char	world[] = "world";
	lst = ft_lstnew(hello);
	ft_lstadd_back(&lst, ft_lstnew(world));
	ft_lstiter(lst, ft_f);
	printf("\nLSTITER\nCapitalize Hello World: %s %s\n",
		(char *)lst->content, (char *)lst->next->content);	
}

int	main(void)
{
	testbonus();
}

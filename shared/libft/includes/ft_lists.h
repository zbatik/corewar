/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:16:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/06 13:30:00 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new_node);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct	s_dblist
{
	char			*str;
	int				n;
	struct s_dblist	*next;
	struct s_dblist	*prev;
}				t_dblist;

t_dblist		*ft_lstdbnew(char *str, int n);
void			ft_lstdbadd(t_dblist **dblst, t_dblist *new_node);
void			ft_lstdbdel(t_dblist **list);
void			ft_lstdbdelone(t_dblist **list);
void			ft_lstdbtotop(t_dblist **list);
void			ft_lstdbtobottom(t_dblist **list);

#endif

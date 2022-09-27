/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:46:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 18:24:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_STRUCTOR_HPP
#  define RBTREE_STRUCTOR_HPP

RBTree	(allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc(alloc)
	,_sentinel(NULL)
	,_root(NULL)
	,_size(-1)
	,_comp()
{
	_construct(_sentinel, _sentinel, value_type(), BLACK);
	_root = _sentinel;
}

RBTree	(RBTree const & src,
		 allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc(alloc)
	,_sentinel(NULL)
	,_root(NULL)
	,_size(-1)
	,_comp()
{
	_construct(_sentinel, _sentinel, value_type(), BLACK);

	_root = _sentinel;

	NodeBase_ptr	tmp = src._root->min();

	while (tmp != src._sentinel)
	{
		this->insert(_cast(tmp)->value);
		tmp = tmp->next();
	}
}

~RBTree	(void)
{
	this->clear();
	_clear(_sentinel, true);
}

# endif
#endif


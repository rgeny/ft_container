/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:46:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 17:04:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_STRUCTOR_HPP
#  define RBTREE_STRUCTOR_HPP

RBTree	(allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc()
	,_sentinel(NULL)
	,_root(NULL)
	,_size(0)
{
	node_type	tmp(_sentinel);
	_sentinel = _node_alloc.allocate(1, &tmp);
	_node_alloc.construct(_sentinel, _sentinel);
	_root = _sentinel;
}

RBTree	(__attribute__ ((unused)) RBTree const & src,
		 allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc()
	,_sentinel(_node_alloc.allocate(1, _sentinel))
	,_root(_sentinel)
	,_size(0)
{
	_node_alloc.construct(_sentinel);
	if (src._root != src._sentinel)
		_root = _node_alloc.allocate(1, *src._root);
}
~RBTree	(void)
{
	this->clear();
	_node_alloc.destroy(_sentinel);
	_node_alloc.deallocate(_sentinel, 1);
}

# endif
#endif


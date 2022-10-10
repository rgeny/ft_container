/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:46:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 14:23:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_STRUCTOR_HPP
#  define RBTREE_STRUCTOR_HPP

Tree	(allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc(alloc)
	,_sentinel(NULL)
	,_root(NULL)
	,_size(0)
	,_comp()
{
	_init_sentinel();
}

Tree	(Tree const & src,
		 allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_node_alloc(alloc)
	,_sentinel(NULL)
	,_root(NULL)
	,_size(0)
	,_comp()
{
	_init_sentinel();

	NodeBase_ptr	tmp = src._root->min();
	while (tmp != src._sentinel)
	{
		this->insert(_cast(tmp)->value);
		tmp = node_increment(tmp);
	}
}

template < typename InputIt >
Tree	(InputIt & first,
		 InputIt & last,
		 allocator_type const & alloc = allocator_type() )
	:_alloc(alloc)
	,_node_alloc(alloc)
	,_sentinel(NULL)
	,_root(NULL)
	,_size(0)
	,_comp()
{
	_init_sentinel();

	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

~Tree	(void)
{
	this->clear();
//	_clear(_sentinel, true);
	_node_alloc.deallocate(_cast(_sentinel), 1);
}

# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:46:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/15 16:13:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_STRUCTOR_HPP
#  define RBTREE_STRUCTOR_HPP

Tree	(allocator_type const & alloc = allocator_type())
	:TreeHeader()
	,_alloc(alloc)
	,_node_alloc(alloc)
	,_root(NULL)
	,_comp()
{
	_init_head();
}

Tree	(Tree const & src,
		 allocator_type const & alloc = allocator_type())
	:TreeHeader(src.TreeHeader)
	,_alloc(alloc)
	,_node_alloc(alloc)
	,_root(NULL)
	,_comp()
{
	_init_head();

	NodeBase_ptr	tmp = src._root->min();
	while (tmp != src._head)
	{
		this->insert(_cast(tmp)->value);
		tmp = node_increment(tmp);
	}
}

template < typename InputIt >
Tree	(InputIt & first,
		 InputIt & last,
		 allocator_type const & alloc = allocator_type() )
	:TreeHeader()
	,_alloc(alloc)
	,_node_alloc(alloc)
	,_root(NULL)
	,_comp()
{
	_init_head();

	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

~Tree	(void)
{
	this->clear();
//	_clear(_head, true);
	_node_alloc.destroy(_cast(_head));
	_node_alloc.deallocate(_cast(_head), 1);
}

# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 19:18:34 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_PRIVATE_HPP
# define RBTREE_PRIVATE_HPP

void	_construct	(node_preference new_node,
					 node_preference parent,
					 value_type const & value = value_type(),
					 e_color const color = RED)
{
	if (new_node != _sentinel)
		_node_alloc.destroy(new_node);
	else
	{
		new_node = _node_alloc.allocate(1);
		++_size;
	}
	
	node_type	tmp(_sentinel, parent, value, color);
	_node_alloc.construct(new_node, tmp);
}

void	_clear		(node_preference node,
					 bool destroy_sentinel = false)
{
	if (node != _sentinel || destroy_sentinel)
	{
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
		node = _sentinel;
		--_size;
	}
}

void	_clear_all	(node_pointer node)
{
	node_pointer	tmp;

	while (node != _sentinel)
	{
		_clear_all(node->right);
		tmp = node;
		node = node->left;
		_clear(tmp);
	}
}

# endif
#endif


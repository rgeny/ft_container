/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 17:20:58 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_PRIVATE_HPP
# define RBTREE_PRIVATE_HPP

void	_construct	(node_preference new_node,
					 node_preference parent,
					 value_type const & value = value_type() )
{
	if (new_node != _sentinel)
		_node_alloc.destroy(new_node);
	else
	{
		new_node = _node_alloc.allocate(1);
		++_size;
	}
	
	node_type	tmp(_sentinel, parent, value);
	_node_alloc.construct(new_node, tmp);
}

void	_clear		(node_preference node)
{
	if (node != _sentinel)
	{
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
		node = _sentinel;
	}
}

void	_clear_all	(node_preference node)
{
	if (node != _sentinel)
	{
		_clear_all(node->left);
		_clear_all(node->right);
		_clear(node);
	}
}

# endif
#endif


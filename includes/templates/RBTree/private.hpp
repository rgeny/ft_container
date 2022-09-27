/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 18:07:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_PRIVATE_HPP
# define RBTREE_PRIVATE_HPP

node_pointer	_cast	(NodeBase_ptr node)
{	return (static_cast<node_pointer>(node));	}

int	_compare	(NodeBase_ptr node,
				 value_type value)
{
	node_pointer	tmp = _cast(node);
	return (_comp(tmp->value, value));
}

int		_compare	(value_type value,
					 NodeBase_ptr node)
{
	node_pointer	tmp = _cast(node);
	return (_comp(value, tmp->value));
}

void	_construct	(NodeBase_ptr & new_node,
					 NodeBase_ptr & parent,
					 value_type const & value = value_type(),
					 node_color const color = RED)
{
	if (new_node != _sentinel)
		_node_alloc.destroy(_cast(new_node));
	else
	{
		new_node = _node_alloc.allocate(1);
		++_size;
	}
	
	node_type	tmp(_sentinel, parent, value, color);
	_node_alloc.construct(_cast(new_node), tmp);
}

void	_clear		(NodeBase_ptr & node,
					 bool destroy_sentinel = false)
{
	if (node != _sentinel || destroy_sentinel)
	{
		node_pointer	tmp = _cast(node);

		_node_alloc.destroy(tmp);
		_node_alloc.deallocate(tmp, 1);
		node = _sentinel;
		--_size;
	}
}

void	_clear_all	(NodeBase_ptr node)
{
	NodeBase_ptr	tmp;

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


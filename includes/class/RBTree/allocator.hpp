/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:09:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 19:11:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ALLOCATOR_HPP
#  define RBTREE_ALLOCATOR_HPP

private:
	void	_construct	(NodeBase_ptr & new_node,
						 NodeBase_ptr & parent,
						 value_type const & value = value_type(),
						 node_color const color = red_node)
	{
		new_node = _node_alloc.allocate(1);
		++_size;

		node_type	tmp(NULL, parent, value, color);
		_node_alloc.construct(_cast(new_node), tmp);
	}

	void	_clear		(NodeBase_ptr & node)
	{
		if (node != NULL)
		{
			node_pointer	tmp = _cast(node);

			_node_alloc.destroy(tmp);
			_node_alloc.deallocate(tmp, 1);
			node = &_head;
			--_size;
		}
	}

	void	_clear_all	(NodeBase_ptr node)
	{
		NodeBase_ptr	tmp;

		while (node != NULL)
		{
			_clear_all(node->right);
			tmp = node;
			node = node->left;
			if (tmp == _head.parent)
				_head.parent = NULL;
			_clear(tmp);
		}
	}

# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/12 18:52:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_PRIVATE_HPP
# define RBTREE_PRIVATE_HPP

node_pointer	_cast	(NodeBase_ptr node)
{	return (static_cast<node_pointer>(node));	}
node_const_pointer	_cast	(NodeBase_const_ptr node) const
{	return (static_cast<node_const_pointer>(node));	}

int	_compare	(NodeBase_ptr node,
				 key_type const & key)
{
	node_pointer	tmp = _cast(node);
	return (_comp(KeyOfValue()(tmp->value), key));
}
int	_compare	(NodeBase_const_ptr node,
				 key_type const & key) const
{
	node_const_pointer	tmp = _cast(node);
	return (_comp(KeyOfValue()(tmp->value), key));
}

int		_compare	(key_type const & key,
					 NodeBase_ptr node)
{
	node_pointer	tmp = _cast(node);
	return (_comp(key, KeyOfValue()(tmp->value)));
}

int		_compare	(key_type const & key,
					 NodeBase_const_ptr node) const
{
	node_const_pointer	tmp = _cast(node);
	return (_comp(key, KeyOfValue()(tmp->value)));
}

void	_construct	(NodeBase_ptr & new_node,
					 NodeBase_ptr & parent,
					 value_type const & value = value_type(),
					 node_color const color = red_node)
{
	if (new_node != _sentinel)
		return ;
	else
	{
		new_node = _node_alloc.allocate(1);
		++_size;
	}
	
	node_type	tmp(_sentinel, parent, value, color);
	_node_alloc.construct(_cast(new_node), tmp);
}

void	_clear		(NodeBase_ptr & node)
{
	if (node != _sentinel)
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
		if (tmp == _root)
			_root = _sentinel;
		_clear(tmp);
	}
}

void	_init_sentinel	(void)
{
	_sentinel = _node_alloc.allocate(1);

	node_type	tmp(_sentinel, _sentinel, value_type(), black_node);
//	_sentinel->left = _sentinel;
//	_sentinel->right = _sentinel;
//	_sentinel->left = _sentinel;
//	_sentinel->color = black_node;
	_node_alloc.construct(_cast(_sentinel), tmp);
	_root = _sentinel;
}

# endif
#endif


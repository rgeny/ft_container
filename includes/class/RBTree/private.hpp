/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 14:56:56 by rgeny            ###   ########.fr       */
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
	if (new_node != &_head)
		return ;
	else
	{
		new_node = _node_alloc.allocate(1);
		++_size;
	}
	
	node_type	tmp(&_head, parent, value, color);
	_node_alloc.construct(_cast(new_node), tmp);
}

void	_clear		(NodeBase_ptr & node)
{
	if (node != &_head)
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

	while (node != &_head)
	{
		_clear_all(node->right);
		tmp = node;
		node = node->left;
		if (tmp == _root)
			_root = &_head;
		_clear(tmp);
	}
}

void	_init_head	(void)
{
//	_head = _node_alloc.allocate(1);

//	node_type	tmp(_head, NULL, value_type(), black_node);
//	_node_alloc.construct(_cast(_head), tmp);
//	this->reset();
	_root = &_head;
}

# endif
#endif


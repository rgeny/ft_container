/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:27:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 16:59:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_FIND_HPP
# define RBTREE_FIND_HPP

public:
	iterator		find	(key_type const & key)
	{
		iterator	it = this->_find_node(key);
		if (it._cur_node == NULL)
			return (iterator(&_head));
		return (it);
	}
//		return (iterator(this->_find_node(key)));	}
	const_iterator	find	(key_type const & key) const
	{
		const_iterator	it = this->_find_node(key);
		if (it._cur_node == NULL)
			return (const_iterator(&_head));
		return (it);
	}
//	{	return (const_iterator(this->_find_node(key)));	}

private:
	NodeBase_ptr &	_find	(key_type const & key)
	{
		NodeBase_ptr	parent = &_head;
		return (this->_find(key, parent));
	}

	NodeBase_ptr &	_find	(key_type const & key,
							 NodeBase_ptr & parent)
	{
		return (_find(key, parent, &_head.parent));
	}

	NodeBase_ptr &	_find	(key_type const & key,
							 NodeBase_ptr & parent,
							 NodeBase_ptr * hint)
	{
		if (*hint == &_head || *hint == NULL || (*hint != _head.parent &&
			(((*hint)->parent->left == *hint && _compare((*hint)->parent, key)) ||
			 ((*hint)->parent->right == *hint && _compare(key, (*hint)->parent)) ||
			 ((!_compare((*hint)->parent, key) && !_compare(key, (*hint)->parent))))))
		{
			hint = &_head.parent;
		}
		while (*hint != &_head && *hint != NULL)
		{
			parent = *hint;
			if (_compare(parent, key))
				hint = &parent->right;
			else if (_compare(key, parent))
				hint = &parent->left;
			else
				return (*hint);
		}
		return (*hint);
	}

	NodeBase_ptr	_find_node	(key_type const & key)
	{
		NodeBase_ptr	node = _head.parent;

		while (node != &_head && node != NULL)
		{
			if (_compare(node, key))
				node = node->right;
			else if (_compare(key, node))
				node = node->left;
			else
				return (node);
		}
		return (node);
	}
	NodeBase_const_ptr	_find_node	(key_type const & key) const
	{
		NodeBase_const_ptr	node = _head.parent;

		while (node != &_head && node != NULL)
		{
			if (_compare(node, key))
				node = node->right;
			else if (_compare(key, node))
				node = node->left;
			else
				return (node);
		}
		return (node);
	}

# endif
#endif


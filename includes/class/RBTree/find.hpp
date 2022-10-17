/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:27:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/12 18:39:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_FIND_HPP
# define RBTREE_FIND_HPP

public:
	iterator		find	(key_type const & key)
	{	return (iterator(this->_find_node(key)));	}
	const_iterator	find	(key_type const & key) const
	{	return (const_iterator(this->_find_node(key)));	}

private:
	NodeBase_ptr &	_find	(key_type const & key)
	{
		NodeBase_ptr	parent = &_head;
		return (this->_find(key, parent));
	}

	NodeBase_ptr &	_find	(key_type const & key,
							 NodeBase_ptr & parent)
	{
		return (_find(key, parent, &_root));
	}

	NodeBase_ptr &	_find	(key_type const & key,
							 NodeBase_ptr & parent,
							 NodeBase_ptr * hint)
	{
		if (*hint == &_head || (*hint != _root &&
			(((*hint)->parent->left == *hint && _compare((*hint)->parent, key)) ||
			 ((*hint)->parent->right == *hint && _compare(key, (*hint)->parent)))))
		{
			hint = &_root;
		}
		while (*hint != &_head)
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
		NodeBase_ptr	node = _root;

		while (node != &_head)
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
		NodeBase_const_ptr	node = _root;

		while (node != &_head)
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


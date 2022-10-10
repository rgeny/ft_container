/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:27:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 15:10:41 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_FIND_HPP
# define RBTREE_FIND_HPP

public:
	iterator		find	(key_type const & key)
	{	return (iterator(this->_find(key)));	}
	const_iterator	find	(key_type const & key) const
	{	return (iterator(this->_find(key)));	}

private:
	NodeBase_ptr &	_find	(key_type const & key)
	{
		NodeBase_ptr	parent = _sentinel;
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
		if (*hint == _sentinel || (*hint != _root &&
			(((*hint)->parent->left == *hint && _compare((*hint)->parent, key)) ||
			 ((*hint)->parent->right == *hint && _compare(key, (*hint)->parent)))))
		{
			hint = &_root;
		}
		while (*hint != _sentinel)
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




# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:27:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 12:35:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_FIND_HPP
# define RBTREE_FIND_HPP

NodeBase_ptr &	find	(key_type const & key,
						 NodeBase_ptr & parent)
{
	NodeBase_ptr *	node = &_root;

	while (*node != _sentinel)
	{
		parent = *node;
		if (_compare(parent, key))
			node = &parent->right;
		else if (_compare(key, parent))
			node = &parent->left;
		else
			return (*node);
	}
	return (*node);
}

NodeBase_ptr &	find	(key_type const & key)
{
	NodeBase_ptr	parent = _sentinel;
	return (this->find(key, parent));
}

# endif
#endif


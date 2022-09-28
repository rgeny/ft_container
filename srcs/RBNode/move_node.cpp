/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:30:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:05:05 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"

ft::RBNodeBase *	ft::decrement	(ft::RBNodeBase * node)
{
	if ( ! node->left->is_sentinel() )
		return (node->left->max());
	
	ft::RBNodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

ft::RBNodeBase *	ft::increment	(ft::RBNodeBase * node)
{
	if ( ! node->right->is_sentinel() )
		return (node->right->min());
	
	ft::RBNodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

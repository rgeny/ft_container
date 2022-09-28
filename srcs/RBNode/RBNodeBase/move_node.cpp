/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:30:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:44:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"

ft::RB::NodeBase *	ft::RB::decrement	(ft::RB::NodeBase * node)
{
	if ( ! node->left->is_sentinel() )
		return (node->left->max());
	
	ft::RB::NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

ft::RB::NodeBase *	ft::RB::increment	(ft::RB::NodeBase * node)
{
	if ( ! node->right->is_sentinel() )
		return (node->right->min());
	
	ft::RB::NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

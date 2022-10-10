/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:30:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 12:59:48 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"

using namespace ft::RB;

NodeBase *	ft::RB::node_decrement	(NodeBase * node)
{
	if (node->is_sentinel())
		return (node->parent->max());
	if ( ! node->left->is_sentinel() )
		return (node->left->max());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase const *	ft::RB::node_decrement	(NodeBase const * node)
{
	if (node->is_sentinel())
		return (node->parent->max());
	if ( ! node->left->is_sentinel() )
		return (node->left->max());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase *	ft::RB::node_increment	(NodeBase * node)
{
	if (node->is_sentinel())
		return (node->parent->max());
	if ( ! node->right->is_sentinel() )
		return (node->right->min());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase const *	ft::RB::node_increment	(NodeBase const * node)
{
	if (node->is_sentinel())
		return (node->parent->max());
	if ( ! node->right->is_sentinel() )
		return (node->right->min());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_sentinel() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

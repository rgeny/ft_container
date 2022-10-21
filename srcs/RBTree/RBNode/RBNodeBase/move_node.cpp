/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:30:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 18:17:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"

using namespace ft::RB;

NodeBase *	ft::RB::node_decrement	(NodeBase * node)
{
	if (node->is_head())
		return (node->parent->max());
	if ( node->left != NULL )
		return (node->left->max());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_head() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase const *	ft::RB::node_decrement	(NodeBase const * node)
{
	if (node->is_head())
		return (node->parent->max());
	if ( node->left != NULL )
		return (node->left->max());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_head() &&
			parent->left == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase *	ft::RB::node_increment	(NodeBase * node)
{
	if (node->is_head())
		return (node->parent->max());
	if ( node->right != NULL )
		return (node->right->min());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_head() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

NodeBase const *	ft::RB::node_increment	(NodeBase const * node)
{
	if (node->is_head())
		return (node->parent->max());
	if ( node->right != NULL )
		return (node->right->min());
	
	NodeBase *	parent = node->parent;
	while ( ! parent->is_head() &&
			parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}

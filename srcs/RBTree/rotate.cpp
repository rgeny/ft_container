/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:25:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/29 16:37:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

void	_left_rotate	(NodeBase_ptr parent,
						 NodeBase_ptr & root)
{
	NodeBase_ptr	child = parent->right;
	NodeBase_ptr	grandp = parent->parent;

	parent->right = child->left;
	if ( ! child->left->is_sentinel() )
		child->left->parent = parent;
	child->parent = grandp;
	if ( grandp->is_sentinel() )
		root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->left = parent;
	parent->parent = child;
}

void	_right_rotate	(NodeBase_ptr parent,
						 NodeBase_ptr & root)
{
	NodeBase_ptr	child = parent->left;
	NodeBase_ptr	grandp = parent->parent;

	parent->left = child->right;
	if ( ! child->right->is_sentinel() )
		child->right->parent = parent;
	child->parent = grandp;
	if ( grandp->is_sentinel() )
		root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->right = parent;
	parent->parent = child;
}

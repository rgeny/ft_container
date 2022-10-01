/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:25:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 11:02:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

void	ft::RB::left_rotate	(NodeBase * parent,
							 NodeBase * & root)
{
	NodeBase *	child = parent->right;
	NodeBase *	grandp = parent->parent;

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

void	ft::RB::right_rotate	(NodeBase * parent,
								 NodeBase * & root)
{
	NodeBase *	child = parent->left;
	NodeBase *	grandp = parent->parent;

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
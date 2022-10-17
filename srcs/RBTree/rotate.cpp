/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:25:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 17:46:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

void	ft::RB::left_rotate	(NodeBase * parent,
							 NodeBase * & root)
{
	NodeBase *	child = parent->right;
	NodeBase *	grandp = parent->parent;

	if (child != NULL)
	{
		parent->right = child->left;
		if ( ! child->left->is_head() )
			child->left->parent = parent;
		child->parent = grandp;
		child->left = parent;
	}
	if ( grandp->is_head() )
		root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	parent->parent = child;
}

void	ft::RB::right_rotate	(NodeBase * parent,
								 NodeBase * & root)
{
	NodeBase *	child = parent->left;
	NodeBase *	grandp = parent->parent;

	parent->left = child->right;
	if ( ! child->right->is_head() )
		child->right->parent = parent;
	child->parent = grandp;
	if ( grandp->is_head() )
		root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->right = parent;
	parent->parent = child;
}

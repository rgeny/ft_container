/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert_and_balance.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:05:59 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 14:13:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

void	ft::RB::tree_insert_and_balance	(NodeBase_ptr new_node,
										 NodeBase_ptr & root)
{
	NodeBase_ptr	parent;
	NodeBase_ptr	uncle;
	NodeBase_ptr	grandp;

	while (new_node->parent->color == red_node)
	{
		parent = new_node->parent;
		grandp = parent->parent;
		if (grandp->left == parent)
		{
			uncle = grandp->right;
			if (uncle->color == red_node)
			{
				uncle->color = black_node;
				parent->color = black_node;
				grandp->color = red_node;
				new_node = grandp;
			}
			else
			{
				if (new_node == parent->right)
				{
					left_rotate(new_node->parent, root);
					new_node = parent;
				}
				new_node->parent->color = black_node;
				new_node->parent->parent->color = red_node;
				right_rotate(new_node->parent->parent, root);
			}
		}
		else
		{
			uncle = grandp->left;
			if (uncle->color == red_node)
			{
				uncle->color = black_node;
				parent->color = black_node;
				grandp->color = red_node;
				new_node = grandp;
			}
			else
			{
				if (new_node == parent->left)
				{
					right_rotate(new_node->parent, root);
					new_node = parent;
				}
				new_node->parent->color = black_node;
				new_node->parent->parent->color = red_node;
				left_rotate(new_node->parent->parent, root);
			}
		}
	}
	root->color = black_node;	
}

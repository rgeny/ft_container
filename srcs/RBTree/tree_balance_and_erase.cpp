/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance_and_erase.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 11:09:41 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

static void	_transplant	(NodeBase_ptr parent,
						 NodeBase_ptr child,
						 NodeBase_ptr & root)
{
	NodeBase_ptr	grandp = parent->parent;

	if ( grandp->is_sentinel() )
		root = child;
	else if (parent == grandp->left)
		grandp->left = child;
	else
		grandp->right = child;
	child->parent = grandp;
}

static void	_erase_balance	(NodeBase_ptr node,
							 NodeBase_ptr & root)
{
	NodeBase_ptr	parent;
	NodeBase_ptr	sister;

	while (node != root && node->color == black_node)
	{
		parent = node->parent;
		if (node == parent->left)
		{
			sister = parent->right;
			if (sister->color == red_node)
			{
				sister->color = black_node;
				parent->color = red_node;
				left_rotate(node->parent, root);
				sister = node->parent->right;
			}
			if (sister->left->color == black_node &&
				sister->right->color == black_node)
			{
				sister->color = red_node;
				node = node->parent;
			}
			else
			{
				if (sister->right->color == black_node)
				{
					sister->left->color = black_node;
					sister->color = red_node;
					right_rotate(sister, root);
					sister = node->parent->right;
				}
				sister->color = node->parent->color;
				node->parent->color = black_node;
				sister->right->color = black_node;
				left_rotate(node->parent, root);
				node = root;
			}
		}
		else
		{
			sister = parent->left;
			if (sister->color == red_node)
			{
				sister->color = black_node;
				parent->color = red_node;
				right_rotate(node->parent, root);
				sister = node->parent->left;
			}
			if (sister->left->color == black_node &&
				sister->right->color == black_node)
			{
				sister->color = red_node;
				node = node->parent;
			}
			else
			{
				if (sister->left->color == black_node)
				{
					sister->right->color = black_node;
					sister->color = red_node;
					left_rotate(sister, root);
					sister = node->parent->left;
				}
				sister->color = node->parent->color;
				node->parent->color = black_node;
				sister->left->color = black_node;
				right_rotate(node->parent, root);
				node = root;
			}
		}
	}
	node->color = black_node;
}

NodeBase_ptr	ft::RB::tree_balance_and_erase	(NodeBase_ptr del_node,
												 NodeBase_ptr & root)
{
	if ( del_node->is_sentinel() )
		return (0);

	node_color		original_color = del_node->color;
	NodeBase_ptr	child,
					min = del_node;

	if ( del_node->left->is_sentinel() )
	{
		child = del_node->right;
		_transplant(del_node, child, root);
	}
	else if ( del_node->right->is_sentinel() )
	{
		child = del_node->left;
		_transplant(del_node, child, root);
	}
	else
	{
		min = del_node->right->min();
		original_color = min->color;
		child = min->right;
		if (min->parent == del_node)
			child->parent = min;
		else
		{
			_transplant(min, min->right, root);
			min->right = del_node->right;
			min->right->parent = min;
		}
		_transplant(del_node, min, root);
		min->left = del_node->left;
		min->left->parent = min;
		min->color = del_node->color;;
	}

//	_clear(del_node);
	if (original_color == black_node)
		_erase_balance(child, root);
//	_sentinel->parent = _sentinel;
//	return (1);
	return (del_node);
}

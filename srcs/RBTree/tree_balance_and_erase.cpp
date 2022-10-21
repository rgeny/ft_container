/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance_and_erase.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 14:28:29 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/balance_erase_insert.hpp"

using namespace ft::RB;

static void	_transplant	(NodeBase_ptr parent,
						 NodeBase_ptr child,
						 NodeBase_ptr & root)
{
	NodeBase_ptr	grandp = parent->parent;

	if ( grandp == root->parent )
		root = child;
	else if (parent == grandp->left)
		grandp->left = child;
	else
		grandp->right = child;
	if (child != NULL)
		child->parent = grandp;
}

static void	_erase_balance	(NodeBase_ptr node,
							 NodeBase_ptr parent,
							 NodeBase_ptr & root)
{
//	NodeBase_ptr	parent;
	NodeBase_ptr	sister;

	while (node != root && (node == NULL || node->color == black_node))
	{
		if (node != NULL)
			parent = node->parent;
		if (node == parent->left)
		{
			sister = parent->right;
			if (sister != NULL && sister->color == red_node)
			{
				sister->color = black_node;
				parent->color = red_node;
				left_rotate(parent, root);
				sister = parent->right;
			}
			if (sister != NULL &&
				(sister->left == NULL || sister->left->color == black_node) &&
				(sister->right == NULL || sister->right->color == black_node))
			{
				sister->color = red_node;
				node = parent;
			}
			else
			{
				if (sister != NULL &&
					(sister->right == NULL || sister->right->color == black_node))
				{
					if (sister->left != NULL)
						sister->left->color = black_node;
					sister->color = red_node;
					right_rotate(sister, root);
					sister = parent->right;
				}
				if (sister != NULL)
				{
					sister->color = parent->color;
					if (sister->right != NULL)
						sister->right->color = black_node;
				}
				parent->color = black_node;
				left_rotate(parent, root);
				node = root;
			}
		}
		else
		{
			sister = parent->left;
			if (sister != NULL && sister->color == red_node)
			{
				sister->color = black_node;
				parent->color = red_node;
				right_rotate(parent, root);
				sister = parent->left;
			}
			if (sister != NULL &&
				(sister->left == NULL || sister->left->color == black_node) &&
				(sister->right == NULL || sister->right->color == black_node))
			{
				sister->color = red_node;
				node = parent;
			}
			else
			{
				if (sister != NULL &&
					(sister->left == NULL || sister->left->color == black_node))
				{
					if (sister->right != NULL)
						sister->right->color = black_node;
					sister->color = red_node;
					left_rotate(sister, root);
					sister = parent->left;
				}
				if (sister != NULL)
				{
					sister->color = parent->color;
					if (sister->left != NULL)
						sister->left->color = black_node;
				}
				parent->color = black_node;
				right_rotate(parent, root);
				node = root;
			}
		}
	}
	if (node != NULL)
		node->color = black_node;
}

NodeBase_ptr	ft::RB::tree_balance_and_erase	(NodeBase_ptr del_node,
												 NodeBase_ptr & root)
{
	node_color		original_color = del_node->color;
	NodeBase_ptr	child,
					parent = del_node,
					min = del_node;

	if ( del_node->left == NULL )
	{
		child = del_node->right;
		parent = del_node->parent;
		_transplant(del_node, child, root);
	}
	else if ( del_node->right == NULL )
	{
		child = del_node->left;
		parent = del_node->parent;
		_transplant(del_node, child, root);
	}
	else
	{
		min = del_node->right->min();
		original_color = min->color;
		child = min->right;
		parent = min;
		if (min->parent == del_node)
		{
			if (child != NULL)
				child->parent = min;
		}
		else
		{
			_transplant(min, min->right, root);
			min->right = del_node->right;
			parent = min->parent;
			if (min->right != NULL)
				min->right->parent = min;
		}
		_transplant(del_node, min, root);
		min->left = del_node->left;
		min->left->parent = min;
		min->color = del_node->color;;
	}

	if (original_color == black_node)
		_erase_balance(child, parent, root);
	return (del_node);
}

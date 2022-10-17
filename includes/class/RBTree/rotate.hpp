/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 14:05:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ROTATE_HPP
#  define RBTREE_ROTATE_HPP

void	_left_rotate	(NodeBase_ptr parent)
{
	NodeBase_ptr	child = parent->right;
	NodeBase_ptr	grandp = parent->parent;

	parent->right = child->left;
	if (child->left != &_head)
		child->left->parent = parent;
	child->parent = grandp;
	if (grandp == &_head)
		_root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->left = parent;
	parent->parent = child;
}

void	_right_rotate	(NodeBase_ptr parent)
{
	NodeBase_ptr	child = parent->left;
	NodeBase_ptr	grandp = parent->parent;

	parent->left = child->right;
	if (child->right != &_head)
		child->right->parent = parent;
	child->parent = grandp;
	if (grandp == &_head)
		_root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->right = parent;
	parent->parent = child;
}

# endif
#endif


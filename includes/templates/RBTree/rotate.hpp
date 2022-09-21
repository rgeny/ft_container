/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 18:00:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ROTATE_HPP
#  define RBTREE_ROTATE_HPP

void	_left_rotate	(node_pointer parent)
{
	node_pointer	child = parent->right;
	node_pointer	grandp = parent->parent;

	parent->right = child->left;
	if (child->left != _sentinel)
		child->left->parent = parent;
	child->parent = grandp;
	if (grandp == _sentinel)
		_root = child;
	else if (grandp->left == parent)
		grandp->left = child;
	else
		grandp->right = child;
	child->left = parent;
	parent->parent = child;
}

void	_right_rotate	(node_pointer parent)
{
	node_pointer	child = parent->left;
	node_pointer	grandp = parent->parent;

	parent->left = child->right;
	if (child->right != _sentinel)
		child->right->parent = parent;
	child->parent = grandp;
	if (grandp == _sentinel)
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


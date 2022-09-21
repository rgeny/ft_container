/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 18:26:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ERASE_HPP
#  define RBTREE_ERASE_HPP

public:
	size_type	erase	(key_type const & key)
	{
		return (this->erase(this->find(key)));
	}

	size_type	erase	(node_pointer del_node)
	{
		if (del_node == _sentinel)
			return (0);

		e_color			original_color = del_node->color;
		node_pointer	child,
						min = del_node;

		if (del_node->left == _sentinel)
		{
			child = del_node->right;
			_transplant(del_node, child);
		}
		else if (del_node->right == _sentinel)
		{
			child = del_node->left;
			_transplant(del_node, child);
		}
		else
		{
			min = _getMin(del_node->right);
			original_color = min->color;
			child = min->right;
			if (min->parent == del_node)
				child->parent = min;
			else
			{
				_transplant(min, min->right);
				min->right = del_node->right;
				min->right->parent = min;
			}
			_transplant(del_node, min);
			min->left = del_node->left;
			min->left->parent = min;
			min->color = del_node->color;;
		}

		_clear(del_node);
		if (original_color == BLACK)
			_erase_balance(child);
		return (1);
	}

private:
	node_pointer	_getMin	(node_pointer node)
	{
		while (node->left != _sentinel)
			node = node->left;
		return (node);
	}

	void	_transplant	(node_pointer parent,
						 node_pointer child)
	{
		node_pointer	grandp = parent->parent;

		if (grandp == _sentinel)
			_root = child;
		else if (parent == grandp->left)
			grandp->left = child;
		else
			grandp->right = child;
		child->parent = grandp;
	}

	void	_erase_balance	(node_pointer node)
	{
		node_pointer	parent;
		node_pointer	sister;

		while (node != _root && node->color == BLACK)
		{
			parent = node->parent;
			if (node == parent->left)
			{
				sister = parent->right;
				if (sister->color == RED)
				{
					sister->color = BLACK;
					parent->color = RED;
					_left_rotate(node->parent);
					sister = node->parent->right;
				}
				if (sister->left->color == BLACK &&
					sister->right->color == BLACK)
				{
					sister->color = RED;
					node = node->parent;
				}
				else
				{
					if (sister->right->color == BLACK)
					{
						sister->left->color = BLACK;
						sister->color = RED;
						_right_rotate(sister);
						sister = node->parent->right;
					}
					sister->color = node->parent->color;
					node->parent->color = BLACK;
					sister->right->color = BLACK;
					_left_rotate(node->parent);
					node = _root;
				}
			}
			else
			{
				sister = parent->left;
				if (sister->color == RED)
				{
					sister->color = BLACK;
					parent->color = RED;
					_right_rotate(node->parent);
					sister = node->parent->left;
				}
				if (sister->left->color == BLACK &&
					sister->right->color == BLACK)
				{
					sister->color = RED;
					node = node->parent;
				}
				else
				{
					if (sister->left->color == BLACK)
					{
						sister->right->color = BLACK;
						sister->color = RED;
						_left_rotate(sister);
						sister = node->parent->left;
					}
					sister->color = node->parent->color;
					node->parent->color = BLACK;
					sister->left->color = BLACK;
					_right_rotate(node->parent);
					node = _root;
				}
			}
		}
		node->color = BLACK;
	}

# endif
#endif


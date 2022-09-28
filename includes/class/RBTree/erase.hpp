/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 17:55:25 by rgeny            ###   ########.fr       */
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

	size_type	erase	(NodeBase_ptr del_node)
	{
		if (del_node == _sentinel)
			return (0);

		node_color		original_color = del_node->color;
		NodeBase_ptr	child,
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
			min = del_node->right->min();
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
		if (original_color == black_node)
			_erase_balance(child);
		_sentinel->parent = _sentinel;
		return (1);
	}

private:

	void	_transplant	(NodeBase_ptr parent,
						 NodeBase_ptr child)
	{
		NodeBase_ptr	grandp = parent->parent;

		if (grandp == _sentinel)
			_root = child;
		else if (parent == grandp->left)
			grandp->left = child;
		else
			grandp->right = child;
		child->parent = grandp;
	}

	void	_erase_balance	(NodeBase_ptr node)
	{
		NodeBase_ptr	parent;
		NodeBase_ptr	sister;

		while (node != _root && node->color == black_node)
		{
			parent = node->parent;
			if (node == parent->left)
			{
				sister = parent->right;
				if (sister->color == red_node)
				{
					sister->color = black_node;
					parent->color = red_node;
					_left_rotate(node->parent);
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
						_right_rotate(sister);
						sister = node->parent->right;
					}
					sister->color = node->parent->color;
					node->parent->color = black_node;
					sister->right->color = black_node;
					_left_rotate(node->parent);
					node = _root;
				}
			}
			else
			{
				sister = parent->left;
				if (sister->color == red_node)
				{
					sister->color = black_node;
					parent->color = red_node;
					_right_rotate(node->parent);
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
						_left_rotate(sister);
						sister = node->parent->left;
					}
					sister->color = node->parent->color;
					node->parent->color = black_node;
					sister->left->color = black_node;
					_right_rotate(node->parent);
					node = _root;
				}
			}
		}
		node->color = black_node;
	}

# endif
#endif


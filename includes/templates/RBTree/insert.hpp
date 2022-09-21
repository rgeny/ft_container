/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:04:59 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 18:05:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef INSERT_HPP
#  define INSERT_HPP

public:
	value_type	insert	(const_reference value)
	{
		node_pointer	parent = _sentinel;
		node_pointer *	new_node = &_root;

		while (*new_node != _sentinel)
		{
			parent = *new_node;
			if (_comp(parent->value, value))
				new_node = &parent->right;
			else if (_comp(value, parent->value))
				new_node = &parent->left;
			else
				return (parent->value);
		}

		_construct(*new_node, parent, value);
			_insert_balance(*new_node);
		return (value);
	}

private:
	void	_insert_balance	(node_pointer node)
	{
		node_pointer	parent;
		node_pointer	uncle;
		node_pointer	grandp;

		while (node->parent->color == RED)
		{
			parent = node->parent;
			grandp = parent->parent;
			if (grandp->left == parent)
			{
				uncle = grandp->right;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					parent->color = BLACK;
					grandp->color = RED;
					node = grandp;
				}
				else
				{
					if (node == parent->right)
					{
						_left_rotate(node->parent);
						node = parent;
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					_right_rotate(node->parent->parent);
				}
			}
			else
			{
				uncle = grandp->left;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					parent->color = BLACK;
					grandp->color = RED;
					node = grandp;
				}
				else
				{
					if (node == parent->left)
					{
						_right_rotate(node->parent);
						node = parent;
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					_left_rotate(node->parent->parent);
				}
			}
		}
		_root->color = BLACK;
	}

# endif
#endif


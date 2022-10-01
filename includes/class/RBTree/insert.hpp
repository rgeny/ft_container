/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:00:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 11:01:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef INSERT_HPP
#  define INSERT_HPP

public:
	value_type	insert	(const_reference value)
	{
		NodeBase_ptr	parent = _cast(_sentinel);
		NodeBase_ptr *	new_node = &_root;

		while (*new_node != _sentinel)
		{
			parent = *new_node;
			if (_compare(parent, value))
				new_node = &parent->right;
			else if (_compare(value, parent))
				new_node = &parent->left;
			else
				return (_cast(parent)->value);
		}

		_construct(*new_node, parent, value);
			_insert_balance(*new_node);
		return (value);
	}

private:
	void	_insert_balance	(NodeBase_ptr node)
	{
		NodeBase_ptr	parent;
		NodeBase_ptr	uncle;
		NodeBase_ptr	grandp;

		while (node->parent->color == red_node)
		{
			parent = node->parent;
			grandp = parent->parent;
			if (grandp->left == parent)
			{
				uncle = grandp->right;
				if (uncle->color == red_node)
				{
					uncle->color = black_node;
					parent->color = black_node;
					grandp->color = red_node;
					node = grandp;
				}
				else
				{
					if (node == parent->right)
					{
						left_rotate(node->parent, _root);
						node = parent;
					}
					node->parent->color = black_node;
					node->parent->parent->color = red_node;
					right_rotate(node->parent->parent, _root);
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
					node = grandp;
				}
				else
				{
					if (node == parent->left)
					{
						right_rotate(node->parent, _root);
						node = parent;
					}
					node->parent->color = black_node;
					node->parent->parent->color = red_node;
					left_rotate(node->parent->parent, _root);
				}
			}
		}
		_root->color = black_node;
	}

# endif
#endif


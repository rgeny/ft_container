/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 22:56:24 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

//tmp
# include <sstream>
# include <vector>
# include "colors.hpp"
//end tmp

# include "print.hpp"
# include "type_traits.hpp"
# include "RBNode.hpp"
# define CLASS_NAME "RBTree"

namespace ft
{
#ifdef __DEBUG__
	static inline void	_print_nl	(std::string str)
	{
		std::cout	<< str
					<< std::endl;
	}
	static inline void	_print_nl	(void)
	{
		std::cout	<< std::endl;
	}
#endif
	template
	<
		typename Key,
		typename Value = Key,
		typename KeyOfValue = Value, // tmp
		typename Compare = std::less<Value>,
		typename Allocator = std::allocator<Value>
	>
	class RBTree
	{
		private:
			typedef typename Allocator::template rebind<RBNode<Value> >::other	_node_allocator_type;

		public:
			typedef Key											key_type;
			typedef Value										value_type;
			typedef typename _node_allocator_type::value_type	node_type;
			typedef typename _node_allocator_type::pointer		node_pointer;
			typedef node_pointer &								node_preference;
			typedef size_t										size_type;
			typedef Allocator									allocator_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
# include "RBTree/structor.hpp"

			RBTree &	operator=	(__attribute__ ((unused)) RBTree const & src)
			{
				this->clear();
				_root = new RBTree<value_type>(*src._root);
				return (*this);
			}

			value_type	insert(value_type const & value )
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

			void	clear	(void)
			{
				_clear_all(_root);
			}

			size_type	size	(void) const
			{	return (_size);	}

		private:

//			iterator insert( iterator hint, const value_type& value );

			allocator_type			_alloc;
			_node_allocator_type	_node_alloc;
			node_pointer			_sentinel;
			node_pointer			_root;
			size_type				_size;
			key_compare				_comp;

# include "RBTree/private.hpp"

//			void	_balance	(node_pointer & node)
//			{
//				if (node->parent->color == BLACK)
//					return ;
//				
//			}



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
								_left_rotate(node);
								node = parent;
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							_right_rotate(node->parent);
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
								_right_rotate(node);
								node = parent;
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							_left_rotate(node->parent);
						}
					}
				}
				_root->color = BLACK;
			}

			void	_left_rotate	(node_pointer node)
			{
				node_pointer	parent = node->parent;
				node_pointer	grandp = parent->parent;

				parent->right = node->left;
				if (node->left != _sentinel)
					node->left->parent = parent;
				node->parent = grandp;
				if (grandp == _sentinel)
					_root = node;
				else if (grandp->left == parent)
					grandp->left = node;
				else
					grandp->right = node;
				node->left = parent;
				parent->parent = node;
			}

			void	_right_rotate	(node_pointer node)
			{
				node_pointer	parent = node->parent;
				node_pointer	grandp = parent->parent;

				parent->left = node->right;
				if (node->right != _sentinel)
					node->right->parent = parent;
				node->parent = grandp;
				if (grandp == _sentinel)
					_root = node;
				else if (grandp->left == parent)
					grandp->left = node;
				else
					grandp->right = node;
				node->right = parent;
				parent->parent = node;
			}

# include "RBTree/print.hpp"
	};
}
# undef CLASS_NAME
#endif


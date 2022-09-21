/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 16:58:27 by rgeny            ###   ########.fr       */
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
			typedef Allocator									allocator_type;
			typedef Key											key_type;
			typedef Value										value_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename _node_allocator_type::value_type	node_type;
			typedef typename _node_allocator_type::pointer		node_pointer;
			typedef node_pointer &								node_preference;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
# include "RBTree/structor.hpp"

			RBTree &	operator=	(RBTree const & src)
			{
				this->clear();
				_root = new RBTree<value_type>(*src._root);
				return (*this);
			}

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
//
//			size_type	erase	(__attribute__((unused)) Key const & key)
//			{
//				node_pointer	del_node = _root;
//				Key				cur_key = KeyOfValue()(_root->value);
//
//				while (_comp(cur_key, key) || _comp(key, cur_key))
//				{
//					if (del_node == _sentinel)
//						return (0);
//					else if (_comp(cur_key, key))
//						del_node = del_node->right;
//					else
//						del_node = del_node->left;
//					cur_key = KeyOfValue()(del_node->value);
//				}
//
//				_erase_balance(del_node);
//
//				_clear(del_node);
//
//				return (1);
//			}


			size_type	erase	(__attribute__((unused)) Key const & key)
			{
				node_pointer	del_node = _sentinel;
				node_pointer	cur_node = _root;
				Key				cur_key = KeyOfValue()(_root->value);

//				while (_comp(cur_key, key) || _comp(key, cur_key))
//				{
//					if (del_node == _sentinel)
//						return (0);
//					else if (_comp(cur_key, key))
//						del_node = del_node->right;
//					else
//						del_node = del_node->left;
//					cur_key = KeyOfValue()(del_node->value);
//					std::cout	<< "t1\n";
//				}
				while (cur_node != _sentinel)
				{
					if (!_comp(cur_key, key) && !_comp(key, cur_key))
						del_node = cur_node;

					if (_comp(key, cur_key))
						cur_node = cur_node->left;
					else
						cur_node = cur_node->right;
					cur_key = KeyOfValue()(cur_node->value);
				}

				if (del_node == _sentinel)
					return 0;

				e_color			original_color = del_node->color;
				node_pointer	child;
				node_pointer	min = del_node;

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
					min = _min(del_node->right);
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

			node_pointer	_min	(node_pointer node)
			{
				while (node->left != _sentinel)
					node = node->left;
				return (node);
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

# include "RBTree/print.hpp"
	};
}
# undef CLASS_NAME
#endif


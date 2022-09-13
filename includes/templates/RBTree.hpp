/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 21:03:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

# include "print.hpp"
# include "type_traits.hpp"
# include "RBNode.hpp"
# define CLASS_NAME "RBTree"

namespace ft
{
#ifdef __DEBUG__
	static void	_print_nl	(std::string str)
	{
		std::cout	<< str
					<< std::endl;
	}
	static void	_print_nl	(void)
	{
		std::cout	<< std::endl;
	}
#endif
	template
	<
		typename Value,
		typename Allocator = std::allocator<RBNode<Value> >
	>
	class RBTree
	{
		public:
			typedef Value				value_type;
			typedef	RBNode<value_type>	node_type;
			typedef Allocator			allocator_type;

			RBTree	(allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(NULL)
				,_root(NULL)
			{
				RBNode<value_type>	tmp(_sentinel);
				_sentinel = _alloc.allocate(1, &tmp);
				_alloc.construct(_sentinel, _sentinel);
				_root = _sentinel;
			}

			RBTree	(__attribute__ ((unused)) RBTree const & src,
					 allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(_alloc.allocate(1, _sentinel))
				,_root(_sentinel)
			{
				_alloc.construct(_sentinel);
				if (src._root != src._sentinel)
					_root = _alloc.allocate(1, *src._root);
			}
			~RBTree	(void)
			{
				this->clear();
				_alloc.destroy(_sentinel);
				_alloc.deallocate(_sentinel, 1);
			}

			RBTree &	operator=	(__attribute__ ((unused)) RBTree const & src)
			{
				this->clear();
				_root = new RBTree<value_type>(*src._root);
				return (*this);
			}

			value_type	insert(value_type const & value )
			{
				if (_root == _sentinel)
				{
					node_type *	new_node = _alloc.allocate(1);
					node_type	tmp(_sentinel, value);
					_alloc.construct(new_node, tmp);
					_root = new_node;
				}
				else
					_insert(_root, value);
				return (value);
			}

			void	clear	(void)
			{
				if (_root != _sentinel)
					_clear(_root);
			}

			void	print	(void)
			{
				print(_root);
			}

			void	print	(RBNode<value_type> * const & node)
			{
				if (node == _sentinel)
					return ;
				print(node->left);
				std::cout	<< node->value
							<< std::endl;
				print(node->right);
			}

//			iterator insert( iterator hint, const value_type& value );

		private:
			allocator_type			_alloc;
			RBNode<value_type> *	_sentinel;
			RBNode<value_type> *	_root;

			void	_clear	(RBNode<value_type> * & node)
			{
				if (node != _sentinel)
				{
					_clear(node->left);
					_clear(node->right);
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					node = _sentinel;
				}
			}

			void	_insert	(RBNode<value_type> * & cur_pt,
							 value_type const & value)
			{
#ifdef __DEBUG__
	ft::_print_nl();
	ft::_print_nl("---_insert (RBNode<value_type> * & cur_pt, value_type const & value)---");
#endif
				if (*cur_pt == value)
				{
#ifdef __DEBUG__
	_print_nl("*cur_pt = value");
#endif
					*cur_pt = value;
				}
				else if (*cur_pt < value)
				{
#ifdef __DEBUG__
	ft::_print_nl("*cur_pt < value");
#endif
					if (cur_pt->right == _sentinel)
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->right == NULL");
#endif
						RBNode<value_type> **	pt = &cur_pt->right;
						*pt = _alloc.allocate(1);
						RBNode<value_type>	tmp(_sentinel, value);
						_alloc.construct(cur_pt->right, tmp);
					}
					else
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->right != NULL");
#endif
						_insert(cur_pt->right, value);
					}
				}
				else
				{
#ifdef __DEBUG__
	ft::_print_nl("*cur_pt > value");
#endif
					if (cur_pt->left == _sentinel)
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->left == NULL");
#endif
						cur_pt->left = _alloc.allocate(1);
						RBNode<value_type>	tmp(_sentinel, value);
						_alloc.construct(cur_pt->left, tmp);
					}
					else
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->left != NULL");
#endif
						_insert(cur_pt->left, value);
					}
				}
#ifdef __DEBUG__
	ft::_print_nl("---end---");
	ft::_print_nl();
#endif
			}
	};
}
# undef CLASS_NAME
#endif


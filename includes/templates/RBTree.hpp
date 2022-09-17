/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/17 10:52:17 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

//tmp
# include <sstream>
//end tmp

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
			typedef Value					value_type;
			typedef	RBNode<value_type>		node_type;
			typedef	RBNode<value_type> *	node_pointer;
			typedef Allocator				allocator_type;
			typedef size_t					size_type;

			RBTree	(allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(NULL)
				,_root(NULL)
				,_size(0)
			{
				node_type	tmp(_sentinel);
				_sentinel = _alloc.allocate(1, &tmp);
				_alloc.construct(_sentinel, _sentinel);
				_root = _sentinel;
			}

			RBTree	(__attribute__ ((unused)) RBTree const & src,
					 allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(_alloc.allocate(1, _sentinel))
				,_root(_sentinel)
				,_size(0)
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
					node_pointer	new_node = _alloc.allocate(1);
					node_type		tmp(_sentinel, value);
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

		private:

//			iterator insert( iterator hint, const value_type& value );

			allocator_type	_alloc;
			node_pointer	_sentinel;
			node_pointer	_root;
			size_type		_size;

			void	_clear	(node_pointer & node)
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

			void	_balance	(node_pointer & cur_pt)
			{
				if (cur_pt->parent->color == BLACK)
					return ;
				
			}

			void	_insert	(node_pointer & cur_pt,
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
						cur_pt->right = _alloc.allocate(1);
						node_type	tmp(_sentinel, value);
						_alloc.construct(cur_pt->right, tmp);
						++_size;
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
						node_type	tmp(_sentinel, value);
						_alloc.construct(cur_pt->left, tmp);
						++_size;
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
#  include "RBTree/print.hpp"
	};
}
# undef CLASS_NAME
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 15:05:25 by rgeny            ###   ########.fr       */
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
	static void	_print_nl	(std::string str)
	{
		std::cout	<< str
					<< std::endl;
	}
	static void	_print_nl	(void)
	{
		std::cout	<< std::endl;
	}

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
				,_head(NULL)
			{
				RBNode<value_type>	tmp(_sentinel);
				_sentinel = _alloc.allocate(1, &tmp);
				_alloc.construct(_sentinel, _sentinel);
			}

			RBTree	(__attribute__ ((unused)) RBTree const & src,
					 allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(NULL)
				,_head(NULL)
			{
				_sentinel = _alloc.allocate(1, _sentinel);
				_alloc.construct(_sentinel);
				if (src._head != NULL)
					_head = _alloc.allocate(1, *src._head);
			}
			~RBTree	(void)
			{
				_delete_all();
				_alloc.destroy(_sentinel);
				_alloc.deallocate(_sentinel, 1);
			}

			RBTree &	operator=	(__attribute__ ((unused)) RBTree const & src)
			{
				_delete_all();
				_head = new RBTree<value_type>(*src._head);
				return (*this);
			}

			value_type	insert(value_type const & value )
			{
				if (_head == NULL)
				{
					node_type *	new_node = _alloc.allocate(1);
					node_type	tmp(_sentinel, value);
					_alloc.construct(new_node, tmp);
					_head = new_node;
				}
				else
					_insert(_head, value);
				return (value);
			}

//			iterator insert( iterator hint, const value_type& value );

		private:
			allocator_type			_alloc;
			RBNode<value_type> *	_sentinel;
			RBNode<value_type> *	_head;



			void	_delete_all	(void)
			{
				if (_head != NULL)
					_delete(_head);
			}
			void	_delete	(RBNode<value_type> * &	node)
			{
				if (node != NULL)
				{
					_delete(node->getLeft());
					_delete(node->getRight());
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					node = NULL;
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
					if (cur_pt->getRight() == NULL)
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->getRight() == NULL");
#endif
						RBNode<value_type> **	pt = &cur_pt->getRight();
						*pt = _alloc.allocate(1);
						RBNode<value_type>	tmp(_sentinel, value);
						_alloc.construct(cur_pt->getRight(), tmp);
					}
					else
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->getRight() != NULL");
#endif
						_insert(cur_pt->getRight(), value);
					}
				}
				else
				{
#ifdef __DEBUG__
	ft::_print_nl("*cur_pt > value");
#endif
					if (cur_pt->getLeft() == NULL)
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->getLeft() == NULL");
#endif
						cur_pt->getLeft() = _alloc.allocate(1);
						RBNode<value_type>	tmp(_sentinel, value);
						_alloc.construct(cur_pt->getLeft(), tmp);
					}
					else
					{
#ifdef __DEBUG__
	ft::_print_nl("cur_pt->getLeft() != NULL");
#endif
						_insert(cur_pt->getLeft(), value);
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


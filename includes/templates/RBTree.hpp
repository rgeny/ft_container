/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 17:24:57 by rgeny            ###   ########.fr       */
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
		public:

# include "RBTree/typedef.hpp"
# include "RBTree/structor.hpp"

			RBTree &	operator=	(__attribute__ ((unused)) RBTree const & src)
			{
				this->clear();
				_root = new RBTree<value_type>(*src._root);
				return (*this);
			}

			value_type	insert(value_type const & value )
			{
				if (_root == _sentinel)
					_construct(_root, _sentinel, value);
				else
					_insert(_root, value);
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

# include "RBTree/private.hpp"

			void	_balance	(node_pointer & cur_pt)
			{
				if (cur_pt->parent->color == BLACK)
					return ;
				
			}

			void	_insert	(node_pointer & cur_pt,
							 value_type const & value)
			{
				if (*cur_pt == value)
					_construct(cur_pt, cur_pt->parent, value);
				else if (*cur_pt < value)
				{
					if (cur_pt->right == _sentinel)
						_construct(cur_pt->right, cur_pt, value);
					else
						_insert(cur_pt->right, value);
				}
				else
				{
					if (cur_pt->left == _sentinel)
						_construct(cur_pt->left, cur_pt, value);
					else
						_insert(cur_pt->left, value);
				}
			}
# include "RBTree/print.hpp"
	};
}
# undef CLASS_NAME
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeConstIterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:40:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 16:58:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREECONSTITERATOR_HPP
# define RBTREECONSTITERATOR_HPP

# include "RBTreeIterator.hpp"

namespace ft
{
	namespace RB
	{
#  define CLASS_NAME "ft::RB::TreeConstIterator"
		template < typename T >
		class TreeConstIterator
		{
			private:
				typedef TreeConstIterator<T>				_self;
				typedef NodeBase::NodeBase_const_ptr		_NodeBase_ptr;
				typedef Node<T> const *						_Node_ptr;

			public:
				typedef std::bidirectional_iterator_tag		iterator_category;
				typedef T const								value_type;
				typedef std::ptrdiff_t						difference_type;
				typedef value_type const *					pointer;
				typedef value_type const &					reference;

				_NodeBase_ptr	_cur_node;
			
				TreeConstIterator	(void)
					:_cur_node(NULL)
				{
#  ifdef __DEBUG__
				DFL_CTOR
#  endif
				}

				TreeConstIterator	(_NodeBase_ptr node)
					:_cur_node(node)
				{
#  ifdef __DEBUG__
				PAR_CTOR
#  endif
				}
				TreeConstIterator	(_self const & src)
					:_cur_node(src._cur_node)
				{
#  ifdef __DEBUG__
				CPY_CTOR
#  endif
				}

				TreeConstIterator	(TreeIterator<T> const & src)
					:_cur_node(src._cur_node)
				{
#  ifdef __DEBUG__
				std::cout	<< CLASS_NAME " cpy constructor with TreeIterator."
							<< std::endl;
#endif
				}

				_self	operator=	(_self const & src)
				{
					_cur_node = src._cur_node;
					return (*this);
				}

				_self &	operator++	(void)
				{
					_cur_node = node_increment(_cur_node);
					return (*this);
				}
				_self	operator++	(int)
				{
					_self	tmp(*this);
					_cur_node = node_increment(_cur_node);
					return (tmp);
				}
				_self &	operator--	(void)
				{
					_cur_node = node_decrement(_cur_node);
					return (*this);
				}
				_self	operator--	(int)
				{
					_self	tmp(*this);
					_cur_node = node_decrement(_cur_node);
					return (tmp);
				}

				friend bool	operator==	(_self const & lhs,
										 _self const & rhs)
				{
					return (lhs._cur_node == rhs._cur_node);
				}
				friend bool	operator!=	(_self const & lhs,
										 _self const & rhs)
				{
					return (lhs._cur_node != rhs._cur_node);
				}

				reference	operator*	(void) const
				{
					return (static_cast<_Node_ptr>(_cur_node)->value);
				}
				pointer		operator->	(void) const
				{
					return (&(static_cast<_Node_ptr>(_cur_node)->value));
				}

		};
#  undef CLASS_NAME
	}
}

#endif


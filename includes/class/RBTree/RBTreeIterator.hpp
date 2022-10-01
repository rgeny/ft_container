/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:38:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 16:52:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREEITERATOR_HPP
#  define RBTREEITERATOR_HPP

namespace ft
{
	namespace RB
	{
#  define CLASS_NAME "ft::RB::TreeIterator"
		template < typename T >
		class TreeIterator
		{
			private:
				typedef TreeIterator<T>						__self;
				typedef NodeBase::NodeBase_ptr				_NodeBase_ptr;
				typedef Node<T> *							_Node_ptr;

			public:
				typedef std::bidirectional_iterator_tag		iterator_category;
				typedef T									value_type;
				typedef std::ptrdiff_t						difference_type;
				typedef value_type *						pointer;
				typedef value_type &						reference;

				_NodeBase_ptr	_cur_node;

				TreeIterator	(void)
					:_cur_node(NULL)
				{
#  ifdef __DEBUG__
				DFL_CTOR
#  endif
				}

				TreeIterator	(_NodeBase_ptr node)
					:_cur_node(node)
				{
#  ifdef __DEBUG__
				PAR_CTOR
#  endif
				}
				TreeIterator	(__self const & src)
					:_cur_node(src._cur_node)
				{
#  ifdef __DEBUG__
				CPY_CTOR
#  endif
				}

				__self	operator=	(__self const & src)
				{
					_cur_node = src._cur_node;
					return (*this);
				}

				__self &	operator++	(void)
				{
					_cur_node = node_increment(_cur_node);
					return (*this);
				}
				__self	operator++	(int)
				{
					__self	tmp(*this);
					_cur_node = node_increment(_cur_node);
					return (tmp);
				}
				__self &	operator--	(void)
				{
					_cur_node = node_decrement(_cur_node);
					return (*this);
				}
				__self	operator--	(int)
				{
					__self	tmp(*this);
					_cur_node = node_decrement(_cur_node);
					return (tmp);
				}

				friend bool	operator==	(__self const & lhs,
										 __self const & rhs)
				{
					return (lhs._cur_node == rhs._cur_node);
				}
				friend bool	operator!=	(__self const & lhs,
										 __self const & rhs)
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

# endif
#endif


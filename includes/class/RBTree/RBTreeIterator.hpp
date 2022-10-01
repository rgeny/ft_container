/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:38:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 16:41:30 by rgeny            ###   ########.fr       */
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
				typedef TreeIterator<T>						self;
				typedef NodeBase::NodeBase_ptr				NodeBase_ptr;
				typedef Node<T> *							Node_ptr;

			public:
				typedef std::bidirectional_iterator_tag		iterator_category;
				typedef T									value_type;
				typedef std::ptrdiff_t						difference_type;
				typedef value_type *						pointer;
				typedef value_type &						reference;

				NodeBase_ptr	_M_node;

				TreeIterator	(void)
					:_M_node(NULL)
				{
#  ifdef __DEBUG__
				DFL_CTOR
#  endif
				}

				TreeIterator	(NodeBase_ptr node)
					:_M_node(node)
				{
#  ifdef __DEBUG__
				PAR_CTOR
#  endif
				}
				TreeIterator	(self const & src)
					:_M_node(src._M_node)
				{
#  ifdef __DEBUG__
				CPY_CTOR
#  endif
				}

				self	operator=	(self const & src)
				{
					_M_node = src._M_node;
					return (*this);
				}

				self &	operator++	(void)
				{
					_M_node = node_increment(_M_node);
					return (*this);
				}
				self	operator++	(int)
				{
					self	tmp(*this);
					_M_node = node_increment(_M_node);
					return (tmp);
				}
				self &	operator--	(void)
				{
					_M_node = node_decrement(_M_node);
					return (*this);
				}
				self	operator--	(int)
				{
					self	tmp(*this);
					_M_node = node_decrement(_M_node);
					return (tmp);
				}

				friend bool	operator==	(self const & lhs,
										 self const & rhs)
				{
					return (lhs._M_node == rhs._M_node);
				}
				friend bool	operator!=	(self const & lhs,
										 self const & rhs)
				{
					return (lhs._M_node != rhs._M_node);
				}

				reference	operator*	(void) const
				{
					return (static_cast<Node_ptr>(_M_node)->value);
				}
				pointer		operator->	(void) const
				{
					return (&(static_cast<Node_ptr>(_M_node)->value));
				}
		};
#  undef CLASS_NAME

//#  define CLASS_NAME "ft::RB::TreeConstIterator"
//		template < typename T >
//		class TreeConstIterator
//		{
//			public:
//				typedef std::bidirectional_iterator_tag		iterator_category;
//				typedef T const								value_type;
//				typedef std::ptrdiff_t						difference_type;
//				typedef value_type const *					pointer;
//				typedef value_type const &					reference;
//
//				typedef TreeConstIterator<T>				self;
//				typedef NodeBase::NodeBase_ptr				NodeBase_ptr;
//				typedef Node<T> *							Node_ptr;
//
//				NodeBase_ptr	_M_node;
//			
//				TreeConstIterator	(void)
//					:_M_node(NULL)
//				{
//#  ifdef __DEBUG__
//				DFL_CTOR
//#  endif
//				}
//
//				TreeConstIterator	(NodeBase_ptr node)
//					:_M_node(node)
//				{
//#  ifdef __DEBUG__
//				PAR_CTOR
//#  endif
//				}
//				TreeConstIterator	(self const & src)
//					:_M_node(src._M_node)
//				{
//#  ifdef __DEBUG__
//				CPY_CTOR
//#  endif
//				}
//
//				TreeConstIterator	(TreeIterator<T> const & src)
//					:_M_node(src._M_node)
//				{	}
//
//				self	operator=	(self const & src)
//				{
//					_M_node = src._M_node;
//					return (*this);
//				}
//
//				self &	operator++	(void)
//				{
//					_M_node = node_increment(_M_node);
//					return (*this);
//				}
//				self	operator++	(int)
//				{
//					self	tmp(*this);
//					_M_node = node_increment(_M_node);
//					return (tmp);
//				}
//				self &	operator--	(void)
//				{
//					_M_node = node_decrement(_M_node);
//					return (*this);
//				}
//				self	operator--	(int)
//				{
//					self	tmp(*this);
//					_M_node = node_decrement(_M_node);
//					return (tmp);
//				}
//
//				friend bool	operator==	(self const & lhs,
//										 self const & rhs)
//				{
//					return (lhs._M_node == rhs._M_node);
//				}
//				friend bool	operator!=	(self const & lhs,
//										 self const & rhs)
//				{
//					return (lhs._M_node != rhs._M_node);
//				}
//
//				reference	operator*	(void) const
//				{
//					return (static_cast<Node_ptr>(_M_node)->value);
//				}
//				pointer		operator->	(void) const
//				{
//					return (&(static_cast<Node_ptr>(_M_node)->value));
//				}
//
//		};
//#  undef CLASS_NAME
	}
}

# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 16:51:40 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

//# include <iostream>
# include <cstdlib>
# include "type_traits.hpp"
# include "RBNode/RBNodeBase.hpp"

namespace ft
{
//	enum node_color
//	{
//		red_node = true,
//		black_node = false
//	};
//
//#define CLASS_NAME "RBNodeBase"
//	class RBNodeBase
//	{
//		public:
//			typedef RBNodeBase *		NodeBase_ptr;
//
//			NodeBase_ptr	parent;
//			NodeBase_ptr	left;
//			NodeBase_ptr	right;
//			node_color		color;
//
//			RBNodeBase	(NodeBase_ptr parent = NULL,
//						 NodeBase_ptr left = NULL,
//						 NodeBase_ptr right = NULL,
//						 node_color color = black_node)
//				:parent(parent)
//				,left(left)
//				,right(right)
//				,color(color)
//			{
//#ifdef __DEBUG__
//PAR_CTOR
//#endif
//			}
//
//			RBNodeBase	(RBNodeBase const & src)
//				:parent(src.parent)
//				,left(src.left)
//				,right(src.right)
//				,color(src.color)
//			{
//#ifdef __DEBUG__
//CPY_CTOR
//#endif
//			}
//
//			~RBNodeBase	(void)	{}
//
//			NodeBase_ptr	min	(void)
//			{
//				NodeBase_ptr	node = this;
//				while ( ! node->left->is_sentinel() )
//					node = node->left;
//				return (node);
//			}
//
//			NodeBase_ptr	max	(void)
//			{
//				NodeBase_ptr	node = this;
//				while ( ! node->right->is_sentinel() )
//					node = node->right;
//				return (node);
//			}
//
//			bool	is_sentinel	(void)
//			{
//				return (this == this->left);
//			}
//
//	};
//#undef CLASS_NAME

	RBNodeBase *	decrement	(RBNodeBase * node);
	RBNodeBase *	increment	(RBNodeBase * node);

#define CLASS_NAME "RBNode"
	template <typename Value>
	class RBNode
		:public RBNodeBase
	{
		public:
			typedef Value						value_type;
			typedef RBNode *					pointer;
			typedef RBNode<value_type> const *	const_pointer;

			template
			<
				typename T
			>
			RBNode	(T & sentinel,
					 typename ft::enable_if<ft::is_pointer<T>::value>::type = 0)
				:RBNodeBase(sentinel, sentinel, sentinel, black_node)
				,value()
			{
#ifdef __DEBUG__
DFL_CTOR
#endif
			}
			RBNode	(NodeBase_ptr & sentinel,
					 NodeBase_ptr & parent,
					 value_type const value,
					 node_color const color = red_node)
				:RBNodeBase(parent, sentinel, sentinel, color)
				,value(value)
			{
#ifdef __DEBUG__
PAR_CTOR
#endif
			}
			RBNode	(RBNode const & src)
				:RBNodeBase(src)
				,value(src.value)
			{
#ifdef __DEBUG__
CPY_CTOR
#endif
			}
			template < typename _T >
			RBNode	(RBNode<_T> const & src)
				:RBNodeBase(src)
				,value(src.value)
			{
#ifdef __DEBUG__
CPY_CTOR
#endif
			}
			~RBNode	(void)	{}

			value_type		value;
	};
#undef CLASS_NAME
}

#endif


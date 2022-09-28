/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:38:36 by rgeny            ###   ########.fr       */
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
	namespace RB
	{
//	RBNodeBase *	decrement	(RBNodeBase * node);
//	RBNodeBase *	increment	(RBNodeBase * node);

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
}

#endif


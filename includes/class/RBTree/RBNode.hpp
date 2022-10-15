/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/15 17:21:24 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

# include "RBNode/RBNodeBase.hpp"

namespace ft
{
	namespace RB
	{
#define CLASS_NAME "RBNode"
		template <typename Value>
		class Node
			:public NodeBase
		{
			public:
				typedef Value						value_type;
				typedef Node *						pointer;
				typedef Node<value_type> const *	const_pointer;

				template < typename T	>
				Node	(T & sentinel)
					:NodeBase(sentinel, sentinel, sentinel, black_node)
					,value()
				{
	#ifdef __DEBUG__
	DFL_CTOR
	#endif
				}
				Node	(NodeBase_ptr & sentinel,
							 NodeBase_ptr parent,
							 value_type const value,
							 node_color const color = red_node)
					:NodeBase(parent, sentinel, sentinel, color)
					,value(value)
				{
	#ifdef __DEBUG__
	PAR_CTOR
	#endif
				}
				Node	(Node const & src)
					:NodeBase(src)
					,value(src.value)
				{
	#ifdef __DEBUG__
	CPY_CTOR
	#endif
				}
				template < typename _Value >
				Node	(Node<_Value> const & src)
					:NodeBase(src)
					,value(src.value)
				{
	#ifdef __DEBUG__
	CPY_CTOR
	#endif
				}
				~Node	(void)	{}

				value_type		value;
		};
#undef CLASS_NAME
	}
}

#endif


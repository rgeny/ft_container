/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/16 13:49:16 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

//# include <iostream>

namespace ft
{
	enum e_color
	{
		RED=true,
		BLACK=false
	};
#define CLASS_NAME "RBNode"
	template <typename Value>
	class RBNode
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
				:sentinel(sentinel)
				,value()
				,color(BLACK)
				,left(sentinel)
				,right(sentinel)
				,parent(sentinel)
			{
#ifdef __DEBUG__
DFL_CTOR
#endif
			}
			RBNode	(pointer & sentinel,
					 value_type const value,
					 e_color const color = RED)
				:sentinel(sentinel)
				,value(value)
				,color(color)
				,left(sentinel)
				,right(sentinel)
				,parent(sentinel)
			{
#ifdef __DEBUG__
PAR_CTOR
#endif
			}
			RBNode	(RBNode const & src)
				:sentinel(src.sentinel)
				,value(src.value)
				,color(src.color)
				,left(src.left)
				,right(src.right)
				,parent(src.parent)
			{
#ifdef __DEBUG__
CPY_CTOR
#endif
			}
			~RBNode	(void)
			{
#ifdef __DEBUG__
DTOR
#endif
			}

			RBNode &	operator=	(value_type const & value)
			{
				this->value = value;
				return (*this);
			}

			bool	operator==	(value_type val)
			{	return (value == val);	}
			bool	operator<	(value_type val)
			{	return (value < val);	}

//		private:
			pointer &		sentinel;
			value_type		value;
			e_color			color;
			pointer			left;
			pointer			right;
			pointer			parent;
	};
#undef CLASS_NAME
}

#endif


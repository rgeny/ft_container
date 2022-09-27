/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 10:45:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

//# include <iostream>

namespace ft
{
	enum node_color
	{
		RED=true,
		BLACK=false
	};

#define CLASS_NAME "RBNodeBase"
	class RBNodeBase
	{
		public:
			typedef RBNodeBase *		NodeBase_ptr;

			NodeBase_ptr	parent;
			NodeBase_ptr	left;
			NodeBase_ptr	right;
			node_color		color;

			RBNodeBase	(NodeBase_ptr parent,
						 NodeBase_ptr left,
						 NodeBase_ptr right,
						 node_color color)
				:parent(parent)
				,left(left)
				,right(right)
				,color(color)
			{
#ifdef __DEBUG__
PAR_CTOR
#endif
			}

			~RBNodeBase	(void)
			{
#ifdef __DEBUG__
DTOR
#endif
			}

			NodeBase_ptr	min	(void)
			{
				NodeBase_ptr	node = this;
				while (! node->left->is_sentinel() )
					node = node->left;
				return (node);
			}

			NodeBase_ptr	max	(void)
			{
				NodeBase_ptr	node = this;
				while ( ! node->right->is_sentinel() )
					node = node->right;
				return (node);
			}

			NodeBase_ptr	previous	(void)
			{
				NodeBase_ptr	node = this;

				if ( ! node->left->is_sentinel() )
					return (node->left->max());

				NodeBase_ptr	parent = node->parent;
				while ( ! parent->is_sentinel() &&
						parent->left == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			NodeBase_ptr	next	(void)
			{
				NodeBase_ptr	node = this;

				if ( ! node->right->is_sentinel() )
					return (node->right->min());

				NodeBase_ptr	parent = node->parent;
				while ( ! parent->is_sentinel() &&
						parent->right == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			bool	is_sentinel	(void)
			{
				return (this == this->parent);
			}

	};
#undef CLASS_NAME
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
				:value()
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
					 pointer & parent,
					 value_type const value,
					 node_color const color = RED)
				:value(value)
				,color(color)
				,left(sentinel)
				,right(sentinel)
				,parent(parent)
			{
#ifdef __DEBUG__
PAR_CTOR
#endif
			}
			RBNode	(RBNode const & src)
				:value(src.value)
				,color(src.color)
				,left(src.left)
				,right(src.right)
				,parent(src.parent)
			{
#ifdef __DEBUG__
CPY_CTOR
#endif
			}
			template < typename _T >
			RBNode	(RBNode<_T> const & src)
				:value(src.value)
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
			value_type		value;
			node_color		color;
			pointer			left;
			pointer			right;
			pointer			parent;
	};
#undef CLASS_NAME
}

#endif


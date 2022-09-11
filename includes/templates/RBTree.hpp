/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/10 22:33:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

//# include "RBNode.hpp"



namespace ft
{
	template
	<
		typename Value
	>
	class RBNode
	{
		public:
			typedef true			RED;
			typedef false			BLACK;
			typedef Value			value_type;
			typedef RBNode const *	const_node

			RBNode	(void)
				:_value()
				,_color(BLACK)
				,_left(NULL)
				,_right(NULL)
				,_parent(NULL)
			{	}
			RBNode	(value_type const value,
					 const_node left,
					 const_node right,
					 const_node parent,
					 bool const color = RED)
				:_value(value)
				,_color(color)
				,_left(left)
				,_right(right)
				,_parent(parent)
			{	}
			RBNode	(RBNode const & src
				:_value(src._value)
				,_color(src._color)
				,_left(src._left)
				,_right(src._right)
				,_parent(src._parent)
			{	}
			~RBNode	(void)
			{	}

			RBNode &	operator=	(RBNode const & src)
			{
				_value = src._value;
				_color = src._color;
				_left = src._left;
				_right = src._right;
				_parent = src._parent;
				return (*this);
			}

			bool	is_red		(void) const
			{	return (this->_color);	}
			bool	is_black	(void) const
			{	return ( ! (this->_color) );	}

		private:
			value_type	_value;
			bool		_color;
			RBNode *	_left;
			RBNode *	_right;
			RBNode *	_parent;
	};

	template
	<
		typename Value
	>
	class RBTree
	{
		public:
			typedef Value	value_type;

			RBTree	(void)
				:_head()
				,_sentinel()
			{	}

			RBTree	(RBTree const & src)
				:_head(src.head)
				,_sentinel()
			{	}
			~RBTree	(void)
			{	}

			RBTree &	operator=	(RBTree const & src)
			{
				_head = src._head;
				return (*this);
			}

		private:
			RBNode<value_type>			_head;
			RBNode<value_type> const	_sentinel
	};
}

#endif


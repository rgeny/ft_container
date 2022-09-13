/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 15:09:44 by rgeny            ###   ########.fr       */
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
				:_sentinel(sentinel)
				,_value()
				,_color(BLACK)
				,_left(_sentinel)
				,_right(_sentinel)
				,_parent(_sentinel)
			{
#ifdef __DEBUG__
DFL_CTOR
#endif
			}
			RBNode	(const_pointer & sentinel,
					 value_type const value,
					 e_color const color = RED)
				:_sentinel(sentinel)
				,_value(value)
				,_color(color)
				,_left(_sentinel)
				,_right(_sentinel)
				,_parent(_sentinel)
			{
#ifdef __DEBUG__
PAR_CTOR
#endif
			}
			RBNode	(RBNode const & src)
				:_sentinel(src._sentinel)
				,_value(src._value)
				,_color(src._color)
				,_left(src._left)
				,_right(src._right)
				,_parent(src._parent)
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

//			RBNode &	operator=	(RBNode const & src)
//			{
//				_value = src._value;
//				_color = src._color;
//				_left = src._left;
//				_right = src._right;
//				_parent = src._parent;
//				return (*this);
//			}
			RBNode &	operator=	(value_type const & value)
			{
				_value = value;
				return (*this);
			}

			bool	is_red		(void) const
			{	return (this->_color);	}
			bool	is_black	(void) const
			{	return ( ! (this->_color) );	}

			pointer	getGrandParent	(void) const
			{
				if (this->_parent == _sentinel)
					return (this->_parent);
				return (this->_parent->_parent);
			}
			pointer	getParent	(void) const
			{
				return (this->_parent);
			}
			pointer	getUncle	(void) const
			{
				pointer	GrandParent	= this->getGrandParent();

				if (GrandParent == _sentinel)
					return (GrandParent);
				if (GrandParent->_left == this->_parent)
					return (GrandParent->_right);
				return (GrandParent->_left);
			}
			pointer	getBrother	(void) const
			{
				if (this->_parent == _sentinel)
					return (this->_parent);
				if (this->_parent->_left == this)
					return (this->_parent->_right);
				return (this->_parent->_left);
			}
			pointer &	getLeft	(void)
			{
				return (this->_left);
			}
			pointer &	getRight	(void)
			{
				return (this->_right);
			}

			bool	operator==	(value_type val)
			{	return (_value == val);	}
			bool	operator<	(value_type val)
			{	return (_value < val);	}

		private:
			pointer &		_sentinel;
			value_type		_value;
			e_color			_color;
			pointer			_left;
			pointer			_right;
			pointer			_parent;
	};
#undef CLASS_NAME
}

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 13:25:48 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

# include "print.hpp"
# include "type_traits.hpp"

//# include "RBNode.hpp"



namespace ft
{
	enum e_color
	{
		RED=true,
		BLACK=false
	};

#define CLASS_NAME "RBNode"
	template
	<
		typename Value
	>
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
				,_left(NULL)
				,_right(NULL)
				,_parent(NULL)
			{
#ifdef __DEBUG__
DFL_CTOR
#endif
			}
			RBNode	(const_pointer & sentinel,
					 value_type const value,
					 const_pointer left,
					 const_pointer right,
					 const_pointer parent,
					 e_color const color = RED)
				:_sentinel(sentinel)
				,_value(value)
				,_color(color)
				,_left(left)
				,_right(right)
				,_parent(parent)
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
			pointer	getLeft	(void) const
			{
				return (this->_left);
			}
			pointer	getRight	(void) const
			{
				return (this->_right);
			}

		private:
			pointer &		_sentinel;
			value_type		_value;
			e_color			_color;
			pointer			_left;
			pointer			_right;
			pointer			_parent;
	};
#undef CLASS_NAME
#define CLASS_NAME "RBTree"
	template
	<
		typename Value,
		typename Allocator = std::allocator<RBNode<Value> >
	>
	class RBTree
	{
		public:
			typedef Value				value_type;
			typedef	RBNode<value_type>	node_type;
			typedef Allocator			allocator_type;

			RBTree	(allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(NULL)
				,_head(NULL)
			{
				RBNode<value_type>	tmp(_sentinel);
				_sentinel = _alloc.allocate(1, &tmp);
				_alloc.construct(_sentinel, _sentinel);
			}

			RBTree	(__attribute__ ((unused)) RBTree const & src,
					 allocator_type const & alloc = allocator_type())
				:_alloc(alloc)
				,_sentinel(NULL)
				,_head(NULL)
			{
				_sentinel = _alloc.allocate(1, _sentinel);
				_alloc.construct(_sentinel);
				if (src._head != NULL)
					_head = _alloc.allocate(1, *src._head);
			}
			~RBTree	(void)
			{
				_delete_all();
				_alloc.destroy(_sentinel);
				_alloc.deallocate(_sentinel, 1);
			}

			RBTree &	operator=	(__attribute__ ((unused)) RBTree const & src)
			{
				_delete_all();
				_head = new RBTree<value_type>(*src._head);
				return (*this);
			}

//			std::pair<iterator, bool> insert( const value_type& value )
//			{
//				node_type *	new_node;
//			}

//			iterator insert( iterator hint, const value_type& value );


		private:
			allocator_type			_alloc;
			RBNode<value_type> *	_sentinel;
			RBNode<value_type> *	_head;

			void	_delete_all	(void)
			{
				if (_head != NULL)
				{
					_alloc.destroy(_head);
					_alloc.deallocate(_head, 1);
					_head = NULL;
				}
			}
	};
#undef CLASS_NAME
}

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 11:39:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

//# include "RBNode.hpp"



namespace ft
{
	enum e_color
	{
		RED=true,
		BLACK=false
	};

	template
	<
		typename Value
	>
	class RBNode
	{
		public:
			typedef Value			value_type;
			typedef RBNode *		pointer;
			typedef RBNode const *	const_pointer;

			RBNode	(const_pointer & sentinel)
				:_sentinel(sentinel)
				,_value()
				,_color(BLACK)
				,_left(NULL)
				,_right(NULL)
				,_parent(NULL)
			{	}
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
			{	}
			RBNode	(RBNode const & src)
				:_sentinel(src._sentinel)
				,_value(src._value)
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
			const_pointer &	_sentinel;
			value_type		_value;
			e_color			_color;
			pointer			_left;
			pointer			_right;
			pointer			_parent;
	};

	template
	<
		typename Value
	>
	class RBTree
	{
		public:
			typedef Value				value_type;
			typedef	RBNode<value_type>	node_type;

			RBTree	(void)
				:_sentinel(new RBNode<value_type>(_sentinel))
				,_head(NULL)
			{	}

			RBTree	(__attribute__ ((unused)) RBTree const & src)
				:_sentinel(new RBNode<value_type>(_sentinel))
				,_head(NULL)
			{	}
			~RBTree	(void)
			{
				_delete_all();
				delete _sentinel;
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
			RBNode<value_type> const *	_sentinel;
			RBNode<value_type> *		_head;

			void	_delete_all	(void)
			{
				if (_head != NULL)
				{
					delete (_head);
					_head = NULL;
				}
			}
	};
}

#endif


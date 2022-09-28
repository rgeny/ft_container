/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:38:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/27 19:01:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ITERATOR_HPP
#  define RBTREE_ITERATOR_HPP

#  define CLASS_NAME "RBTree_iterator"
template
<
	typename T,
	typename Node = RBNodeBase
>
class RBTree_iterator
{
	private:
		typedef RBTree_iterator<T>					_self;

	public:
		typedef T									iterator_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef value_type *						pointer;
		typedef value_type &						reference;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef Node								node_type;
		typedef node_type *							node_pointer;

# include "RBTree_iterator/structor.hpp"

//		friend bool operator==	(_self const & lhs,
//								 _self const & rhs)
//		{	return (lhs._current == rhs._current);	}
//		friend bool operator!=	(_self const & lhs,
//								 _self const & rhs)
//		{	return ( ! (lhs == rhs) );	}

		_self	operator=	(_self const & src)
		{
			_current = src._current;
			return (*this);
		}

		template
		<
			typename _T,
			typename _Node
		>
		_self	operator=	(RBTree_iterator<_T, _Node> const & src)
		{
			_current = src.base();
			return (*this);
		}

		node_pointer	base	(void) const
		{	return (_current);	}

	private:
		node_pointer	_current;
};
#  include "RBTree_iterator/comparison_operator.hpp"
#  undef CLASS_NAME

# endif
#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:38:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/23 17:52:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ITERATOR_HPP
#  define RBTREE_ITERATOR_HPP

#  define CLASS_NAME "RBTree_iterator"
template < typename T >
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
		typedef RBNode<value_type>					node_type;
		typedef RBNode<value_type> *				node_pointer;

# include "RBTree_iterator/structor.hpp"


		node_pointer	base	(void) const
		{	return (_current);	}

	private:
		node_pointer	_current;
};
#  include "RBTree_iterator/comparison_operator.hpp"
#  undef CLASS_NAME

# endif
#endif


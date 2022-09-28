/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_operator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:51:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:48:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_ITERATOR_HPP
#ifndef RBTREE_ITERATOR_COMPARISON_OPERATOR_HPP
# define RBTREE_ITERATOR_COMPARISON_OPERATOR_HPP

template
<
	typename _T_left,
	typename _T_right,
	typename _Node_left,
	typename _Node_right
>
bool	operator==	(Tree_iterator<_T_left, _Node_left> const & lhs,
					 Tree_iterator<_T_right, _Node_right> const & rhs)
{	return (lhs.base() == rhs.base());	}

template
<
	typename _T
>
bool	operator==	(Tree_iterator<_T> const & lhs,
					 Tree_iterator<_T> const & rhs)
{	return (lhs.base() == rhs.base());	}


template
<
	typename _T_left,
	typename _T_right,
	typename _Node_left,
	typename _Node_right
>
bool	operator!=	(Tree_iterator<_T_left, _Node_left> const & lhs,
					 Tree_iterator<_T_right, _Node_right> const & rhs)
{	return ( ! (lhs == rhs) );	}

template
<
	typename _T
>
bool	operator!=	(Tree_iterator<_T> const & lhs,
					 Tree_iterator<_T> const & rhs)
{	return ( ! (lhs == rhs) );	}

# endif
#endif


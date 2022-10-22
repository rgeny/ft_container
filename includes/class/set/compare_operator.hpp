/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_operator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:10:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/22 14:12:16 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SET_HPP
# ifndef SET_COMPARE_OPERATOR_HPP
#  define SET_COMPARE_OPERATOR_HPP

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator==	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return (lhs._rbtree == rhs._rbtree);	}

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator!=	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return ( ! (lhs == rhs) );	}

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator<	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return (lhs._rbtree < rhs._rbtree);	}

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator>	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return ( rhs < lhs );	}

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator<=	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return ( ! (rhs < lhs ) );	}

template
<
	class _Key,
	class _Compare,
	class _Alloc
>
bool	operator>=	(ft::set<_Key, _Compare, _Alloc> const & lhs,
					 ft::set<_Key, _Compare, _Alloc> const & rhs )
{	return ( ! (lhs < rhs) );	}

# endif
#endif


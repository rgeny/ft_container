/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_operator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:04:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:16:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MAP_HPP
# ifndef MAP_COMPARE_OPERATOR_HPP
#  define MAP_COMPARE_OPERATOR_HPP

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator==	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return (lhs._rbtree == rhs._rbtree);	}

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator!=	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return ( ! (lhs == rhs) );	}

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator<	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return (lhs._rbtree < rhs._rbtree);	}

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator>	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return ( rhs < lhs );	}

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator<=	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return ( ! (rhs < lhs ) );	}

template
<
	class _Key,
	class _T,
	class _Compare,
	class _Alloc
>
bool	operator>=	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
					 ft::map<_Key, _T, _Compare, _Alloc> const & rhs )
{	return ( ! (lhs < rhs) );	}

# endif
#endif


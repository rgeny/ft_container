/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 17:52:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATORS_HPP
# ifndef ITERATORS_TRAITS_HPP
#  define ITERATORS_TRAITS_HPP

#  include <iostream>

template <class Iterator>
class iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T>
class iterator_traits <T *>
{
	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
	typedef T *											pointer;
	typedef T &											reference;
	typedef typename std::random_access_iterator_tag	iterator_category;
};


template <class T>
class iterator_traits <T const *>
{
	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
	typedef T const *									pointer;
	typedef T const &									reference;
	typedef typename std::random_access_iterator_tag	iterator_category;
};

# endif
#endif


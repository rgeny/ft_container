/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 15:00:25 by rgeny            ###   ########.fr       */
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
	typedef typename ptrdiff_t					difference_type;
	typedef typename T							value_type;
	typedef typename T *						pointer;
	typedef typename T &						reference;
	typedef typename random_access_iterator_tag	iterator_category;
};


template <class T>
class iterator_traits <T const *>
{
	typedef typename ptrdiff_t					difference_type;
	typedef typename T							value_type;
	typedef typename T const *					pointer;
	typedef typename T const &					reference;
	typedef typename random_access_iterator_tag	iterator_category;
};

# endif
#endif


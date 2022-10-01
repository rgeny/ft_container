/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 14:53:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef ITERATOR_TRAITS_HPP
#  define ITERATOR_TRAITS_HPP

template
<
	typename Iterator
>
class iterator_traits
{
	public:
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
};

template
<
	typename T
>
class iterator_traits <T *>
{
	public:
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef T *											pointer;
		typedef T &											reference;
};


template
<
	typename T
>
class iterator_traits <T const *>
{
	public:
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef T const *									pointer;
		typedef T const &									reference;
};

# endif
#endif


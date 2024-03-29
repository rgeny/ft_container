/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:08:42 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 18:54:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef REVERSE_ITERATOR_HPP
#  define REVERSE_ITERATOR_HPP

#  define CLASS_NAME "reverse_iterator"

template < typename Iterator >
class reverse_iterator
	:public ft::iterator<
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference >
{
	protected:
		Iterator	current;

		typedef ft::iterator_traits<Iterator>	__traits_type;

	public:
		typedef Iterator									iterator_type;
		typedef typename __traits_type::difference_type		difference_type;
		typedef typename __traits_type::pointer				pointer;
		typedef typename __traits_type::reference			reference;

		reverse_iterator	(void)
			:current()
		{
#  ifdef __DEBUG__
DFL_CTOR
#  endif
		}

		explicit reverse_iterator	(iterator_type	src)
			:current(src)
		{
#  ifdef __DEBUG__
PAR_CTOR
#  endif
		}

		reverse_iterator	(reverse_iterator const & src)
			:current(src.base())
		{
#  ifdef __DEBUG__
CPY_CTOR
#  endif
		}

		template < typename Iter >
		reverse_iterator	(reverse_iterator<Iter> const & src)
			:current(src.base())
		{
#ifdef __DEBUG__
std::cout	<< CLASS_NAME " const cpy constructor."
			<< std::endl;
#endif
		}

#  include "reverse_iterator/member_move_operator.hpp"
#  include "reverse_iterator/assign_operator.hpp"
#  include "reverse_iterator/access_operator.hpp"

		iterator_type	base	(void) const
		{	return (this->current);	}
};

#  include "reverse_iterator/compares_operator.hpp"
#  include "reverse_iterator/non_member_move_operator.hpp"

#  undef CLASS_NAME

# endif
#endif

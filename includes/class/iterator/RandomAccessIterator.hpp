/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:20:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 18:48:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_HPP
#  define RANDOMACCESSITERATOR_HPP

#  define CLASS_NAME "RandomAccessIterator"
#  include "print.hpp"

template
<
	typename Iterator,
	typename Container
>
class RandomAccessIterator
	:public ft::iterator<std::random_access_iterator_tag, Iterator>
{
	protected:
		Iterator	_M_current;

		typedef ft::iterator_traits<Iterator>			__traits_type;

	public:
		typedef Iterator									iterator_type;
		typedef typename __traits_type::iterator_category	iterator_category;
		typedef typename __traits_type::value_type			value_type;
		typedef typename __traits_type::difference_type		difference_type;
		typedef typename __traits_type::pointer				pointer;
		typedef typename __traits_type::reference			reference;


		RandomAccessIterator	(void)
			:_M_current(Iterator())
		{
#  ifdef __DEBUG__
DFL_CTOR
#  endif
		}

		RandomAccessIterator	(Iterator const & it)
			:_M_current(it)
		{
#  ifdef __DEBUG__
PAR_CTOR
#  endif
		}

		template < typename Iter >
		RandomAccessIterator (RandomAccessIterator
								<Iter,
								 typename ft::enable_if
								 	<(ft::is_same
										<Iter,
										 typename Container::pointer
										>::value),
									Container>::type
								> const & it)
			:_M_current(it.base())
		{	}

		~RandomAccessIterator	(void)
		{
#  ifdef __DEBUG__
DTOR
#  endif
		}

		Iterator const &	base	(void) const
		{	return (_M_current);	}

#  include "RandomAccessIterator/modifiers_operator.hpp"
#  include "RandomAccessIterator/member_operation_operator.hpp"
#  include "RandomAccessIterator/access_operator.hpp"
};
#  include "RandomAccessIterator/comparison_operator.hpp"
#  include "RandomAccessIterator/non_member_operation_operator.hpp"

#  undef CLASS_NAME
# endif
#endif

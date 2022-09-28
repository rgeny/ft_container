/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:20:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/22 16:43:53 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_HPP
#  define RANDOMACCESSITERATOR_HPP

#  define CLASS_NAME "RandomAccessIterator"

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
		typedef typename __traits_type::difference_type		difference_type;
		typedef typename __traits_type::value_type			value_type;
		typedef typename __traits_type::pointer				pointer;
		typedef typename __traits_type::reference			reference;
		typedef typename __traits_type::iterator_category	iterator_category;

#  include "RandomAccessIterator/structor.hpp"
#  include "RandomAccessIterator/modifiers_operator.hpp"
#  include "RandomAccessIterator/member_operation_operator.hpp"
#  include "RandomAccessIterator/member.hpp"
#  include "RandomAccessIterator/access_operator.hpp"
};
#  include "RandomAccessIterator/comparison_operator.hpp"
#  include "RandomAccessIterator/non_member_operation_operator.hpp"

#  undef CLASS_NAME
# endif
#endif

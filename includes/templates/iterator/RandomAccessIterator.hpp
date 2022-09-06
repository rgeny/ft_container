/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:20:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 17:51:28 by rgeny            ###   ########.fr       */
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

		typedef ft::iterator_traits<Iterator>			traits_type;

	public:
		#include "RandomAccessIterator/typedef.hpp"
		#include "RandomAccessIterator/structor.hpp"
		#include "RandomAccessIterator/modifiers_operator.hpp"
		#include "RandomAccessIterator/member_operation_operator.hpp"
		#include "RandomAccessIterator/member.hpp"
		#include "RandomAccessIterator/access_operator.hpp"
};
#include "RandomAccessIterator/comparison_operator.hpp"
#include "RandomAccessIterator/non_member_operation_operator.hpp"

#  undef CLASS_NAME
# endif
#endif

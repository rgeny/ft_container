/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:08:42 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/22 16:56:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef REVERSE_ITERATOR_HPP
#  define REVERSE_ITERATOR_HPP

template
<
	typename Iterator
>
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

#  include "reverse_iterator/structor.hpp"
#  include "reverse_iterator/member_move_operator.hpp"
#  include "reverse_iterator/assign_operator.hpp"
#  include "reverse_iterator/access_operator.hpp"

		iterator_type	base	(void) const
		{	return (this->current);	}
};

#  include "reverse_iterator/compares_operator.hpp"
#  include "reverse_iterator/non_member_move_operator.hpp"

# endif
#endif

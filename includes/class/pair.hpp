/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:50:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 15:09:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	class pair
	{
		public:
			typedef FIRST_TYPE	first_type;
			typedef SECOND_TYPE	second_type;
			
			first_type	first;
			second_type	second;

			pair	(void)
				:first()
				,second()
			{	}
			pair	(first_type const & _first,
					 second_type const & _second)
				:first(_first)
				,second(_second)
			{	}
			template
			<
				typename _FIRST_TYPE,
				typename _SECOND_TYPE
			>
			pair	(pair<_FIRST_TYPE, _SECOND_TYPE> const & src)
				:first(src.first)
				,second(src.second)
			{	}
			~pair	(void)
			{	}

			pair &	operator=	(pair const & other)
			{
				this->first = other.first;
				this->second = other.second;
				return (*this);
			}

	};
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	ft::pair<FIRST_TYPE, SECOND_TYPE>
		make_pair	(FIRST_TYPE first,
					 SECOND_TYPE second)
	{
		return (ft::pair<FIRST_TYPE, SECOND_TYPE>(first, second));
	}



	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator==	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{
		return (lhs.first == rhs.first &&
				lhs.second == rhs.second);
	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator<	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{
		return ( lhs.first < rhs.first ||
				 ( ! (rhs.first < lhs.first) &&
				 	  lhs.second < rhs.second));
	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator!=	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{	return ( ! (lhs == rhs) );	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator>	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{	return ( rhs < lhs );	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator<=	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{	return ( ! (rhs < lhs) );	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	bool	operator>=	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & lhs,
						 ft::pair<FIRST_TYPE, SECOND_TYPE> const & rhs)
	{	return ( ! (rhs > lhs) );	}
}

#endif


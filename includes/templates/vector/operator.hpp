/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:22:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/03 14:19:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_OPERATOR_HPP
#  define VECTOR_OPERATOR_HPP

friend bool	operator==	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	ft::vector<value_type, allocator_type>::const_iterator	lhs_it  = lhs.begin(),
															lhs_ite = lhs.end(),
															rhs_it  = rhs.begin(),
															rhs_ite = rhs.end();
#ifdef __DEBUG__
	std::cout	<< "lhs.begin() == "
				<< &(*lhs.begin())
				<< std::endl

				<< "lhs.end() == "
				<< &(*lhs.end())
				<< std::endl

				<< "rhs.begin() == "
				<< &(*rhs.begin())
				<< std::endl

				<< "rhs.end() == "
				<< &(*rhs.end())
				<< std::endl;
#endif
	return ( ! ft::lexicographical_compare	(lhs_it,
											 lhs_ite,
											 rhs_it,
											 rhs_ite) &&
			 ! ft::lexicographical_compare	(rhs_it,
			 								 rhs_ite,
											 lhs_it,
											 lhs_ite));
}

friend bool	operator!=	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	return ( ! (lhs == rhs) );
}

friend bool	operator<	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	return (ft::lexicographical_compare	(lhs.begin(),
										 lhs.end(),
										 rhs.begin(),
										 rhs.end()));
}

friend bool	operator<=	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	return (lhs < rhs ||
			lhs == rhs);
}

friend bool	operator>	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	return ( ! (lhs <= rhs) );
}

friend bool	operator>=	(ft::vector<value_type, allocator_type> const & lhs,
						 ft::vector<value_type, allocator_type> const & rhs)
{
	return ( ! (lhs < rhs) );
}

# endif
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compares_operator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:04:18 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 22:04:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef COMPARES_OPERATOR_HPP
#  define COMPARES_OPERATOR_HPP

public:
	friend bool	operator==	(Tree const & lhs,
							 Tree const & rhs)
	{
		return	(lhs.size() == rhs.size() &&
				 ft::equal (lhs.begin(),
							lhs.end(),
							rhs.begin()));
	}
	friend bool	operator<	(Tree const & lhs,
							 Tree const & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(),
											lhs.end(),
											rhs.begin(),
											rhs.end()));
	}

# endif
#endif


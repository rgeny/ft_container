/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_operator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:00:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 14:31:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef ACCESS_OPERATOR_HPP
#  define ACCESS_OPERATOR_HPP

reference	operator*	(void) const
{	return (*_M_current);	}

pointer	operator->	(void) const
{	return (_M_current);	}

reference	operator[]	(difference_type n) const
{	return (_M_current[n]);	}

# endif
#endif


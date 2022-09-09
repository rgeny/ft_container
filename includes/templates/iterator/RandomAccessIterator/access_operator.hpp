/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_operator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:00:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:59:17 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_ACCESS_OPERATOR_HPP
#  define RANDOMACCESSITERATOR_ACCESS_OPERATOR_HPP

reference	operator*	(void) const
{	return (*_M_current);	}

pointer	operator->	(void) const
{	return (_M_current);	}

reference	operator[]	(difference_type n) const
{	return (_M_current[n]);	}

# endif
#endif


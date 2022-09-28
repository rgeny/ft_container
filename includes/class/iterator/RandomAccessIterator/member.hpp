/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:56:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 11:00:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_MEMBER_HPP
#  define RANDOMACCESSITERATOR_MEMBER_HPP

Iterator const &	base	(void) const
{	return (_M_current);	}

# endif
#endif


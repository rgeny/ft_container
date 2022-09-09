/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:52:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 11:00:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_TYPEDEF_HPP
#  define RANDOMACCESSITERATOR_TYPEDEF_HPP

typedef Iterator									iterator_type;
typedef typename __traits_type::difference_type		difference_type;
typedef typename __traits_type::value_type			value_type;
typedef typename __traits_type::pointer				pointer;
typedef typename __traits_type::reference			reference;
typedef typename __traits_type::iterator_category	iterator_category;

# endif
#endif


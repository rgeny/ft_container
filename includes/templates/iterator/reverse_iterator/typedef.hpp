/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:46:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 11:55:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_TYPEDEF_HPP
#  define REVERSE_ITERATOR_TYPEDEF_HPP

typedef Iterator									iterator_type;
typedef typename __traits_type::iterator_category	iterator_category;
typedef typename __traits_type::value_type			value_type;
typedef typename __traits_type::difference_type		difference_type;
typedef typename __traits_type::pointer				pointer;
typedef typename __traits_type::reference			reference;

# endif
#endif


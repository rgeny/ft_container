/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:52:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 13:53:53 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef TYPEDEF_HPP
#  define TYPEDEF_HPP

typedef Iterator								iterator_type;
typedef typename traits_type::difference_type	difference_type;
typedef typename traits_type::value_type		value_type;
typedef typename traits_type::pointer			pointer;
typedef typename traits_type::reference			reference;
typedef typename traits_type::iterator_category	iterator_category;

# endif
#endif


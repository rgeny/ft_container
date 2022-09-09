/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:46:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:44:04 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_TYPEDEF_HPP
#  define REVERSE_ITERATOR_TYPEDEF_HPP

typedef Iterator														iterator_type;
typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
typedef typename ft::iterator_traits<iterator_type>::reference			reference;

# endif
#endif


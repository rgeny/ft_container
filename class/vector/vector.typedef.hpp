/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.typedef.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:16:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 20:08:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_TYPEDEF_HPP
#  define VECTOR_TYPEDEF_HPP

typedef T											value_type;
typedef Allocator									allocator_type;
typedef std::size_t									size_type;
typedef std::ptrdiff_t								difference_type;
typedef value_type &								reference;
typedef value_type const &							const_reference;
typedef typename allocator_type::pointer			pointer;
typedef typename allocator_type::const_pointer		const_pointer;
typedef typename ft::vector<T>::MyIterator			iterator;
typedef typename std::vector<T>::const_iterator		const_iterator;
//typedef std::reverse_iterator<iterator>				reverse_iterator;
//typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

# endif
#endif

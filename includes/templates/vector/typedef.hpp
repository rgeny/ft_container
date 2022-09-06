/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:16:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 22:31:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_TYPEDEF_HPP
#  define VECTOR_TYPEDEF_HPP

typedef T													value_type;
typedef Allocator											allocator_type;
typedef std::size_t											size_type;
typedef std::ptrdiff_t										difference_type;
typedef value_type &										reference;
typedef value_type const &									const_reference;
typedef typename allocator_type::pointer					pointer;
typedef typename allocator_type::const_pointer				const_pointer;
//typedef	pointer												iterator;
//typedef const_pointer										const_iterator;
typedef ft::RandomAccessIterator<pointer, vector>			iterator;
typedef ft::RandomAccessIterator<const_pointer, vector>		const_iterator;
typedef ft::reverse_iterator<iterator>						reverse_iterator;
typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
//typedef typename std::vector<value_type>::iterator			iterator;
//typedef typename std::vector<value_type>::const_iterator	const_iterator;
//typedef typename std::vector<value_type>::reverse_iterator	reverse_iterator;
//typedef typename std::vector<value_type>::const_reverse_iterator	const_reverse_iterator;

# endif
#endif

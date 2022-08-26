/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_typedef.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:02:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 16:08:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STACK_HPP
# ifndef STACK_TYPEDEF_HPP
#  define STACK_TYPEDEF_HPP

typedef Container								container_type;
typedef typename Container::value_type			value_type;
typedef typename Container::size_type			size_type;
typedef typename Container::reference			reference;
typedef typename Container::const_reference		const_reference;

# endif
#endif


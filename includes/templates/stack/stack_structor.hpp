/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_structor.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:27:35 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 16:39:54 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STACK_HPP
# ifndef STACK_STRUCTOR_HPP
#  define STACK_STRUCTOR_HPP

explicit	stack	(container_type const & cont = container_type())
	:c(cont)
{
#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "stack default constructor."
				<< std::endl;
#endif
}

# endif
#endif


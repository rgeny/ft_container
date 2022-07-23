/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:58:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/07/17 21:02:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# define ERROR_NULL_ARGUMENT "Error: a pointer type argument is NULL."

# include <iostream>

class error_null_argument
	:public std::exception
{
	public:
		virtual char const *	what(void) const throw();
};

#endif


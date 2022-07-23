/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:42:34 by rgeny             #+#    #+#             */
/*   Updated: 2022/07/18 11:00:50 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	tester::print_data	(void) const
{
	std::cout	<< std::endl
				<< "argc = "
				<< this->_argc
				<< std::endl
				<< std::endl

				<< "argv : "
				<< std::endl;

	for (size_t i = 0;
		i < this->_argc;
		i++)
	{
		std::cout	<< "argv["
					<< i
					<< "] = "
					<< this->_argv[i]
					<< std::endl;
	}

	std::cout	<< "\nenvp : "
				<< ((this->_envp.size() == 0) ? "NULL\n": "NOT NULL\n");

	std::cout	<< "\npath : "
				<< this->_path
				<< std::endl;
}

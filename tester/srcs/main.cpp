/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:14:45 by rgeny             #+#    #+#             */
/*   Updated: 2022/07/18 11:08:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "tester.hpp"

int	main	(__attribute__((unused)) int argc
			,__attribute__((unused)) char ** argv
			,__attribute__((unused)) char ** envp)
{
	try
	{
		tester	t(argv, argc, envp);

		t.print_data();
	}
	catch (std::exception const & err)
	{
		std::cout	<< err.what()
					<< std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

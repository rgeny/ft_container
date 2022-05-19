/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:54:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 19:25:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 17
#define VAL 4

int	main	(void)
{
	NAMESPACE::vector<int>	v(SIZE);

	init_vector(v, SIZE, VAL);

	std::cout	<< "copy constructor"
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it1 = v.begin(),
											it2 = v.end(),
											it3(it1),
											it4(it2);

		std::cout	<< *it1
					<< std::endl
					<< *it2
					<< std::endl
					<< *it3
					<< std::endl
					<< *it4
					<< std::endl;
	}
	std::cout	<< "pointer constructor"
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it1 = v.begin(),
											it2 = v.end(),
											it3(&(*it1)),
											it4(&(*it2));

		std::cout	<< *it1
					<< std::endl
					<< *it2
					<< std::endl
					<< *it3
					<< std::endl
					<< *it4
					<< std::endl;
	}
	std::cout	<< "Default constructor"
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it;

		std::cout	<< *it
					<< std::endl;
	}


	return (0);
}

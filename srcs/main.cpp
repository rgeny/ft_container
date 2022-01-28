/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:58:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/01/28 17:44:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>

int	main(void)
{
/*	ft::vector<std::string>	a;
	ft::vector<std::string>	b(4, "abc");

	ft::vector<std::string>::iterator	i = b.begin();
	std::cout << *i << std::endl;*/
	std::vector<std::string>	b(4, "abc");

	std::vector<std::string>::iterator	c = b.begin();

	/*std::vector<std::string>	b;

	std::cout << b.capacity() << std::endl;

	b.push_back("abc");
	if (b.begin() == b.end())
		std::cout << "abc" << std::endl;
	else if (b.begin() + 1 == b.end())
		std::cout << "def" << std::endl;
	std::vector<std::string>::iterator	i = b.end();
	std::vector<std::string>::reverse_iterator	j = b.rend();
	
	std::cout << std::endl << b.max_size() << std::endl;
	std::cout << b.capacity() << std::endl;
	b.push_back("def");
	std::cout << b.capacity() << std::endl;
	b.push_back("def");
	std::cout << b.capacity() << std::endl;
	for (int i = 0; i < 1000; i++)
		b.push_back("ghi");
	std::cout << b.capacity() << std::endl;
	b.reserve(2000);
	std::cout << b.capacity() << std::endl;*/
	return (0);
}


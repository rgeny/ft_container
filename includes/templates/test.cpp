/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:26:35 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/20 20:28:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include "pair.hpp"

int	main	(void)
{
	std::pair<int, int>	p(10, 5);
	std::pair<int const, int>	t(10, 5);

	std::cout	<< std::boolalpha
				<< (p == t)
				<< std::endl;
}

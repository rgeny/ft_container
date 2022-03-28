/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:01:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/28 12:42:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE
# define NAMESPACE ft
# define NAME "ft"
#else
# define NAME "std"
#endif
#include <vector>
#include <vector.hpp>

int	main	(void)
{
	std::vector<int>	test(10, 20);
//	PRINT(NAME)
	std::cout << test.size() << std::endl;

	return (0);
}

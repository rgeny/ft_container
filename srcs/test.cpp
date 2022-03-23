/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:08:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/23 18:18:39 by rgeny            ###   ########.fr       */
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
	NAMESPACE::vector<int>	test;
	PRINT(NAME)
	return (0);
}

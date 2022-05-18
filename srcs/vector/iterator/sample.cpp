/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:24:43 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 19:13:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

int	main	(void)
{
	NAMESPACE::vector<int>	t1(5, 3);

	std::for_each(t1.begin(), t1.end(), _print_val<int>);
	
	NAMESPACE::vector<int>::const_iterator	it	= t1.begin(),
											ite	= t1.end();

	std::for_each(it, ite, _print_val<int>);

	std::cout	<< std::distance(t1.begin(), t1.end())
				<< std::endl;
	return (0);
}

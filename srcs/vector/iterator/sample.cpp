/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:24:43 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 17:53:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

int	main	(void)
{
	NAMESPACE::vector<int>	t1(5, 3);

	std::for_each(t1.begin(), t1.end(), _print_val<int>);

	std::cout	<< std::distance(t1.begin(), t1.end())
				<< std::endl;
	return (0);
}

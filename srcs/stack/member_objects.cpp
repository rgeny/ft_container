/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_objects.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:02:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 16:23:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T
>
class Tmp
	:public NAMESPACE::stack<T>
{
	public:
		void	print_data	(void)
		{
			while (!this->c.empty())
			{
				std::cout	<< this->c.back()
							<< std::endl;
				this->c.pop_back();
			}
		}
};

int	main	(void)
{
	_print_nl	("underlying container is named c :");
	{
		Tmp<int>	tmp;

		for (int i = 0; i < 10; i++)
			tmp.push(i);
		tmp.print_data();
	}
}

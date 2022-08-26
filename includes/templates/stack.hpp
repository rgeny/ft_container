/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:48:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 16:25:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>
# include <stack>

namespace ft
{
	template
	<
		class T,
		class Container = std::vector<T>
	>
	class stack
	{
		public:
			#include "stack_typedef.hpp"
			
			void	push (value_type & value)
			{
				this->c.push_back(value);
			}


		protected:
			container_type	c;

		private:
	};
}

#endif


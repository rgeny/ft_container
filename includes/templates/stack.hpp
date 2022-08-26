/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:48:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 14:10:34 by rgeny            ###   ########.fr       */
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
		:public std::stack<T, Container>
	{
		public:
			#include "stack_typedef.hpp"

		protected:
//			Container

		private:
	};
}

#endif


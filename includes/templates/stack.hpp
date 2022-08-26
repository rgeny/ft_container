/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:48:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 17:40:57 by rgeny            ###   ########.fr       */
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
			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;

			explicit	stack	(container_type const & cont = container_type())
				:c(cont)
			{	}
			~stack	(void)
			{	}

			reference		top	(void)
			{	return (this->c.back());	}
			const_reference	top	(void) const
			{	return (this->c.back());	}

			bool	empty	(void) const
			{	return (this->c.empty());	}

			size_type	size	(void) const
			{	return (this->c.size());	}

			void	push	(value_type const & value)
			{	this->c.push_back(value);	}

			void	pop	(void)
			{	this->c.pop_back();	}


		protected:
			container_type	c;

		private:
	};
}

#endif


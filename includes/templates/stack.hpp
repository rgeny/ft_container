/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:48:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/02 17:51:15 by rgeny            ###   ########.fr       */
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

			ft::stack<T> &	operator=	(ft::stack<T> const & other)
			{
				this->c = other.c;
				return (*this);
			}

			friend bool	operator==	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator=="
							<< std::endl;
#endif
				return (lhs.c == rhs.c);
			}
			friend bool	operator!=	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator!="
							<< std::endl;
#endif
				return (!(lhs == rhs));
			}
			friend bool	operator<	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator<"
							<< std::endl;
#endif
				return (lhs.c < rhs.c);
			}
			friend bool	operator<=	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator<="
							<< std::endl;
#endif
				return (lhs < rhs || lhs == rhs);
			}
			friend bool	operator>	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator>"
							<< std::endl;
#endif
				return (!(lhs <= rhs));
			}
			friend bool	operator>=	(ft::stack<T, Container> const & lhs,
									 ft::stack<T, Container> const & rhs)
			{
#ifdef __DEBUG__
				std::cout	<< "ft::stack operator>="
							<< std::endl;
#endif
				return (!(lhs < rhs));
			}

		protected:
			container_type	c;

		private:
	};
}

#endif


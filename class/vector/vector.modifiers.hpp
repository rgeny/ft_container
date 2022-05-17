/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.modifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 19:08:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_MODIFIERS_HPP

template < class InputIterator >
void	assign	(InputIterator first
				,InputIterator last
				,typename std::enable_if<!std::is_integral<InputIterator>::value, bool>::type = 0)
{
	for (size_t i = 0; i < this->_capacity; i++)
		this->_alloc.destroy(this->_data + i);
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_size = std::distance(first, last);
	this->_capacity = this->_size;
	this->_data = this->_alloc.allocate(this->_size);
	for (size_t i = 0; first != last; i++, first++)
		this->_alloc.construct(this->_data + i, *first);
}
void	assign	(size_type n
				,value_type const & val)
{
	for (size_t i = 0; i < this->_size; i++)
		this->_alloc.destroy(this->_data + i);
	this->_alloc.deallocate(this->_data, this->_size);
	this->_size = n;
	this->_capacity = n;
	this->_data = this->_alloc.allocate(n);
	for (size_t i = 0; i < n; i++)
		this->_alloc.construct(this->_data + i, val);
}

void	clear	(void)
{
	for (size_t i = 0; i < this->_size; i++)
		this->_alloc.destroy(this->_data + i);
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_size = 0;
	this->_capacity = 0;
}

# endif
#endif

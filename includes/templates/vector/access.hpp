/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:26:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/03 11:39:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef ACCESS_HPP
#  define ACCESS_HPP

reference	at	(size_type pos)
{
	if (pos >= _size)
	{
		std::string	error("pos (" + 
						  ft::to_string(pos) +
						  ") >= this->size() (" +
						  ft::to_string(_size) +
						  ")");

		throw (std::out_of_range(error));
	}
	return (_data[pos]);
}

const_reference	at	(size_type pos) const
{
	if (pos >= _size)
	{
		std::string	error("pos (" + 
						  ft::to_string(pos) +
						  ") >= this->size() (" +
						  ft::to_string(_size) +
						  ")");

		throw (std::out_of_range(error));
	}
	return (_data[pos]);
}

reference	operator[]	(size_type pos)
{
	return (_data[pos]);
}

const_reference	operator[]	(size_type pos) const
{
	return (_data[pos]);
}

reference	front	(void)
{
	return (*_data);
}

const_reference	front	(void) const
{
	return (*_data);
}

reference	back	(void)
{
	return	(*this->end());
}

const_reference	back	(void) const
{
	return (*this->end());
}

pointer	data	(void)
{
	return (_data);
}

const_pointer	data	(void) const
{
	return (_data);
}

# endif
#endif


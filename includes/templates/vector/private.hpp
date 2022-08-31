/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:05:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 17:09:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef PRIVATE_HPP
#  define PRIVATE_HPP

void	_destroy	(pointer it,
					 pointer ite)
{
	while (it != ite)
	{
		_alloc.destroy(it);
		it++;
	}
}

void	_destroy_all	(void)
{
	for (pointer it = _data, ite = _data + _size;
		 it != ite;
		 it++)
	{
		_alloc.destroy(it);
	}
}

# endif
#endif


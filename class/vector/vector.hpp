/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:48:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 14:30:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include "define.hpp"

# define VECT_DFL_SIZE 0
# define VECT_NAME "vector"

//tmp
#include <vector>
//find tmp

namespace ft
{
	template
	<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type &								reference;
			typedef value_type const &							const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename std::vector<T>::iterator			iterator;
			typedef typename std::vector<T>::const_iterator		const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
//			typedef std::random_access_iterator_tag					iterator;
//			typedef random_access_iterator<const T>				const_iterator;
//			typedef iterator_traits<iterator>::difference_type	difference_type;

			explicit	vector	(const allocator_type & alloc = allocator_type())
				:_alloc(alloc)
				,_size(0)
				,_capacity(0)
				,_data(NULL)
			{
			}

			explicit	vector	(size_type n
								,const value_type & val = value_type()
								,const allocator_type & alloc = allocator_type())
				:_alloc(alloc)
				,_size(n)
				,_capacity(n)
				,_data(this->_alloc.allocate(this->_capacity))
			{
				for (size_t i = 0; i < n; i++)
					this->_data[i] = val;
			}

			size_type	size	(void)	const
			{
				return (this->_size);
			}

			size_type	max_size	(void) const
			{
				return (this->_alloc.max_size());
			}

			iterator	begin	(void)
			{
				return (iterator(this->_data));
			}

			iterator	end	(void)
			{
				return (iterator(this->_data + this->_size));
			}


		protected:

		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_data;
			
	};
}
#endif

/*
** Size du container : 1 au départ puis multiplié par deux à chaque fois que nécessaire.



** begin : return std::vector<T>::iterator sur le premier élément
** end : return  std::vector<T>::iterator sur l'adresse après le dernier élément
** rbegin : return std::vector<T>::reverse_iterator sur l'adresse du dernier élément, l'incrémenter le fait en réalité décrémenté.
** rend : return std::vector<T>::reverse_iterator sur l'adresse précédent le premier élément.

** size : return nombre d'éléments
** size_max : return nombre maximum d'éléments théorique
** resize : modifie la taille du conteneur en ajoutant ou supprimant des éléments. Si une deuxième valeur est entré remplis les ajouts supplémentaires avec cet élément.
** capacity : affiche la taille réelle actuelle du container.
** empty : return true if empty, false sinon
** reserve : alloue n mémoire si la mémoire alloué est plus petite.



Operator :
[]
=

*/

//TODO :
//	CONSTRUCTOR
//	DESTRUCTOR
//	OPERATOR=
//	ITERATOR
//	- begin
//	- end
//	- rbegin
//	- rend
//	CAPACITY
//	- size
//	- max_size
//	- resize
//	- capacity
//	- empty
//	- reserve
//	ELEMENT ACCESS
//	- []
//	- at
//	- front
//	- back
//	MODIFIERS
//	- assign
//	- push_back
//	- pop_back
//	- insert
//	- erase
//	- swap
//	- clear
//	ALLOCATOR
//	- get_allocator
//	NON MEMBER
//	- relational operators
//	- swap



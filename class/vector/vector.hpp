/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:48:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 21:19:39 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include "define.hpp"
# include "type_traits.hpp"

# define VECT_DFL_SIZE 0
# define VECT_NAME "vector"

//tmp
#include <vector>
#include <iterator>
#include <type_traits>
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
			#include "vector.typedef.hpp"
			#include "vector.structor.hpp"
			#include "vector.iterators.hpp"
			#include "vector.capacity.hpp"
			#include "vector.modifiers.hpp"

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



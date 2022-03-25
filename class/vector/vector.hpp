/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:48:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/25 10:42:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include "define.hpp"

# define VECT_DFL_SIZE 0
# define VECT_NAME "vector"



namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
//			typedef allocator_type::reference					reference;
//			typedef allocator_type::const_reference				const_reference;
//			typedef allocator_type::pointer						pointer;
//			typedef allocator_type::const_pointer				const_point;
//			typedef random_access_iterator<T>					iterator;
//			typedef random_access_iterator<const T>				const_iterator;
//			typedef iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t									size_type;

			explicit	vector	(const allocator_type &		alloc	= allocator_type())
				:_data(NULL)
				,_size(0)
				,_capacity(0)
			{
//				DFL_CTOR("Vector")
			}

			size_type	size	(void)	const
			{
				return (this->_size);
			}
//
//			explicit	vector	(size_type					n
//								,const value_type &			val		= value_type()
//								,const allocator_type &		alloc	= allocator_type())
//			{
//				FILL_CTOR("Vector")
//			}
//
//			template <class InputIterator>
//						vector	(InputIterator				first
//								,InputIterator				last
//								,const allocator_type &		alloc	= allocator_type())
//			{
//				RANGE_CTOR("Vector")
//			}
//						vector	(const vector &				x)
//			{
//				CPY_CTOR("Vector")
//			}

		protected:

		private:
			T				*_data;
			std::size_t		_size;
			std::size_t		_capacity;
			
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

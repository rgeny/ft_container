/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:48:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/01/28 17:43:05 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include "define.hpp"

# define VECT_DFL_SIZE 0
# define VECT_NAME "vector"


namespace ft
{
	template< class T>
	class vector
	{
		public:

/********************* CONSTRUCTOR **********************/
			vector	(void)
				: _size(0)
				, _tab(0)
			{	std::cout << DFL_CONSTRUCTOR(VECT_NAME) << std::endl;	}

			vector	(std::size_t n, T val)
				: _size(n)
				, _tab(new T[n])
			{
				std::cout << PARAMETER_CONSTRUCTOR(VECT_NAME) << std::endl;
				for (std::size_t i = 0; i < n; i++)
					this->_tab[i] = val;
			}

/********************* DESTRUCTOR **********************/
			~vector	(void)
			{
				std::cout << DESTRUCTOR(VECT_NAME) << std::endl;
				delete[] this->_tab;
			}

/********************* ITERATORS **********************/
			class iterator : public std::iterator<std::input_iterator_tag, T>
			{
				public:
					iterator	(void) {}

					iterator	(T *p)
						: _p(p)
					{	std::cout << DFL_CONSTRUCTOR("iterator") << std::endl;	}

					~iterator	(void) {}

					iterator &	operator++	(void)
					{	this->_p++;	return (*this);	}
					iterator &	operator++	(int)
					{	T *	p = this->_p;	this->_p++;	return p;	}
					T &			operator*	(void)
					{	return *this->_p;	}
					bool		operator==	(iterator & p)
					{	return (p == this->_p);	}
					bool		operator!=	(iterator & p)
					{	return !(p == this->_p);	}
				private:
					T	*_p;
			};
			iterator &	begin(void)
			{
				return iterator(this->_tab);
			}


		protected:

		private:
			std::size_t	_size;
			T			*_tab;
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

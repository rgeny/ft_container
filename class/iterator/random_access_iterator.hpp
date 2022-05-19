/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:20:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:06:50 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef RANDOM_ACCESS_ITERATOR_HPP
#  define RANDOM_ACCESS_ITERATOR_HPP

template <class T>
class RandomAccessIterator
	:public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;


		RandomAccessIterator	(void)
			:_ptr(NULL)
		{	}
		RandomAccessIterator	(pointer ptr)
			:_ptr(ptr)
		{	}
		RandomAccessIterator	(RandomAccessIterator const & src)
			:_ptr(src._ptr)
		{	}
		virtual ~RandomAccessIterator	(void)
		{	}

		RandomAccessIterator &	operator=	(RandomAccessIterator const & src)
		{
			if (this == &src)
				return (*this);
			this->_ptr = src._ptr;
			return (*this);
		}

		pointer	base	(void) const
		{
			return (this->_ptr);
		}

		reference operator*	(void) const
		{
			return (*this->_ptr);
		}
		pointer operator->	(void)
		{
			return (&(this->operator*()));
		}
		reference	operator[]	(difference_type n)
		{
			return (*(this->operator+(n)));
		}

		RandomAccessIterator &	operator++	(void)
		{
			++this->_ptr;
			return (*this);
		}
		RandomAccessIterator	operator++	(int)
		{
			RandomAccessIterator	tmp(*this);
			this->operator++();
			return (tmp);
		}

		RandomAccessIterator &	operator--	(void)
		{
			this->_ptr--;
			return (*this);
		}
		RandomAccessIterator	operator--	(int)
		{
			RandomAccessIterator	tmp(*this);
			this->operator--();
			return (tmp);
		}

		RandomAccessIterator	operator+	(difference_type n) const
		{
			return (this->_ptr + n);
		}
		RandomAccessIterator	operator-	(difference_type n) const
		{
			return (this->_ptr - n);
		}
		difference_type operator-	(RandomAccessIterator const & rhs) const
		{
			return (this->_ptr - rhs._ptr);
		}
		RandomAccessIterator	operator+=	(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}
		RandomAccessIterator	operator-=	(difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		bool	operator==	(RandomAccessIterator const & rhs)
		{
			return (this->base() == rhs.base());
		}

		bool	operator!=	(RandomAccessIterator const & rhs)
		{
			return (this->base() != rhs.base());
		}

		bool	operator<	(RandomAccessIterator const & rhs)
		{
			return (this->base() < rhs.base());
		}

		bool	operator>	(RandomAccessIterator const & rhs)
		{
			return (this->base() > rhs.base());
		}

		bool	operator<=	(RandomAccessIterator const & rhs)
		{
			return (this->base() <= rhs.base());
		}

		bool	operator>=	(RandomAccessIterator const & rhs)
		{
			return (this->base() >= rhs.base());
		}

		operator RandomAccessIterator<T const>	(void) const
		{
			return (RandomAccessIterator<T const>(this->_ptr));
		}

	private:
		pointer	_ptr;
};

# endif
#endif

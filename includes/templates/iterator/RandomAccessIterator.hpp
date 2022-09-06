/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:20:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 12:51:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_HPP
#  define RANDOMACCESSITERATOR_HPP

# define CLASS_NAME "RandomAccessIterator"

template
<
	typename Iterator,
	typename Container
>
class RandomAccessIterator
	:public ft::iterator<std::random_access_iterator_tag, Iterator>
{
	protected:
		Iterator	_M_current;

		typedef ft::iterator_traits<Iterator>			traits_type;

	public:
//	all categories iterator
		typedef Iterator								iterator_type;
		typedef typename traits_type::difference_type	difference_type;
		typedef typename traits_type::value_type		value_type;
		typedef typename traits_type::pointer			pointer;
		typedef typename traits_type::reference			reference;
		typedef typename traits_type::iterator_category	iterator_category;

		RandomAccessIterator	(void)
			:_M_current(Iterator())
		{		}
		RandomAccessIterator	(Iterator const & it)
			:_M_current(it)
		{		}
		template
		<
			typename Iter
		>
		RandomAccessIterator	
			(RandomAccessIterator<Iter,
			 typename ft::enable_if<
				(ft::is_same<Iter,typename Container::pointer>::value),
				Container>::type
			 > const & it)
			:_M_current(it.base())
		{		}

		~RandomAccessIterator	(void)
		{		}


		RandomAccessIterator &	operator=	(RandomAccessIterator const & src)
		{
			_M_current = src._M_current;
			return (*this);
		}
		RandomAccessIterator &	operator++	(void)
		{
			++_M_current;
			return (*this);
		}
		RandomAccessIterator 	operator++	(int)
		{
			RandomAccessIterator	tmp(*this);
			++_M_current;
			return (tmp);
		}

		Iterator const &	base(void) const
		{	return (_M_current);	}

//	Forward iterator

		reference	operator*	(void) const
		{	return (*_M_current);	}
		pointer	operator->	(void) const
		{	return (_M_current);	}

//	Bidirectional iterator
		RandomAccessIterator &	operator--	(void)
		{
			--_M_current;
			return (*this);
		}
		RandomAccessIterator 	operator--	(int)
		{
			RandomAccessIterator	tmp(*this);
			--_M_current;
			return (tmp);
		}

//	RandomAccess iterator
		RandomAccessIterator	operator+	(difference_type n) const
		{
			return (RandomAccessIterator(_M_current + n));
		}
		RandomAccessIterator &	operator+=	(difference_type n)
		{
			_M_current += n;
			return (*this);
		}
		RandomAccessIterator	operator-	(difference_type n) const
		{
			return (RandomAccessIterator(_M_current - n));
		}
		RandomAccessIterator &	operator-=	(difference_type n)
		{
			_M_current -= n;
			return (*this);
		}

		reference	operator[]	(difference_type n) const
		{	return (_M_current[n]);	}

};

//	Input-Output iterator
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator==	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() == rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator==	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() == rhs.base());	}

template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator!=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() != rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator!=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() != rhs.base());	}

//	random_access iterator
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator<	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() < rhs.base());	}

template
<
	typename Iterator,
	typename Container
>
bool	operator<	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() < rhs.base());	}



template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator<=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() <= rhs.base());	}

template
<
	typename Iterator,
	typename Container
>
bool	operator<=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() <= rhs.base());	}



template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator>	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() > rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator>	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() > rhs.base());	}



template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator>=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() >= rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator>=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() >= rhs.base());	}



template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
typename RandomAccessIterator<IteratorLeft, Container>::difference_type
	operator-	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
				 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() - rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
typename RandomAccessIterator<Iterator, Container>::difference_type
	operator-	(RandomAccessIterator<Iterator, Container> const & lhs,
				 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() - rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
RandomAccessIterator<Iterator, Container>
	operator+	(typename RandomAccessIterator<Iterator, Container>::difference_type n,
				 RandomAccessIterator<Iterator, Container> const & it)
{	return (RandomAccessIterator<Iterator, Container>(it.base() + n));	}


# undef CLASS_NAME

# endif
#endif

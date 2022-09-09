/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:08:42 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:35:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ITERATOR_HPP
# ifndef REVERSE_ITERATOR_HPP
#  define REVERSE_ITERATOR_HPP

template
<
	typename Iterator
>
class reverse_iterator
	:public ft::iterator<
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference >
{
	public:
#  include "reverse_iterator/typedef.hpp"
#  include "reverse_iterator/structor.hpp"
#  include "reverse_iterator/member_move_operator.hpp"


		iterator_type	base	(void) const
		{	return (this->current);	}

	protected:
		iterator_type	current;

};

#  include "reverse_iterator/compares_operator.hpp"
#  include "reverse_iterator/non_member_move_operator.hpp"

//template <class Iterator>
//class reverse_iterator
//{
//	public:
//		typedef Iterator												iterator_type;
//		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
//		typedef typename iterator_traits<Iterator>::value_type			value_type;
//		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
//		typedef typename iterator_traits<Iterator>::pointer				pointer;
//		typedef typename iterator_traits<Iterator>::reference			reference;
//
//		reverse_iterator	(void)
//			:_it()
//		{	}
//		explicit reverse_iterator	(iterator_type it)
//			:_it(it)
//		{	}
//		template <class Iter>
//		reverse_iterator	(reverse_iterator<Iter> const & src)
//			:_it(src.base())
//		{	}
//		~reverse_iterator	(void)
//		{	}
//
//		iterator_type	base	(void) const
//		{
//			return (this->_it);
//		}
//
//		reference	operator*	(void) const
//		{
//			iterator_type	tmp(this->_it);
//			--tmp;
//			return (*tmp);
//		}
//
//		reverse_iterator	operator+	(difference_type n) const
//		{
//			iterator_type	tmp(this->_it);
//			tmp--;
//			return (tmp - n);
//		}
//
//		reverse_iterator &	operator++	(void)
//		{
//			this->_it--;
//			return (*this);
//		}
//		reverse_iterator	operator++	(int)
//		{
//			iterator_type	tmp(this->_it);
//			this->_it--;
//			return (tmp);
//		}
//
//		reverse_iterator &	operator+=	(difference_type n)
//		{
//			this->_it -= n;
//			return (*this);
//		}
//
//		reverse_iterator	operator-	(difference_type n) const
//		{
//			iterator_type	tmp(this->_it);
//			tmp--;
//			return (tmp + n);
//		}
//
//		reverse_iterator &	operator--	(void)
//		{
//			this->_it++;
//			return (*this);
//		}
//		reverse_iterator	operator--	(int)
//		{
//			reverse_iterator	tmp = *this;
//			--(*this);
//			return (tmp);
//		}
//
//		reverse_iterator &	operator-=	(difference_type n)
//		{
//			this->_it += n;
//			return (*this);
//		}
//
//		pointer	operator->	(void) const
//		{
//			return (&(this->operator*()));
//		}
//		reference	operator[]	(difference_type n) const
//		{
//			return ((*this) + n);
//		}
//
//		operator reverse_iterator<Iterator const>	(void) const
//		{
//			return (reverse_iterator<Iterator const>(this->_it));
//		}
//
//	private:
//		iterator_type	_it;
//};
//
//template <class Iterator>
//bool	operator==	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() == rhs.base());
//}
//
//template <class Iterator>
//bool	operator!=	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() != rhs.base());
//}
//
//template <class Iterator>
//bool	operator<	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() < rhs.base());
//}
//
//template <class Iterator>
//bool	operator<=	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() <= rhs.base());
//}
//
//template <class Iterator>
//bool	operator>	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() > rhs.base());
//}
//
//template <class Iterator>
//bool	operator>=	(reverse_iterator<Iterator> const & lhs,
//					 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() >= rhs.base());
//}
//
//template <class Iterator>
//reverse_iterator<Iterator>	operator+
//	(typename reverse_iterator<Iterator>::difference_type n,
//	 reverse_iterator<Iterator> const & rev_it)
//{
//	return (rev_it + n);
//}
//
//template <class Iterator>
//typename reverse_iterator<Iterator>::difference_type	operator-
//	(reverse_iterator<Iterator> const & lhs,
//	 reverse_iterator<Iterator> const & rhs)
//{
//	return (lhs.base() - rhs.base());
//}

# endif
#endif

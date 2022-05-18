/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:27:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 16:43:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_ITERATORS_HPP
#  define VECTOR_ITERATORS_HPP

//class MyIterator
//	:public std::iterator<std::input_iterator_tag, T>
//{
//	public:
//		MyIterator	(int * x)
//			:p(x)
//		{	}
//		MyIterator	(const MyIterator & mit)
//			:p(mit.p)
//		{	}
//		
//		MyIterator &	operator++	(void)
//		{
//			++p;
//			return (*this);
//		}
//		MyIterator	operator++	(int)
//		{
//			MyIterator tmp(*this);
//			operator++();
//
//			return (tmp);
//		}
//		bool	operator==	(const MyIterator& rhs) const
//		{
//			return (p==rhs.p);
//		}
//		bool	operator!=	(const MyIterator& rhs) const
//		{
//			return (p!=rhs.p);
//		}
//		int &	operator*	(void)
//		{
//			return (*p);
//		}
//
//	private:
//		int *	p;
//};

iterator	begin	(void)
{
	return (iterator(this->_data));
}

const_iterator	begin	(void) const
{
	return (const_iterator(this->_data));
}

iterator	end		(void)
{
	return (iterator(this->_data + this->_size));
}

const_iterator	end		(void) const
{
	return (const_iterator(this->_data + this->_size));
}

# endif
#endif

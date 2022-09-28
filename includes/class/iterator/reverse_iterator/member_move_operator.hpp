/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_move_operator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:57:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 15:14:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_MEMBER_MOVE_OPERATOR_HPP
#  define REVERSE_ITERATOR_MEMBER_MOVE_OPERATOR_HPP

reverse_iterator & operator++	(void)
{
	--this->current;
	return (*this);
}
reverse_iterator &	operator--	(void)
{
	++this->current;
	return (*this);
}
reverse_iterator	operator++	(int)
{
	reverse_iterator	tmp(*this);
	--this->current;
	return (tmp);
}
reverse_iterator	operator--	(int)
{
	reverse_iterator	tmp(*this);
	++this->current;
	return (tmp);
}

reverse_iterator	operator+	(difference_type n) const
{
	return (reverse_iterator(this->current - n));
}
reverse_iterator	operator-	(difference_type n) const
{
	return (reverse_iterator(this->current + n));
}

reverse_iterator &	operator+=	(difference_type n)
{
	this->current -= n;
	return (*this);
}
reverse_iterator &	operator-=	(difference_type n)
{
	this->current += n;
	return (*this);
}

# endif
#endif


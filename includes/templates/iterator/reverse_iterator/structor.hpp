/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:47:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 15:13:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_STRUCTOR_HPP
#  define REVERSE_ITERATOR_STRUCTOR_HPP

reverse_iterator	(void)
	:current()
{	}

explicit reverse_iterator	(iterator_type	src)
	:current(src)
{	}

template
<
	typename Iter
>
reverse_iterator	(reverse_iterator<Iter> const & src)
	:current(src.base())
{	}

reverse_iterator	(reverse_iterator const & src)
	:current(src.current)
{	}

# endif
#endif


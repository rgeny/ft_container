/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:54:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 13:55:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef STRUCTOR_HPP
#  define STRUCTOR_HPP

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

# endif
#endif


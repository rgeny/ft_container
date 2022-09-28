/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/10 16:54:45 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_MODIFIERS_HPP
#  define VECTOR_MODIFIERS_HPP

template < class InputIterator >
void	assign	(InputIterator first,
				 InputIterator last,
				 typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
{
	this->clear();
	this->insert(this->begin(), first, last);
}
void	assign	(size_type n,
				 const_reference val)
{
	this->clear();
	this->insert(this->begin(), n, val);
}

void	clear	(void)
{
	_destroy_all();
	_size = 0;
}

iterator	insert	(iterator pos,
					 const_reference value)
{
	size_t	position = pos - this->begin();
	this->insert(pos, 1, value);
	return (this->begin() + position);
}

void	insert	(iterator pos,
				 size_type count,
				 const_reference value)
{
	size_t	position = pos - this->begin();
#ifdef __DEBUG__
	std::cout	<< "insert position = "
				<< position
				<< std::endl
				<< "insert pos = "
				<< &(*pos)
				<< std::endl
				<< "insert end() = "
				<< &(*this->end())
				<< std::endl
				<< "insert begin() = "
				<< &(*this->begin())
				<< std::endl
				<< "insert count = "
				<< count
				<< std::endl
				<< "insert _size + count = "
				<< _size + count
				<< std::endl;
#endif
	this->resize(ft::max(count, _size + count), value);

	if (position >= _size - count)
		return ;

	ft::swap_backward	(this->end() - 1,
						 this->end() - 1 - count,
						 this->begin() + position - 1);
}


template
<
	typename InputIt
>
void	insert	(iterator pos,
				 InputIt first,
				 InputIt last,
				 typename ft::enable_if<!ft::is_integral<InputIt>::value>::type = 0)
{
	size_t	position = pos - this->begin(),
			count = std::distance(first, last);

#ifdef __DEBUG__
	std::cout	<< "insert template count = "
				<< count
				<< std::endl
				<< "insert template position ="
				<< position
				<< std::endl;
#endif

	if (&(*first) < &(*last))
		this->insert(pos, count, *first);
	else
		this->insert(pos, count, T() );

	for (iterator it = this->begin() + position;
		 first != last;
		 it++, first++)
	{
		*it = *first;
	}
}

iterator	erase	(iterator pos)
{
	iterator	__pos = (pos >= this->end()) ?
						this->end() - 1:
						pos;
#ifdef __DEBUG__
	std::cout	<< std::endl
				<< "-------------------------- erase --------------------------"
				<< std::endl
				<< "content before : "
				<< std::endl;
	for (size_t i = 0; i < _size; i++)
		std::cout	<< "- "
					<< _data[i]
					<< std::endl;
#endif

	for (iterator lhs = __pos, rhs = __pos + 1, ite = this->end();
		 rhs != ite;
		 lhs++, rhs++)
	{
#ifdef __DEBUG__
		std::cout	<< "lhs before = "
					<< *lhs
					<< std::endl
					<< "rhs before = "
					<< *rhs
					<< std::endl;
#endif
		ft::swap(*lhs, *rhs);
#ifdef __DEBUG__
		std::cout	<< "lhs after = "
					<< *lhs
					<< std::endl
					<< "rhs after = "
					<< *rhs
					<< std::endl;
#endif
	}

	--_size;
	_T_alloc.destroy(_data + _size);

#ifdef __DEBUG__
	std::cout	<< "content after : "
				<< std::endl;
//	for (size_t i = 0; i < _size; i++)
//		std::cout	<< "- "
//					<< _data[i]
//					<< std::endl;
	std::cout	<< "------------------------ end erase -------------------------"
				<< std::endl;
#endif

	return (pos);
}

iterator	erase	(iterator first,
					 iterator last)
{
	size_t	dist = std::distance(first, last),
			start = first - this->begin();
	move_forward(first, last, this->end());
	_destroy(_data + _size - dist, _data + _size);
	_size -= dist;

	return (iterator(_data + start));
}

void	push_back	(const_reference value)
{
	this->insert(this->end(), value);
}

void	pop_back	(void)
{
	this->erase(this->end());
}

void	swap	(vector & other)
{
	ft::swap(_size, other._size);
	ft::swap(_capacity, other._capacity);
	ft::swap(_data, other._data);
}

vector &	operator=	(vector const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->clear();
	this->assign(rhs.begin(), rhs.end());
	return (*this);
}

# endif
#endif

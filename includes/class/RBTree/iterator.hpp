/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:52:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 18:56:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ITERATOR_HPP
#  define RBTREE_ITERATOR_HPP

public:

//	begin
	iterator		begin	(void)
	{
		if (_head.parent == NULL)
			return (&_head);
		return (_head.parent->min());
	}
	const_iterator	begin	(void) const
	{
		if (_head.parent == NULL)
			return (&_head);
		return (_head.parent->min());
	}

//	end
	iterator		end		(void)
	{	return (&_head);	}
	const_iterator	end		(void) const
	{	return (&_head);	}

//	rbegin
	reverse_iterator		rbegin	(void)
	{	return (reverse_iterator(this->end()));	}
	const_reverse_iterator	rbegin	(void) const
	{	return (const_reverse_iterator(this->end()));	}

//	rend
	reverse_iterator		rend	(void)
	{	return (reverse_iterator(this->begin()));	}
	const_reverse_iterator	rend	(void) const
	{	return (const_reverse_iterator(this->begin()));	}

//	lower_bound
	iterator	lower_bound	(key_type const & key)
	{
		iterator	it = this->begin(),
					ite = this->end();

		while (it != ite && _compare(it._cur_node, key))
			++it;
		return (it);
	}
	const_iterator	lower_bound	(key_type const & key) const
	{
		const_iterator	it = this->begin(),
						ite = this->end();

		while (it != ite && _compare(it._cur_node, key))
			++it;
		return (it);

	}

//	upper_bound
	iterator	upper_bound	(key_type const & key)
	{
		iterator	it = this->begin(),
					ite = this->end();

		while (it != ite && !_compare(key, it._cur_node))
			++it;
		return (it);
	}
	const_iterator	upper_bound	(key_type const & key) const
	{
		const_iterator	it = this->begin(),
						ite = this->end();

		while (it != ite && !_compare(key, it._cur_node))
			++it;
		return (it);
	}

//	equal_range
	ft::pair<iterator, iterator>	equal_range	(key_type const & key)
	{
		return (ft::make_pair(this->lower_bound(key),
							  this->upper_bound(key)));
	}
	ft::pair<const_iterator, const_iterator>	equal_range	(key_type const & key ) const
	{
		return (ft::make_pair(this->lower_bound(key),
							  this->upper_bound(key)));
	}

# endif
#endif


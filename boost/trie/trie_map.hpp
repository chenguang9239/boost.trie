#ifndef BOOST_TRIE_MAP
#define BOOST_TRIE_MAP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

//#include <boost/trie/trie.hpp>
#include "trie.hpp"

namespace boost { namespace tries {

template<typename Key, typename Value,
		class Compare = std::less<Key> >
class trie_map
{
public:
	typedef Key key_type;
	typedef Value value_type;
	typedef trie<key_type, value_type, Compare> trie_type;
	typedef trie_map<Key, Value, Compare> trie_map_type;
	typedef typename trie_type::iterator iterator;
	typedef typename trie_type::const_iterator const_iterator;
	typedef typename trie_type::reverse_iterator reverse_iterator;
	typedef typename trie_type::const_reverse_iterator const_reverse_iterator;
	typedef typename trie_type::pair_iterator_bool pair_iterator_bool;
	typedef typename trie_type::iterator_range iterator_range;
	typedef size_t size_type;

protected:
	trie_type t;

public:
	explicit trie_map() : t()
	{
	}

	explicit trie_map(const trie_map_type& other) : t(other.t)
	{
	}

	trie_map_type& operator=(const trie_map_type& other)
	{
		t = other.t;
		return *this;
	}

	iterator begin() 
	{
		return t.begin();
	}

	const_iterator begin() const
	{
		return t.begin();
	}

	const_iterator cbegin() const
	{
		return t.cbegin();
	}

	iterator end() 
	{
		return t.end();
	}

	const_iterator end() const
	{
		return t.end();
	}

	const_iterator cend() const
	{
		return t.cend();
	}

	reverse_iterator rbegin() 
	{
		return t.rbegin();
	}

	const_reverse_iterator rbegin() const
	{
		return t.rbegin();
	}

	const_reverse_iterator crbegin() const
	{
		return t.crbegin();
	}

	reverse_iterator rend() 
	{
		return t.rend();
	}

	const_reverse_iterator rend() const
	{
		return t.rend();
	}

	const_reverse_iterator crend() const
	{
		return t.crend();
	}

// modifying functions
	
	template<typename Container>
	value_type& operator [] (const Container& container)
	{
		return *(t.insert_unique(container, value_type()).first);
	}

	// insert
	template<typename Iter>
	pair_iterator_bool insert(Iter first, Iter last, const value_type& value)
	{
		return t.insert_unique(first, last, value);
	}

	template<typename Container>
	pair_iterator_bool insert(const Container& container, const value_type& value)
	{
		return t.insert_unique(container, value);
	}

	// findLongestPrefixOfKey
	template<typename Iter>
	iterator findLongestPrefixOfKey(Iter first, Iter last)
	{
		return t.findLongestPrefixOfKey(first, last);
	}

	// find
	template<typename Iter>
	iterator find(Iter first, Iter last)
	{
		return t.find(first, last);
	}

	template<typename Container>
	iterator find(const Container& container)
	{
		return t.find(container);
	}

	template<typename Container>
	iterator findLongestPrefixOfKey(const Container& container)
	{
		return t.findLongestPrefixOfKey(container);
	}

	// count
	template<typename Iter>
	size_type count(Iter first, Iter last)
	{
		return t.count(first, last);
	}

	template<typename Container>
	size_type count(const Container& container)
	{
		return t.count(container);
	}

	template<typename Iter>
	size_type count_prefix(Iter first, Iter last)
	{
		return t.count_prefix(first, last);
	}

	template<typename Container>
	size_type count_prefix(const Container& container)
	{
		return t.count_prefix(container);
	}

	// find_with_prefix
	template<typename Iter>
	iterator_range find_prefix(Iter first, Iter last)
	{
		return t.find_prefix(first, last);
	}

	template<typename Container>
	iterator_range find_prefix(const Container& container)
	{
		return t.find_prefix(container);
	}

	// upper and lower bound
	template<typename Iter>
	iterator upper_bound(Iter first, Iter last)
	{
		return (iterator)t.upper_bound(first, last);
	}

	template<typename Container>
	iterator upper_bound(const Container& container)
	{
		return (iterator)t.upper_bound(container);
	}

	template<typename Iter>
	iterator lower_bound(Iter first, Iter last)
	{
		return (iterator)t.lower_bound(first, last);
	}

	template<typename Container>
	iterator lower_bound(const Container& container)
	{
		return (iterator)t.lower_bound(container);
	}

	// erasions
	iterator erase(iterator it)
	{
		return t.erase(it);
	}

	iterator erase(const_iterator it)
	{
		return t.erase(it);
	}

	reverse_iterator erase(reverse_iterator it)
	{
		return t.erase(it);
	}

	reverse_iterator erase(const_reverse_iterator it)
	{
		return t.erase(it);
	}

	template<typename Container>
	iterator erase(const Container &container)
	{
		return t.erase(container);
	}

	template<typename Iter>
	iterator erase(Iter first, Iter last)
	{
		return t.erase(first, last);
	}

	template<typename Container>
	size_type erase_prefix(const Container &container)
	{
		return t.erase_prefix(container);
	}

	template<typename Iter>
	size_type erase_prefix(Iter first, Iter last)
	{
		return t.erase_prefix(first, last);
	}

	size_type count_node() const
	{
		return t.count_node();
	}

	size_type size() const
	{
		return t.size();
	}

	bool empty()
	{
		return t.empty();
	}

	void swap(const trie_map_type& other)
	{
		t.swap(other.t);
	}

	void clear()
	{
		t.clear();
	}

	~trie_map()
	{
	}

};
}	// namespace tries
}	// namespace boost
#endif

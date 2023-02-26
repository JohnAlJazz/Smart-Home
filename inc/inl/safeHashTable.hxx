#ifndef SAFE_HASH_TABLE_HXX
#define SAFE_HASH_TABLE_HXX

namespace threads {

template<typename Key, typename Value>
SafeHashTable<Key,Value>::SafeHashTable()
: m_map()
, m_lockMap()
{
}

template<typename Key, typename Value>
const Value& SafeHashTable<Key,Value>::getValue(const Key a_key)
{
	m_lockMap.lock_shared();
	auto& result = m_map[a_key];		
	m_lockMap.unlock_shared();
	return result;
}

template<typename Key, typename Value>
bool SafeHashTable<Key, Value>::IsContained(const Key a_key)
{
	m_lockMap.lock_shared();
	auto result = m_map.find(a_key) != m_map.end();
	m_lockMap.unlock_shared();
	return result;
}

template<typename Key, typename Value>
size_t SafeHashTable<Key, Value>::Count()
{
	m_lockMap.lock_shared();
	auto result = m_map.count();
	m_lockMap.unlock_shared();
	return result;
}

template<typename Key, typename Value>
void SafeHashTable<Key, Value>::Insert(Key &a_key, Value &a_value)
{
	m_lockMap.lock();
	m_map.insert({a_key, a_value});
	m_lockMap.unlock();
}

template<typename Key, typename Value>
void SafeHashTable<Key, Value>::Update(const Key &a_key, Value &a_value)
{
	m_lockMap.lock();
	m_map.at(a_key) = a_value;
	m_lockMap.unlock();
}

template<typename Key, typename Value>
void SafeHashTable<Key, Value>::Earse(Key &a_key)
{
	m_lockMap.lock();
	m_map.erase(a_key);
	m_lockMap.unlock();
}

}	//threads

# endif /*SAFE_HASH_TABLE_HXX*/
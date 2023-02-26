#ifndef SAFE_HASH_TABLE_HPP
#define SAFE_HASH_TABLE_HPP

#include <thread>
#include <shared_mutex>
#include <unordered_map>
#include <functional>	//std::
#include <mutex>

namespace threads {

template<typename Key, typename Value>
class SafeHashTable {
public:
	explicit SafeHashTable();
	SafeHashTable(const SafeHashTable &a_other) = delete;
	SafeHashTable& operator=(const SafeHashTable &a_other) = delete;
	~SafeHashTable() = default;

	const Value& getValue(const Key a_key);
	bool IsContained(const Key a_key);
	size_t Count();

	void Insert(Key &a_key, Value &a_value);
	void Update(const Key &a_key, Value &a_value);
	void Earse(Key &a_key);

	std::shared_mutex AddMutex(const Key a_key);

private:
	void RunModifiers();

private:
	std::unordered_map<Key, Value> m_map;
	std::shared_mutex m_lockMap;
};

}	//threads

#include "inl/safeHashTable.hxx"

# endif /*SAFE_HASH_TABLE_HPP*/
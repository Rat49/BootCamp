#pragma once
#include <stack>
#include <vector>
#include <cassert>

class PoolElement
{
public:
    virtual void Reset() = 0;
};

template<typename T>
class Pool
{
public:
    explicit Pool( size_t poolSize )
    {
        static_assert(std::is_base_of<PoolElement, T>::value || std::is_fundamental<T>::value, "Object need to be either trivial or poolable");
        assert( poolSize != 0 && "Pool size of 0 is not acceptable" );

        m_all.resize( poolSize );
        for ( auto i = 0; i != poolSize; ++i )
        {
            Put( &m_all[i] );
        }
    }

    ~Pool()
    {
        assert( m_all.size() == m_pool.size() && "Some elements are still in use" );
    }

	bool Empty()
	{
		return m_pool.empty();
	}

	size_t Count()
	{
		return m_pool.size();
	}

	size_t MaxCount()
	{
		return m_all.size();
	}

    T* Get()
    {
        if ( m_pool.empty() )
        {
            return nullptr;
        }

        T* elem = m_pool.top();
        m_pool.pop();
        return elem;
    }

    template <typename U = T, typename std::enable_if< std::is_fundamental<U>::value, int >::type = 0 >
    void Put( T* elem )
    {
        assert( elem != nullptr && "Element is null" );
        m_pool.push( elem );
    }
    
    template <typename U = T, typename std::enable_if< !(std::is_fundamental<U>::value), int >::type = 0 >
    void Put( T* elem )
    {
        assert( elem != nullptr && "Element is null" );
        elem->Reset();
        m_pool.push( elem );
    }

private:
    std::stack<T*> m_pool;
    std::vector<T> m_all;
};

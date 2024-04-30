#pragma once 

#include <memory>

// std::allocator는 생성자 호출 없이 컨테이너에서 메모리 할당을 위해 사용
template<typename T, typename Allocator = std::allocator<T>> 
class MyVector
{
private :
    // 클래스 공통으로 사용하는 상수 (변하지 않는 값)
    static constexpr size_t DEFAULT_CAPACITY_SIZE = 10;

public : 
    using value_type = T;
    using iterator = value_type* ; // [type의 pointer형을 iterator로 사용]
    
    explicit MyVector ( const size_t count,
                        const value_type value,
                        const Allocator& alloc = Allocator())
        :m_Allocator(alloc)
    {
        AllocCapacity(count);
        m_Size = count;
        std::uninitialized_fill( begin(), end(), value); // value의 copy 생성자 호출 
    }

    explicit MyVector( const size_t count = DEFAULT_CAPACITY_SIZE,
                       const Allocator& alloc = Allocator())
        :m_Allocator(alloc)
    {
        AllocCapacity(count);
    }

    MyVector ( const MyVector& _Other,
                        const Allocator& alloc = Allocator())
        :m_Allocator(alloc)
    {
        AllocCapacity(_Other.m_CapacitySize);
        std::uninitialized_copy(_Other.begin(), _Other.end(), m_pData);
        m_Size = _Other.m_Size;
    }

    MyVector ( MyVector && _Other) noexcept
    {
        std::swap(m_CapacitySize, _Other.m_CapacitySize);
        std::swap(m_Size, _Other.m_Size);
        std::swap(m_pData, _Other.m_pData);
        std::swap(m_Allocator, _Other.m_Allocator);
    }

    ~MyVector()
    {
        DeAllocCapacity();
    }

    MyVector& operator=(const MyVector& _Other)
    {
        if(this != &_Other)
        {   
            DeAllocCapacity();

            m_pData = m_Allocator.allocate(_Other.m_CapacitySize);
            std::uninitialized_copy(_Other.begin(), _Other.end(), m_pData);
            m_Size = _Other.m_Size;
        }
        return *this;
    }

    MyVector& operator=(MyVector&& _Other)
    {
        if(this != &_Other)
        {
            std::swap(m_CapacitySize, _Other.m_CapacitySize);
            std::swap(m_Size, _Other.m_Size);
            std::swap(m_pData, _Other.m_pData);
            std::swap(m_Allocator, _Other.m_Allocator);
        }
        return *this;
    }

    T& operator [](const size_t idx)
    {
        m_pData[idx];
    }

    const T& operator [](const size_t idx) const // const vector의 경우 , 필요 
    {
        m_pData[idx];
    }

    template<class... ArgTypes>
    auto emplace_back( ArgTypes&&... args)
    {
        if((m_Size + 1) > m_CapacitySize)
        {
            ExpendCapacity();
        }
        ::new(end())T(std::forward<ArgTypes>(args)...);
        m_Size++;
    }
    auto push_back(const T& data) ->void
    {
        if((m_Size + 1) > m_CapacitySize)
        {
            ExpendCapacity();
        }
        emplace_back(data);
    }
    auto push_back(T&& data) -> void
    {
        if((m_Size + 1) > m_CapacitySize)
        {
            ExpendCapacity();
        }
        emplace_back(std::forward<T>(data));
    }



    auto begin() const noexcept -> iterator
    {
        return m_pData;
    }
    auto end() const noexcept -> iterator
    {
        return m_pData + m_Size;
    }
    auto size() const noexcept->size_t
    {
        return m_Size;
    }
    auto capacity() const noexcept ->size_t
    {
        return m_CapacitySize;
    }

private:
    auto AllocCapacity (const size_t count ) -> void
    {
        m_pData = m_Allocator.allocate(count);
        m_CapacitySize = count;
    }
    auto DeAllocCapacity () -> void 
    {
        std::destroy(begin(), end());
        m_Allocator.deallocate(begin(), m_CapacitySize);
    }
    auto ExpendCapacity() -> void 
    {
        const size_t newCapacitySize = m_CapacitySize * 2; 
        value_type* pNew = m_Allocator.allocate(newCapacitySize);

        if constexpr ( std::is_move_constructible<T>::value )
        {
            std::uninitialized_move(begin(), end(), pNew);
        }
        else
        {
            std::uninitialized_copy(begin(), end(), pNew);
        }

        DeAllocCapacity();

        m_pData = pNew;
        m_CapacitySize = newCapacitySize;

    }
    

private:
    size_t m_CapacitySize{0};
    size_t m_Size{0};
    Allocator m_Allocator;
    value_type* m_pData{nullptr};
};
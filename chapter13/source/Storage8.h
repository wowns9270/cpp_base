
template<typename T>
class Storage8
{
private:
    T m_array[8];


public:
    void set(int idx, const T& tmp)
    {
        m_array[idx] = tmp;
    }

    const T& get(int idx) const
    {
        return m_array[idx];
    }
};

template<>
class Storage8<bool>
{
private:
    unsigned char m_data; // 8bit

public:
    Storage8()
    : m_data(0)
    {

    }

    void set(int idx, bool value)
    {
        unsigned char tmp = ( 1 << idx);

        if(value)
        {
            m_data |= tmp;
        }
        else
        {
            m_data &= ~tmp;
        }
    }

    bool print(int idx)
    {
        return (m_data & ( 1 << idx)) != 0;
    }

};
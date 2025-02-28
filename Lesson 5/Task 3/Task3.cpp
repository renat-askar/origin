template<class T>
class Vector
{
    T* elements{};
    size_t m_size{};
    size_t m_capacity{};
    
    public:
        T at(int index) const
        {
            if(index >= m_size || index < 0)
                std::out_of_range{};
            return elements[index];
        }

        void push_back(T value)
        {       
            if(!m_capacity)
            {
                elements = new T[++m_capacity]{};
                elements[m_size++] = value;
            }
            else if(m_size >= m_capacity)
            {
                T* temp{elements};
                elements = new T[m_capacity *= 2]{};
                for(size_t idx{}; idx < m_size; ++idx)
                {
                    elements[idx] = temp[idx];
                }
                elements[m_size++] = value;
                delete[] temp;
            }
            else
                elements[m_size++] = value;
        }

        ~Vector(){if(m_capacity) delete[] elements;}

        size_t size() const {return m_size;}
        size_t capacity() const {return m_capacity;}
};

#include <iostream>

template<class Type>
class unique_ptr
{
    Type* ptr{nullptr};

    public:
        unique_ptr(Type* getPtr): ptr{getPtr}{}

        Type operator * () const {return *ptr;}

        unique_ptr<Type> operator = (const unique_ptr& ptr) = delete;

        unique_ptr(const unique_ptr& ptr) = delete;

        Type* release()
        {
            if(ptr == nullptr) return ptr;
            delete ptr;
            ptr = nullptr;
            return ptr;
        }

        ~unique_ptr()
        {
            if(ptr != nullptr) delete ptr;
        }
};

int main()
{
    unique_ptr<int> uptr{new int{5}};
    std::cout << *uptr << '\n';

    int* ptr{uptr.release()};
    ptr = new int{3};
    unique_ptr uptr2{ptr};
    std::cout << *uptr2 << '\n';

    return 0;
}

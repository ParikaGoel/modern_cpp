// RAII - Resource Acquisition is Initialization
// Wrap a resource in a class, resource is acquired in the constructor
// and released in the destructor
// Below class in a way implements unique pointer
#include <utility>
#include <iostream>

template <typename T>
class smart_ptr{
    public:
        // Below constructor uses perfect forwarding
        template<typename... Args>
        smart_ptr(Args&&... args): _mptr(new T(std::forward<Args>(args)...)){}

        // copy constructs
        smart_ptr(const smart_ptr& ptr) = delete;
        smart_ptr& operator=(const smart_ptr& ptr) = delete;

        // move constructs
        smart_ptr(smart_ptr&& rhs): _mptr(std::exchange(rhs._mptr,nullptr)){}

        smart_ptr& operator=(smart_ptr&& rhs)
        {
            if (&rhs == this) return *this;
            if (_mptr) delete _mptr;
            _mptr = std::exchange(rhs._mptr, nullptr);
            return *this;
        }


        ~smart_ptr()
        {
            if (_mptr) delete _mptr;
        }

    private:
        T* _mptr{nullptr};
};

class resource{
    public:
        resource(int i, int j):a{i},b{j}{}
    private:
        int a{0};
        int b{0};       
};

// int main()
// {
//     smart_ptr<resource> rptr(1,2);
//     smart_ptr<resource> sptr(3,4);
//     sptr = std::move(rptr);
//     return 0;
// }
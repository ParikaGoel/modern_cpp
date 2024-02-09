// CRTP: Curiously Recurring Template Pattern
// Form of static polymorphism
// Example: Base class to limit the number of instances that can be created
#include <atomic>
#include <iostream>

template<int N_MAX, class Derived>
class LimitInstance{
    public:
        LimitInstance()
        {
            if (_ninstances.load() >= N_MAX)
            {
                // this is erroneous implementation. it will still create 
                // the instance but it explains the concept
                std::cout << "Maximum instances already created.\n";
                return;
            }
            _ninstances.fetch_add(1);
            std::cout << "Base class constructor: " << _ninstances.load() << "\n";
        }

        ~LimitInstance()
        {
            _ninstances.fetch_sub(1);
            std::cout << "Base class destructor: " << _ninstances.load() << "\n";
        }

    private:
        static inline std::atomic<int> _ninstances{0};
};

class Derived1: public LimitInstance<2, Derived1>
{
    public:
        Derived1()
        {
            std::cout << "Derived class constructor\n";
        }
};

class Derived2: public LimitInstance<1, Derived2>
{
    public:
        Derived2()
        {
            std::cout << "Derived class constructor\n";
        }
};

// int main()
// {
//     Derived1 d1;
//     Derived2 d2;
//     Derived2 d3; // this would print that error statement

//     return 0;
// }
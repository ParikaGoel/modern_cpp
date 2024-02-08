// Substitution Failure is not an error
#include <type_traits>
#include <iostream>


// Commented code below explains the concept behind enable_if
// So basically if boolean B evaluates to true, variable type is defined and valid
// otherwise it is not; in that case template substitution will fail and corresponding
// instance of template wont be generated

// template<bool B, typename T>
// struct enable_if {};

// template <typename T>
// struct enable_if<true, T>{typedef T type;};

// Example of SFINAE
// Function implementation for integer value
template <typename T, std::enable_if_t<std::is_integral_v<T>,T> = 0>
void func(T val)
{
    std::cout << "integral func called\n";
}

// Function implementation for float value
template <typename U, typename = std::enable_if_t<std::is_floating_point_v<U>>>
void func(U val)
{
    std::cout << "floating point func called\n";
}

// int main()
// {
//     func(10);
//     func(4.5);
//     return 0;
// }
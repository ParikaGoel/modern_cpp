#ifndef PRINTING_H
#define PRINTING_H

#include <concepts>
#include <iostream>
#include <map>
#include <unordered_map>
#include <type_traits>

// To check if the type has a random access iterator
template <typename Iterator>
struct is_random_access_iterator{
    static constexpr bool value = std::is_same_v<
                                    typename std::iterator_traits<Iterator>::iterator_category,
                                    std::random_access_iterator_tag>;
};

/*-----------------Concept to check if type is a stl container---------------------*/
template <typename ContType>
concept STLCont = requires(ContType cont){
    cont.begin();
    cont.end();
};
/*---------------------------------------------------------------------------------------*/


/*-----------------Structures to check if the template type is stl map---------------------*/
template<typename map_type>
struct is_map{
    inline static constexpr bool value = false;
};

template <typename K, typename V>
struct is_map<std::map<K, V>>{
    inline static constexpr bool value = true;
};

template <typename K, typename V>
struct is_map<std::unordered_map<K, V>>{
    inline static constexpr bool value = true;
};

template <typename K, typename V>
struct is_map<std::multimap<K, V>>{
    inline static constexpr bool value = true;
};
/*---------------------------------------------------------------------------------------*/

/*-----------------------------------PRINT FUNCTIONS-------------------------------------*/

// For built in types
// template <typename Type>
// void print(const Type& m)
// {
//     std::cout << m << "\n";
// }

// All STL Containers except maps
// Bug: works for std::string also
template <typename ContainerType, 
        typename std::enable_if<!is_map<ContainerType>::value, ContainerType>::type* = nullptr>
requires STLCont<ContainerType>
void print(const ContainerType& m)
{
    for (const auto& val: m)
        std::cout << val << " ";
    std::cout << "\n";
}

// for stl map containers
template <typename ContainerType, 
        typename std::enable_if<is_map<ContainerType>::value, ContainerType>::type* = nullptr>
void print(const ContainerType& m)
{
    for(const auto& [k, v]: m)
        std::cout << "{" << k << "," << v << "}  ";
    std::cout << "\n";
}


#endif // PRINTING_H
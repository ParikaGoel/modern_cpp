#include <iostream>
#include <type_traits>
#include <concepts>
#include <vector>
#include <span>
#include <any>
#include <string>

// int main()
// {
//     std::any val;
//     val = 42;
//     val = std::string("Hello, std::any!");

//     try{
//         if (std::any_cast<int>(&val))
//             std::cout << std::any_cast<int>(val) << "\n";
//         else if(std::any_cast<std::string>(&val))
//             std::cout << std::any_cast<std::string>(val) << "\n";
//     }
//     catch(const std::bad_any_cast& e)
//     {
//         std::cout << "Error: " << e.what() << "\n";
//     }

//     return 0;
// }
// RTR - Return Type Resolver
// Also known as return type overloading
// To deduce the type of object being assigned to 
// Example: when using nullptr, this is the technique used under the hood to determine
// the type of the pointer it is being assigned to
#include <string>
#include <iostream>

// Functions cant be overloaded based only on return type like below
// This functionality can be achieved using RTR
// int from_string(const std::string& s)
// {
//     return std::stoi(s);
// }

// float from_string(const std::string& s)
// {
//     return std::stof(s);
// }

class from_string{
    public:
        from_string(std::string str): _mstr(str){}

        template<typename type>
        operator type(){
            if constexpr(std::is_same_v<type, int>) return std::stoi(_mstr);
            else if (std::is_same_v<type, float>) return std::stof(_mstr);
            else if (std::is_same_v<type, double>) return std::stod(_mstr);
            else{
                std::cout << "Conversion to called type not defined. Undefined behaviour\n";
                return -1;
            }
        }
    private:
        std::string _mstr{""};
};

// int main()
// {
//     std::cout << int(from_string("123")) << "\n";
//     std::cout << double(from_string("123.456")) << "\n";
//      int a = from_string("123"); // calls int() under the hood
//     return 0;
// }


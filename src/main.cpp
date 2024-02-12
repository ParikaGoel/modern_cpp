#include <iostream>
#include <type_traits>
#include <concepts>
#include <vector>
#include <span>
#include <any>
#include <string>
#include <map>
#include <string>

#include "helpers/printing.h"

int main()
{
    std::map<int, std::string> val1 = {{1,"one"},{2,"two"},{3,"three"}};
    std::vector<int> val2 = {1, 2, 3, 4, 5, 6};
    std::string val3 = "Hi Parika";

    print(val1);
    print(val2);
    print(val3);

    return 0;
}
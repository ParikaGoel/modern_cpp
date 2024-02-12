// Splicing for maps and sets
// Moving nodes and merging containers without expensive copy, move and heap allocation/deallocation

#include <iostream>
#include <map>
#include <set>
#include <string>

void showMapFunc()
{
    std::map<int, std::string> src{{1, "one"},{2, "two"},{3, "three"},{4, "four"}};
    std::map<int, std::string> dest{{3, "not required"}};
    dest.insert(src.extract(1)); // cheap remove and insert of 1 from src to dest
}

void showSetFunc()
{
    std::set<int> src{1, 2, 3};
    std::set<int> dst{4, 5, 6};
    dst.merge(src);
}
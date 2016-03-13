#include "pair.h"

#include <string>
#include <iostream>

#define PRINT(a) std::cout << (#a) << " " << (a) << "\n";

int main()
{
    pair<int, std::string> p1;
    pair<int, std::string> p2 {2, "str"};
    pair<int, std::string> p3(3, "str");
    pair<int, std::string> p4 = p2;
    p1 = p4;

    PRINT(p1 == p4);
    PRINT(p2 == p4);
    PRINT(p3 == p4);
    PRINT(p3 != p4);
}

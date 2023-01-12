#include <iostream>

#include "jolly_jumper.h"

int main()
{
    std::cout << (JollyJumper::IsJollyJumper(std::vector<int>{1, 2, 4, 7, 11}) ? "True" : "False") << std::endl;

    return 0;
}

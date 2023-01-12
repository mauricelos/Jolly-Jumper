#include <algorithm>

#include "jolly_jumper.h"

bool JollyJumper::IsJollyJumper(const std::vector<int>& numbers)
{
    std::vector<bool> differences(numbers.size(), true);

    return !numbers.empty() &&
           (std::adjacent_find(numbers.begin(), numbers.end(),
                               [&differences](int a, int b)
                               {
                                   auto diff{std::abs(a - b)};
                                   if (diff == 0 || diff > differences.size() - 1 || differences[diff] == false)
                                   {
                                       return true;
                                   }
                                   else
                                   {
                                       differences.at(diff) = false;
                                       return false;
                                   }
                               }) == numbers.end() ||
            numbers == std::vector(numbers.size(), numbers.front()));
}

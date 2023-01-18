#include <algorithm>

#include "jolly_jumper.h"

bool JollyJumper::IsJollyJumper(const std::vector<int>& numbers)
{
    return !numbers.empty() &&
           (std::adjacent_find(numbers.begin(), numbers.end(),
                               [differences{std::vector(numbers.size(), false)}, diff{0u}](int a, int b) mutable {
                                   differences.at(diff) = true;
                                   diff = static_cast<unsigned int>(std::abs(a - b));
                                   return !(diff > 0 && diff < differences.size() && !differences.at(diff));
                               }) == numbers.end() ||
            std::equal(std::next(numbers.begin()), numbers.end(), numbers.begin()));
}

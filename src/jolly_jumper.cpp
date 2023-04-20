#include <algorithm>

#include "jolly_jumper.h"

bool JollyJumper::IsJollyJumper(const std::vector<int>& numbers)
{
    return !numbers.empty() &&
           (std::adjacent_find(numbers.begin(), numbers.end(),
                               [differences{std::vector<bool>(numbers.size())}, diff{0u}](auto a, auto b) mutable {
                                   differences.at(diff).flip();
                                   diff = std::make_unsigned_t<int>(std::abs(a - b));
                                   return !(diff < differences.size() && !differences.at(diff));
                               }) == numbers.end() ||
            std::equal(std::next(numbers.begin()), numbers.end(), numbers.begin()));
}

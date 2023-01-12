#include <algorithm>
#include <unordered_set>

#include "jolly_jumper.h"

bool JollyJumper::IsJollyJumper(const std::vector<int>& numbers)
{
    std::unordered_set<int> differences{};

    return !numbers.empty() && (std::adjacent_find(numbers.begin(), numbers.end(),
                                                   [&differences, &numbers](int a, int b)
                                                   {
                                                       auto diff{std::abs(a - b)};
                                                       return diff == 0 || diff > numbers.size() - 1 ||
                                                              !*differences.insert(diff).first;
                                                   }) == numbers.end() ||
                                std::equal(std::next(numbers.begin()), numbers.end(), numbers.begin()));
}

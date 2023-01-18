#include <algorithm>

#include <benchmark/benchmark.h>

#include "jolly_jumper.h"

std::vector<int> CreateJollyJumper(std::size_t size)
{
    std::vector<int> numbers(size);
    std::generate(numbers.begin(), numbers.end(), [n = 1, i = 0] () mutable { return n += i++; });
    return numbers;
}

class JollyJumperFixture : public benchmark::Fixture
{
public:
    std::vector<int> numbers{};

    JollyJumperFixture()
    {
        numbers = CreateJollyJumper(1000000);
    }
};

BENCHMARK_F(JollyJumperFixture, TestJollyJumper)(benchmark::State& state)
{
    for (auto _ : state)
    {
        JollyJumper::IsJollyJumper(numbers);
    }
}

BENCHMARK_MAIN();

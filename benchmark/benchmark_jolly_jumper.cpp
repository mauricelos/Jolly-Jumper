#include <algorithm>

#include <benchmark/benchmark.h>

#include "jolly_jumper.h"

std::vector<int> CreateJollyJumper(size_t size)
{
    std::vector<int> numbers(size, 0);
    std::generate(numbers.begin(), numbers.end(), [n = 1, i = 0]() mutable { return n += i++; });
    return numbers;
}

static void BenchmarkIsJollyJumper(benchmark::State& state)
{
    auto numbers = CreateJollyJumper(1000);

    for (auto _ : state)
    {
        JollyJumper::IsJollyJumper(numbers);
    }
}

BENCHMARK(BenchmarkIsJollyJumper);
BENCHMARK_MAIN();

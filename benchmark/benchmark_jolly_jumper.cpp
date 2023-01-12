#include <benchmark/benchmark.h>

#include "jolly_jumper.h"

std::vector<int> CreateJollyJumper(int size)
{
    return std::vector{0};
}

static void BenchmarkIsJollyJumper(benchmark::State& state)
{
    auto numbers = CreateJollyJumper(1);

    for (auto _ : state)
    {
        JollyJumper::IsJollyJumper(numbers);
    }
}

BENCHMARK(BenchmarkIsJollyJumper);
BENCHMARK_MAIN();

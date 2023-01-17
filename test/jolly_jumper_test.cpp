#include "gtest/gtest.h"

#include "jolly_jumper.h"

namespace
{

TEST(JollyJumperTest, SimpleTest)
{
    EXPECT_TRUE(JollyJumper::IsJollyJumper(std::vector{1, 2, 4, 7, 11}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector{1, 2, 4, 7, 12}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector{2, 4, 7, 11}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector{1, 2, 4, 7, 8}));
    EXPECT_TRUE(JollyJumper::IsJollyJumper(std::vector{1, 1, 1, 1, 1}));
    EXPECT_TRUE(JollyJumper::IsJollyJumper(std::vector{-1, 0, 2, 5, 9}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector{11, 2, 1, 4, 7}));
    EXPECT_TRUE(JollyJumper::IsJollyJumper(std::vector{11, 7, 10, 8, 9}));
    EXPECT_TRUE(JollyJumper::IsJollyJumper(std::vector{10, 8, 9, 12, 16}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector{10, 8, 9, 12, 500}));
    EXPECT_FALSE(JollyJumper::IsJollyJumper(std::vector<int>{}));
}

} // namespace

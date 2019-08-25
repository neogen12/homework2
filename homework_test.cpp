#include "main.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(splitTest, split_string)
{
    std::string line = "46.3.3.3    str1    str2";  
    EXPECT_EQ("46.3.3.3", split(line, '\t'););
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


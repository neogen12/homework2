#include "main.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(filterTest, filter_string)
{
    std::string s{"46"};
    std::vector<std::string> v{"2.12.3.46"};
    v.push_back("3.3.3.3");
    v.push_back("46.3.3.3");
    EXPECT_EQ("46.3.3.3", filter(s, v));
}

/*TEST(squareRootTest, NegativeNos)
{
    ASSERT_EQ(0.0, squareRoot(0.0));
    ASSERT_EXIT(squareRoot(-22.0), ::testing::ExitedWithCode(-1), "Error: Negative Input");
}
*/
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


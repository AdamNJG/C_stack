#include <gtest/gtest.h>

TEST(MyTestSuite, TestExample) {
    // Your test assertions here
    EXPECT_EQ(2 + 2, 4); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
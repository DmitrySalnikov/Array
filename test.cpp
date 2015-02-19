#include "Simple_array.h"
#include <gtest/gtest.h>

TEST(Simple_array, constructor) {
    Simple_array<int> a;

    Simple_array<int> b(2);

    Simple_array<int> c(3);
}

TEST(Simple_array, push) {
    Simple_array<int> a;
    for (int i = 0; i < 25; ++i) 
        a.push(i);

    Simple_array<int> b(2);
    for (int i = 0; i < 33; ++i) 
        b.push(i);
}

TEST(Simple_array, pop) {
    Simple_array<int> a;

    EXPECT_FALSE(a.pop());

    for (int i = 0; i < 25; ++i) 
        a.push(i);

    EXPECT_TRUE(a.pop());
    EXPECT_TRUE(a.pop());

    for (size_t i = 0; i < 22; ++i) 
        a.pop();

    EXPECT_TRUE(a.pop());
    EXPECT_FALSE(a.pop());
    EXPECT_FALSE(a.pop());
}

TEST(Simple_array, pick) {
    Simple_array<int> a;

    for (int i = 0; i < 25; ++i) 
        a.push(i);

    EXPECT_EQ(24, *(a.pick()));

    EXPECT_EQ(a[24], *(a.pick()));

    for (size_t i = 0; i < 24; ++i) 
        a.pop();

    EXPECT_EQ(0, *(a.pick()));

    a.pop();
    EXPECT_EQ(nullptr, a.pick());
}

TEST(Simple_array, index) {
    Simple_array<int> a;
    a[8] = 5;
    EXPECT_EQ(5, *(a.pick()));
    a[152] = 5;
    EXPECT_EQ(5, *(a.pick()));
    EXPECT_EQ(153, a.size());
}

TEST(Simple_array, constant) {
    Simple_array<int> a(10, 5);
    int bb[] = {1, 2, 3, 4, 5};
    Simple_array<int> b(5, bb);

    EXPECT_EQ(5, *(a.pick()));
    EXPECT_EQ(5, *(b.pick()));
    EXPECT_EQ(5, b[4]);
}

TEST(Simple_array, copy) {
    int bb[] = {1, 2, 3, 4, 5};
    Simple_array<int> b(5, bb);
    Simple_array<int> a(b);
    Simple_array<int> c;
    c=b;

    EXPECT_EQ(5, *(a.pick()));
    EXPECT_EQ(5, a[4]);

    EXPECT_EQ(5, *(c.pick()));
    EXPECT_EQ(5, c[4]);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

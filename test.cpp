#include "Simple_array.h"
#include "../gtest/gtest/gtest.h"

TEST(Array, constructor) {
	Array<int> a;

	Array<int> b(2);

	Array<int> c(3);
}

TEST(Array, push) {
	Array<int> a;
	for (int i = 0; i < 25; ++i) 
		a.push(i);

	Array<int> b(2);
	for (int i = 0; i < 33; ++i) 
		b.push(i);
}

TEST(Array, pop) {
	Array<int> a;

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

TEST(Array, pick) {
	Array<int> a;

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

GTEST_API_ int main(int argc, char ** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

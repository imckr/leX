#include <gtest/gtest.h>
#include "../include/"

TEST(HelloTest, BasicTest) {
	EXPECT_TRUE(true);
}


TEST(HelloTest, SayHelloTest) {
	EXPECT_NO_THROW(sayHello());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TEST();
}

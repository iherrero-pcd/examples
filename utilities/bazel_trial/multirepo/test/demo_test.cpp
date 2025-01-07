#include "gtest/gtest.h"
#include "app/greet.h"

TEST(DemoTest, GetGreet) {
  EXPECT_EQ(get_greet("Bazel"), "Hello Bazel");
}


#include <gtest/gtest.h>
#include "Window.hpp"


TEST (test, test) {
   Color color;
   color.r = 255;
   color.b = 255;
   color.g = 255;
   color.a = 255;
   EXPECT_EQ( color.r, 255 );
   EXPECT_EQ( color.a, 255 );
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
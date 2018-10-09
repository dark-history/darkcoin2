#include "gtest/gtest.h"
#include "System/Future.h"

using namespace System;
using namespace Detail;

TEST(Future, 1)
{
  async<bool>([&](){ return true; });
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"
#include "System/InterruptedException.h"

using namespace System;

// constructor
TEST(InterruptedException, 1)
{
  InterruptedException();
}

// what()
TEST(InterruptedException, 2)
{
  InterruptedException exception;
  ASSERT_EQ("interrupted", exception.what());
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
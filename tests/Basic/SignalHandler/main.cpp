#include <Common/SignalHandler.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace Tools;

// constructor
TEST(SignalHandler, 1)
{
  SignalHandler();
}

// install()
TEST(SignalHandler, 2)
{
  SignalHandler signalHandler;

  std::function<void(void)> myFunction = [&](){ std::cout << "Hello World" << std::endl; };
  ASSERT_TRUE(signalHandler.install(myFunction));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
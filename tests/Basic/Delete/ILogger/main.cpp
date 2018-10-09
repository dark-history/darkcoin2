#include "gtest/gtest.h"
#include "Logging/ILogger.h"

using namespace Logging;

// constructor
TEST(ILogger, 1)
{
  ILogger logger;
}


int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
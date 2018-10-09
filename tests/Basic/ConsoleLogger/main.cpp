#include "gtest/gtest.h"
#include "Logging/ConsoleLogger.h"

using namespace Logging;

// constructor
TEST(ConsoleLogger, 1)
{
  ConsoleLogger logger1;

  Level level = Level::DEBUGGING;
  ConsoleLogger logger2(level);

  ConsoleLogger logger3(Level::FATAL);
  ConsoleLogger logger4(Level::ERROR);
  ConsoleLogger logger5(Level::WARNING);
  ConsoleLogger logger6(Level::INFO);
  ConsoleLogger logger7(Level::TRACE);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
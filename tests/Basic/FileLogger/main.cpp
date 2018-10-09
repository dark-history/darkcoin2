#include "gtest/gtest.h"
#include "Logging/FileLogger.h"

using namespace Logging;

// constructor
TEST(FileLogger, 1)
{
  FileLogger logger1;

  Level level = Level::DEBUGGING;
  FileLogger logger2(level);

  FileLogger logger3(Level::FATAL);
  FileLogger logger4(Level::ERROR);
  FileLogger logger5(Level::WARNING);
  FileLogger logger6(Level::INFO);
  FileLogger logger7(Level::TRACE);
}

// init
TEST(FileLogger, 2)
{
  FileLogger logger;

  std::string filename = "log.txt";
  logger.init(filename);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
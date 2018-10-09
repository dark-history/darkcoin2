#include "gtest/gtest.h"
#include "Logging/LoggerRef.h"
#include "Logging/ConsoleLogger.h"

using namespace Logging;

// constructor
TEST(LoggerRef, 1)
{
  ConsoleLogger logger;
  std::string category = "myCategory";
  LoggerRef(logger, category);
}

// operator()
TEST(LoggerRef, 2)
{
  ConsoleLogger logger;
  std::string category = "myCategory";
  LoggerRef loggerRef(logger, category);

  Level level = Level::DEBUGGING;
  std::string color = "green";
  LoggerMessage loggerMessage = loggerRef(level, color);
}

// getLogger()
TEST(LoggerRef, 3)
{
  ConsoleLogger logger;
  std::string category = "myCategory";
  LoggerRef loggerRef(logger, category);

  ILogger& loggerRet = loggerRef.getLogger();
}


int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
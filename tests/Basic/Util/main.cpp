#include <Common/Util.h>
#include <gtest/gtest.h>

using namespace Tools;

// getDefaultDataDirectory()
TEST(Util, 1)
{
  std::string dir = getDefaultDataDirectory();
  ASSERT_TRUE(dir.find(".cash2") != std::string::npos);
}

// get_os_version_string()
TEST(Util, 2)
{
  std::string version = get_os_version_string();
  ASSERT_TRUE(version.find("Ubuntu") != std::string::npos);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
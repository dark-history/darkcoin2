#include "gtest/gtest.h"
#include "System/TcpStream.h"
#include "System/TcpConnection.h"

using namespace System;

// constructor
TEST(TcpStream, 1)
{
  TcpConnection connection;
  TcpStreambuf buf(connection);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
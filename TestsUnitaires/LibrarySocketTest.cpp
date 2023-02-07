#include "SfmlSocket.hpp"
#include "gtest/gtest.h"

class SfmlSocketTest : public ::testing::Test {
 protected:
  SfmlSocket sfmlSocket;
};

TEST_F(SfmlSocketTest, BindSocket) {
  EXPECT_TRUE(sfmlSocket.BindSocket(1234));
  EXPECT_EQ(sfmlSocket.getPort(), 1234);
}

TEST_F(SfmlSocketTest, GetIp) {
  EXPECT_EQ(sfmlSocket.getIp(), "127.0.0.1");
}

TEST_F(SfmlSocketTest, ReceivePacket) {
  PacketStruct packet = sfmlSocket.ReceivePacket();
  EXPECT_EQ(packet.ip, "");
  EXPECT_EQ(packet.port, 0);
}

TEST_F(SfmlSocketTest, SendPacket) {
  PacketStruct packet;
  packet.ip = "127.0.0.1";
  packet.port = 1234;
  EXPECT_TRUE(sfmlSocket.SendPacket(packet));
}

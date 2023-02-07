#include <gtest/gtest.h>
#include "Game.hpp"

class GameTest : public ::testing::Test {
 protected:
  Game game;

  virtual void SetUp() {
    game = Game();
  }

  virtual void TearDown() {
  }
};

TEST_F(GameTest, TestObtainServerIp) {
  std::string expected_ip = "127.0.0.1";
  std::stringstream input_stream;
  input_stream << expected_ip;
  std::cin.rdbuf(input_stream.rdbuf());
  ASSERT_EQ(expected_ip, game.obtainServerIp());
}

TEST_F(GameTest, TestClientEvent) {
  Input event = Input::Z_KEY;
  game.window.input_ = event;
  game.clientEvent();
  ASSERT_EQ(game.input, 3);
}

TEST_F(GameTest, TestClientSendEvent) {
  game.input = 2;
  game.ipServer = "127.0.0.1";
  game.portServer = 55002;
  game.clientSendEvent();
 
}

TEST_F(GameTest, TestClientObtainCoord) {
  IdentifyPackage identifyPackage;
  identifyPackage.setIdTypeSprite(1);
  identifyPackage.setPosX(100);
  identifyPackage.setPosY(200);
  game.clientObtainCoord(identifyPackage);
  ASSERT_EQ(game.posplayerOne.x, 100);
  ASSERT_EQ(game.posplayerOne.y, 200);
}

TEST_F(GameTest, TestClientSendDisconnect) {
  game.ipServer = "127.0.0.1";
  game.portServer = 55002;
  game.clientSendDisconnect();
}

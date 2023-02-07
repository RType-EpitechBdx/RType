#include "CreatePackage.hpp"
#include <gtest/gtest.h>

TEST(CreatePackage, createMessagePackage) {
  CreatePackage cp;
  cp.createMessagePackage(5);
  sf::Packet packet = cp.getPacket();
  CreatePackage::IdHeader idHeader;
  packet >> idHeader.id;
  ASSERT_EQ(idHeader.id, 1);
  CreatePackage::Message message;
  packet >> message.idMessage;
  ASSERT_EQ(message.idMessage, 5);
}

TEST(CreatePackage, createEventPackage) {
  CreatePackage cp;
  cp.createEventPackage(7);
  sf::Packet packet = cp.getPacket();
  CreatePackage::IdHeader idHeader;
  packet >> idHeader.id;
  ASSERT_EQ(idHeader.id, 2);
  CreatePackage::Event event;
  packet >> event.idEvent;
  ASSERT_EQ(event.idEvent, 7);
}

TEST(CreatePackage, createErrorPackage) {
  CreatePackage cp;
  cp.createErrorPackage(9);
  sf::Packet packet = cp.getPacket();
  CreatePackage::IdHeader idHeader;
  packet >> idHeader.id;
  ASSERT_EQ(idHeader.id, 3);
  CreatePackage::Error error;
  packet >> error.idError;
  ASSERT_EQ(error.idError, 9);
}

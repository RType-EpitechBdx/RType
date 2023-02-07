#include <gtest/gtest.h>
#include "IdentifyPackage.hpp"
#include <SFML/Network.hpp>

TEST(IdentifyPackage, ConstructorWithValidPacket) {
    sf::Packet packet;
    packet << (sf::Uint8)1 << (sf::Uint8)2;
    IdentifyPackage identifyPackage(packet);
    EXPECT_EQ(identifyPackage.getIdHeader(), 1);
    EXPECT_EQ(identifyPackage.getIdMessage(), 2);
}

TEST(IdentifyPackage, ConstructorWithInvalidPacket) {
    sf::Packet packet;
    packet << (sf::Uint8)4;
    IdentifyPackage identifyPackage(packet);
    EXPECT_EQ(identifyPackage.getIdHeader(), 4);
    EXPECT_EQ(identifyPackage.getIdMessage(), 0);
}

TEST(IdentifyPackage, GetIdSprite) {
    sf::Packet packet;
    packet << (sf::Uint8)2 << (sf::Uint8)3 << (sf::Uint8)4 << (sf::Uint32)5 << (sf::Uint32)6;
    IdentifyPackage identifyPackage(packet);
    EXPECT_EQ(identifyPackage.getIdSprite(), 3);
    EXPECT_EQ(identifyPackage.getIdTypeSprite(), 4);
    EXPECT_EQ(identifyPackage.getPosX(), 5);
    EXPECT_EQ(identifyPackage.getPosY(), 6);
}

TEST(IdentifyPackage, GetIdError) {
    sf::Packet packet;
    packet << (sf::Uint8)3 << (sf::Uint8)7;
    IdentifyPackage identifyPackage(packet);
    EXPECT_EQ(identifyPackage.getIdError(), 7);
}

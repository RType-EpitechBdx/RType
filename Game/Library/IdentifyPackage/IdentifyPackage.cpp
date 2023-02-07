#include "IdentifyPackage.hpp"

/**
 * @brief Construct a new Identify Package:: Identify Package object from a packet
 * @param packet
 */

IdentifyPackage::IdentifyPackage(sf::Packet packet) : packet(packet)
{
    packet >> idHeader.id;
    if (idHeader.id == 1) {
        packet >> message.idMessage;
    }
    else if (idHeader.id == 2) {
        packet >> gameSprite.idSprite >> gameSprite.idTypeSprite >> gameSprite.posX >> gameSprite.posY;
    }
    else if (idHeader.id == 3) {
        packet >> error.idError;
    }
}

/**
 * @brief Get the Id Header object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdHeader() const { return idHeader.id; }

/**
 * @brief Get the Id Message object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdMessage() const { return message.idMessage; }

/**
 * @brief Get the Id Sprite object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdSprite() const { return gameSprite.idSprite; }

/**
 * @brief Get the Id Type Sprite object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdTypeSprite() const { return gameSprite.idTypeSprite; }

/**
 * @brief Get the Pos X object
 * @return sf::Uint32
 */

sf::Uint32 IdentifyPackage::getPosX() const { return gameSprite.posX; }

/**
 * @brief Get the Pos Y object
 * @return sf::Uint32
 */

sf::Uint32 IdentifyPackage::getPosY() const { return gameSprite.posY; }

/**
 * @brief Get the Id Error object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdError() const { return error.idError; }
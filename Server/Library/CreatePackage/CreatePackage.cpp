#include "CreatePackage.hpp"

/**
 * @brief Create the header of the package
 * @param id
 */

void CreatePackage::createIdHeader(sf::Uint8 id)
{
    IdHeader idHeader;
    idHeader.id = id;
    packet << idHeader.id;
}

/**
 * @brief Create the message of the package
 * @param idMessage
 */

void CreatePackage::createMessagePackage(sf::Uint8 idMessage)
{
    createIdHeader(1);
    Message message;
    message.idMessage = idMessage;
    packet << message.idMessage;
}

/**
 * @brief Create the game sprite of the package
 * @param idSprite
 * @param idType
 * @param posX
 * @param posY
 */

void CreatePackage::createGameSpritePackage(sf::Uint8 idSprite, sf::Uint8 idType, sf::Uint32 posX, sf::Uint32 posY)
{
    createIdHeader(2);
    GameSprite gameSprite;
    gameSprite.idSprite = idSprite;
    gameSprite.idTypeSprite = idType;
    gameSprite.posX = posX;
    gameSprite.posY = posY;
    packet << gameSprite.idSprite << gameSprite.idTypeSprite << gameSprite.posX << gameSprite.posY;
}

/**
 * @brief Create the error of the package
 * @param idError
 */

void CreatePackage::createErrorPackage(sf::Uint8 idError)
{
    createIdHeader(3);
    Error error;
    error.idError = idError;
    packet << error.idError;
}

/**
 * @brief Get the Packet object
 * @return sf::Packet
 */

sf::Packet CreatePackage::getPacket() const { return packet; }

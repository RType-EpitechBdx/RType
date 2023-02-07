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
 * @brief Create the event of the package
 * @param idEvent
 */

void CreatePackage::createEventPackage(sf::Uint8 idEvent)
{
    createIdHeader(2);
    Event event;
    event.idEvent = idEvent;
    packet << event.idEvent;
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

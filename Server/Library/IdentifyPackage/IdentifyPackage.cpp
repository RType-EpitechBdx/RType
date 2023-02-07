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
        packet >> event.idEvent;
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
 * @brief Get the Id Event object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdEvent() const { return event.idEvent; }

/**
 * @brief Get the Id Error object
 * @return sf::Uint8
 */

sf::Uint8 IdentifyPackage::getIdError() const { return error.idError; }

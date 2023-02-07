#pragma once

#include <SFML/Network.hpp>

/**
 * @brief create a struct to store the packet, the ip and the port
 * @struct PacketStruct
 * @param packet
 * @param ip
 * @param port
 */

struct PacketStruct {
    sf::Packet packet;
    std::string ip;
    unsigned short port;
};
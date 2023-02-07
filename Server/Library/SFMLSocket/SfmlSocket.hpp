#pragma once

#ifndef SFMLSOCKET_
#define SFMLSOCKET_

#include "INetwork.hpp"
#include "SFML/Network.hpp"
#include <iostream>
#include <string>

/**
 * @brief create a socket with sfml
 */

class SfmlSocket : public INetwork {
    public:
    SfmlSocket();
    SfmlSocket(SfmlSocket const &other) noexcept = default;
    SfmlSocket(SfmlSocket &&other) noexcept = default;
    SfmlSocket &operator=(SfmlSocket const &other) noexcept = default;
    SfmlSocket &operator=(SfmlSocket &&other) noexcept = default;
    ~SfmlSocket() = default;

    bool BindSocket(unsigned short port) override;
    unsigned short getPort() override;
    std::string getIp() override;
    PacketStruct ReceivePacket();
    bool SendPacket(PacketStruct packet);

    private:
    unsigned short port;
    sf::UdpSocket socket;
    sf::IpAddress ip;
};

#endif /* !SFMLSOCKET_*/
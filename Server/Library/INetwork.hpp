#pragma once
#ifndef INETWORK_
#define INETWORK_

#include "PacketStruct.hpp"
#include <string>

/**
 * @brief create a socket
 */

class INetwork {
    public:
    INetwork() = default;
    INetwork(INetwork const &other) noexcept = default;
    INetwork(INetwork &&other) noexcept = delete;
    virtual INetwork &operator=(INetwork const &other) noexcept = delete;
    virtual INetwork &operator=(INetwork &&other) noexcept = delete;
    virtual ~INetwork() = default;

    virtual bool BindSocket(unsigned short port) = 0;
    virtual unsigned short getPort() = 0;
    virtual std::string getIp() = 0;
    virtual PacketStruct ReceivePacket() = 0;
    virtual bool SendPacket(PacketStruct packet) = 0;
};

#endif /* !INETWORK_*/
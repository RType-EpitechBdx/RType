#pragma once
#ifndef SERVER_
#define SERVER_

#include "CreatePackage.hpp"
#include "IdentifyPackage.hpp"
#include "PacketStruct.hpp"
#include "SfmlSocket.hpp"
#include "UserData.hpp"
#include <iostream>
#include <string>

class Server {
    public:
    Server();
    Server(Server const &other) noexcept = default;
    Server(Server &&other) noexcept = default;
    Server &operator=(Server const &other) noexcept = default;
    Server &operator=(Server &&other) noexcept = default;
    ~Server() noexcept = default;

    void setPort(int port) noexcept;
    void setIp(std::string ip) noexcept;
    void setClientConnected(int clientConnected) noexcept;
    int getPort() const noexcept;
    std::string getIp() const noexcept;
    int getClientConnected() const noexcept;

    void startServer();

    private:
    PacketStruct receivePacket();
    bool sendPacket(PacketStruct packet);
    void analysePacket(PacketStruct packet);
    void sendPacketToAll(PacketStruct packet);
    void analyseMessage(PacketStruct packet, IdentifyPackage identifyPackage);
    void analyseEvent(PacketStruct packet, IdentifyPackage identifyPackage);
    void analyseError(PacketStruct packet, IdentifyPackage identifyPackage);

    void connectUser(PacketStruct packet);
    void disconnectUser(PacketStruct packet);
    bool checkConnectedUser(PacketStruct packet);
    int getIdUser(PacketStruct packet);

    void sendPosition(int id, int idType);

    SfmlSocket socket;
    std::vector<UserData> users;
    std::string ip;
    int port;
    int clientConnected;
    int x;
    int y;
};

#endif /* !SERVER_*/
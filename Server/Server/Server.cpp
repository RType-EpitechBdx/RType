#include "Server.hpp"

/**
 * @brief Construct a new Server:: Server object
 */

Server::Server()
{
    port = 55002;
    clientConnected = 0;
    socket.BindSocket(port);
    x = 100;
    y = 100;
}

/**
 * @brief start the server
 */

void Server::startServer()
{
    std::cout << "Server started" << std::endl;
    while (1) {
        PacketStruct packet = receivePacket();
        analysePacket(packet);
        if (clientConnected >= 1) {
            sendPosition(1, 1);
            sendPosition(2, 2);
        }
    }
}

/**
 * @brief Set the Port object
 *
 * @param port
 */

void Server::setPort(int port) noexcept { this->port = port; }

/**
 * @brief Set the Ip object
 *
 * @param ip
 */

void Server::setIp(std::string ip) noexcept { this->ip = ip; }

/**
 * @brief Set the Client Connected object
 *
 * @param clientConnected : number of client connected
 */

void Server::setClientConnected(int clientConnected) noexcept { this->clientConnected = clientConnected; }

/**
 * @brief Get the Port object
 *
 * @return int
 */

int Server::getPort() const noexcept { return port; }

/**
 * @brief Get the Ip object
 *
 * @return std::string
 */

std::string Server::getIp() const noexcept { return ip; }

/**
 * @brief Get the Client Connected object
 *
 * @return int
 */

int Server::getClientConnected() const noexcept { return clientConnected; }

/**
 * @brief receive a packet
 *
 * @return PacketStruct
 */

PacketStruct Server::receivePacket()
{
    PacketStruct packet;
    packet = socket.ReceivePacket();
    return packet;
}

/**
 * @brief send a packet
 *
 * @param packet
 * @return true
 * @return false
 */

bool Server::sendPacket(PacketStruct packet)
{
    socket.SendPacket(packet);
    return true;
}

/**
 * @brief Analyse the packet
 *
 * @param packet
 */

void Server::analysePacket(PacketStruct packet)
{
    IdentifyPackage identifyPackage(packet.packet);
    switch (identifyPackage.getIdHeader()) {
    case 1:
        analyseMessage(packet, identifyPackage);
        break;
    case 2:
        analyseEvent(packet, identifyPackage);
        break;
    case 3:
        analyseError(packet, identifyPackage);
        break;
    default:
        break;
    }
}

/**
 * @brief send a packet to all the client
 *
 * @param packet
 */

void Server::sendPacketToAll(PacketStruct packet)
{
    for (int i = 0; i < clientConnected; i++) {
        packet.ip = users[i].getIp();
        packet.port = users[i].getPort();
        sendPacket(packet);
    }
}

/**
 * @brief Analyse the message
 *
 * @param packet
 */

void Server::analyseMessage(PacketStruct packet, IdentifyPackage identifyPackage)
{
    if (identifyPackage.getIdMessage() == 1) {
        std::cout << "New client connected" << std::endl;
        if (checkConnectedUser(packet) == false && clientConnected < 2) {
            connectUser(packet);
        }
    }
    if (identifyPackage.getIdMessage() == 2) {
        std::cout << "Client ready" << std::endl;
    }
    if (identifyPackage.getIdMessage() == 3) {
        std::cout << "Client quit the game" << std::endl;
    }
    if (identifyPackage.getIdMessage() == 4) {
        std::cout << "Client disconnected" << std::endl;
        if (checkConnectedUser(packet) == true) {
            disconnectUser(packet);
        }
    }
}

/**
 * @brief Connect a user and add it to the list
 *
 * @param packet
 */

void Server::connectUser(PacketStruct packet)
{
    UserData user;
    if (clientConnected == 0) {
        user.setId(1);
        user.setX(100);
        user.setY(100);
    }
    else if (clientConnected == 1 && users[0].getId() == 1) {
        user.setId(2);
        user.setX(100);
        user.setY(200);
    }
    else {
        user.setId(1);
        user.setX(100);
        user.setY(100);
    }
    user.setIp(packet.ip);
    user.setPort(packet.port);
    std::cout << packet.port << std::endl;

    users.push_back(user);
    clientConnected++;
}

/**
 * @brief Disconnect a user and remove it from the list
 *
 * @param packet
 */

void Server::disconnectUser(PacketStruct packet)
{
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getIp() == packet.ip && users[i].getPort() == packet.port) {
            users.erase(users.begin() + i);
            clientConnected--;
        }
    }
}

bool Server::checkConnectedUser(PacketStruct packet)
{
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getIp() == packet.ip && users[i].getPort() == packet.port) {
            return (true);
        }
    }
    return (false);
}

/**
 * @brief Get the Id User object
 * @param packet : packet received by the server
 * @return int : id of the user who sent the packet
 */

int Server::getIdUser(PacketStruct packet)
{
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getIp() == packet.ip && users[i].getPort() == packet.port) {
            return (users[i].getId());
        }
    }
    return (0);
}

/**
 * @brief Analyse the event
 *
 * @param packet
 */

void Server::analyseEvent(PacketStruct packet, IdentifyPackage identifyPackage)
{
    if (checkConnectedUser(packet) == false)
        return;
    int id = getIdUser(packet);
    if (identifyPackage.getIdEvent() == 1) {
        users[id - 1].setX(users[id - 1].getX() - 10);
    }
    if (identifyPackage.getIdEvent() == 2) {
        users[id - 1].setX(users[id - 1].getX() + 10);
    }
    if (identifyPackage.getIdEvent() == 3) {
        users[id - 1].setY(users[id - 1].getY() - 10);
    }
    if (identifyPackage.getIdEvent() == 4) {
        users[id - 1].setY(users[id - 1].getY() + 10);
    }
}

/**
 * @brief Analyse the error
 *
 * @param packet
 */

void Server::analyseError(PacketStruct packet, IdentifyPackage identifyPackage)
{
    if (identifyPackage.getIdError() == 1) {
        std::cout << "Client sent a wrong packet" << std::endl;
    }
    if (identifyPackage.getIdError() == 2) {
        std::cout << "Client sent a wrong packet" << std::endl;
    }
    if (identifyPackage.getIdError() == 3) {
        std::cout << "Client sent a wrong packet" << std::endl;
    }
}

void Server::sendPosition(int id, int idType)
{
    if (clientConnected == 0)
        return;
    CreatePackage createPackage;
    createPackage.createGameSpritePackage(id, idType, users[id - 1].getX(), users[id - 1].getY());
    PacketStruct packet;
    packet.ip = users[id - 1].getIp();
    packet.port = users[id - 1].getPort();
    packet.packet = createPackage.getPacket();
    sendPacketToAll(packet);
}

#include "SfmlSocket.hpp"

/**
 * @brief Construct a new Sfml Socket:: Sfml Socket object
 */

SfmlSocket::SfmlSocket()
{
    ip = sf::IpAddress::getLocalAddress();
    port = 0;
    socket.setBlocking(false);
}

/**
 * @brief bind the socket to a port
 * @param port
 * @return true if the bind is successful
 * @return false if the bind failed
 */

bool SfmlSocket::BindSocket(unsigned short portArg)
{
    this->port = portArg;
    ip = sf::IpAddress::getLocalAddress();
    if (socket.bind(port) != sf::Socket::Done) {
        std::cout << "Error: Bind failed" << std::endl;
        return false;
    }
    else {
        std::cout << "Bind successful, port is: " << port << " and ip is: " << ip << std::endl;
        return true;
    }
}

/**
 * @brief get the port of the socket
 * @return size_t
 */

unsigned short SfmlSocket::getPort() { return port; }

/**
 * @brief get the ip of the socket
 * @return std::string
 */

std::string SfmlSocket::getIp()
{
    // convert ip to string
    std::string ip = this->ip.toString();
    return ip;
}

/**
 * @brief receive a Packet from the socket
 * @return PacketStruct struct with the Packet, ip and port
 */

PacketStruct SfmlSocket::ReceivePacket()
{
    PacketStruct packet;
    std::size_t received;
    sf::IpAddress sender;
    unsigned short port;

    if (socket.receive(packet.packet, sender, port) != sf::Socket::Done)
        return packet;
    packet.ip = sender.toString();
    packet.port = port;
    return packet;
}

/**
 * @brief send a packet to the socket
 * @param Packet struct with the packet, ip and port
 */

bool SfmlSocket::SendPacket(PacketStruct packet)
{
    sf::IpAddress ip(packet.ip);
    if (socket.send(packet.packet, ip, packet.port) != sf::Socket::Done) {
        return false;
    }
    else {
        return true;
    }
}
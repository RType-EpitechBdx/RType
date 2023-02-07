#include "Game.hpp"
#include <iostream>

void Game::clientLoop()
{
    int port = 4000;
    portServer = 55002;
    ipServer = obtainServerIp();
    if (socket.BindSocket(socket.getPort()) == false) {
        std::cout << "Bind failed" << std::endl;
        return;
    }
    CreatePackage createPackage;
    PacketStruct packet;
    packet.ip = ipServer;
    packet.port = portServer;
    createPackage.createMessagePackage(1);
    packet.packet = createPackage.getPacket();
    socket.SendPacket(packet);
    this->posplayerOne.x = 300;
    this->posplayerOne.y = 700;
    this->colorPlayerOne.r = 255;
    this->colorPlayerOne.b = 0;
    this->colorPlayerOne.g = 0;
    this->colorPlayerOne.a = 255;
    this->posPlayerTwo.x = 300;
    this->posPlayerTwo.y = 100;
    this->colorPlayerTwo.r = 0;
    this->colorPlayerTwo.b = 255;
    this->colorPlayerTwo.g = 0;
    this->colorPlayerTwo.a = 255;
    while (this->window.winIsOpen()) {
        clientEvent();
        this->window.clearWindow();
        this->window.displayGraphics(this->posplayerOne, this->colorPlayerOne);
        this->window.displayGraphics(this->posPlayerTwo, this->colorPlayerTwo);
        this->window.displayWindow();
        clientReceive();
    }
}

std::string Game::obtainServerIp()
{
    std::string ip;
    std::cout << "Enter the server ip: ";
    std::cin >> ip;
    return ip;
}

void Game::clientEvent()
{
    Input event = this->window.inputEvent();
    if (event == Input::Z_KEY)
        this->input = 3;
    else if (event == Input::S_KEY)
        this->input = 4;
    else if (event == Input::Q_KEY)
        this->input = 1;
    else if (event == Input::D_KEY)
        this->input = 2;
    else if (event == Input::ESCAPE) {
        std::cout << "Press ESCAPE" << std::endl;
        clientSendDisconnect();
        this->window.closeWindow();
    }
    else
        this->input = 0;
    clientSendEvent();
}

void Game::clientSendEvent()
{
    CreatePackage createPackage;
    createPackage.createEventPackage(this->input);
    PacketStruct packet;
    packet.ip = ipServer;
    packet.port = portServer;
    packet.packet = createPackage.getPacket();
    socket.SendPacket(packet);
}

void Game::clientReceive()
{
    PacketStruct packet;
    packet = socket.ReceivePacket();
    IdentifyPackage identifyPackage(packet.packet);
    if (identifyPackage.getIdHeader() == 2) {
        clientObtainCoord(identifyPackage);
    }
}

void Game::clientObtainCoord(IdentifyPackage identifyPackage)
{
    if (identifyPackage.getIdTypeSprite() == 1) {
        this->posplayerOne.x = identifyPackage.getPosX();
        this->posplayerOne.y = identifyPackage.getPosY();
    }
    else if (identifyPackage.getIdTypeSprite() == 2) {
        this->posPlayerTwo.x = identifyPackage.getPosX();
        this->posPlayerTwo.y = identifyPackage.getPosY();
    }
}

void Game::clientSendDisconnect()
{
    CreatePackage createPackage;
    createPackage.createMessagePackage(4);
    PacketStruct packet;
    packet.ip = ipServer;
    packet.port = portServer;
    packet.packet = createPackage.getPacket();
    socket.SendPacket(packet);
}
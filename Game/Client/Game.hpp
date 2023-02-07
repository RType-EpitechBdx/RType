#pragma once

#include "Color.hpp"
#include "CreatePackage.hpp"
#include "IdentifyPackage.hpp"
#include "Position.hpp"
#include "SfmlSocket.hpp"
#include "Window.hpp"

class Game {
    public:
    Game() = default;
    Game(Game const &other) noexcept = default;
    Game(Game &&other) noexcept = default;
    Game &operator=(Game const &other) noexcept = default;
    Game &operator=(Game &&other) noexcept = default;
    ~Game() noexcept = default;

    void clientLoop();

    private:
    void clientEvent();
    void clientObtainCoord(IdentifyPackage identifyPackage);
    void clientSendEvent();
    void clientReceive();
    void clientSendDisconnect();
    std::string obtainServerIp();
    int input;
    Window window;
    Position posplayerOne;
    Position posPlayerTwo;
    Color colorPlayerOne;
    Color colorPlayerTwo;
    SfmlSocket socket;
    std::string ipServer;
    int portServer;
};
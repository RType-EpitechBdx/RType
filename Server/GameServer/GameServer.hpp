#pragma once
#ifndef GAMESERVER_
#define GAMESERVER_

#include <iostream>
#include <string>
#include <vector>

class GameServer {
    public:
    GameServer() noexcept = default;
    GameServer(GameServer const &other) noexcept = default;
    GameServer(GameServer &&other) noexcept = default;
    GameServer &operator=(GameServer const &other) noexcept = default;
    GameServer &operator=(GameServer &&other) noexcept = default;
    ~GameServer() noexcept = default;

    private:
};

#endif /* !GAMESERVER_*/
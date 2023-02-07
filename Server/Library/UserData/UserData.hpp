#pragma once
#ifndef USERDATA_
#define USERDATA_

#include "PacketStruct.hpp"
#include <string>

/**
 * @brief UserData class is used to store the user's data
 * @param port is the port of the user
 * @param ip is the ip of the user
 */

class UserData {
    public:
    UserData();
    UserData(UserData const &other) = default;
    UserData(UserData &&other) noexcept = default;
    UserData &operator=(UserData const &other) = default;
    UserData &operator=(UserData &&other) noexcept = default;
    ~UserData() noexcept = default;

    void setPort(unsigned short port) noexcept;
    void setIp(std::string const &ip) noexcept;
    void setX(int x) noexcept;
    void setY(int y) noexcept;
    void setId(int id) noexcept;
    unsigned short getPort() const noexcept;
    std::string getIp() const noexcept;
    int getX() const noexcept;
    int getY() const noexcept;
    int getId() const noexcept;

    private:
    unsigned short port;
    std::string ip;
    int x;
    int y;
    int id;
};

#endif /* !UserData_*/
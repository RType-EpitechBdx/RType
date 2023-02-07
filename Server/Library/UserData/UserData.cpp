#include "UserData.hpp"

/**
 * @brief UserData class is used to store the user's data
 */

UserData::UserData()
{
    port = 0;
    ip = "";
    x = 50;
    y = 50;
    id = 0;
}

/**
 * @brief return the port of the user
 * @return unsigned short of the port
 */

unsigned short UserData::getPort() const noexcept { return port; }

/**
 * @brief set the port of the user
 * @param port
 */

void UserData::setPort(unsigned short port) noexcept { this->port = port; }

/**
 * @brief set the ip of the user
 * @param ip
 */

void UserData::setIp(std::string const &ip) noexcept { this->ip = ip; }

/**
 * @brief return the ip of the user
 * @return std::string of the ip
 */

std::string UserData::getIp() const noexcept { return ip; }

/**
 * @brief set the x of the user
 * @param x
 */

void UserData::setX(int x) noexcept { this->x = x; }

/**
 * @brief return the x of the user
 * @return int of the x
 */

int UserData::getX() const noexcept { return x; }

/**
 * @brief set the y of the user
 * @param y
 */

void UserData::setY(int y) noexcept { this->y = y; }

/**
 * @brief return the y of the user
 * @return int of the y
 */

int UserData::getY() const noexcept { return y; }

/**
 * @brief set the id of the user
 * @param id
 */

void UserData::setId(int id) noexcept { this->id = id; }

/**
 * @brief return the id of the user
 * @return int of the id
 */

int UserData::getId() const noexcept { return id; }
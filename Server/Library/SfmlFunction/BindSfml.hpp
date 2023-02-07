#pragma once
#ifndef BINDSFML_
#define BINDSFML_

#include <SFML/Network.hpp>

/**
 * @brief bind a socket to a port
 * @param port
 * @return true if the bind is successful
 * @return false if the bind failed
 */

class BindSfml {
    public:
    BindSfml() noexcept = default;
    BindSfml(BindSfml const &other) noexcept = default;
    BindSfml(BindSfml &&other) noexcept = default;
    BindSfml &operator=(BindSfml const &other) noexcept = default;
    BindSfml &operator=(BindSfml &&other) noexcept = default;
    ~BindSfml() noexcept = default;

    private:
};

#endif /* !BINDSFML_*/
#pragma once

#include <string>

#include "Color.hpp"
#include "Input.hpp"
#include "Position.hpp"
#include "Text.hpp"

/**
 * @brief Window Interface
 *
 */

class IWindow {
    public:
    IWindow() = default;
    IWindow(IWindow const &other) noexcept = delete;
    IWindow(IWindow &&other) noexcept = delete;
    IWindow &operator=(IWindow const &other) noexcept = delete;
    IWindow &operator=(IWindow &&other) noexcept = default;
    virtual ~IWindow() = default;

    virtual void displayGraphics(Position pos, Color color) = 0;
    virtual void writeText(Position pos, Text text, Color color) = 0;
    virtual void clearWindow() = 0;
    virtual void closeWindow() = 0;
    virtual void displayWindow() = 0;
    virtual bool winIsOpen() = 0;
    virtual Input inputEvent() = 0;

    private:
};
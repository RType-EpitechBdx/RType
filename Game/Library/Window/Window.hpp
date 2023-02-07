#pragma once

#include "IWindow.hpp"
#include "SFML/Graphics.hpp"

/**
 * @brief Window in SFML
 *
 */

class Window : public IWindow {
    public:
    Window();
    Window(Window const &other) noexcept = default;
    Window(Window &&other) noexcept = default;
    Window &operator=(Window const &other) noexcept = default;
    Window &operator=(Window &&other) noexcept = default;
    ~Window() noexcept = default;

    void displayGraphics(Position pos, Color color);
    void writeText(Position pos, Text text, Color color);
    void clearWindow();
    void closeWindow();
    void displayWindow();
    bool winIsOpen();
    Input inputEvent();

    private:
    sf::RenderWindow window;
};
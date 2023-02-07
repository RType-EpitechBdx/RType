#include "Window.hpp"

/**
 * @brief Construct a new Window:: Window object
 *
 */

Window::Window()
{
    window.setFramerateLimit(60);
    window.create(sf::VideoMode(1920, 1080), "RTYPE", sf::Style::Resize | sf::Style::Close);
}

/**
 * @brief Display a rectangle shape in the window
 *
 * @param pos
 * @param color
 */

void Window::displayGraphics(Position pos, Color color)
{
    sf::RectangleShape shape(sf::Vector2f(120, 50));
    shape.setPosition(pos.x, pos.y);
    sf::Color my_color(color.r, color.g, color.b);
    shape.setFillColor(my_color);
    window.draw(shape);
}

/**
 * @brief write a text in the window
 *
 * @param pos
 * @param text
 * @param color
 */

void Window::writeText(Position pos, Text text, Color color)
{
    sf::Font font;
    font.loadFromFile(text.font);
    sf::Text my_text(text.text, font);
    sf::Color my_color(color.r, color.g, color.b, color.a);

    my_text.setPosition(pos.x, pos.y);
    my_text.setCharacterSize(text.size);
    my_text.setFillColor(my_color);
    window.draw(my_text);
}

/**
 * @brief clear window to black color
 *
 */

void Window::clearWindow() { window.clear(sf::Color::Black); }

/**
 * @brief close the window
 *
 */

void Window::closeWindow() { window.close(); }

/**
 * @brief display the window
 *
 */

void Window::displayWindow() { window.display(); }

/**
 * @brief loop that keep window open
 *
 * @return true
 * @return false
 */

bool Window::winIsOpen() { return window.isOpen(); }

/**
 * @brief Event function that return an Input to manage event
 *
 * @return Input
 */

Input Window::inputEvent()
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return (Input::QUIT);
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                return (Input::UP_ARROW);
            if (event.key.code == sf::Keyboard::Down)
                return (Input::DOWN_ARROW);
            if (event.key.code == sf::Keyboard::Left)
                return (Input::LEFT_ARROW);
            if (event.key.code == sf::Keyboard::Right)
                return (Input::RIGHT_ARROW);
            if (event.key.code == sf::Keyboard::Enter)
                return (Input::ENTER);
            if (event.key.code == sf::Keyboard::Space)
                return (Input::SPACE);
            if (event.key.code == sf::Keyboard::Escape)
                return (Input::ESCAPE);
            if (event.key.code == sf::Keyboard::Backspace)
                return (Input::BACKSPACE);
            if (event.key.code == sf::Keyboard::A)
                return (Input::A_KEY);
            if (event.key.code == sf::Keyboard::B)
                return (Input::B_KEY);
            if (event.key.code == sf::Keyboard::C)
                return (Input::C_KEY);
            if (event.key.code == sf::Keyboard::D)
                return (Input::D_KEY);
            if (event.key.code == sf::Keyboard::E)
                return (Input::E_KEY);
            if (event.key.code == sf::Keyboard::F)
                return (Input::F_KEY);
            if (event.key.code == sf::Keyboard::G)
                return (Input::G_KEY);
            if (event.key.code == sf::Keyboard::H)
                return (Input::H_KEY);
            if (event.key.code == sf::Keyboard::I)
                return (Input::I_KEY);
            if (event.key.code == sf::Keyboard::J)
                return (Input::J_KEY);
            if (event.key.code == sf::Keyboard::K)
                return (Input::K_KEY);
            if (event.key.code == sf::Keyboard::L)
                return (Input::L_KEY);
            if (event.key.code == sf::Keyboard::M)
                return (Input::M_KEY);
            if (event.key.code == sf::Keyboard::N)
                return (Input::N_KEY);
            if (event.key.code == sf::Keyboard::O)
                return (Input::O_KEY);
            if (event.key.code == sf::Keyboard::P)
                return (Input::P_KEY);
            if (event.key.code == sf::Keyboard::Q)
                return (Input::Q_KEY);
            if (event.key.code == sf::Keyboard::R)
                return (Input::R_KEY);
            if (event.key.code == sf::Keyboard::S)
                return (Input::S_KEY);
            if (event.key.code == sf::Keyboard::T)
                return (Input::T_KEY);
            if (event.key.code == sf::Keyboard::U)
                return (Input::U_KEY);
            if (event.key.code == sf::Keyboard::V)
                return (Input::V_KEY);
            if (event.key.code == sf::Keyboard::W)
                return (Input::W_KEY);
            if (event.key.code == sf::Keyboard::X)
                return (Input::X_KEY);
            if (event.key.code == sf::Keyboard::Y)
                return (Input::Y_KEY);
            if (event.key.code == sf::Keyboard::Z)
                return (Input::Z_KEY);
            if (event.key.code == sf::Keyboard::F1)
                return (Input::F1);
            if (event.key.code == sf::Keyboard::F2)
                return (Input::F2);
            if (event.key.code == sf::Keyboard::F3)
                return (Input::F3);
            if (event.key.code == sf::Keyboard::F4)
                return (Input::F4);
            if (event.key.code == sf::Keyboard::F5)
                return (Input::F5);
            if (event.key.code == sf::Keyboard::F6)
                return (Input::F6);
            if (event.key.code == sf::Keyboard::F7)
                return (Input::F7);
            if (event.key.code == sf::Keyboard::F8)
                return (Input::F8);
            if (event.key.code == sf::Keyboard::F9)
                return (Input::F9);
            if (event.key.code == sf::Keyboard::F10)
                return (Input::F10);
            if (event.key.code == sf::Keyboard::F11)
                return (Input::F11);
            if (event.key.code == sf::Keyboard::F12)
                return (Input::F12);
        }
    }
    return (Input::EVENT_NULL);
}
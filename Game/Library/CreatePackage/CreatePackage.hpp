#pragma once
#ifndef CREATEPACKAGE_
#define CREATEPACKAGE_

#include <SFML/Network.hpp>

class CreatePackage {
    public:
    CreatePackage() = default;
    CreatePackage(CreatePackage const &other) noexcept = default;
    CreatePackage(CreatePackage &&other) noexcept = default;
    CreatePackage &operator=(CreatePackage const &other) noexcept = default;
    CreatePackage &operator=(CreatePackage &&other) noexcept = default;
    ~CreatePackage() noexcept = default;

    void createMessagePackage(sf::Uint8 idMessage);
    void createEventPackage(sf::Uint8 idEvent);
    void createErrorPackage(sf::Uint8 idError);
    sf::Packet getPacket() const;

    struct IdHeader {
        sf::Uint8 id;
    };
    struct Message {
        sf::Uint8 idMessage;
    };
    struct Event {
        sf::Uint8 idEvent;
    };
    struct Error {
        sf::Uint8 idError;
    };

    private:
    void createIdHeader(sf::Uint8 id);
    sf::Packet packet;
};

#endif /* !CREATEPACKAGE_*/
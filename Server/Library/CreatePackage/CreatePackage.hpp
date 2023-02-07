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
    void createGameSpritePackage(sf::Uint8 idSprite, sf::Uint8 idType, sf::Uint32 posX, sf::Uint32 posY);
    void createErrorPackage(sf::Uint8 idError);
    sf::Packet getPacket() const;

    struct IdHeader {
        sf::Uint8 id;
    };
    struct Message {
        sf::Uint8 idMessage;
    };
    struct GameSprite {
        sf::Uint8 idSprite;
        sf::Uint8 idTypeSprite;
        sf::Uint32 posX;
        sf::Uint32 posY;
    };
    struct Error {
        sf::Uint8 idError;
    };

    private:
    void createIdHeader(sf::Uint8 id);
    sf::Packet packet;
};

#endif /* !CREATEPACKAGE_*/
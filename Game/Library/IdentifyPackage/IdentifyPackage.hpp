#pragma once
#ifndef IDENTIFYPACKAGE_
#define IDENTIFYPACKAGE_

#include <SFML/Network.hpp>

class IdentifyPackage {
    public:
    IdentifyPackage(sf::Packet packet);
    IdentifyPackage(IdentifyPackage const &other) = default;
    IdentifyPackage(IdentifyPackage &&other) noexcept = default;
    IdentifyPackage &operator=(IdentifyPackage const &other) noexcept = default;
    IdentifyPackage &operator=(IdentifyPackage &&other) noexcept = default;
    ~IdentifyPackage() noexcept = default;

    sf::Uint8 getIdHeader() const;
    sf::Uint8 getIdMessage() const;
    sf::Uint8 getIdSprite() const;
    sf::Uint8 getIdTypeSprite() const;
    sf::Uint32 getPosX() const;
    sf::Uint32 getPosY() const;
    sf::Uint8 getIdError() const;

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
    sf::Packet packet;
    IdHeader idHeader;
    Message message;
    GameSprite gameSprite;
    Error error;
};

#endif /* !IDENTIFYPACKAGE_*/
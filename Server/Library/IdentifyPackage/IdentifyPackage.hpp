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
    sf::Uint8 getIdEvent() const;
    sf::Uint8 getIdError() const;

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
    sf::Packet packet;
    IdHeader idHeader;
    Message message;
    Event event;
    Error error;
};

#endif /* !IDENTIFYPACKAGE_*/
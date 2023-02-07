/*
** EPITECH PROJECT, 2023
** tek3
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

struct position
{
    int x;
    int y;
};

class ComponentHp {
    public:
        ComponentHp() = default;
        ~ComponentHp() = default;
        int GetHp() const;
    protected:
        int hp;
};

class ComponentAttack {
    public:
        ComponentAttack() = default;
        ~ComponentAttack() = default;
        int GetAttack() const;
    protected:
        int attack;
};

class ComponentVelocity {
    public:
        ComponentVelocity() = default;
        ~ComponentVelocity() = default;
        int GetVelocity() const;
    protected:
        int velocity;
};

class ComponentAcceleration {
    public:
        ComponentAcceleration() = default;
        ~ComponentAcceleration() = default;
        int GetAcceleration() const;
    protected:
        int acceleration;
};

class ComponentPosition {
    public:
        ComponentPosition() = default;
        ~ComponentPosition() = default;
        position GetPosition() const;
    protected:
        position position;
};

#endif /* !COMPONENT_HPP_ */

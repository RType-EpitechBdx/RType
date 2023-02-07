/*
** EPITECH PROJECT, 2023
** tek3
** File description:
** Component
*/

#include "Component.hpp"

int ComponentHp::GetHp() const
{
    return hp;
}

int ComponentAttack::GetAttack() const
{
    return attack;
}

int ComponentVelocity::GetVelocity() const
{
    return velocity;
}

int ComponentAcceleration::GetAcceleration() const
{
    return acceleration;
}

position ComponentPosition::GetPosition() const
{
    return position;
}



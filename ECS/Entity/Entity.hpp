/*
** EPITECH PROJECT, 2023
** tek3
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include "Entity.hpp"
    #include <iostream>
    #include <vector>

    class Entity {
        public:
            Entity(std::size_t entity);
            ~Entity();

            operator std::size_t() const { return entity; }
        private:
            std::size_t entity;
            std::vector<IComponent> components;
    };


#endif /* !ENTITY_HPP_ */

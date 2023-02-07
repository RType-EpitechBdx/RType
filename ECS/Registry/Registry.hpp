/*
** EPITECH PROJECT, 2023
** tek3
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_

#include <typeindex>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "../SparseArrays/SparseArrays.hpp"

class Registry {
    public:
        Registry();
        ~Registry() = default;

        


        std::unordered_map<std::type_index, std::string>&getTypeNames() { return type_names; }

    private:
        std::unordered_map<std::type_index, std::string> type_names;
};

#endif /* !REGISTRY_HPP_ */

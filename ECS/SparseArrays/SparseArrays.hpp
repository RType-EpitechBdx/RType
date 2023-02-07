/*
** EPITECH PROJECT, 2023
** tek3
** File description:
** SparseArrays
*/

#ifndef SPARSEARRAYS_HPP_
#define SPARSEARRAYS_HPP_

#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <optional>
#include <algorithm>
#include <iterator>
#include "../Component/Component.hpp"

template <typename Component> // You can also mirror the definition of std :: vector , that takes an additional allocator .

class SparseArrays {
    public :
        using value_type = Component;  // remettre les std::optional quand il marchera
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector < value_type > ;
        using size_type = typename container_t::size_type ;
        using iterator = typename container_t::iterator ;
        using const_iterator = typename container_t::const_iterator ;

        SparseArrays() noexcept = default;
        ~SparseArrays() noexcept = default;
        SparseArrays (SparseArrays const &) noexcept = delete; // copy constructor
        SparseArrays (SparseArrays &&)  noexcept = default; // move constructor

        SparseArrays & operator =( SparseArrays const &)  noexcept = delete; // copy assignment operator
        SparseArrays & operator =( SparseArrays &&) noexcept = default; // move assignment operator

        reference_type operator[](size_t idx) {
            return data[idx];
        };
        const_reference_type operator[](size_t idx) const {
            return data[idx];
        };
        iterator begin () {
            return data.begin();
        };
        const_iterator begin () const {
            return data.begin();
        };
        const_iterator cbegin () const {
            return data.cbegin();
        };
        iterator end () {
            return data.end();
        };
        const_iterator end () const {
            return data.end();
        };
        const_iterator cend () const {
            return data.cend();
        }
        size_type size () const {
            return data.size();
        };
        reference_type insert_at ( size_type pos , Component const & c) {
            return *data.insert(begin() + pos, c);
        }
        reference_type insert_at ( size_type pos , Component && c) {
            return *data.insert(begin() + pos, std::move(c));
        }
        template < class ... Params >
        reference_type emplace_at ( size_type pos , Params &&...) ;
        void erase ( size_type pos ) {
            data.erase(begin() + pos);
        }
        size_type get_index ( value_type const & c) const {
            return std::distance(begin(), std::find(begin(), end(), c));
        }

    private :
        std::vector <Component> data;
};

#endif /* !SPARSEARRAYS_HPP_ */
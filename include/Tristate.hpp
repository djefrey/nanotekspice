/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Tristate
*/

#pragma once

#include <ostream>
#include <exception>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = (false),
        TRUE = (true),
    };

    class InvalidStateError : public std::exception {};

    class Gates {
        public:
            static Tristate  not_gate(Tristate a);

            static Tristate  and_gate(Tristate a, Tristate b);
            static Tristate   or_gate(Tristate a, Tristate b);
            static Tristate nand_gate(Tristate a, Tristate b);
            static Tristate  nor_gate(Tristate a, Tristate b);
            static Tristate  xor_gate(Tristate a, Tristate b);

            static Tristate get_state_from_char(char c);

            static std::size_t statesToInt(Tristate states[], std::size_t nbStates);
    };

    std::ostream &operator<<(std::ostream &s, Tristate value);
}
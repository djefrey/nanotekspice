/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Tristate
*/

#pragma once

#include <ostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = (false),
        TRUE = (true),
    };

    Tristate  not_gate(Tristate a);

    Tristate  and_gate(Tristate a, Tristate b);
    Tristate   or_gate(Tristate a, Tristate b);
    Tristate nand_gate(Tristate a, Tristate b);
    Tristate  nor_gate(Tristate a, Tristate b);
    Tristate  xor_gate(Tristate a, Tristate b);

    Tristate get_state_from_char(char c);
    std::ostream &operator<<(std::ostream &s, Tristate value);
}
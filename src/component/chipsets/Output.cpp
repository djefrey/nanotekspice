/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Output
*/

#include <iostream>
#include "component/chipsets/Output.hpp"

nts::Output::Output() : Component(OUTPUT, "Output", 1)
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    (void) pin;
    return UNDEFINED;
}

void nts::Output::simulate(std::size_t tick)
{
    Connection conn = this->getConnectionAt(0);
    Tristate state;

    if (conn.component) {
        for (size_t t = 0; t < tick; t++) {
            state = conn.component->compute(conn.toPin);
            std::cout << "Output :" << state << std::endl;
        }
    }
}


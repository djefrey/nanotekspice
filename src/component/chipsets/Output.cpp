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

void nts::Output::simulate(std::size_t tick)
{
    Connection conn = this->getConnectionAt(0);
    Tristate state;

    (void) tick;
    clearUpdatedPins();
    if (conn.component) {
        state = conn.component->compute(conn.pin);
        std::cout << "Output :" << state << std::endl;
    }
}


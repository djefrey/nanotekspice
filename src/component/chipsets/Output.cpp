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

    (void) tick;
    clearUpdatedPins();
    if (conn.component)
        setStateAt(0, conn.component->compute(conn.pin), false);
}

nts::Tristate nts::Output::getValue()
{
    return compute(0);
}
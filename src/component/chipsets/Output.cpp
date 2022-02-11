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

void nts::Output::update()
{
    Connection conn = this->getConnectionAt(0);
    Tristate state;

    if (conn.component) {
        state = conn.component->compute(conn.toPin);
        std::cout << "Output :" << state << std::endl;
    }
}


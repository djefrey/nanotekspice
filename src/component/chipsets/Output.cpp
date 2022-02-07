/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Output
*/

#include "component/chipsets/Output.hpp"

nts::Output::Output() : Component("Output", 1)
{
}

void nts::Output::simulate(std::size_t tick)
{
    (void) tick;
}

nts::Tristate nts::Output::getState()
{
    return compute(0);
}

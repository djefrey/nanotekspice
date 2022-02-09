/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#include "component/chipsets/TrueFalse.hpp"

nts::TrueInput::TrueInput() : Component(INPUT, "TrueInput", 1)
{
}

nts::Tristate nts::TrueInput::compute(std::size_t pin)
{
    (void) pin;
    return nts::Tristate::TRUE;
}

void nts::TrueInput::simulate(std::size_t tick)
{
    (void) tick;
}

nts::FalseInput::FalseInput() : Component(INPUT, "FalseInput", 1)
{
}

nts::Tristate nts::FalseInput::compute(std::size_t pin)
{
    (void) pin;
    return nts::Tristate::FALSE;
}

void nts::FalseInput::simulate(std::size_t tick)
{
    (void) tick;
}

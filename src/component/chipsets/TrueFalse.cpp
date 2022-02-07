/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#include "component/chipsets/TrueFalse.hpp"

nts::TrueInput::TrueInput() : Component("TrueInput", 1)
{
    updateState(TRUE, 0);
}

void nts::TrueInput::simulate(std::size_t tick)
{
    (void) tick;
    updateState(TRUE, 0);
}



nts::FalseInput::FalseInput() : Component("FalseInput", 1)
{
    updateState(FALSE, 0);
}

void nts::FalseInput::simulate(std::size_t tick)
{
    (void) tick;
    updateState(FALSE, 0);
}
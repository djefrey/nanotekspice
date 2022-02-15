/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Clock
*/

#include "component/inputs/Clock.hpp"

nts::Clock::Clock() : InputComponent("Clock")
{
    _state = FALSE;
}

void nts::Clock::simulate(std::size_t tick)
{
    InputComponent::simulate(tick);
    this->_state = not_gate(this->_state);
}
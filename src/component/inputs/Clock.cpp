/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Clock
*/

#include "component/inputs/Clock.hpp"

nts::Clock::Clock() : InputComponent("Clock")
{
}

void nts::Clock::update()
{
    InputComponent::update();
    this->_state = not_gate(this->_state);
}
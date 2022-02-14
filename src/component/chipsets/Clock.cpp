/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Clock
*/

#include "component/chipsets/Clock.hpp"

nts::Clock::Clock() : Component(INPUT, "Clock", 1)
{
}

void nts::Clock::simulate(std::size_t tick)
{
    (void) tick;
    clearUpdatedPins();
    setStateAt(0, this->_state);
    this->_state = not_gate(this->_state);
}
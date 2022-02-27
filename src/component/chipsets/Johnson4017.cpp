/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Johnson4017
*/

#include "component/chipsets/Johnson4017.hpp"

nts::Johnson4017::Johnson4017() : Component("Johnson4017", 15)
{
}

void nts::Johnson4017::simulate(std::size_t tick)
{
    Tristate clock0 = readStateAt(13);
    Tristate clock1 = readStateAt(12);
    Tristate reset = readStateAt(14);
    Tristate andClocks = and_gate(clock0, not_gate(clock1));

    (void) tick;
    clearUpdatedPins();
    if (reset == TRUE) {
        _count = 0;
        updatePins();
    } else if (andClocks == TRUE) {
        _count++;
        if (_count == 10)
            _count = 0;
        updatePins();
    }
}

void nts::Johnson4017::updatePins()
{
    this->setStateAt(2,  _count == 0 ? TRUE : FALSE, true);
    this->setStateAt(1,  _count == 1 ? TRUE : FALSE, true);
    this->setStateAt(3,  _count == 2 ? TRUE : FALSE, true);
    this->setStateAt(6,  _count == 3 ? TRUE : FALSE, true);
    this->setStateAt(9,  _count == 4 ? TRUE : FALSE, true);
    this->setStateAt(0,  _count == 5 ? TRUE : FALSE, true);
    this->setStateAt(4,  _count == 6 ? TRUE : FALSE, true);
    this->setStateAt(5,  _count == 7 ? TRUE : FALSE, true);
    this->setStateAt(8,  _count == 8 ? TRUE : FALSE, true);
    this->setStateAt(10, _count == 9 ? TRUE : FALSE, true);
    this->setStateAt(11, _count <  5 ? TRUE : FALSE, true);
}
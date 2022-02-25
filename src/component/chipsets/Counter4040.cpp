/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Counter4040
*/

#include "component/chipsets/Counter4040.hpp"

nts::Counter4040::Counter4040() : Component("4040", 16)
{
}

void nts::Counter4040::simulate(std::size_t tick)
{
    Tristate clock = readStateAt(9);
    Tristate reset = readStateAt(10);

    (void) tick;
    clearUpdatedPins();
    if (reset == TRUE) {
        _count = 0;
        updatePins();
    } else if (clock == FALSE) {
        _count++;
        updatePins();
    }
}

void nts::Counter4040::updatePins()
{
    this->setStateAt(8,  _count & 0x001 ? TRUE : FALSE, true);
    this->setStateAt(6,  _count & 0x002 ? TRUE : FALSE, true);
    this->setStateAt(5,  _count & 0x004 ? TRUE : FALSE, true);
    this->setStateAt(4,  _count & 0x008 ? TRUE : FALSE, true);
    this->setStateAt(2,  _count & 0x010 ? TRUE : FALSE, true);
    this->setStateAt(1,  _count & 0x020 ? TRUE : FALSE, true);
    this->setStateAt(3,  _count & 0x040 ? TRUE : FALSE, true);
    this->setStateAt(12, _count & 0x080 ? TRUE : FALSE, true);
    this->setStateAt(11, _count & 0x100 ? TRUE : FALSE, true);
    this->setStateAt(13, _count & 0x200 ? TRUE : FALSE, true);
    this->setStateAt(14, _count & 0x400 ? TRUE : FALSE, true);
    this->setStateAt(0,  _count & 0x800 ? TRUE : FALSE, true);
}
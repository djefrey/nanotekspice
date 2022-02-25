/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FlipFlop4013
*/

#include "component/chipsets/FlipFlop4013.hpp"

nts::FlipFlop4013::FlipFlop4013() : Component("4013", 14)
{
}

void nts::FlipFlop4013::simulate(std::size_t tick)
{
    const FlipFlopPins ff1 = { 0,  1,  2, 3, 4, 5};
    const FlipFlopPins ff2 = {12, 11, 10, 9, 8, 7};

    (void) tick;
    clearUpdatedPins();
    updateFlipFlop(ff1);
    updateFlipFlop(ff2);
}

void nts::FlipFlop4013::updateFlipFlop(const FlipFlopPins &pins)
{
    Tristate data = readStateAt(pins.data);
    Tristate clock = readStateAt(pins.clock);
    Tristate reset = readStateAt(pins.reset);
    Tristate set = readStateAt(pins.set);

    clearUpdatedPins();
    if (reset == TRUE && set == TRUE) {
        this->setStateAt(pins.Q, TRUE, true);
        this->setStateAt(pins.notQ, TRUE, true);
    } else if (reset == TRUE) {
        this->setStateAt(pins.Q, FALSE, true);
        this->setStateAt(pins.notQ, TRUE, true);
    } else if (set == TRUE) {
        this->setStateAt(pins.Q, TRUE, true);
        this->setStateAt(pins.notQ, FALSE, true);
    } else {
        if (clock == TRUE) {
            if (data == FALSE) {
                this->setStateAt(pins.Q, FALSE, true);
                this->setStateAt(pins.notQ, TRUE, true);
            } else if (data == TRUE) {
                this->setStateAt(pins.Q, TRUE, true);
                this->setStateAt(pins.notQ, FALSE, true);
            }
        }
    }
}
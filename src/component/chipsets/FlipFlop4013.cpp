/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FlipFlop4013
*/

#include "component/chipsets/FlipFlop4013.hpp"

nts::FlipFlop4013::FlipFlop4013() : Component("4013", 14)
{
    const std::size_t inputs[] = {2, 3, 4, 5, 10, 9, 8, 7};
    const std::size_t outputs[] = {0, 1, 12, 11};

    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 4; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::FlipFlop4013::update()
{
    const FlipFlopPins ff1 = { 0,  1,  2, 3, 4, 5};
    const FlipFlopPins ff2 = {12, 11, 10, 9, 8, 7};

    updateFlipFlop(ff1);
    updateFlipFlop(ff2);
}

void nts::FlipFlop4013::updateFlipFlop(const FlipFlopPins &pins)
{
    Tristate data = readStateAt(pins.data);
    Tristate clock = readStateAt(pins.clock);
    Tristate reset = readStateAt(pins.reset);
    Tristate set = readStateAt(pins.set);

    if (reset == TRUE && set == TRUE) {
        this->setStateAt(pins.Q, TRUE);
        this->setStateAt(pins.notQ, TRUE);
    } else if (reset == TRUE) {
        this->setStateAt(pins.Q, FALSE);
        this->setStateAt(pins.notQ, TRUE);
    } else if (set == TRUE) {
        this->setStateAt(pins.Q, TRUE);
        this->setStateAt(pins.notQ, FALSE);
    } else {
        if (clock == TRUE) {
            this->setStateAt(pins.Q, data);
            this->setStateAt(pins.notQ, Gates::not_gate(data));
        }
    }
}
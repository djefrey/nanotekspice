/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Nor4001
*/

#include "component/chipsets/Nor4001.hpp"

nts::Nor4001::Nor4001() : Component("4001", 14)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};

    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 4; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Nor4001::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};
    Tristate stateA;
    Tristate stateB;

    (void) tick;
    clearUpdatedPins();
    for (std::size_t i = 0; i < 4; i++) {
        stateA = readStateAt(inputs[i * 2]);
        stateB = readStateAt(inputs[i * 2 + 1]);
        this->setStateAt(outputs[i], nor_gate(stateA, stateB), true);
    }
}
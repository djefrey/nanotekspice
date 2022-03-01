/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Nand4011
*/

#include "component/chipsets/Nand4011.hpp"

nts::Nand4011::Nand4011() : Component("4011", 14)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};

    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 4; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Nand4011::simulate(std::size_t tick)
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
        this->setStateAt(outputs[i], nand_gate(stateA, stateB), true);
    }
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Chipset4081
*/

#include <map>
#include "component/chipsets/And4081.hpp"

nts::And4081::And4081() : Component("4081", 14)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};

    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 4; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::And4081::update()
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};
    Tristate stateA;
    Tristate stateB;

    for (std::size_t s = 0; s < 4; s++) {
        for (std::size_t i = 0; i < 4; i++) {
            stateA = readStateAt(inputs[i * 2]);
            stateB = readStateAt(inputs[i * 2 + 1]);
            this->setStateAt(outputs[i], and_gate(stateA, stateB));
        }
    }
}

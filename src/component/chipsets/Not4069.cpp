/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Chipset4081
*/

#include <map>
#include "component/chipsets/Not4069.hpp"

nts::Not4069::Not4069() : Component("4069", 14)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};

    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 4; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Not4069::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {0, 2, 4, 8, 10, 12};
    const std::size_t outputs[] = {1, 3, 5, 7, 9, 11};
    Tristate state;

    (void) tick;
    clearUpdatedPins();
    for (std::size_t i = 0; i < 6; i++) {
        state = readStateAt(inputs[i]);
        this->setStateAt(outputs[i], not_gate(state), true);
    }
}

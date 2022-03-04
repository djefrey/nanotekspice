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
    const std::size_t inputs[] = {0, 2, 4, 8, 10, 12};
    const std::size_t outputs[] = {1, 3, 5, 7, 9, 11};

    for (std::size_t i = 0; i < 6; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 6; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Not4069::update()
{
    const std::size_t inputs[] = {0, 2, 4, 8, 10, 12};
    const std::size_t outputs[] = {1, 3, 5, 7, 9, 11};
    Tristate state;

    for (std::size_t s = 0; s < 6; s++) {
        for (std::size_t i = 0; i < 6; i++) {
            state = readStateAt(inputs[i]);
            this->setStateAt(outputs[i], Gates::not_gate(state));
        }
    }
}

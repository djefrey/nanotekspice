/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Chipset4081
*/

#include "component/chipsets/Chipset4081.hpp"

nts::Chipset4081::Chipset4081() : Component("4081", 14)
{
}

void nts::Chipset4081::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {0, 1,  4, 5,  7, 8,  11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};
    Tristate a = UNDEFINED;
    Tristate b = UNDEFINED;

    for (std::size_t actualTick = 0; actualTick < tick; actualTick++) {
        for (int i = 0; i < 4; i++) {
            a = compute(inputs[i * 2]);
            b = compute(inputs[i * 2 + 1]);
            updateState(and_gate(a, b), outputs[i]);
        }
    }
}

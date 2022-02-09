/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Chipset4081
*/

#include <map>
#include "component/chipsets/Chipset4081.hpp"

nts::Chipset4081::Chipset4081() : Component(COMPONENT, "4081", 14)
{
}

nts::Tristate nts::Chipset4081::compute(std::size_t pin)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};
    nts::Connection connA;
    nts::Connection connB;
    Tristate stateA;
    Tristate stateB;

    for (std::size_t i = 0; i < 4; i++) {
        if (outputs[i] == pin) {
            connA = this->getConnectionAt(inputs[i * 2]);
            connB = this->getConnectionAt(inputs[i * 2 + 1]);
            stateA = connA.component ? connA.component->compute(connA.toPin) : UNDEFINED;
            stateB = connA.component ? connB.component->compute(connB.toPin) : UNDEFINED;
            return and_gate(stateA, stateB);
        }
    }
    return UNDEFINED;
}

void nts::Chipset4081::simulate(std::size_t tick)
{
    const std::size_t outputs[] = {2, 3, 9, 10};

    for (std::size_t t = 0; t < tick; t++) {
        for (std::size_t i = 0; i < 4; i++)
            this->compute(outputs[i]);
    }
}

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

void nts::Chipset4081::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {0, 1, 4, 5, 7, 8, 11, 12};
    const std::size_t outputs[] = {2, 3, 9, 10};
    nts::Connection connA;
    nts::Connection connB;
    Tristate stateA;
    Tristate stateB;

    (void) tick;
    clearUpdatedPins();
    for (std::size_t i = 0; i < 4; i++) {
        connA = this->getConnectionAt(inputs[i * 2]);
        connB = this->getConnectionAt(inputs[i * 2 + 1]);
        stateA = connA.component ? connA.component->compute(connA.pin) : UNDEFINED;
        stateB = connA.component ? connB.component->compute(connB.pin) : UNDEFINED;
        this->setStateAt(outputs[i], and_gate(stateA, stateB));
    }
}

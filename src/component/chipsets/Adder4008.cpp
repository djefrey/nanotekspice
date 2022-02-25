/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Adder4008
*/

#include "component/chipsets/Adder4008.hpp"

nts::Adder4008::Adder4008() : Component("4008", 16)
{
}

void nts::Adder4008::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {6, 5, 4, 3, 2, 1, 0, 14};
    const std::size_t outputs[] = {9, 10, 11, 12};
    Tristate stateA;
    Tristate stateB;
    Tristate c = readStateAt(8);
    std::tuple<Tristate, Tristate> result;

    (void) tick;
    clearUpdatedPins();
    for (std::size_t i = 0; i < 4; i++) {
        stateA = readStateAt(inputs[i * 2]);
        stateB = readStateAt(inputs[i * 2 + 1]);
        result = add(stateA, stateB, c);
        this->setStateAt(outputs[i], std::get<0>(result), true);
        c = std::get<1>(result);
    }
    this->setStateAt(13, c, true);
}

std::tuple<nts::Tristate, nts::Tristate> nts::Adder4008::add(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    Tristate XorAB = xor_gate(a, b);
    Tristate XorS = xor_gate(XorAB, c);
    Tristate AndABS = and_gate(XorAB, c);
    Tristate AndAB = and_gate(a, b);
    Tristate OrCout = or_gate(AndABS, AndAB);
    return (std::make_tuple<Tristate, Tristate>(std::move(XorS), std::move(OrCout)));
}
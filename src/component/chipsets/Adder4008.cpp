/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Adder4008
*/

#include "component/chipsets/Adder4008.hpp"

nts::Adder4008::Adder4008() : Component("4008", 16)
{
    const std::size_t inputs[] = {8, 6, 5, 4, 3, 2, 1, 0, 14};
    const std::size_t outputs[] = {9, 10, 11, 12, 13};

    for (std::size_t i = 0; i < 9; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 5; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Adder4008::update()
{
    const std::size_t inputs[] = {6, 5, 4, 3, 2, 1, 0, 14};
    const std::size_t outputs[] = {9, 10, 11, 12};
    Tristate c = readStateAt(8);
    std::tuple<Tristate, Tristate> result;
    Tristate stateA;
    Tristate stateB;

    for (std::size_t i = 0; i < 4; i++) {
        stateA = readStateAt(inputs[i * 2]);
        stateB = readStateAt(inputs[i * 2 + 1]);
        result = add(stateA, stateB, c);
        this->setStateAt(outputs[i], std::get<0>(result));
        c = std::get<1>(result);
    }
    this->setStateAt(13, c);
}

std::tuple<nts::Tristate, nts::Tristate> nts::Adder4008::add(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    Tristate XorAB = Gates::xor_gate(a, b);
    Tristate XorS = Gates::xor_gate(XorAB, c);
    Tristate AndABS = Gates::and_gate(XorAB, c);
    Tristate AndAB = Gates::and_gate(a, b);
    Tristate OrCout = Gates::or_gate(AndABS, AndAB);

    return (std::make_tuple<Tristate, Tristate>(std::move(XorS), std::move(OrCout)));
}
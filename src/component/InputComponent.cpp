/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** InputComponent
*/

#include "component/InputComponent.hpp"

nts::InputComponent::InputComponent(std::string model) : Component(model, 1)
{
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void) tick;
    clearUpdatedPins();
    this->setStateAt(0, _state, true);
}

nts::Tristate nts::InputComponent::getValue()
{
    return compute(0);
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _state = value;
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** InputComponent
*/

#include "component/InputComponent.hpp"

nts::InputComponent::InputComponent(std::string model) : Component(model, 1)
{
    setPinTypeAt(0, OUTPUT);
}

void nts::InputComponent::update()
{
    this->setStateAt(0, _state);
}

nts::Tristate nts::InputComponent::getValue()
{
    return getStateAt(0);
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _state = value;
}
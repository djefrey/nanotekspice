/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Output
*/

#include <iostream>
#include "component/OutputComponent.hpp"

nts::OutputComponent::OutputComponent() : Component("Output", 1)
{
    setPinTypeAt(0, INPUT);
}

nts::OutputComponent::OutputComponent(std::string model, std::size_t nbPins) : Component(model, nbPins)
{
}

void nts::OutputComponent::update()
{
    readStateAt(0);
}

nts::Tristate nts::OutputComponent::getValue()
{
    return getStateAt(0);
}
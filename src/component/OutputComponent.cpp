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
}

void nts::OutputComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::OutputComponent::getValue()
{
    return compute(0);
}
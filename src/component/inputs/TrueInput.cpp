/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#include "component/inputs/TrueInput.hpp"

nts::TrueInput::TrueInput() : InputComponent("TrueInput")
{
}

void nts::TrueInput::update()
{
    _state = TRUE;
    InputComponent::update();
}
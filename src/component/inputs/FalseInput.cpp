/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FalseInput
*/

#include "component/inputs/FalseInput.hpp"

nts::FalseInput::FalseInput() : InputComponent("FalseInput")
{
}

void nts::FalseInput::update()
{
    _state = FALSE;
    InputComponent::update();
}
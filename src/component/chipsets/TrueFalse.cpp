/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#include "component/chipsets/TrueFalse.hpp"

nts::TrueInput::TrueInput() : Component(INPUT, "TrueInput", 1)
{
}

void nts::TrueInput::update()
{
    setStateAt(0, TRUE);
}

nts::FalseInput::FalseInput() : Component(INPUT, "FalseInput", 1)
{
}

void nts::FalseInput::update()
{
    setStateAt(0, FALSE);
}
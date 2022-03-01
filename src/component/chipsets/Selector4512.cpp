/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Selector4512
*/

#include "component/chipsets/Selector4512.hpp"

nts::Selector4512::Selector4512() : Component("4514", 16)
{
    const std::size_t inputs[] = {10, 11, 12, 14, 9};
    const std::size_t outputs[] = {0, 1, 2, 3, 4, 5, 6, 8, 13};

    for (std::size_t i = 0; i < 5; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 9; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Selector4512::update()
{
    const std::size_t inputs[] = {10, 11, 12};
    const std::size_t channels[] = {0, 1, 2, 3, 4, 5, 6, 8};
    Tristate enable = not_gate(readStateAt(14));
    Tristate inhibit = readStateAt(9);
    Tristate state;
    std::size_t idx = 0;

    if (inhibit == TRUE)
        setStateAt(13, FALSE);
    if (inhibit == FALSE && enable == TRUE) {
        for (std::size_t i = 0; i < 3; i++) {
            state = readStateAt(inputs[i]);
            if (state == UNDEFINED)
                return;
            if (state == TRUE)
                idx |= (1 << i);
        }
        state = readStateAt(channels[idx]);
        setStateAt(13, state);
    }
}
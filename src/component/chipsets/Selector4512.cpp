/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Selector4512
*/

#include "component/chipsets/Selector4512.hpp"

nts::Selector4512::Selector4512() : Component("4514", 16)
{
    const std::size_t inputs[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 14};
    const std::size_t outputs[] = {13};

    for (std::size_t i = 0; i < 13; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 1; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Selector4512::update()
{
    const std::size_t inputs[] = {10, 11, 12};
    const std::size_t channels[] = {0, 1, 2, 3, 4, 5, 6, 8};
    Tristate enable = not_gate(readStateAt(14));
    Tristate inhibit = readStateAt(9);
    Tristate bits[4];
    std::size_t idx = 0;

    for (std::size_t i = 0; i < 4; i++)
        bits[i] = readStateAt(inputs[i]);
    for (std::size_t i = 0; i < 8; i++)
        readStateAt(channels[idx]);
    if (enable == FALSE) {
        setStateAt(13, UNDEFINED);
    } else if (enable == TRUE) {
        if (inhibit == TRUE) {
            setStateAt(13, FALSE);
        } else if (inhibit == FALSE) {
            for (std::size_t i = 0; i < 3; i++) {
                if (bits[i] == UNDEFINED) {
                    setStateAt(13, UNDEFINED);
                    return;
                }
                if (bits[i] == TRUE)
                    idx |= (1 << i);
            }
            setStateAt(13, readStateAt(channels[idx]));
        }
    }
}
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
    Tristate enable = Gates::not_gate(readStateAt(14));
    Tristate inhibit = readStateAt(9);
    Tristate bits[4];
    Tristate channelsValues[8];
    std::size_t idx = 0;

    readPins(inputs, bits, 4);
    readPins(channels, channelsValues, 8);
    try {
        if (enable == FALSE) {
            setStateAt(13, UNDEFINED);
        } else if (enable == TRUE) {
            if (inhibit == TRUE) {
                setStateAt(13, FALSE);
            } else if (inhibit == FALSE) {
                idx = Gates::statesToInt(bits, 4);
                setStateAt(13, channelsValues[idx]);
            }
        }
    } catch (InvalidStateError &e) {
        setStateAt(13, UNDEFINED);
    }
}
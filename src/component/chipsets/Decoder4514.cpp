/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Decoder4514
*/

#include "component/chipsets/Decoder4514.hpp"

nts::Decoder4514::Decoder4514() : Component("4514", 24)
{
    const std::size_t inputs[] = {1, 2, 20, 21, 0, 22};
    const std::size_t outputs[] = {10, 8, 9, 7, 6, 5, 4, 3, 17, 16, 19, 18, 13, 12, 15, 14};

    for (std::size_t i = 0; i < 6; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 16; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

void nts::Decoder4514::update()
{
    const std::size_t inputs[] = {1, 2, 20, 21};
    const std::size_t outputs[] = {10, 8, 9, 7, 6, 5, 4, 3, 17, 16, 19, 18, 13, 12, 15, 14};
    Tristate strobe = readStateAt(0);
    Tristate inhibit = readStateAt(22);
    Tristate values[4];
    std::size_t idx = 0;

    readPins(inputs, values, 4);
    if (inhibit == TRUE)
        setStateToPins(outputs, FALSE, 16);
    if (inhibit == FALSE && strobe == TRUE) {
        idx = Gates::statesToInt(values, 4);
        for (std::size_t i = 0; i < 16; i++)
            setStateAt(outputs[i], i == idx ? TRUE : FALSE);
    }
}

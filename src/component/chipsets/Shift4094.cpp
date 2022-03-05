/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Shift4094
*/

#include "component/chipsets/Shift4094.hpp"

nts::Shift4094::Shift4094() : Component("4094", 16)
{
    const std::size_t inputs[] = {0, 1, 2, 14};
    const std::size_t outputs[] = {3, 4, 5, 6, 13, 12, 11, 10, 9, 8};
    for (std::size_t pin : inputs)
        setPinTypeAt(pin, INPUT);
    for (std::size_t pin : outputs)
        setPinTypeAt(pin, OUTPUT);
}

void nts::Shift4094::update()
{
    Tristate strobe = readStateAt(0);
    Tristate data = readStateAt(1);
    Tristate clock = readStateAt(2);
    Tristate enable = readStateAt(14);
    const std::size_t outputs[] = {3, 4, 5, 6, 13, 12, 11, 10};

    if (clock == TRUE) {
        if (strobe == TRUE)
            _value = (_value << 1) | (data == TRUE ? 1 : 0);
        setStateAt(8, _value & 128 ? TRUE : FALSE);
    }
    else if (clock == FALSE)
        setStateAt(9, _value & 128 ? TRUE : FALSE);
    if (enable == FALSE)
        setStateToPins(outputs, UNDEFINED, 8);
    else if (enable == TRUE) {
        for (std::size_t i = 0; i < 8; i++)
            setStateAt(outputs[i], _value & (1 << i) ? TRUE : FALSE);
    }
}
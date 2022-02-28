/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Decoder4514
*/

#include "component/chipsets/Decoder4514.hpp"

nts::Decoder4514::Decoder4514() : Component("4514", 24)
{
}

void nts::Decoder4514::simulate(std::size_t tick)
{
    const std::size_t inputs[] = {1, 2, 20, 21};
    const std::size_t outputs[] = {10, 8, 9, 7, 6, 5, 4, 3, 17, 16, 19, 18, 13, 12, 15};
    Tristate strobe = readStateAt(0);
    Tristate inhibit = readStateAt(22);
    Tristate state;
    std::size_t idx = 0;

    (void) tick;
    clearUpdatedPins();
    if (inhibit == TRUE) {
        for (std::size_t i = 0; i < 15; i++)
            setStateAt(outputs[i], FALSE, true);
    }
    if (inhibit == FALSE && strobe == TRUE) {
        for (std::size_t i = 0; i < 4; i++) {
            state = readStateAt(inputs[i]);
            if (state == UNDEFINED)
                return;
            if (state == TRUE)
                idx |= (1 << i);
        }
        for (std::size_t i = 0; i < 15; i++)
            setStateAt(outputs[i], i == idx ? TRUE : FALSE, true);
    }
}

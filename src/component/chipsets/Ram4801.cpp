/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Ram4801
*/

#include "component/chipsets/Ram4801.hpp"
#include "NTS.hpp"

nts::Ram4801::Ram4801() : Component("4801", 24)
{
    _data = std::unique_ptr<uint8_t>((uint8_t*) malloc(8 * 1024));
    if (_data.get() == nullptr)
        throw NtsError("Ram4801:Ram4801", "Can not allocated memory");
}

void nts::Ram4801::simulate(std::size_t tick)
{
    const std::size_t address[] = {7, 6, 5, 4, 3, 2, 1, 0, 22, 21};
    const std::size_t data[] = {8, 9, 10, 12, 13, 14, 15, 16};
    Tristate state;
    std::size_t addr = 0;
    uint8_t val = 0;
    Tristate chipEnable = not_gate(readStateAt(17));
    Tristate outputEnable = not_gate(readStateAt(19));
    Tristate writeEnable = not_gate(readStateAt(20));

    (void) tick;
    clearUpdatedPins();
    if (chipEnable == TRUE) {
        for (std::size_t i = 0; i < 10; i++) {
            state = readStateAt(address[i]);
            if (state == UNDEFINED)
                return;
            if (state == TRUE)
                addr |= (1 << i);
        }
        if (writeEnable == TRUE) {
            for (std::size_t i = 0; i < 8; i++) {
                state = readStateAt(data[i]);
                if (state == UNDEFINED)
                    return;
                if (state == TRUE)
                    val |= (1 << i);
            }
            *(_data.get() + addr) = val;
        } else if (outputEnable == TRUE) {
            val = *(_data.get() + addr);
            for (std::size_t i = 0; i < 8; i++)
                setStateAt(data[i], val & (1 << i) ? TRUE : FALSE, true);
        }
    }
}
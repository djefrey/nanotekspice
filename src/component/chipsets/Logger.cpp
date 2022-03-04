/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Logger
*/

#include <iostream>
#include "NTS.hpp"
#include "component/chipsets/Logger.hpp"

nts::Logger::Logger() : OutputComponent("logger", 10)
{
    file.open("./log.bin");
    if (!file.is_open())
        throw NtsError("Logger::Logger()", "Could not open ./log.bin");
    for (std::size_t i = 0; i <= 9; i++)
        setPinTypeAt(i, INPUT);
}

nts::Logger::~Logger()
{
}

void nts::Logger::update()
{
    const PinId inputs[] = {0, 1, 2, 3, 4, 5, 6, 7};
    Tristate clock = readStateAt(8);
    Tristate inhibit = readStateAt(9);
    Tristate bits[8];
    uint8_t c = 0;

    readPins(inputs, bits, 8);
    if (inhibit == TRUE || clock != TRUE)
        return;
    try {
        c = (uint8_t) Gates::statesToInt(bits, 8);
        this->file << c;
    } catch (InvalidStateError &e) {
    }
}

nts::Tristate nts::Logger::getValue()
{
    return UNDEFINED;
}
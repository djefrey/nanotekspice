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
    this->file.flush();
    this->file.close();
}

void nts::Logger::update()
{
    Tristate clock = readStateAt(8);
    Tristate inhibit = readStateAt(9);
    Tristate bits[8];
    char c = 0;

    for (std::size_t pin = 0; pin < 8; pin++)
        bits[pin] = readStateAt(pin);
    if (inhibit == TRUE || clock != TRUE)
        return;
    for (std::size_t pin = 0; pin <= 7; pin++) {
        if (bits[pin] == UNDEFINED)
            return;
        if (bits[pin] == TRUE)
            c |= (1 << pin);
    }
    std::cout << c << std::endl;
    this->file << c;
}

nts::Tristate nts::Logger::getValue()
{
    return UNDEFINED;
}
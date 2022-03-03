/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Rom2716
*/

#include <iostream>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "NTS.hpp"
#include "component/chipsets/Rom2716.hpp"

nts::Rom2716::Rom2716() : Component("rom", 24)
{
    const std::size_t inputs[] = {7, 6, 5, 4, 3, 2, 1, 0, 22, 21, 18, 17, 19};
    const std::size_t outputs[] = {8, 9, 10, 12, 13, 14, 15, 16};
    struct stat s;

    _fd = open("./rom.bin", O_RDONLY);
    if (_fd == -1)
        throw NtsError("Rom2716::Rom2716()", "Could not open rom.bin");
    fstat(_fd, &s);
    if (s.st_size != 2 * 1024)
        throw NtsError("Rom2716::Rom2716()", "rom.bin is not 16KB");
    _data = (uint8_t*) mmap(NULL, 2 * 1024, PROT_READ, MAP_PRIVATE, _fd, 0);
    if (!_data)
        throw NtsError("Rom2716::Rom2716()", "Could not map rom.bin");

    for (std::size_t i = 0; i < 13; i++)
        setPinTypeAt(inputs[i], INPUT);
    for (std::size_t i = 0; i < 8; i++)
        setPinTypeAt(outputs[i], OUTPUT);
}

nts::Rom2716::~Rom2716()
{
    munmap(_data, 2 * 1024);
    close(_fd);
}

void nts::Rom2716::update()
{
    const PinId addressPins[] = {7, 6, 5, 4, 3, 2, 1, 0, 22, 21, 18};
    const PinId outputPins[] = {8, 9, 10, 12, 13, 14, 15, 16};
    Tristate chipEnable = not_gate(readStateAt(17));
    Tristate outEnable = not_gate(readStateAt(19));
    Tristate state;
    uint64_t addr = 0;
    uint8_t byte;

    if (chipEnable == TRUE && outEnable == TRUE) {
        for (std::size_t i = 0; i < 10; i++) {
            state = readStateAt(addressPins[i]);
            if (state == UNDEFINED)
                return;
            if (state == TRUE)
                addr |= (1 << i);
        }
        byte = *(_data + addr);
        for (std::size_t i = 0; i < 8; i++)
            setStateAt(outputPins[i], byte & (1 << i) ? TRUE : FALSE);
    } else {
        for (std::size_t i = 0; i < 8; i++)
            setStateAt(outputPins[i], UNDEFINED);
    }
}
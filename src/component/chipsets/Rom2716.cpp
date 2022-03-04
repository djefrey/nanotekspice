/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Rom2716
*/

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
    if (_data != nullptr && _fd != -1) {
        munmap(_data, 2 * 1024);
        close(_fd);
    }
}

nts::Rom2716& nts::Rom2716::operator=(Rom2716&& other)
{
    this->_data = other._data;
    this->_fd = other._fd;
    other._data = nullptr;
    other._fd = -1;
    return *this;
}

void nts::Rom2716::update()
{
    const PinId addressPins[] = {7, 6, 5, 4, 3, 2, 1, 0, 22, 21, 18};
    const PinId outputPins[] = {8, 9, 10, 12, 13, 14, 15, 16};
    Tristate chipEnable = Gates::not_gate(readStateAt(17));
    Tristate outEnable = Gates::not_gate(readStateAt(19));
    Tristate addressBits[11];
    std::size_t addr = 0;
    uint8_t byte;

    readPins(addressPins, addressBits, 11);
    try {
        if (chipEnable == TRUE && outEnable == TRUE) {
            addr = Gates::statesToInt(addressBits, 11);
            byte = *(_data + addr);
            for (std::size_t i = 0; i < 8; i++)
                setStateAt(outputPins[i], byte & (1 << i) ? TRUE : FALSE);
        } else
            setStateToPins(outputPins, UNDEFINED, 8);
    } catch(InvalidStateError &e) {
        setStateToPins(outputPins, UNDEFINED, 8);
    }
}

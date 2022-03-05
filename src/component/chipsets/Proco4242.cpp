/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** 4242Proco
*/

#include "component/chipsets/Proco4242.hpp"

const std::map<char, nts::Proco4242::instrFctPtr> nts::Proco4242::INSTRUCTIONS = {
    std::make_pair('>', &nts::Proco4242::incrementInstr),
    std::make_pair('<', &nts::Proco4242::decrementInstr),
    std::make_pair('+', &nts::Proco4242::increaseInstr),
    std::make_pair('-', &nts::Proco4242::decreaseInstr),
    std::make_pair('.', &nts::Proco4242::outputInstr),
    std::make_pair('[', &nts::Proco4242::jumpForwardInstr),
    std::make_pair(']', &nts::Proco4242::jumpBackwardInstr),
};

/*
 * PINS:
 * 0  -> 10 : Address pins
 * 11 -> 18 : Data pins
 * 19       : ROM enable
 * 20       : RAM enable
 * 21       : Write enable
 * 22       : IO enable
 * 23       : Clock
 * 24       : Reset
 */
nts::Proco4242::Proco4242() : Component("4242", 25)
{
    for (std::size_t i = 0; i < 11; i++)
        setPinTypeAt(i, OUTPUT);
    for (std::size_t i = 11; i < 19; i++)
        setPinTypeAt(i, INOUT);
    for (std::size_t i = 19; i < 23; i++)
        setPinTypeAt(i, OUTPUT);
    setPinTypeAt(23, INPUT);
    setPinTypeAt(24, INPUT);
}

#include <iostream>

void nts::Proco4242::update()
{
    Tristate clock = readStateAt(23);
    Tristate reset = readStateAt(24);

    std::cout << "\n ---" << std::endl;
    std::cout << "Proc: " << clock << " - " << reset << " -> " << _state << ", " << (int) _substate << std::endl;
    std::cout << "Instruction: *(" << _instrPtr << ") = " << (int) _instr << " (" << _instr << ")" << std::endl;
    std::cout << "Data: *(" << _dataPtr << ") = " << (int) _data << std::endl;
    std::cout << "Stack: " << _stack.size() << std::endl;
    std::cout << std::endl;

    if (reset == TRUE) {
        this->reset();
    }
    if (clock == TRUE) {
        resetControlPins();
        switch (_state) {
            case State::NEXT:
                _substate = 0;
                readROMInstruction();
                break;
            case State::EXECUTE:
                executeInstruction();
                break;
            default:
                this->reset();
                break;
        }
    } else if (clock == FALSE) {
        executeIO();
    }
}

void nts::Proco4242::executeInstruction()
{
    auto it = INSTRUCTIONS.find(_instr);
    instrFctPtr ptr;

    if (_jumpTest > 0) {
        if (_instr == '[')
            _jumpTest++;
        else if (_instr == ']')
            _jumpTest--;
        return;
    }
    if (it == INSTRUCTIONS.end()) {
        moveToNextInstruction();
        return;
    }
    ptr = it->second;
    (this->*ptr)();
    _substate++;
}

void nts::Proco4242::executeIO()
{
    const PinId dataPins[] = {11, 12, 13, 14, 15, 16, 17, 18};
    Tristate dataBits[8];

    switch (_state) {
        case READ_INSTR:
            readPins(dataPins, dataBits, 8);
            std::cout << "> Read Instr : " << dataBits[0] << dataBits[1] << dataBits[2] << dataBits[3] << dataBits[4] << dataBits[5] << dataBits[6] << dataBits[7] << std::endl;
            _instr = (uint8_t) Gates::statesToInt(dataBits, 8);
            _state = State::EXECUTE;
            break;
        case READ_DATA:
            readPins(dataPins, dataBits, 8);
            std::cout << "> Read Data : " << dataBits[0] << dataBits[1] << dataBits[2] << dataBits[3] << dataBits[4] << dataBits[5] << dataBits[6] << dataBits[7] << std::endl;
            _data = (uint8_t) Gates::statesToInt(dataBits, 8);
            _state = State::EXECUTE;
            break;
        case WRITE:
            std::cout << "> Write Data" << std::endl;
            // Force update
            readStateAt(dataPins[0]);
            _state = State::EXECUTE;
            break;
        case IO:
            std::cout << "> IO" << std::endl;
            _state = State::EXECUTE;
            break;
        default:
            break;
    }
}

void nts::Proco4242::incrementInstr()
{
    std::cout << "> Instr" << std::endl;
    _dataPtr++;
    moveToNextInstruction();
}

void nts::Proco4242::decrementInstr()
{
    std::cout << "< Instr" << std::endl;
    _dataPtr--;
    moveToNextInstruction();
}

void nts::Proco4242::increaseInstr()
{
    std::cout << "+ Instr" << std::endl;
    switch (_substate) {
        case 0:
            readRAMData();
            break;
        case 1:
            _data++;
            break;
        case 2:
            writeRAMData();
            break;
        case 3:
            moveToNextInstruction();
            break;
        default:
            reset();
            break;
    }
}

void nts::Proco4242::decreaseInstr()
{
    std::cout << "- Instr" << std::endl;
    switch (_substate) {
        case 0:
            readRAMData();
            break;
        case 1:
            _data--;
            break;
        case 2:
            writeRAMData();
            break;
        case 3:
            moveToNextInstruction();
            break;
        default:
            reset();
            break;
    }
}

void nts::Proco4242::outputInstr()
{
    std::cout << ". Instr" << std::endl;
    switch (_substate) {
        case 0:
            readRAMData();
            break;
        case 1:
            writeIO();
            break;
        case 2:
            moveToNextInstruction();
            break;
        default:
            reset();
            break;
    }
}

void nts::Proco4242::jumpForwardInstr()
{
    std::cout << "[ Instr" << std::endl;
    if (_substate == 0) {
        readRAMData();
    } else if (_substate == 1) {
        if (_data == 0)
            _jumpTest = 1;
        else
            _stack.push(_instrPtr + 1);
        moveToNextInstruction();
    } else {
        reset();
    }
}

void nts::Proco4242::jumpBackwardInstr()
{
    std::cout << "] Instr" << std::endl;
    if (_substate == 0) {
        readRAMData();
    } else if (_substate == 1) {
        if (_data > 0) {
            if (!_stack.empty())
                _instrPtr = _stack.top();
            _state = State::NEXT;
        } else {
            _stack.pop();
            moveToNextInstruction();
        }
    } else {
        reset();
    }
}

void nts::Proco4242::moveToNextInstruction()
{
    _instrPtr++;
    _state = State::NEXT;
}

void nts::Proco4242::readROMInstruction()
{
    std::cout << "Read ROM Instr" << std::endl;
    setStateAt(19, TRUE);
    for (std::size_t pin = 0; pin < 11; pin++)
        setStateAt(pin, _instrPtr & (1 << pin) ? TRUE : FALSE);
    _state = State::READ_INSTR;
}

void nts::Proco4242::readRAMData()
{
    std::cout << "Read RAM Data" << std::endl;
    setStateAt(20, TRUE);
    setStateAt(21, FALSE);
    for (std::size_t pin = 0; pin < 11; pin++)
        setStateAt(pin, _dataPtr & (1 << pin) ? TRUE : FALSE);
    _state = State::READ_DATA;
}

void nts::Proco4242::writeRAMData()
{
    std::cout << "Write RAM Data" << std::endl;
    setStateAt(20, TRUE);
    setStateAt(21, TRUE);
    for (std::size_t pin = 0; pin < 11; pin++)
        setStateAt(pin, _dataPtr & (1 << pin) ? TRUE : FALSE);
    for (std::size_t i = 0; i < 8; i++)
        setStateAt(11 + i, _data & (1 << i) ? TRUE : FALSE);
    _state = State::WRITE;
}

void nts::Proco4242::writeIO()
{
    std::cout << "Write IO" << std::endl;
    setStateAt(22, TRUE);
    for (std::size_t i = 0; i < 8; i++)
        setStateAt(11 + i, _data & (1 << i) ? TRUE : FALSE);
    _state = State::IO;
}

void nts::Proco4242::reset()
{
    std::cout << "RESET !" << std::endl;
    _instrPtr = 0;
    _dataPtr = 0;
    _data = 0;
    _state = State::NEXT;
    _substate = 0;
    _jumpTest = 0;
    while (!_stack.empty())
        _stack.pop();
    resetControlPins();
}

void nts::Proco4242::resetControlPins()
{
    setStateAt(19, FALSE);
    setStateAt(20, FALSE);
    setStateAt(21, FALSE);
    setStateAt(22, FALSE);
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** NTS
*/

#include <iostream>
#include <stdexcept>
#include "NTS.hpp"

const std::map<std::string, nts::NTSFctPtr> nts::NTS::commandsList{
    std::make_pair("simulate", &nts::NTS::simulateCmd),
    std::make_pair("display", &nts::NTS::displayCmd),
    std::make_pair("loop", &nts::NTS::loopCmd),
    std::make_pair("dump", &nts::NTS::dumpCmd),
    std::make_pair("exit", &nts::NTS::exitCmd),
};

nts::NTS::NTS() : _circuit("Main Circuit", 0)
{
    IComponent &clock = _circuit.createComponent(std::string("clock"), "clock");
    IComponent &in0 = _circuit.createComponent(std::string("input"), "in0");
    IComponent &reset = _circuit.createComponent(std::string("input"), "reset");

    IComponent &johnson = _circuit.createComponent(std::string("4017"), "johnson");

    johnson.setLink(13, clock, 0);
    johnson.setLink(12, in0, 0);
    johnson.setLink(14, reset, 0);
}

nts::NTS::NTS(const std::string &config) : _circuit("Main Circuit", 0)
{
}

int nts::NTS::run()
{
    std::string line;

    while (this->_run && readInput(line))
        executeCmd(line);
    return 0;
}

bool nts::NTS::readInput(std::string &line)
{
    std::cout << "> ";
    std::cout.flush();
    if (std::getline(std::cin, line).eof())
        return false;
    return true;
}

void nts::NTS::executeCmd(const std::string &cmd)
{
    NTSFctPtr ptr;

    if (setInputFromCmd(cmd))
        return;
    try {
        ptr = commandsList.at(cmd);
        (this->*ptr)();
    } catch (const std::out_of_range &e) {
        throw nts::NtsError("NTS::executeCmd()", "Invalid cmd");
    }
}

bool nts::NTS::setInputFromCmd(const std::string &cmd)
{
    std::size_t pos = cmd.find_first_of('=');
    Tristate state;

    if (pos == cmd.npos || cmd.size() != (pos + 2))
        return false;
    state = get_state_from_char(cmd[pos + 1]);
    _circuit.setInputState(cmd.substr(0, pos), state);
    return true;
}

void nts::NTS::simulateCmd()
{
    this->_circuit.simulate(this->_tick);
    this->_tick++;
}

void nts::NTS::displayCmd()
{
    std::cout << "tick: " << this->_tick << "\n";
    this->_circuit.printInOut();
}

void nts::NTS::loopCmd()
{
    while (true) {
        simulateCmd();
        displayCmd();
    }
}

void nts::NTS::dumpCmd()
{
    this->_circuit.dump();
}

void nts::NTS::exitCmd()
{
    this->_run = false;
}

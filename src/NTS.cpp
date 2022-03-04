/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** NTS
*/

#include <iostream>
#include <stdexcept>
#include "NTS.hpp"
#include "../include/Parser.hpp"

const std::map<std::string, nts::NTSFctPtr> nts::NTS::commandsList{
    std::make_pair("simulate", &nts::NTS::simulateCmd),
    std::make_pair("display", &nts::NTS::displayCmd),
    std::make_pair("loop", &nts::NTS::loopCmd),
    std::make_pair("dump", &nts::NTS::dumpCmd),
    std::make_pair("exit", &nts::NTS::exitCmd),
};

nts::NTS::NTS(const std::string &config) : _circuit("Main Circuit", 0)
{
    Parser parser(_circuit);

    parser.parseFile(config);
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
    state = Gates::get_state_from_char(cmd[pos + 1]);
    _circuit.setInputState(cmd.substr(0, pos), state);
    return true;
}

void nts::NTS::simulateCmd()
{
    this->_tick++;
    this->_circuit.simulate(this->_tick);
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
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TestsTools
*/

#include "Tests.hpp"
#include "Parser.hpp"

void assert_output(nts::Circuit &circuit, std::string name, nts::Tristate value)
{
    cr_assert_eq(circuit.getComponentByName(name).getStateAt(0), value);
}

void simulate(nts::Circuit &circuit, std::size_t &tick)
{
    tick++;
    circuit.simulate(tick);
}

void init_circuit(nts::Circuit &circuit, const std::string path)
{
    nts::Parser parser(circuit);

    parser.parseFile(path);
}

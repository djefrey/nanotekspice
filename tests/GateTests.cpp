/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** GateTests
*/

#include <criterion/criterion.h>
#include "component/Circuit.hpp"
#include "Parser.hpp"

void initCircuit(nts::Circuit &circuit, const std::string path)
{
    nts::Parser parser(circuit);

    parser.parseFile(path);
}

Test(And, and)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/and_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::UNDEFINED);
    cr_assert_eq(circuit.getComponentByName("out4").getStateAt(0), nts::FALSE);

}

Test(Or, or)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/or_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out4").getStateAt(0), nts::UNDEFINED);

}

Test(Nand, nand)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/nand_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::UNDEFINED);
    cr_assert_eq(circuit.getComponentByName("out4").getStateAt(0), nts::TRUE);

}

Test(Nor, nor)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/nor_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out4").getStateAt(0), nts::UNDEFINED);

}

Test(Xor, xor)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/xor_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::UNDEFINED);
    cr_assert_eq(circuit.getComponentByName("out4").getStateAt(0), nts::UNDEFINED);

}

Test(Not, not)
{
    nts::Circuit circuit("circuit", 0);
    initCircuit(circuit, "tests/nts/not_tests.nts");

    circuit.simulate(1);

    cr_assert_eq(circuit.getComponentByName("out1").getStateAt(0), nts::FALSE);
    cr_assert_eq(circuit.getComponentByName("out2").getStateAt(0), nts::TRUE);
    cr_assert_eq(circuit.getComponentByName("out3").getStateAt(0), nts::UNDEFINED);

}
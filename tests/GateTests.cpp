/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** GateTests
*/

#include "Tests.hpp"

Test(And, and)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/and_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", TRUE);
    assert_output(circuit, "out2", FALSE);
    assert_output(circuit, "out3", UNDEFINED);
    assert_output(circuit, "out4", FALSE);

}

Test(Or, or)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/or_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", TRUE);
    assert_output(circuit, "out2", FALSE);
    assert_output(circuit, "out3", TRUE);
    assert_output(circuit, "out4", UNDEFINED);

}

Test(Nand, nand)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/nand_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", FALSE);
    assert_output(circuit, "out2", TRUE);
    assert_output(circuit, "out3", UNDEFINED);
    assert_output(circuit, "out4", TRUE);

}

Test(Nor, nor)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/nor_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", FALSE);
    assert_output(circuit, "out2", TRUE);
    assert_output(circuit, "out3", FALSE);
    assert_output(circuit, "out4", UNDEFINED);
}

Test(Xor, xor)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/xor_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", FALSE);
    assert_output(circuit, "out2", TRUE);
    assert_output(circuit, "out3", UNDEFINED);
    assert_output(circuit, "out4", UNDEFINED);
}

Test(Not, not)
{
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/not_tests.nts");

    circuit.simulate(1);

    assert_output(circuit, "out1", FALSE);
    assert_output(circuit, "out2", TRUE);
    assert_output(circuit, "out3", UNDEFINED);
}
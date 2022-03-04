/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** JohnsonTests
*/

#include "Tests.hpp"

static void set_clocks(Circuit &circuit, Tristate a, Tristate b)
{
    circuit.setInputState("in_0", a);
    circuit.setInputState("in_1", b);
}

static void set_reset(Circuit &circuit, Tristate a)
{
    circuit.setInputState("in_r", a);
}

static void assert_value(Circuit &circuit, uint value)
{
    char name[6] = {0};

    for (uint i = 0; i < 10; i++) {
        snprintf(name, 6, "out_%01u", i);
        assert_output(circuit, name, i == value ? TRUE : FALSE);
    }
    assert_output(circuit, "out_s", value < 5 ? TRUE : FALSE);
}

Test(Johnson, testCave)
{
    std::size_t tick = 0;
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/4017_johnson.nts");

    set_clocks(circuit, TRUE, FALSE);
    set_reset(circuit, TRUE);
    simulate(circuit, tick);
    assert_value(circuit, 0);

    set_reset(circuit, FALSE);
    for (int i = 1; i < 10; i++) {
        simulate(circuit, tick);
        assert_value(circuit, i);
    }

    simulate(circuit, tick);
    assert_value(circuit, 0);

    simulate(circuit, tick);
    simulate(circuit, tick);
    simulate(circuit, tick);
    assert_value(circuit, 3);

    set_reset(circuit, TRUE);
    simulate(circuit, tick);
    assert_value(circuit, 0);

    simulate(circuit, tick);
    assert_value(circuit, 0);

    set_reset(circuit, FALSE);
    simulate(circuit, tick);
    assert_value(circuit, 1);

    set_clocks(circuit, TRUE, TRUE);
    simulate(circuit, tick);
    assert_value(circuit, 1);
    simulate(circuit, tick);
    assert_value(circuit, 1);
}
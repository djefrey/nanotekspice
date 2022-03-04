/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FlipFlopTests
*/

#include "Tests.hpp"

using namespace nts;

void set_clocks(nts::Circuit &circuit, nts::Tristate state)
{
    circuit.setInputState("cl_1_clock", state);
    circuit.setInputState("cl_2_clock", state);
}

void set_datas(nts::Circuit &circuit, nts::Tristate state)
{
    circuit.setInputState("in_1_data", state);
    circuit.setInputState("in_2_data", state);
}

void set_set(nts::Circuit &circuit, nts::Tristate state)
{
    circuit.setInputState("in_1_set", state);
    circuit.setInputState("in_2_set", state);
}

void set_reset(nts::Circuit &circuit, nts::Tristate state)
{
    circuit.setInputState("in_1_reset", state);
    circuit.setInputState("in_2_reset", state);
}

void assert_outputs(nts::Circuit &circuit, Tristate state, Tristate state2)
{
    assert_output(circuit, "out_1_q", state);
    assert_output(circuit, "out_2_q", state);
    assert_output(circuit, "out_1_qb", state2);
    assert_output(circuit, "out_2_qb", state2);
}

Test(FlipFlop, testFF)
{
    std::size_t tick = 0;
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/4013_flipflop.nts");

    set_clocks(circuit, TRUE);
    set_datas(circuit, FALSE);
    set_set(circuit, FALSE);
    set_reset(circuit, FALSE);

    simulate(circuit, tick);
    assert_outputs(circuit, FALSE, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, FALSE, TRUE);

    set_datas(circuit, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, FALSE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, FALSE);

    set_reset(circuit, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, FALSE, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, FALSE, TRUE);

    set_datas(circuit, FALSE);
    set_reset(circuit, FALSE);
    set_set(circuit, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, FALSE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, FALSE);

    set_reset(circuit, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, TRUE);
    simulate(circuit, tick);
    assert_outputs(circuit, TRUE, TRUE);
}

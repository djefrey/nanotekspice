/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Decoder
*/

#include <stdio.h>
#include "Tests.hpp"

void set_inputs(Circuit &circuit, Tristate a, Tristate b, Tristate c, Tristate d)
{
    circuit.setInputState("in_0", a);
    circuit.setInputState("in_1", b);
    circuit.setInputState("in_2", c);
    circuit.setInputState("in_3", d);
}

void set_active(Circuit &circuit, Tristate strobe, Tristate inhibit)
{
    circuit.setInputState("strobe", strobe);
    circuit.setInputState("inhibit", inhibit);
}

#include <iostream>

void assert_channel_is_active(Circuit &circuit, int chann)
{
    char output[8] = {0};

    for (int i = 0; i < 16; i++) {
        snprintf(output, 7, "out_%02d", i);
        if (i == chann)
            assert_output(circuit, output, TRUE);
        else
            assert_output(circuit, output, FALSE);
    }
}

Test(Decoder, testDecoder)
{
    std::size_t tick = 0;
    nts::Circuit circuit("circuit", 0);
    init_circuit(circuit, "tests/nts/4514_decoder.nts");

    set_inputs(circuit, TRUE, TRUE, TRUE, TRUE);
    set_active(circuit, TRUE, TRUE);
    simulate(circuit, tick);
    assert_channel_is_active(circuit, -1);

    set_active(circuit, TRUE, FALSE);
    for (int i = 0; i < 15; i++) {
        set_inputs(circuit, i & 0x1 ? TRUE : FALSE,
                            i & 0x2 ? TRUE : FALSE,
                            i & 0x4 ? TRUE : FALSE,
                            i & 0x8 ? TRUE : FALSE);
        simulate(circuit, tick);
        assert_channel_is_active(circuit, i);
    }
}
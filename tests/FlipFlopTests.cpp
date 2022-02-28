/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FlipFlopTests
*/

#include <criterion/criterion.h>
#include "component/Circuit.hpp"
#include "component/chipsets/FlipFlop4013.hpp"

static void testFlipFlop(nts::IComponent &comp,
                    nts::PinId clock,
                    nts::PinId data,
                    nts::PinId set,
                    nts::PinId reset,
                    nts::PinId q,
                    nts::PinId nq)
{
    comp.setStateAt(clock, nts::FALSE, false);
    comp.setStateAt(data, nts::FALSE, false);
    comp.setStateAt(set, nts::FALSE, false);
    comp.setStateAt(reset, nts::FALSE, false);

    comp.simulate(0);

    // FIRST STATE

    cr_assert_eq(comp.readStateAt(q), nts::UNDEFINED);
    cr_assert_eq(comp.readStateAt(nq), nts::UNDEFINED);

    // DATA = FALSE

    comp.setStateAt(clock, nts::TRUE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::FALSE);
    cr_assert_eq(comp.readStateAt(nq), nts::TRUE);

    comp.setStateAt(clock, nts::FALSE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::FALSE);
    cr_assert_eq(comp.readStateAt(nq), nts::TRUE);

    // DATA = TRUE

    comp.setStateAt(clock, nts::TRUE, false);
    comp.setStateAt(data, nts::TRUE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::TRUE);
    cr_assert_eq(comp.readStateAt(nq), nts::FALSE);

    comp.setStateAt(clock, nts::FALSE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::TRUE);
    cr_assert_eq(comp.readStateAt(nq), nts::FALSE);

    // RESET = 1

    comp.setStateAt(reset, nts::TRUE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::FALSE);
    cr_assert_eq(comp.readStateAt(nq), nts::TRUE);

    // SET = 1

    comp.setStateAt(reset, nts::FALSE, false);
    comp.setStateAt(set, nts::TRUE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::TRUE);
    cr_assert_eq(comp.readStateAt(nq), nts::FALSE);

    // SET = 1, RESET = 1

    comp.setStateAt(reset, nts::TRUE, false);
    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(q), nts::TRUE);
    cr_assert_eq(comp.readStateAt(nq), nts::TRUE);
}

Test(FlipFlop, testFF)
{
    nts::Circuit circuit("Test", 0);
    nts::IComponent &comp = circuit.createComponent("4013", "flipflop");

    testFlipFlop(comp, 2, 4, 5, 3, 0, 1);
    testFlipFlop(comp, 10, 8, 7, 9, 12, 11);
}
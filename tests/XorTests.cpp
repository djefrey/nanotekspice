/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** AndTests
*/

#include <criterion/criterion.h>
#include "component/Circuit.hpp"
#include "component/chipsets/Xor4030.hpp"

Test(Xor4030, testXor)
{
    nts::Circuit circuit("Test", 0);
    nts::IComponent &comp = circuit.createComponent("4030", "xor");

    comp.setStateAt(0, nts::TRUE, false);
    comp.setStateAt(1, nts::TRUE, false);

    comp.setStateAt(4, nts::FALSE, false);
    comp.setStateAt(5, nts::TRUE, false);

    comp.setStateAt(7, nts::TRUE, false);
    comp.setStateAt(8, nts::UNDEFINED, false);

    comp.setStateAt(11, nts::FALSE, false);
    comp.setStateAt(12, nts::UNDEFINED, false);

    comp.simulate(0);

    cr_assert_eq(comp.readStateAt(2), nts::FALSE);
    cr_assert_eq(comp.readStateAt(3), nts::TRUE);
    cr_assert_eq(comp.readStateAt(9), nts::UNDEFINED);
    cr_assert_eq(comp.readStateAt(10), nts::UNDEFINED);
}
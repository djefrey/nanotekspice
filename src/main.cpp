/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** main
*/

#include "component/Circuit.hpp"
#include "component/chipsets/Clock.hpp"
#include "component/chipsets/TrueFalse.hpp"
#include "component/chipsets/Output.hpp"
#include "component/chipsets/Chipset4081.hpp"

int main(void)
{
    nts::TrueInput in0;
    nts::Clock clock;
    nts::TrueInput in2;
    nts::Output out0;

    nts::Chipset4081 chipset;

    nts::Circuit circuit(nts::ComponentType::COMPONENT, "Main Circuit", 0);

    chipset.setLink(0, in0, 0);
    chipset.setLink(1, clock, 0);

    chipset.setLink(2, chipset, 4);
    chipset.setLink(5, in2, 0);

    chipset.setLink(3, out0, 0);

    circuit.addInput(in0);
    circuit.addInput(clock);
    circuit.addInput(in2);

    circuit.simulate(5);
}
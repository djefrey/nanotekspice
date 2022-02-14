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
    nts::Circuit circuit(nts::ComponentType::COMPONENT, "Main Circuit", 0);

    nts::IComponent &in0 = circuit.createComponent(std::string("true"), "in0");
    nts::IComponent &clock = circuit.createComponent(std::string("clock"), "clock");
    nts::IComponent &in2 = circuit.createComponent(std::string("true"), "in2");
    nts::IComponent &out0 = circuit.createComponent(std::string("output"), "out0");
    nts::IComponent &chipset = circuit.createComponent(std::string("4081"), "and");

    chipset.setLink(0, in0, 0);
    chipset.setLink(1, clock, 0);

    chipset.setLink(2, chipset, 4);
    chipset.setLink(5, in2, 0);

    chipset.setLink(3, out0, 0);

    circuit.simulate(0);
    circuit.simulate(1);
    circuit.simulate(2);

    circuit.dump();
}

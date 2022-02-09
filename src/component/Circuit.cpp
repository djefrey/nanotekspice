/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#include <algorithm>
#include "component/Circuit.hpp"

nts::Circuit::Circuit(ComponentType type, std::size_t nbPins) : Component(type, "Circuit", nbPins)
{
}

void nts::Circuit::simulate(std::size_t tick)
{
    Connection conn;

    for (std::size_t t = 0; t < tick; t++) {
        for (IComponent *output : _outputs) {
            conn = getConnectionWith(output);
            if (conn.component)
                conn.component->compute(conn.toPin);
        }
    }
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    Connection conn = this->getConnectionAt(pin);

    if (conn.component)
        return conn.component->compute(conn.toPin);
    return UNDEFINED;
}

void nts::Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Component::setLink(pin, other, otherPin);
    if (other.getType() == OUTPUT)
        this->_outputs.push_back(&other);
}
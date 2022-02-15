/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Component
*/

#include <iostream>
#include <algorithm>
#include "NTS.hpp"
#include "component/Component.hpp"

nts::Component::Component(std::string model, std::size_t nbPins)
    : _model(model), _name(model), _nbPins(nbPins)
{
    _states.resize(nbPins);
    _connections.resize(nbPins);
    for (std::size_t i = 0; i < nbPins; i++)
        _states[i] = UNDEFINED;
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::compute()", "Invalid pin");
    return this->_states[pin];
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (this->getConnectionAt(pin).component == nullptr
    && other.getConnectionAt(otherPin).component == nullptr) {
        this->setConnectionAt(pin, other, otherPin);
        other.setConnectionAt(otherPin, *this, pin);
    }
}

void nts::Component::dump() const
{
    std::cout
    << "Component: " << this->_model << "\n"
    << "Name: " << this->_name << "\n"
    << "Number of pins: " << this->_nbPins << "\n"
    << "Pins:\n";
    for (std::size_t i = 0; i < _nbPins; i++) {
        std::cout << " - " << i << " : " << this->_states[i];
        if (this->_connections[i].component != nullptr)
            std::cout << " - "
            << this->_connections[i].component->getName()
            << " (" << this->_connections[i].pin << ")\n";
        else
            std::cout << " - None\n";
    }
    std::cout << "\n";
}

void nts::Component::setName(std::string name)
{
    this->_name = name;
}

nts::Connection nts::Component::getConnectionAt(PinId pin) const
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::getConnectionAt()", "Invalid pin");
    return this->_connections[pin];
}

void nts::Component::setConnectionAt(nts::PinId pin, nts::IComponent &component, nts::PinId otherPin)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::setConnectionAt()", "Invalid pin");
    this->_connections[pin] = {&component, otherPin};
}

void nts::Component::setStateAt(PinId pin, Tristate state, bool update)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::setStateAt()", "Invalid pin");
    if (update && this->_states[pin] != state)
        this->_updatedPins.push_back(pin);
    this->_states[pin] = state;
}

std::vector<std::size_t> nts::Component::getUpdatedPins() const
{
    return this->_updatedPins;
}

void nts::Component::clearUpdatedPins()
{
    this->_updatedPins.clear();
}

nts::Tristate nts::Component::readStateAt(nts::PinId pin)
{
    nts::Connection conn;
    Tristate state;

    if (pin >= this->_nbPins)
        throw NtsError("Component::readStateAt()", "Invalid pin");
    conn = this->getConnectionAt(pin);
    state = conn.component ? conn.component->compute(conn.pin) : UNDEFINED;
    this->setStateAt(pin, state, false);
    return state;
}
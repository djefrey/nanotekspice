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
    _types.resize(nbPins);
    _connections.resize(nbPins);
    for (std::size_t i = 0; i < nbPins; i++) {
        _states[i] = UNDEFINED;
        _types[i] = UNUSED;
    }
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::compute()", "Invalid pin");
    return this->_states[pin];
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->addConnectionAt(pin, other, otherPin);
    other.addConnectionAt(otherPin, *this, pin);
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
        if (this->_connections[i].size() == 0)
            std::cout << " - None\n";
        else {
            std::cout << " - ";
            for (Connection conn : this->_connections[i]) {
                std::cout << conn.component->getName()
                << " (" << conn.pin << "), ";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void nts::Component::setName(std::string name)
{
    this->_name = name;
}

std::vector<nts::Connection> nts::Component::getConnectionsAt(PinId pin) const
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::getConnectionAt()", "Invalid pin");
    return this->_connections[pin];
}

void nts::Component::addConnectionAt(nts::PinId pin, nts::IComponent &component, nts::PinId otherPin)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::setConnectionAt()", "Invalid pin");
    this->_connections[pin].push_back({&component, otherPin});
}

nts::Tristate nts::Component::readStateAt(nts::PinId pin)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::readStateAt()", "Invalid pin");
    return this->_states[pin];
}

void nts::Component::setStateAt(PinId pin, Tristate state, bool update)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::setStateAt()", "Invalid pin");
    if (update) {
        for (Connection conn : this->_connections[pin]) {
            if (!(conn.component->getPinTypeAt(conn.pin) & INPUT))
                continue;
            conn.component->setStateAt(conn.pin, state, false);
        }
        this->_updatedPins.push_back(pin);
    }
    this->_states[pin] = state;
}

nts::PinType nts::Component::getPinTypeAt(PinId pin) const
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::getPinTypeAt()", "Invalid pin");
    return this->_types[pin];
}

void nts::Component::setPinTypeAt(PinId pin, PinType type)
{
    if (pin >= this->_nbPins)
        throw NtsError("Component::getPinTypeAt()", "Invalid pin");
    this->_types[pin] = type;
}

std::vector<std::size_t> nts::Component::getUpdatedPins() const
{
    return this->_updatedPins;
}

void nts::Component::clearUpdatedPins()
{
    this->_updatedPins.clear();
}

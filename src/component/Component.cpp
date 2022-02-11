/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Component
*/

#include <iostream>
#include <algorithm>
#include "component/Component.hpp"

nts::Component::Component(ComponentType type, std::string name, std::size_t nbPins)
    : _type(type), _name(name), _nbPins(nbPins)
{
    _states.resize(nbPins);
    _connections.resize(nbPins);
    for (std::size_t i = 0; i < nbPins; i++) {
        _states[i] = UNDEFINED;
        _connections[i] = {nullptr, SIZE_MAX};
    }
}

void nts::Component::simulate(std::size_t tick)
{
    for (size_t t = 0; t < tick; t++) {
        clearUpdatedPins();
        update();
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
    if (this->getConnectionAt(pin).component == nullptr
    && other.getConnectionAt(otherPin).component == nullptr) {
       this->setConnectionAt(pin, {&other, otherPin});
        other.setConnectionAt(otherPin, {this, pin});
    }
}

void nts::Component::dump() const
{
    std::cout
    << "Component: " << this->_name << "\n"
    << "Number of pins: " << this->_nbPins << "\n"
    << "States:\n";
    for (std::size_t i = 0; i < _nbPins; i++)
        std::cout << " - " << i << " : " << this->_states[i] << "\n";
    std::cout << "Connections:\n";
    for (std::size_t i = 0; i < _nbPins; i++) {
        if (this->_connections[i].component != nullptr)
            std::cout << " - " << i << " : " << this->_connections[i].component->getName() << "\n";
        else
            std::cout << " - " << i << " : None\n";
    }
}

std::vector<std::size_t> nts::Component::getUpdatedPins() const
{
    return this->_updatedPins;
}

void nts::Component::setStateAt(std::size_t pin, nts::Tristate state)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::setStateAt()", "Invalid pin");
    if (this->_states[pin]!= state) {
        if (std::find(this->_updatedPins.begin(), this->_updatedPins.end(), pin) == this->_updatedPins.end())
            this->_updatedPins.push_back(pin);
    }
    this->_states[pin] = state;
}

nts::Connection nts::Component::getConnectionAt(std::size_t pin) const
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::getConnectionAt()", "Invalid pin");
    return this->_connections[pin];
}

nts::Connection nts::Component::getConnectionWith(nts::IComponent *component) const
{
    for (Connection conn : _connections) {
        if (conn.component == component)
            return conn;
    }
    return {nullptr, SIZE_MAX};
}

void nts::Component::setConnectionAt(std::size_t pin, nts::Connection connection)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::setConnectionAt()", "Invalid pin");
    this->_connections[pin] = connection;
}

std::vector<nts::IComponent*> nts::Component::getConnections() const
{
    std::vector<IComponent*> comps;

    for (Connection conn : _connections) {
        comps.push_back(conn.component);
    }
    return comps;
}

void nts::Component::clearUpdatedPins()
{
    this->_updatedPins.clear();
}
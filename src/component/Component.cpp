/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Component
*/

#include <iostream>
#include "component/Component.hpp"

nts::Component::Component(std::string name, std::size_t nbPins) : _name(name), _nbPins(nbPins)
{
    _states.resize(nbPins);
    _connections.resize(nbPins);
    for (std::size_t i = 0; i < nbPins; i++) {
        _states[i] = UNDEFINED;
        _connections[i] = {nullptr, SIZE_MAX};
    }
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::compute()", "Invalid pin");
    return this->_states[pin];
}

void nts::Component::updateState(Tristate state, std::size_t pin)
{
    Connection connection;

    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::updateState()", "Invalid pin");
    this->_states[pin] = state;
    if (this->_connections[pin].component != nullptr) {
        connection = this->_connections[pin];
        connection.component->updateState(state, connection.toPin);
    }
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (this->getConnectionAt(pin).component == nullptr && other.getConnectionAt(otherPin).component == nullptr) {
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

nts::Connection nts::Component::getConnectionAt(std::size_t pin) const
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::getComponentAt()", "Invalid pin");
    return this->_connections[pin];
}

void nts::Component::setConnectionAt(std::size_t pin, nts::Connection connection)
{
    if (pin >= this->_nbPins)
        throw nts::NtsError("Component::setComponentAt()", "Invalid pin");
    this->_connections[pin] = connection;
}
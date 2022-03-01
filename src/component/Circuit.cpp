/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#include <algorithm>
#include <iostream>
#include "NTS.hpp"
#include "component/Circuit.hpp"
#include "component/ComponentFactory.hpp"

nts::Circuit::Circuit(std::string model, std::size_t nbPins) : Component(model, nbPins)
{
}

void nts::Circuit::update()
{
    for (OutputComponent *out : this->_outputs)
        out->simulate(this->_lastUpdate);
}

void nts::Circuit::dump() const
{
    Component::dump();
    std::cout << "\n";
    for (auto it = _components.begin(); it != _components.end(); it++) {
        it->second->dump();
        std::cout << "\n";
    }
}

nts::IComponent &nts::Circuit::createComponent(const std::string &model, std::string name)
{
    auto comp = ComponentFactory::get().createComponent(model);
    IComponent *ptr;
    InputComponent *inPtr;
    OutputComponent *outPtr;

    if (this->_components.find(name) != this->_components.end())
        throw NtsError("Circuit::createComponent()", "Component with same name already exists");
    comp->setName(name);
    this->_components[name] = std::move(comp);
    ptr = this->_components[name].get();
    if ((inPtr = dynamic_cast<InputComponent*>(ptr)))
        this->insertInput(inPtr);
    if ((outPtr = dynamic_cast<OutputComponent*>(ptr)))
        this->insertOutput(outPtr);
    return *ptr;
}

void nts::Circuit::setInputState(const std::string &name, Tristate state)
{
    for (InputComponent *input : this->_inputs) {
        if (!input->isStatic() && input->getName() == name) {
            input->setValue(state);
            return;
        }
    }
    throw NtsError("Circuit::setInputState()", "Input not found");
}

void nts::Circuit::printInOut() const
{
    std::cout << "input(s):\n";
    for (InputComponent *input : this->_inputs) {
        if (!input->isStatic())
            std::cout << "  " << input->getName() <<": " << input->getValue() << "\n";
    }
    std::cout << "output(s):\n";
    for (OutputComponent *output : this->_outputs)
        std::cout << "  " << output->getName() << ": " << output->getValue() << "\n";
    std::cout.flush();
}

void nts::Circuit::addUpdatedPinsToUpdate(std::vector<IComponent*> &update, IComponent &comp)
{
    for (std::size_t pin : comp.getUpdatedPins()) {
        for (Connection conn : comp.getConnectionsAt(pin)) {
            std::cout <<  conn.component->getStateAt(conn.pin) << " - " <<  comp.getStateAt(pin) << std::endl;
            if (!(conn.component->getPinTypeAt(conn.pin) & INPUT)
             || conn.component->getStateAt(conn.pin) == comp.getStateAt(pin))
                continue;
            if (std::find(update.begin(), update.end(), conn.component) == update.end())
                update.push_back(conn.component);
        }
    }
}

void nts::Circuit::insertInput(InputComponent *input)
{
    auto pos = this->_inputs.begin();
    std::string name = input->getName();

    for (; pos != this->_inputs.end(); pos++) {
        if ((*pos.base())->getName().compare(name) > 0)
            break;
    }
    this->_inputs.insert(pos, input);
}

void nts::Circuit::insertOutput(OutputComponent *output)
{
    auto pos = this->_outputs.begin();
    std::string name = output->getName();

    for (; pos != this->_outputs.end(); pos++) {
        if ((*pos.base())->getName().compare(name) > 0)
            break;
    }
    this->_outputs.insert(pos, output);
}

void nts::Circuit::setLink(std::string &name1, std::string &name2, nts::PinId pin1, nts::PinId pin2)
{
    IComponent &comp1 = getComponentByName(name1);
    IComponent &comp2 = getComponentByName(name2);

    comp1.setLink(pin1, comp2, pin2);
}

nts::IComponent &nts::Circuit::getComponentByName(std::string name) const
{
    auto it = _components.find(name);

    if (it == _components.end())
        throw NtsError("nts::Circuit::getComponentByName()", "Component not find");
    return (*(it->second));
}
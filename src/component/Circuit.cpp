/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#include <algorithm>
#include <iostream>
#include "component/Circuit.hpp"
#include "component/ComponentFactory.hpp"

nts::Circuit::Circuit(std::string model, std::size_t nbPins) : Component(model, nbPins)
{
}

void nts::Circuit::simulate(std::size_t tick)
{
    std::vector<IComponent*> toUpdate = *reinterpret_cast<std::vector<IComponent*>*>(&this->_inputs);
    std::vector<IComponent*> nextUpdate;

    (void) tick;
    clearUpdatedPins();
    while (!toUpdate.empty()) {
        for (IComponent *comp : toUpdate) {
            comp->simulate(1);
            addUpdatedPinsToUpdate(nextUpdate, *comp);
        }
        toUpdate = nextUpdate;
        nextUpdate.clear();
    }
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
        if (input->getName() == name) {
            input->setValue(state);
            return;
        }
    }
    throw NtsError("Circuit::setInputState()", "Input not found");
}

void nts::Circuit::printInOut() const
{
    std::cout << "inputs(s):\n";
    for (InputComponent *input : this->_inputs)
        std::cout << "  " << input->getName() <<": " << input->getValue() << "\n";
    std::cout << "output(s):\n";
    for (OutputComponent *output : this->_outputs)
        std::cout << "  " << output->getName() << ": " << output->getValue() << "\n";
    std::cout.flush();
}

void nts::Circuit::addUpdatedPinsToUpdate(std::vector<IComponent*> &update, IComponent &comp)
{
    Connection conn;

    for (std::size_t pin : comp.getUpdatedPins()) {
        conn = comp.getConnectionAt(pin);
        if (conn.component
        &&  std::find(update.begin(), update.end(), conn.component) == update.end()) {
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
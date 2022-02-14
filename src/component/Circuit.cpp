/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#include <algorithm>
#include "component/Circuit.hpp"

nts::Circuit::Circuit(ComponentType type, std::string model, std::size_t nbPins)
    : Component(type, model, nbPins)
{
}

void nts::Circuit::simulate(std::size_t tick)
{
    std::vector<IComponent*> toUpdate = this->_inputs;
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

/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#include <algorithm>
#include "component/Circuit.hpp"

nts::Circuit::Circuit(std::size_t nbPins) : Component("Circuit", nbPins)
{
}


void nts::Circuit::simulate(std::size_t tick)
{
    std::vector<IComponent*> toUpdate{this->_entryPoints};
    std::vector<IComponent*> nextUpdate;
    std::vector<IComponent*> alreadyUpdated;

    for (std::size_t i = 0; i < tick; i++) {
        while (!toUpdate.empty()) {
            updateComponents(toUpdate, nextUpdate, alreadyUpdated);
            toUpdate = nextUpdate;
            nextUpdate.clear();
        }
    }
}

void nts::Circuit::updateComponents(std::vector<nts::IComponent*> &toUpdate,
                                    std::vector<nts::IComponent*> &nextUpdate,
                                    std::vector<nts::IComponent*> &alreadyUpdated)
{
    IComponent *component;
    std::vector<IComponent*> *next;

    while (!toUpdate.empty()) {
        component = toUpdate.back();
        component->simulate(1);
        next = &this->_connections[component];
        for (std::size_t i = 0; i < next->size(); i++) {
            if (std::find(alreadyUpdated.begin(), alreadyUpdated.end(), (*next)[i]) == alreadyUpdated.end())
                alreadyUpdated.push_back((*next)[i]);
        }
    }
}

void nts::Circuit::addComponent(std::string name, IComponent *component)
{
}
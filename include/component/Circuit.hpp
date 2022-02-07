/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#pragma once

#include <map>
#include <vector>
#include "component/Component.hpp"

namespace nts {
    class Circuit : public Component {
        public:
            Circuit(std::size_t nbPins);
            ~Circuit() = default;

            void simulate(std::size_t tick);

            void addComponent(std::string name, IComponent *component);

            void updateComponents(std::vector<nts::IComponent*>&, std::vector<nts::IComponent*>&, std::vector<nts::IComponent*>&);

        protected:
        private:
            std::map<std::string, IComponent*> _components;
            std::map<IComponent*, std::vector<IComponent*>> _connections;
            std::vector<IComponent*> _entryPoints;
    };
}
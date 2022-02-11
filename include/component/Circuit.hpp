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
            Circuit(ComponentType type, std::string name, std::size_t nbPins);
            ~Circuit() = default;

            void update();
            void addInput(IComponent &comp);

        protected:
            std::vector<IComponent*> _inputs;
            std::map<std::string, IComponent*> _components;

            void addUpdatedPinsToUpdate(std::vector<IComponent*> &update, IComponent *comp);

        private:
    };
}
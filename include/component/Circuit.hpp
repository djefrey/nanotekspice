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
            Circuit(ComponentType type, std::string model, std::size_t nbPins);
            ~Circuit() = default;

            void simulate(std::size_t tick);
            IComponent &createComponent(std::string &model, std::string name);

        protected:
            std::map<std::string, std::unique_ptr<IComponent>> _components;
            std::vector<IComponent*> _inputs;

            void addUpdatedPinsToUpdate(std::vector<IComponent*> &update, IComponent &comp);

        private:
    };
}
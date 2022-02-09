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
            Circuit(ComponentType type, std::size_t nbPins);
            ~Circuit() = default;

            void simulate(std::size_t tick);
            Tristate compute(std::size_t pin);

            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);

        protected:
        private:
            std::vector<IComponent*> _outputs;
            std::map<std::string, IComponent*> _components;
    };
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Component
*/

#pragma once

#include <vector>
#include "component/IComponent.hpp"

namespace nts {
    class Component : public IComponent {
        public:
            Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
            void dump() const;

            void updateState(Tristate state, std::size_t pin);

            Connection getConnectionAt(std::size_t pin) const;
            void setConnectionAt(std::size_t pin, Connection connection);

            std::string getName() const { return _name; };
            std::size_t getNbOfPins() const { return _nbPins; };

        protected:
            Component(std::string name, std::size_t nbPins);

        private:
            std::string _name;
            std::size_t _nbPins;
            std::vector<Tristate> _states;
            std::vector<Connection> _connections;
    };
}

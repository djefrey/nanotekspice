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
            Component() = delete;

            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
            void dump() const;

            void setStateAt(std::size_t pin, Tristate state);
            Tristate getStateAt(std::size_t pin);

            Connection getConnectionAt(std::size_t pin) const;
            Connection getConnectionWith(IComponent *component) const;
            void setConnectionAt(std::size_t pin, Connection connection);
            std::vector<IComponent*> getConnections() const;

            ComponentType getType() const { return _type; };

            std::string getName() const { return _name; };
            std::size_t getNbOfPins() const { return _nbPins; };

        protected:
            Component(ComponentType type, std::string name, std::size_t nbPins);

        private:
            ComponentType _type;
            std::string _name;
            std::size_t _nbPins;
            std::vector<Tristate> _states;
            std::vector<Connection> _connections;
    };
}

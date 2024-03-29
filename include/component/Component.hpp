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
            ~Component() = default;

            virtual void update() = 0;

            void simulate(std::size_t tick);
            Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
            virtual void dump() const;

            std::string getModel() const { return _model; };
            std::string getName() const { return _name; };

            std::size_t getNbOfPins() const { return _nbPins; };

            void setName(std::string name);
            std::vector<Connection> getConnectionsAt(PinId pin) const;
            void addConnectionAt(PinId pin, IComponent &component, PinId otherPin);

            Tristate getStateAt(PinId pin);
            void setStateAt(PinId, Tristate state);
            PinType getPinTypeAt(PinId pin) const;

            std::size_t getLastUpdate() { return _lastUpdate; };

        protected:
            Component(std::string model, std::size_t nbPins);

            void setPinTypeAt(PinId id, PinType type);
            Tristate readStateAt(PinId pin);

            void readPins(const PinId pins[], Tristate states[], std::size_t size);
            void setStateToPins(const PinId pins[], Tristate state, std::size_t size);

        private:
            std::string _model;
            std::string _name;
            std::size_t _nbPins;
            std::vector<PinType> _types;
            std::vector<Tristate> _states;
            std::vector<std::vector<Connection>> _connections;
            std::size_t _lastUpdate = 0;
    };
}

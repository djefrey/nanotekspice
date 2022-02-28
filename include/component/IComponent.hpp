/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** IComponent
*/

#pragma once

#include <cstddef>
#include <memory>

#include "Tristate.hpp"

namespace nts {
    typedef struct Connection_s Connection;
    typedef std::size_t PinId;

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t) = 0;
            virtual Tristate compute(PinId) = 0;
            virtual void setLink(PinId, IComponent&, PinId) = 0;
            virtual void dump() const = 0;

            virtual std::string getModel() const = 0;
            virtual std::string getName() const = 0;

            virtual void setName(std::string name) = 0;
            virtual std::vector<Connection> getConnectionsAt(PinId) const = 0;
            virtual void addConnectionAt(PinId pin, IComponent &component, PinId otherPin) = 0;

            virtual Tristate readStateAt(PinId pin) = 0;
            virtual void setStateAt(PinId pin, Tristate state, bool update) = 0;
            virtual std::vector<std::size_t> getUpdatedPins() const = 0;
    };

    struct Connection_s {
        IComponent *component = nullptr;
        PinId pin = SIZE_MAX;
    };
}
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
    enum PinType_e {
        UNUSED = 0,
        INPUT = 1,
        OUTPUT = 2,
        INOUT = 3,
    };

    typedef struct Connection_s Connection;
    typedef enum PinType_e PinType;
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

            virtual Tristate getStateAt(PinId pin) = 0;
            virtual void setStateAt(PinId pin, Tristate state) = 0;

            virtual PinType getPinTypeAt(PinId pin) const = 0;
    };

    struct Connection_s {
        IComponent *component = nullptr;
        PinId pin = SIZE_MAX;
    };
}
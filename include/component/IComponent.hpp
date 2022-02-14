/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** IComponent
*/

#pragma once

#include <cstddef>
#include <optional>
#include <exception>
#include <memory>

#include "Tristate.hpp"

namespace nts {
    typedef struct Connection_s Connection;
    typedef std::size_t PinId;

    enum ComponentType {
        COMPONENT = 0,
        INPUT = 1,
        OUTPUT = 2,
    };

    class NtsError : public std::exception {
        public:
            NtsError(std::string loc, std::string msg) : _err("Error at " + loc + " : " + msg) {};
            const char *what() const noexcept override { return _err.c_str(); };

        private:
            std::string _err;
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t) = 0;
            virtual Tristate compute(PinId) = 0;
            virtual void setLink(PinId, IComponent&, PinId) = 0;
            virtual void dump() const = 0;

            virtual ComponentType getType() const = 0;
            virtual std::string getModel() const = 0;
            virtual std::string getName() const = 0;

            virtual void setName(std::string name) = 0;
            virtual Connection getConnectionAt(PinId) const = 0;
            virtual void setConnectionAt(PinId pin, IComponent &component, PinId otherPin) = 0;
            virtual std::vector<std::size_t> getUpdatedPins() const = 0;
    };

    struct Connection_s {
        IComponent *component = nullptr;
        PinId pin = SIZE_MAX;
    };
}
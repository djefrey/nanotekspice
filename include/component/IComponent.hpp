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

#include "Tristate.hpp"

namespace nts {
    typedef struct Connection_s Connection;

    enum ComponentType {
        INPUT,
        COMPONENT,
        OUTPUT,
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

            virtual void simulate(std::size_t tick) = 0;
            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;

            virtual void setStateAt(std::size_t pin, Tristate state) = 0;
            virtual Connection getConnectionAt(std::size_t pin) const = 0;
            virtual void setConnectionAt(std::size_t pin, Connection connection) = 0;
            virtual std::vector<IComponent*> getConnections() const = 0;

            virtual std::string getName() const = 0;
            virtual ComponentType getType() const = 0;
    };

    struct Connection_s {
        IComponent *component;
        std::size_t toPin;
    };
}
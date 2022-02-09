/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class TrueInput : public Component {
        public:
            TrueInput();
            ~TrueInput() = default;

            Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
    };

    class FalseInput : public Component {
        public:
            FalseInput();
            ~FalseInput() = default;

            Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
    };
}

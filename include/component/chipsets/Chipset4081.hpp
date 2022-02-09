/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Chipset4081
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Chipset4081 : public Component {
        public:
            Chipset4081();
            ~Chipset4081() = default;

            Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
        protected:
        private:
    };
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Clock
*/

#pragma once

#include "component/InputComponent.hpp"

namespace nts {
    class Clock : public InputComponent {
        public:
            Clock();
            ~Clock() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
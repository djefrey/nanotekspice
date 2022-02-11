/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Clock
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Clock : public Component {
        public:
            Clock();
            ~Clock() = default;

            void update();

        protected:
        private:
            Tristate _state = FALSE;
    };
}
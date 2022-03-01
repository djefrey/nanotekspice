/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Johnson4017
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Johnson4017 : public Component {
        public:
            Johnson4017();
            ~Johnson4017() = default;

            void update();

        protected:
        private:
            int _count = 0;

            void updatePins();
    };
}
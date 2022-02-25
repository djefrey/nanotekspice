/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Xor4030
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Xor4030 : public Component {
        public:
            Xor4030();
            ~Xor4030() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
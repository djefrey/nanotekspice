/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Nor4001
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Nor4001 : public Component {
        public:
            Nor4001();
            ~Nor4001() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
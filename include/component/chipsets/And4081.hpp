/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** And4081
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class And4081 : public Component {
        public:
            And4081();
            ~And4081() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
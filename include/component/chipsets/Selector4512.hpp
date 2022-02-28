/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Selector4512
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Selector4512 : public Component {
        public:
            Selector4512();
            ~Selector4512() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
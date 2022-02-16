/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Counter4040
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Counter4040 : public Component {
        public:
            Counter4040();
            ~Counter4040() = default;

            void simulate(std::size_t tick);

        protected:
        private:
            int _count = 0;

            void updatePins();
    };
}
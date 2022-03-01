/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Adder4008
*/

#pragma once
#include "component/Component.hpp"
#include <tuple>

namespace nts {
    class Adder4008: public Component {
        public:
            Adder4008();
            ~Adder4008() = default;

            void update();
            std::tuple<Tristate, Tristate> add(Tristate a, Tristate b, Tristate c);

        protected:
        private:
    };
}
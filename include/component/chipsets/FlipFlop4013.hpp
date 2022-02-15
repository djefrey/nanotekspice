/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** FlipFlop4013
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class FlipFlop4013 : public Component {
        struct FlipFlopPins {
            PinId Q;
            PinId notQ;
            PinId clock;
            PinId reset;
            PinId data;
            PinId set;
        };

        public:
            FlipFlop4013();
            ~FlipFlop4013() = default;

            void simulate(std::size_t tick);

        protected:
        private:
            void updateFlipFlop(const FlipFlopPins &pins);
    };
}
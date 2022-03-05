/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Shift4094
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Shift4094 : public Component {
        public:
            Shift4094();
            ~Shift4094() = default;

            void update();

        protected:
        private:
            uint8_t _value;
    };
}
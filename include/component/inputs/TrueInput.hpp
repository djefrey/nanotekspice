/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#pragma once

#include "component/InputComponent.hpp"

namespace nts {
    class TrueInput : public InputComponent {
        public:
            TrueInput();
            ~TrueInput() = default;

            void update();

            bool isStatic() { return true; };
    };
}

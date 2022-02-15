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

            void simulate(std::size_t tick);
    };

    class FalseInput : public InputComponent {
        public:
            FalseInput();
            ~FalseInput() = default;

            void simulate(std::size_t tick);
    };
}

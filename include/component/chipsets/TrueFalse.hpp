/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** TrueFalse
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class TrueInput : public Component {
        TrueInput();
        ~TrueInput() = default;

        void simulate(std::size_t tick);
    };

    class FalseInput : public Component {
        FalseInput();
        ~FalseInput() = default;

        void simulate(std::size_t tick);
    };
}

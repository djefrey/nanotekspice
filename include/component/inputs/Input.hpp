/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Input
*/

#pragma once

#include "component/InputComponent.hpp"

namespace nts {
    class Input : public InputComponent {
        public:
            Input() : InputComponent("input") {};
            ~Input() = default;
    };
}
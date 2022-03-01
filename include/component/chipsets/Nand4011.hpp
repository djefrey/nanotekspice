/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Nand4011
*/

#pragma once
#include "component/Component.hpp"

namespace nts {
    class Nand4011: public Component {
        public:
            Nand4011();
            ~Nand4011() = default;

            void update();

        protected:
        private:
    };
}
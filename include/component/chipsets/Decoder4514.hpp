/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Decoder4514
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Decoder4514 : public Component {
        public:
            Decoder4514();
            ~Decoder4514() = default;

            void update();
            void setOutputsToUndef(const std::size_t &outputs[]);

        protected:
        private:
    };
}
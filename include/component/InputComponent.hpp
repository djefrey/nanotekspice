/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Input
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class InputComponent : public Component {
        public:
            virtual void simulate(std::size_t tick);

            Tristate getValue();
            void setValue(Tristate state);

        protected:
            Tristate _state = UNDEFINED;

            InputComponent(std::string model);

        private:
    };
}
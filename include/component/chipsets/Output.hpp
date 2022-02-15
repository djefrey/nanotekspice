/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Output
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Output : public Component {
        public:
            Output();
            ~Output() = default;

            void simulate(std::size_t tick);
            Tristate getValue();

        protected:
        private:
    };
}
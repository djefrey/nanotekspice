/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Not4069
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class Not4069 : public Component {
        public:
            Not4069();
            ~Not4069() = default;

            void simulate(std::size_t tick);

        protected:
        private:
    };
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Output
*/

#pragma once

#include "component/Component.hpp"

namespace nts {
    class OutputComponent : public Component {
        public:
            OutputComponent();
            ~OutputComponent() = default;

            void update();
            Tristate getValue();

        protected:
        private:
    };
}
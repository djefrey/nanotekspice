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

            virtual void update();
            virtual Tristate getValue();
            virtual bool isVisible() { return true; };

        protected:
            OutputComponent(std::string model, std::size_t nbPins);

        private:
    };
}
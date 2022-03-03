/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Logger
*/

#pragma once

#include <fstream>
#include "component/OutputComponent.hpp"

namespace nts {
    class Logger : public OutputComponent {
        public:
            Logger();
            ~Logger();

            void update();
            Tristate getValue();
            bool isVisible() { return false; };

        protected:
        private:
            std::ofstream file;
    };
}
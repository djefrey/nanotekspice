/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Logger
*/

#pragma once

#include <fstream>
#include "component/Component.hpp"

namespace nts {
    class Logger : public Component {
        public:
            Logger();
            ~Logger();

            void update();

        protected:
        private:
            std::ofstream file;
    };
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Rom2716
*/

#pragma once

#include <stdint.h>
#include <sys/mman.h>
#include "component/Component.hpp"

namespace nts {
    class Rom2716 : public Component {
        public:
            Rom2716();
            ~Rom2716();
            Rom2716& operator=(Rom2716&&);

            void update();

        protected:
        private:
            int _fd = -1;
            uint8_t *_data = nullptr;
    };
}
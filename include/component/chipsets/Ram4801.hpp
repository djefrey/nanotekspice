/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Ram4801
*/

#pragma once

#include <memory>
#include <stdint.h>
#include "component/Component.hpp"

namespace nts {
    class Ram4801 : public Component {
        public:
            Ram4801();
            ~Ram4801() = default;

            void simulate(std::size_t tick);

        protected:
        private:
            std::unique_ptr<uint8_t> _data = nullptr;
    };
}
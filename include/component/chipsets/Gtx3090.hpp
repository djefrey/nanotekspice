/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Gtx3090
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "component/OutputComponent.hpp"

namespace nts {
    class Gtx3090 : public OutputComponent {
        enum State {
            WAIT_POS,
            WAIT_COLOR,
        };

        public:
            Gtx3090();
            ~Gtx3090();

            void update();
            Tristate getValue() { return nts::UNDEFINED; };
            bool isVisible() { return false; };

        protected:
        private:
            sf::RenderWindow _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
            State _state = WAIT_POS;
            uint8_t _pos = 0;
            uint8_t _color = 0;
            std::unique_ptr<uint8_t> _data;

            void setColor();
            void render();
            void reset();
    };
}
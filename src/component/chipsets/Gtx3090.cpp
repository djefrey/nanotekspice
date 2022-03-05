/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Gtx3090
*/

#include <stdlib.h>
#include <string.h>
#include "NTS.hpp"
#include "component/chipsets/Gtx3090.hpp"

/* PINS:
 * 0 -> 7 : Data
 * 8      : Clock
 * 9      : Inhibit
 * 10     : Reset
 */
nts::Gtx3090::Gtx3090() : OutputComponent("3090", 11),
    _window(sf::VideoMode(640, 640), "NanoTekSpice", sf::Style::Titlebar)
{
    _data = std::unique_ptr<uint8_t>{(uint8_t*) malloc(4 * 16 * 16)};
    if (_data.get() == nullptr || !_texture.create(16, 16))
        throw NtsError("nts::Gtx3090::Gtx3090()", "Could not allocate memory");
    memset(_data.get(), 0, 4 * 16 * 16);
    _texture.setSmooth(false);
    _sprite.setTexture(_texture);
    _sprite.setPosition(sf::Vector2f{0, 0});
    _sprite.setScale(sf::Vector2f{40, 40});
    for (std::size_t pin = 0; pin < 11; pin++)
        setPinTypeAt(pin, INPUT);
}

nts::Gtx3090::~Gtx3090()
{
    _window.close();
}

void nts::Gtx3090::update()
{
    const PinId dataPins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    Tristate clock = readStateAt(8);
    Tristate inhibit = readStateAt(9);
    Tristate reset = readStateAt(10);
    Tristate bits[8];
    sf::Event event;

    while (_window.pollEvent(event));
    readPins(dataPins, bits, 8);
    try {
        if (reset == TRUE) {
            this->reset();
        } else if (reset == FALSE && clock == TRUE && inhibit == FALSE) {
            if (_state == WAIT_POS) {
                _pos = (uint8_t) Gates::statesToInt(bits, 8);
                _state = State::WAIT_COLOR;
            } else {
                _color = (uint8_t) Gates::statesToInt(bits, 8);
                setColor();
                render();
                _state = State::WAIT_POS;
            }
        }
    } catch(InvalidStateError &e) {}
}

#include <iostream>

void nts::Gtx3090::setColor()
{
    sf::Uint8 r = ((_color & 0xE0) >> 6) * 255;
    sf::Uint8 g = ((_color & 0x1C) >> 3) * 255;
    sf::Uint8 b = ((_color & 0x03))      * 255;
    sf::Uint8 x = ((_pos & 0xF0) >> 4);
    sf::Uint8 y = ((_pos & 0x0F));
    uint64_t idx = (x + y * 16) * 4;

    printf("- %#02x %hhu %hhu\n", _pos, x, y);
    printf(". %#02x %hhu %hhu %hhu\n", _color, x, y, b);
    _data.get()[idx + 0] = r;
    _data.get()[idx + 1] = g;
    _data.get()[idx + 2] = b;
    _data.get()[idx + 3] = 255;
}

void nts::Gtx3090::render()
{
    _texture.update(_data.get());
    _window.draw(_sprite);
    _window.display();
}

void nts::Gtx3090::reset()
{
    _state = WAIT_POS;
    _pos = 0;
    _color = 0;
    memset(_data.get(), 0, 4 * 16 * 16);
    _window.clear(sf::Color::Black);
    _window.display();
}
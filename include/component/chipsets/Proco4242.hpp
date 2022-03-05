/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Proco4242
*/

#pragma once

#include <map>
#include <stack>
#include "component/Component.hpp"

namespace nts {
    class Proco4242 : public Component {
        enum State {
            NEXT,
            EXECUTE,
            READ_INSTR,
            READ_DATA,
            WRITE,
            IO,
        };

        public:
            typedef void (Proco4242::*instrFctPtr)();

            Proco4242();
            ~Proco4242() = default;

            void update();

            void incrementInstr();
            void decrementInstr();
            void increaseInstr();
            void decreaseInstr();
            void jumpForwardInstr();
            void jumpBackwardInstr();
            void outputInstr();
        protected:
        private:
            static const std::map<char, instrFctPtr> INSTRUCTIONS;

            uint16_t _instrPtr = 0;
            uint16_t _dataPtr = 0;
            uint8_t _instr = 0;
            uint8_t _data = 0;
            State _state = NEXT;
            uint8_t _substate = 0;
            uint32_t _jumpTest = 0;
            std::stack<uint32_t> _stack;

            void executeInstruction();
            void executeIO();

            void moveToNextInstruction();

            void readROMInstruction();
            void readRAMData();
            void writeRAMData();
            void writeIO();

            void reset();
            void resetControlPins();
    };
}
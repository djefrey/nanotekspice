/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** NTS
*/

#pragma once

#include <string>
#include <map>
#include <functional>
#include <exception>
#include "component/Circuit.hpp"

namespace nts {
    class NTS;

    typedef void (nts::NTS::*NTSFctPtr)(void);

    class NtsError : public std::exception {
        public:
            NtsError(std::string loc, std::string msg) : _err("Error at " + loc + " : " + msg) {};
            const char *what() const noexcept override { return _err.c_str(); };

        private:
            std::string _err;
    };

    class NTS {
        const static std::map<std::string, NTSFctPtr> commandsList;

        public:
            NTS();
            NTS(const std::string &config);
            ~NTS() = default;

            int run();

        protected:
        private:
            nts::Circuit _circuit;
            std::size_t _tick = 0;
            bool _run = true;

            bool readInput(std::string &line);
            void executeCmd(const std::string &cmd);
            bool setInputFromCmd(const std::string &cmd);

            void simulateCmd();
            void displayCmd();
            void loopCmd();
            void dumpCmd();
            void exitCmd();
    };
}
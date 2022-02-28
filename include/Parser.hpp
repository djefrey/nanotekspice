/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <iostream>
#include "component/Circuit.hpp"
#include <regex>
#include "NTS.hpp"

namespace nts {
    class Parser {
        public:
            Parser(nts::Circuit &circuit);
            ~Parser() = default;

            void parseFile(const std::string &path);
            void parseStr(const std::string &content);
            void parseChipset(std::sregex_token_iterator &iter, std::sregex_token_iterator end);
            void parseLinks(std::sregex_token_iterator &iter, std::sregex_token_iterator end);

        protected:
        private:
            nts::Circuit &_circuit;
    };
}

#endif /* !PARSER_HPP_ */

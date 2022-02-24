/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Parser
*/

#include <fstream>
#include "../include/Parser.hpp"
#include "../include/component/IComponent.hpp"

nts::Parser::Parser(nts::Circuit &circuit) : _circuit(circuit) {}

void nts::Parser::Parse(const std::string &path)
{
    std::regex skipComment("[#].*");
    std::regex getInfo("\\.([A-Za-z]+)|([A-Za-z0-9]+)");
    std::ifstream file(path);
    std::stringstream stream;
    std::string content;

    if (!file.is_open())
        std::cerr << "No such file or directory" << std::endl;
    stream << file.rdbuf();
    content = stream.str();
    content = std::regex_replace(content, skipComment, "");
    std::sregex_token_iterator iter(content.begin(), content.end(), getInfo, 0);
    std::sregex_token_iterator end;
    ParseChipset(iter, end);
    ParseLinks(iter, end);
}

void nts::Parser::ParseLinks(std::sregex_token_iterator &iter, std::sregex_token_iterator end)
{
    std::string tmp_comp1 = NULL;
    std::string tmp_comp2 = NULL;
    nts::PinId tmp_pin1 = NULL;
    nts::PinId tmp_pin2 = NULL;
    std::regex checkPin("[0-9]+");

    if (*iter != ".links")
        throw NtsError("Parser::Parse()", ".chipsets not found !");
    iter++;
    for (int i = 0; iter != end; iter++) {
        if (i == 0) {
            tmp_comp1 = *iter;
            i++;
        } else if (i == 1) {
            /* if (!std::regex_match(*iter, *iter + 1, checkPin))
                throw NtsError("Parser::ParseLinks()", "Invalid Pin!"); */
            tmp_pin1 = std::stoi(*iter);
            i++;
        } else if (i == 2) {
            tmp_comp2 = *iter;
            i++;
        } else {
            /* if (!std::regex_match(*iter, *iter + 1, checkPin))
                throw NtsError("Parser::ParseLinks()", "Invalid Pin!"); */
            tmp_pin2 = std::stoi(*iter);
            i = 0;
            _circuit.setLink(tmp_comp1, tmp_comp2, tmp_pin1, tmp_pin2);
        }
    }
}

void nts::Parser::ParseChipset(std::sregex_token_iterator &iter, std::sregex_token_iterator end)
{
    std::string tmp_model = NULL;
    std::string tmp_name = NULL;

    if (*iter != ".chipsets")
        throw NtsError("Parser::Parse()", ".chipsets not found !");
    iter++;
    for (int i = 0; iter != end; iter++) {
        if (*iter == ".links")
            return;
        if (i == 0) {
            tmp_model = *iter;
            i++;
        } else {
            tmp_name = *iter;
            i = 0;
            _circuit.createComponent(tmp_model, tmp_name);
        }
    }
}
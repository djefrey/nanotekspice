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
    std::regex getInfo("\\.([A-Za-z]+)|([A-Za-z0-9_-]+)");
    std::ifstream file(path);
    std::stringstream stream;
    std::string content;

    if (path.find(".nts") == path.npos)
        throw NtsError("Parse::Parse()", "Not good extension");
    if (!file.is_open())
        throw NtsError("Parse::Parse()", "No such file or directory");
    stream << file.rdbuf();
    if (!stream.good())
        throw NtsError("Parse::Parse()", "Empty file");
    content = stream.str();
    content = std::regex_replace(content, skipComment, "");
    std::sregex_token_iterator iter(content.begin(), content.end(), getInfo, 0);
    std::sregex_token_iterator end;
    ParseChipset(iter, end);
    ParseLinks(iter, end);
}

void nts::Parser::ParseChipset(std::sregex_token_iterator &iter, std::sregex_token_iterator end)
{
    std::string model;
    std::string name;

    if (*iter != ".chipsets")
        throw NtsError("Parser::Parse()", ".chipsets not found !");
    iter++;
    for (int i = 0; iter != end; iter++) {
        if (*iter == ".links")
            return;
        if (i == 0) {
            model = iter->str();
            i++;
        } else {
            name = iter->str();
            _circuit.createComponent(model, name);
            i = 0;
        }
    }
}

void nts::Parser::ParseLinks(std::sregex_token_iterator &iter, std::sregex_token_iterator end)
{
    std::string comp1;
    std::string comp2;
    nts::PinId pin1 = 0;
    nts::PinId pin2 = 0;
    std::regex checkPin("[0-9]+");

    if (*iter != ".links")
        throw NtsError("Parser::Parse()", ".links not found !");
    iter++;
    for (int i = 0; iter != end; iter++) {
        if (i == 0) {
            comp1 = iter->str();
            i++;
        } else if (i == 1) {
            if (!std::regex_match(iter->first, iter->second, checkPin))
                throw NtsError("Parser::ParseLinks()", "Invalid Pin!");
            pin1 = std::stoi(iter->str()) - 1;
            i++;
        } else if (i == 2) {
            comp2 = iter->str();
            i++;
        } else {
            if (!std::regex_match(iter->first, iter->second, checkPin))
                throw NtsError("Parser::ParseLinks()", "Invalid Pin!");
            pin2 = std::stoi(iter->str()) - 1;
            _circuit.setLink(comp1, comp2, pin1, pin2);
            i = 0;
        }
    }
}
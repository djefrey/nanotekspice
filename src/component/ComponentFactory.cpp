/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** ComponentFactory
*/

#include <algorithm>

#include "NTS.hpp"
#include "component/ComponentFactory.hpp"

#include "component/inputs/TrueInput.hpp"
#include "component/inputs/FalseInput.hpp"
#include "component/inputs/Clock.hpp"
#include "component/OutputComponent.hpp"

#include "component/chipsets/Chipset4081.hpp"

std::unique_ptr<nts::ComponentFactory> nts::ComponentFactory::instance = nullptr;

const std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(void)>> nts::ComponentFactory::componentList{
    std::make_pair("true", [](){ return std::make_unique<nts::TrueInput>(); }),
    std::make_pair("false", [](){ return std::make_unique<nts::FalseInput>(); }),
    std::make_pair("clock", [](){ return std::make_unique<nts::Clock>(); }),
    std::make_pair("output", [](){ return std::make_unique<nts::OutputComponent>(); }),

    std::make_pair("4081", [](){ return std::make_unique<nts::Chipset4081>(); }),

};

nts::ComponentFactory &nts::ComponentFactory::get()
{
    if (!instance)
        instance = std::unique_ptr<nts::ComponentFactory>(new nts::ComponentFactory);
    return *instance;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &model)
{
    auto it = componentList.find(model);

    if (it == componentList.end())
        throw NtsError("ComponentFactory::createComponent()", "Invalid model");
    return (it->second)();
}
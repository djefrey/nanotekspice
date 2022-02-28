/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** ComponentFactory
*/

#include <algorithm>

#include "NTS.hpp"
#include "component/ComponentFactory.hpp"

#include "component/inputs/Input.hpp"
#include "component/inputs/TrueInput.hpp"
#include "component/inputs/FalseInput.hpp"
#include "component/inputs/Clock.hpp"
#include "component/OutputComponent.hpp"
#include "component/chipsets/Logger.hpp"

#include "component/chipsets/And4081.hpp"
#include "component/chipsets/Or4071.hpp"
#include "component/chipsets/Not4069.hpp"
#include "component/chipsets/FlipFlop4013.hpp"
#include "component/chipsets/Counter4040.hpp"
#include "component/chipsets/Johnson4017.hpp"
#include "component/chipsets/Adder4008.hpp"
#include "component/chipsets/Nand4011.hpp"
#include "component/chipsets/Nor4001.hpp"
#include "component/chipsets/Xor4030.hpp"
#include "component/chipsets/Rom2716.hpp"
#include "component/chipsets/Decoder4514.hpp"
#include "component/chipsets/Selector4512.hpp"
#include "component/chipsets/Ram4801.hpp"

std::unique_ptr<nts::ComponentFactory> nts::ComponentFactory::instance = nullptr;

const std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(void)>> nts::ComponentFactory::componentList{
    std::make_pair("input", [](){ return std::make_unique<nts::Input>(); }),
    std::make_pair("true", [](){ return std::make_unique<nts::TrueInput>(); }),
    std::make_pair("false", [](){ return std::make_unique<nts::FalseInput>(); }),
    std::make_pair("clock", [](){ return std::make_unique<nts::Clock>(); }),
    std::make_pair("output", [](){ return std::make_unique<nts::OutputComponent>(); }),
    std::make_pair("logger", [](){ return std::make_unique<nts::Logger>(); }),

    std::make_pair("4081", [](){ return std::make_unique<nts::And4081>(); }),
    std::make_pair("4071", [](){ return std::make_unique<nts::Or4071>(); }),
    std::make_pair("4069", [](){ return std::make_unique<nts::Not4069>(); }),
    std::make_pair("4013", [](){ return std::make_unique<nts::FlipFlop4013>(); }),
    std::make_pair("4040", [](){ return std::make_unique<nts::Counter4040>(); }),
    std::make_pair("4017", [](){ return std::make_unique<nts::Johnson4017>(); }),
    std::make_pair("4008", [](){ return std::make_unique<nts::Adder4008>(); }),
    std::make_pair("4011", [](){ return std::make_unique<nts::Nand4011>(); }),
    std::make_pair("4001", [](){ return std::make_unique<nts::Nor4001>(); }),
    std::make_pair("4030", [](){ return std::make_unique<nts::Xor4030>(); }),
    std::make_pair("2716", [](){ return std::make_unique<nts::Rom2716>(); }),
    std::make_pair("4514", [](){ return std::make_unique<nts::Decoder4514>(); }),
    std::make_pair("4512", [](){ return std::make_unique<nts::Selector4512>(); }),
    std::make_pair("4801", [](){ return std::make_unique<nts::Ram4801>(); }),
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